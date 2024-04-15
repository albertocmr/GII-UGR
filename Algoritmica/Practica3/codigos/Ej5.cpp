
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct Calle {
  string nombre;
  int src, dst;
  int coste;
};

struct Plaza {
  int id;
  vector<Calle> calles; // Lista de adyacencia: (destino, coste asfalto)
};

class Pueblo {
private:
  vector<Plaza> plazas;

public:
  Pueblo(int nPlazas) {
    plazas.resize(nPlazas);
    for (int i = 0; i < nPlazas; i++) {
      plazas[i].id = i;
    }
  }

  void addCalle(string nombre, int src, int dest, int coste){
    plazas[src].calles.push_back({nombre, src, dest, coste});
    plazas[dest].calles.push_back({nombre, dest, src, coste});
  }
  string toString() const {
    string res = "";
    for (const auto &plaza : plazas) {
      res += "Nodo " + to_string(plaza.id) + ":\n";
      for (const auto &calle : plaza.calles) {
        res += "-> " + to_string(calle.dst) +
               " (Peso: " + to_string(calle.coste) += ")\n";
      }
      res += "\n";
    }

    return res;
  }
  int getNumPlazas() const { return plazas.size(); }
  vector<Plaza> getPlazas() const { return plazas; }

  // v[0] y v[1] son las plazas que une esa calle
  // Si no existe la calle devuelve -1, -1
  vector<int> getPlazasNombreCalle(string nombreCalle) const{
    bool encontrado = false;
    vector<int> res(2, -1);
    for (int i = 0; i < plazas.size() && !encontrado; i++) {
      for (int j = 0; j < plazas[i].calles.size() && !encontrado; j++) {
        if (plazas[i].calles[j].nombre == nombreCalle) {
          encontrado = true;
          res[0] = plazas[i].calles[j].src;
          res[1] = plazas[i].calles[j].dst;
        }
      }
    }
  
    return res;
  }
};

vector<int> asfaltar(const Pueblo &p,  map<string,int> &presupuestos) {
  int n = p.getNumPlazas();
  vector<int> resultado;
  set<set<int>> componentes;

  //Generar las componentes conexas
  for (int i = 0; i < n; i++){
    set<int> componente;
    componente.insert( p.getPlazas()[i].id);
    componentes.insert(componente);
  }
  
  while (resultado.size() < n - 1) {
    int coste_calle = presupuestos.begin()->second;
    string nombre_calle = presupuestos.begin()->first;
    presupuestos.erase(nombre_calle);

    //Sacar las plazas conectadas por esa calle
    vector<int> conectadas  = p.getPlazasNombreCalle(nombre_calle);
    int u = conectadas[0], v = conectadas[1];

    //Sacar las componentes de las plazas
    set<int> compu;
    set<int> compv;
    for (auto it = componentes.begin(); it != componentes.end(); ++it)
      if (it->find(u) != it->end())
        compu = *it;
    

    for (auto it = componentes.begin(); it != componentes.end(); ++it)
      if (it->find(v) != it->end())
        compv = *it;
    
    //Comprobar si son distintas
    if (compu != compv){
      //Unir esas componentes
      componentes.erase(compu);
      componentes.erase(compv);
      for (int ele : compv)
        compu.insert(ele);
      componentes.insert(compu);
      
      //Añadir el precio al resultado
      resultado.push_back(coste_calle);
    }
  }

  return resultado;
}

int main() {
  // Crear un grafo con 4 nodos
  Pueblo g(4);

  g.addCalle("Calle 1", 0, 1, 130);
  g.addCalle("Calle 2", 0, 2, 1100);
  g.addCalle("Calle 3", 0, 3, 450);
  g.addCalle("Calle 4", 1, 3, 555);
  g.addCalle("Calle 5", 1, 2, 1300);

  map<string,int> presupuestos = {{"Calle 1", 130}, {"Calle 2", 1100}, {"Calle 3", 450}, {"Calle 4", 555}, 
                                {"Calle 5", 1300}};
  

  vector<int> res = asfaltar(g, presupuestos);

  for (int ele : res)
      cout << ele << endl;
}


#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int INF = INT_MAX; // Representa el infinito

void MostrarMatriz(vector<vector<int>> & m){
  for(int i = 0; i < m.size(); i++){
    for(int j = 0; j < m[i].size(); j++){
      if(m[i][j] == INF)
        cout << "∞ ";
      else
        cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

void RecuperacionSolucion( vector<vector<int>> & ruta, int inicio, int fin, vector<int>& camino){
  if (ruta[inicio][fin] == 0) {
    camino.push_back(fin+1);
    return;
  }
  
  // Si hay un nodo intermedio k, primero imprimos el camino de i a k
  int k = ruta[inicio][fin] -1;
  RecuperacionSolucion(ruta, inicio, k, camino);
  // Luego imprimimos el camino de k a j
  RecuperacionSolucion(ruta, k, fin, camino);
}

vector<int> floydWarshall(vector<vector<int>>& original, vector<vector<int>>& costes, vector<vector<int>> caminos, int aldeaInicial, int aldeaFinal){
  
  int tam = original.size();
  
  // Inicializar la matriz de distancias con los costes directos
  costes = original;

  // Algoritmo de Floyd-Warshall
  for (int k = 0; k < tam; ++k) {
      for (int i = 0; i < tam; ++i) {
          for (int j = 0; j < tam; ++j) {
             if (costes[i][k] != INF && costes[k][j] != INF){ 
                if (costes[i][k] + costes[k][j] < costes[i][j]){
                  costes[i][j] = costes[i][k] + costes[k][j];
                  caminos[i][j] = k + 1;
                }
              }
          }
      }
  }

  vector<int> ruta(1, aldeaInicial);
  RecuperacionSolucion(caminos, aldeaInicial-1, aldeaFinal-1, ruta);

  return ruta;
}

int main(int argc, char * argv[]){

  if(argc != 3){
    cerr << "Error en el número de argumentos. Uso: " << argv[0] << " <aldea inicial> <aldea final>" << endl;
    exit(-1);
  }

  int aldeaInicial = atoi(argv[1]);
  int aldeaFinal = atoi(argv[2]);

  if(aldeaInicial < 0 || aldeaInicial > 5 || aldeaFinal < 0 || aldeaFinal > 5){
    cerr << "Error en el rango de las aldeas. Debe ser un valor entre 1 y 5." << endl;
    exit(-1);
  }

  vector<vector<int>> original = {
      {0, 3, 3, INF, INF},
      {INF, 0, 4, 7, INF},
      {INF, INF, 0, 2, 3},
      {INF, INF, INF, 0, 2},
      {INF, INF, INF, INF, 0}
  };

  vector<vector<int>> costes;
  vector<vector<int>> caminos(original.size(), vector<int>(original.size(), 0));
  vector<int> ruta = floydWarshall(original, costes, caminos, aldeaInicial, aldeaFinal);
  
  cout << "Matriz original: " << endl;
  MostrarMatriz(original);
  cout << "-------------------------------------" << endl;
  cout << "Matriz de costes mínimos: " << endl;
  MostrarMatriz(costes);
  cout << "-------------------------------------" << endl;
 
  cout << "El coste de ir de la aldea " << aldeaInicial << " a la aldea " << aldeaFinal;
  cout << " es: " << costes[aldeaInicial-1][aldeaFinal-1] << endl;
  cout << "La ruta óptima es: ";
  for(int i = 0; i < ruta.size(); i++){
    cout << ruta[i] << " ";
  }
  cout << endl;
  

  return 0;
}
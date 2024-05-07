#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

// const int MOV = 31;
const int TAM = 7;

enum estado { libre, ocupada, no_valida };

/*
  1 -> izquierda
  2 -> arriba
  3 -> derecha
  4 -> abajo
*/
struct ubicacion {
  int fil;
  int col;
};

struct accion {
  ubicacion u;
  int dir;
};



bool esSolucion(vector<vector<estado>> tablero) {
  bool sol = tablero[TAM / 2][TAM / 2] == estado::ocupada;

  for (int i = 0; i < TAM && sol; i++)
    for (int j = 0; j < TAM && sol; j++) {
      if (!(i == TAM / 2 && j == TAM / 2)) {
        if (tablero[i][j] == estado::ocupada)
          sol = false;
        
      }
    }

  return sol;
}

void pintarTablero(const vector<vector<estado>> &tablero) {
  for (const auto &fila : tablero) {
    for (estado valor : fila) {
      if (valor == estado::ocupada) {
        cout << "O ";
      } else if (valor == estado::libre) {
        cout << "L ";
      } else {
        std::cout << "X ";
      }
    }
    std::cout << std::endl; // Salto de línea después de cada fila
  }
}

bool dentroRango(const ubicacion &u) {
  return u.fil >= 0 && u.fil < TAM && u.col >= 0 && u.col < TAM;
}

bool esValido(const ubicacion &ubi, const int &movimiento,
              const vector<vector<estado>> &tablero) {
    bool valido =
        dentroRango(ubi) && tablero[ubi.fil][ubi.col] == estado::ocupada;
    ubicacion siguiente = ubi;
    if (valido)
        switch (movimiento) {
          case 1:
            siguiente.col -= 2;
            valido = dentroRango(siguiente) &&
            tablero[ubi.fil][ubi.col - 1] == estado::ocupada &&
            tablero[siguiente.fil][siguiente.col] == estado::libre;
            break;
          case 2:
            siguiente.fil -= 2;
            valido = dentroRango(siguiente) &&
                    tablero[ubi.fil - 1][ubi.col] == estado::ocupada &&
                    tablero[siguiente.fil][siguiente.col] == estado::libre;
            break;
          case 3:
            siguiente.col += 2;
            valido = dentroRango(siguiente) &&
                    tablero[ubi.fil][ubi.col + 1] == estado::ocupada &&
                    tablero[siguiente.fil][siguiente.col] == estado::libre;
            break;
          case 4:
            siguiente.fil += 2;
            valido = dentroRango(siguiente) &&
                    tablero[ubi.fil + 1][ubi.col] == estado::ocupada &&
                    tablero[siguiente.fil][siguiente.col] == estado::libre;
            break;
        }

    return valido;
}

vector<vector<estado>> cambiaTablero(const ubicacion &ubi,
                                     const int &movimiento,
                                     const vector<vector<estado>> &tablero) {
  vector<vector<estado>> nuevo = tablero;

  switch (movimiento) {
  case 1:
    nuevo[ubi.fil][ubi.col] = estado::libre;
    nuevo[ubi.fil][ubi.col - 1] = estado::libre;
    nuevo[ubi.fil][ubi.col - 2] = estado::ocupada;
    break;
  case 2:
    nuevo[ubi.fil][ubi.col] = estado::libre;
    nuevo[ubi.fil - 1][ubi.col] = estado::libre;
    nuevo[ubi.fil - 2][ubi.col] = estado::ocupada;
    break;
  case 3:
    nuevo[ubi.fil][ubi.col] = estado::libre;
    nuevo[ubi.fil][ubi.col + 1] = estado::libre;
    nuevo[ubi.fil][ubi.col + 2] = estado::ocupada;
    break;
  case 4:
    nuevo[ubi.fil][ubi.col] = estado::libre;
    nuevo[ubi.fil + 1][ubi.col] = estado::libre;
    nuevo[ubi.fil + 2][ubi.col] = estado::ocupada;
    break;
  }

  return nuevo;
}

vector<accion> senku2(const vector<vector<estado>> &tablero){
    bool hemosMovido = false;
    bool encontradoSol = false;
    vector< accion > plan;

    for (int i = 0; i < TAM && !encontradoSol; i++)
      for (int j = 0; j < TAM && ! encontradoSol; j++)
        for (int k = 1; k <= 4; k++)
          if (esValido({i,j}, k, tablero) && !hemosMovido){
              vector<vector<estado>> otro = cambiaTablero({i,j}, k, tablero);
              if (esSolucion(otro)) {
                  hemosMovido = true;
                  plan.push_back({{i,j}, k});
                  encontradoSol = true;
              }
              else{
                  vector< accion > mini = senku2(otro);
                  if (!mini.empty()){
                      hemosMovido = true;
                      plan.push_back({{i,j}, k});
                      plan.insert(plan.end(), mini.begin(), mini.end());
                  }
              }        
        }

    if (!hemosMovido){
        return vector< accion >();
    }

    return plan;
}
int main() {

    vector<vector<estado>> tablero(TAM, vector<estado>(TAM, ocupada));

    tablero[TAM / 2][TAM / 2] = estado::libre;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
        tablero[i][j] = estado::no_valida;
        tablero[TAM - i - 1][j] = estado::no_valida;
        tablero[i][TAM - j - 1] = estado::no_valida;
        tablero[TAM - i - 1][TAM - j - 1] = estado::no_valida;
        }

    pintarTablero(tablero);

    vector<accion> plan = senku2(tablero);

    cout << plan.size() << endl;
    cout << "MAAAIn" << endl;
    for (accion a : plan) {
        tablero = cambiaTablero(a.u, a.dir, tablero);
        cout << "-----------------------" << endl;
        pintarTablero(tablero);
    }
}

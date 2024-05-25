#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int INF = INT_MAX; // Representa el infinito

void floydWarshall(vector<vector<int>>& costes, int tam, int aldeaInicial, int aldeaFinal) {
  
  // Inicializar la matriz de distancias con los costes directos
  vector<vector<int>> C = costes;

  // Algoritmo de Floyd-Warshall
  for (int k = 0; k < tam; ++k) {
      for (int i = 0; i < tam; ++i) {
          for (int j = 0; j < tam; ++j) {
              if (C[i][k] != INF && C[k][j] != INF) {
                  C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
            }
          }
      }
  }

  cout << "Matriz original: " << endl;
  for (int i = 0; i < tam; ++i) {
      for (int j = 0; j < tam; ++j) {
          if (costes[i][j] == INF) {
              cout << "INF ";
          } else {
              cout << costes[i][j] << " ";
          }
      }
      cout << endl;
  }
  cout << "-------------------------------------" << endl;

  cout << "Matriz de costes mínimos: " << endl;
  for (int i = 0; i < tam; ++i) {
      for (int j = 0; j < tam; ++j) {
          if (C[i][j] == INF) {
              cout << "INF ";
          } else {
              cout << C[i][j] << " ";
          }
      }
      cout << endl;
  }
  cout << "-------------------------------------" << endl;
  cout << "El coste de ir de la aldea " << aldeaInicial << " a la aldea " << aldeaFinal;
  cout << " es: " << C[aldeaInicial-1][aldeaFinal-1] << endl;

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

  vector<vector<int>> costes = {
      {0, 3, 3, INF, INF},
      {INF, 0, 4, 7, INF},
      {INF, INF, 0, 2, 3},
      {INF, INF, INF, 0, 2},
      {INF, INF, INF, INF, 0}
  };

  floydWarshall(costes, costes.size(), aldeaInicial, aldeaFinal);

  return 0;
}

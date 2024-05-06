#include <vector>
#include <iostream>

using namespace std;

struct Resultado {
    int sumaMaxima;
    vector< pair<int, int> > mejoresParejas;
};


// Función para intentar emparejar los estudiantes
Resultado Emparejar( vector< vector<int> > preferencias ,int n, vector<bool>& emparejados, vector< pair<int, int>>& ParejasActuales, int sumaActual, int indice, int sumaMaxima) {
    Resultado resul;
    resul.sumaMaxima = sumaMaxima;
    if (indice == n) {
        if (sumaActual > sumaMaxima) {
            resul.sumaMaxima = sumaActual;
            resul.mejoresParejas = ParejasActuales;
        }
        return  resul;
    }

    Resultado bestResul = resul;

    if (emparejados[indice]) {
        return Emparejar(preferencias,n, emparejados, ParejasActuales, sumaActual, indice + 1,sumaMaxima);
       
    }

    for (int j = indice + 1; j < n; j++) {
        if (!emparejados[j]) {
            emparejados[indice] = true;
            emparejados[j] = true;
            ParejasActuales.emplace_back(indice, j);
            int valorPareja = preferencias[indice][j] * preferencias[j][indice];

            Resultado currentResul = Emparejar(preferencias,n, emparejados, ParejasActuales, sumaActual + valorPareja, indice + 1, bestResul.sumaMaxima);

            if ( currentResul.sumaMaxima > bestResul.sumaMaxima ){
                bestResul = currentResul;
            }
            // Deshacemos cambios para la próxima iteración
            emparejados[indice] = false;
            emparejados[j] = false;
            ParejasActuales.pop_back();
        }
    }

    return bestResul;
}

int main() {

  vector< vector<int> > preferencias;
  int n = 4;
    preferencias.resize(n, vector<int>(n));

  // Semilla para la generación de números aleatorios
  srand(time(0));

  // Rellenar la matriz línea por línea con números aleatorios
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if ( i != j ){
            preferencias[i][j] = 1 + rand() % 9; // Números aleatorios entre 0 y 9 (inclusive)
        }
      }
  }

  // Enseño el vector
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << preferencias[i][j] << " ";
    }
    cout << endl;
  }

  vector<bool> emparejado(n, false);
  vector< pair<int, int>> currentPairs;
  Resultado finalResul = Emparejar(preferencias,n, emparejado, currentPairs, 0, 0, 0);

 
  int suma = 0;
     cout << "The best pairs are:" << endl;
  for (const auto& pair : finalResul.mejoresParejas) {
      cout << "(" << (pair.first)+1 << ", " << (pair.second)+1 << ")" << endl;
    suma += preferencias[pair.first][pair.second] * preferencias[pair.second][pair.first];
 
  }
  cout << "La maxima suma de los emparejamientos es: : " << suma << endl;
 
   
}
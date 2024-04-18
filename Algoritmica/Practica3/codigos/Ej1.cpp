#include <iostream>
#include <vector>

using namespace std;


vector < pair < int,int > > Mejor_emparejamiento(vector<vector<int>> &preferencias) {

  vector < pair < int,int > > emparejamiento;
  
  int n = preferencias.size();
  vector<bool> disponible(n, true); 
  int numEmparejados = 0;

  while (numEmparejados < n) {
    int estudianteLibre;
    // Compruebo cuál es el siguiente almumno sin pareja
    bool libre = false;
    for (estudianteLibre = 0; estudianteLibre < n && !libre; ++estudianteLibre) {
      if (disponible[estudianteLibre]) {
        libre = true;
      }
    }

    int mult = 0;
    int estudiante_eleg;

    for (int primer_estudiante = 0;
         primer_estudiante < n && disponible[estudianteLibre];
         ++primer_estudiante) {
      //Un alumno no puede ir consigo mismo
      if (primer_estudiante == estudianteLibre) {
      }
     

      int actual = preferencias[primer_estudiante][estudianteLibre] *
                   preferencias[estudianteLibre][primer_estudiante];
      // Si la multiplicacion es mayor al del anterior y esta disponible , se actualiza la pareja
      if ( actual > mult && disponible[primer_estudiante]){
        mult = actual;
        estudiante_eleg = primer_estudiante;
      }
    }
    
    // Hago la pareja
    numEmparejados+=2;
    
    //Meto la pareja en el vector de emparejados
    emparejamiento.push_back(make_pair(estudianteLibre,estudiante_eleg ));
    
    // Hago que no esten disponibles los estudiantes ya emparejados
    disponible[estudiante_eleg] = false;
    disponible[estudianteLibre] = false;
  }
  return emparejamiento;
}

int main() {

  int n = 4; // Define the size of the vector
  vector<vector<int>> matriz(n, vector<int>(n,0)); // Initialize a n x n 2D vector

  // Semilla para la generación de números aleatorios
  srand(time(0));

  // Rellenar la matriz línea por línea con números aleatorios
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if ( i != j ){
          matriz[i][j] = 1 + rand() % 9; // Números aleatorios entre 0 y 99 (inclusive)
        }
      }
  }

  // Printing the elements of the vector
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  vector<pair<int, int>> parejas;
  parejas = Mejor_emparejamiento(matriz);

  int suma = 0;

  for (const auto& pareja : parejas) {
      cout << "Estudiante " << pareja.first + 1 << " -> Estudiante " << pareja.second + 1 << endl;
    suma +=(matriz[pareja.first][pareja.second] * matriz[pareja.second][pareja.first]);
  }

  cout << "Suma de los valores de la matriz: " << suma << endl;

  return 0;
}
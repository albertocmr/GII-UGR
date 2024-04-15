#include <vector>
#include <limits>
#include <iostream>
#include <unordered_map>

using namespace std;

const double M = numeric_limits<double>::max();

vector<int> Greedy(vector<vector<double>>& valores, int source, int destino, double& coste_acumulado) {
	int actual = source;
	vector<int> camino;
	coste_acumulado = 0;
	bool haySolucion = true;
   bool esDestino = false;

   camino.push_back(actual);

   while (actual != destino && haySolucion) {
      double minimo = M;
      vector<int> minimos;
   	int seleccion = 0;

      // Encuentra el m�nimo y los �ndices iguales al m�nimo
      for (int i = 0; i < valores[actual].size(); i++) {
         if (valores[actual][i] < minimo) {
            minimo = valores[actual][i];
            minimos.clear();
            minimos.push_back(i);
         }else if (valores[actual][i] == minimo) {
            minimos.push_back(i);
            if(i == destino){
               esDestino = true;
            }
         }
      }

      if (!esDestino){
         double media_min = M;
         for (int i : minimos) {
            double suma = 0;
            int contador = 0;
            
            for (int j = 0; j < valores[i].size(); j++) {
               if (valores[i][j] != M) {
                  suma += valores[i][j];
                  contador++;
               }
            }
            double media = suma / contador;
            if (media <= media_min) {
               media_min = media;
               seleccion = i;
            }
         }
      }else{
         seleccion=destino;
      }
		
		
      // Aseguramos que no haya repetidos
      valores[actual][seleccion] = M;
      valores[seleccion][actual] = M;
      camino.push_back(seleccion);
      coste_acumulado += minimo;
      actual = seleccion;

      // Si el m�nimo es M, no hay soluci�n
      if (minimo == M) {
         haySolucion = false;
         cout << "\nNo existe una soluci�n Greedy para la matriz de adyacencia\n";
         camino.clear();
         coste_acumulado = 0;
      }
   }

    return camino;
}


int main() {
   // Mapeo de �ndices a letras
	unordered_map<int, char> indice_a_letra = {
        {0, 'A'}, {1, 'B'}, {2, 'C'}, {3, 'D'}, {4, 'E'}, {5, 'F'}
    };

   // Instancia más grande
   // vector<vector<double>> valores = {
   //    {M, 4, M, 3, M, M, M, M, 1, M, M, M, M},
   //    {4, M, 3, M, M, M, M, 4, M, M, M, M, M},
   //    {M, 3, M, M, M, M, M, 2, M, 8, M, M, M},
   //    {3, M, M, M, M, M, M, M, 3, M, M, M, 1},
   //    {M, M, M, M, M, 1, M, M, 2, M, 4, M, M},
   //    {M, M, M, M, 1, M, 3, M, M, 1, M, M, M},
   //    {M, M, M, M, M, 3, M, 2, M, 9, M, M, M},
   //    {M, 4, 2, M, M, M, 2, M, M, M, M, 1, 3},
   //    {1, M, M, 3, 2, M, M, M, M, M, M, M, M},
   //    {M, M, 8, M, M, 1, 9, M, M, M, M, M, M},
   //    {M, M, M, M, 4, M, M, M, M, M, M, M, 2},
   //    {M, M, M, M, M, M, M, 1, M, M, M, M, 1},
   //    {M, M, M, 1, M, M, M, 3, M, M, 2, 1, M}
   // };
	
	// //Del nodo A al M
   //  int source = 0;
   //  int destino = 12;

   vector<vector<double>> valores = {
      {M, 2, 1, M, M, 8},
      {2, M, 3, M, 1, 4},
      {1, 3, M, 2, M, 3},
      {M, M, 2, M, 3, 2},
      {M, 1, M, 3, M, 1},
      {8, 4, 3, 2, 1, M},  
    };
	
	//Del nodo A al F
    int source = 0;
    int destino = 5;
    double coste_acumulado = 0;

    vector<int> camino = Greedy(valores, source, destino, coste_acumulado);

    // Mostrar el camino y el coste acumulado con letras
    cout << "Camino: ";
    for (int i = 0; i < camino.size(); i++) {
        cout << indice_a_letra[camino[i]];

        if(i < camino.size()-1){
         cout << " -> ";
        }
    }
    cout << endl;

    cout << "Coste acumulado: " << coste_acumulado << endl;

    return 0;
}

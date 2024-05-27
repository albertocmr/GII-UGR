#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 4;
const int M = 5;

vector<vector<int>> calcularMatriz(vector<vector<int>>& costes) {

    //Crear una matriz N x M rellena de valores infinitos
    vector<vector<int>> matrizCosteAcumulado(N, vector<int>(M, INT_MAX));
    
    // La primera fila no tiene coste acumulado
    for (int j = 0; j < M; j++) {
        matrizCosteAcumulado[0][j] = costes[0][j];
    }
    

    //Recorremos la matriz de arriba a abajo. Para cada uno de los nodos restantes de la matriz
    //calculamos el coste que supondría desplazarnos en las tres direcciones posibles y cogemos el menor
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //Si estamos a la izquierda del todo(j=0), el coste de desplazarnos a la izquierda será infinito
            //Sino, obtenemos el coste del nodo anterior a este de la fila anterior(diagonal izquierda) 
            int izquierda = (j > 0) ? matrizCosteAcumulado[i-1][j-1] : INT_MAX;

            //Obtenemos el coste del nodo de la fila anterior(arriba)
            int arriba = matrizCosteAcumulado[i-1][j];

            //Si estamos a la derecha del todo(j=M-1), el coste de desplazarnos a la derecha será infinito
            //Sino, obtenemos el coste del nodo siguiente a este de la fila anterior(diagonal derecha) 
            int derecha = (j < M - 1) ? matrizCosteAcumulado[i-1][j+1] : INT_MAX;

            //Se suma al coste de este nodo el coste del movimiento menos costoso
            matrizCosteAcumulado[i][j] = costes[i][j] + min({izquierda, arriba, derecha});
        }
    }
    
    return matrizCosteAcumulado;
}

//Función de recuperación
vector<int> recuperarCamino(const vector<vector<int>>& matrizCosteAcumulado, int costeMinimo, int posMinimo) {

    vector<int> camino(N);
    int j = posMinimo;

    //Recorremos la matriz desde abajo hacia arriba partiendo del nodo que ya sabemos que tiene el coste acumulado minimo
    for (int i = N - 1; i >= 0; i--) {
        camino[i] = j;

        //Para las filas superiores a la de abajo del todo
        if (i > 0) {
            int izquierda = (j > 0) ? matrizCosteAcumulado[i-1][j-1] : INT_MAX;
            int arriba = matrizCosteAcumulado[i-1][j];
            int derecha = (j < M - 1) ? matrizCosteAcumulado[i-1][j+1] : INT_MAX;
            
            //Si el de la izquierda es el menor retrocedemos la j para la siguiente fila
            if (izquierda <= arriba && izquierda <= derecha) {
                j = j - 1;

            //Si el de la derecha es el menor avanzamos la j para la siguiente fila
            } else if (derecha <= izquierda && derecha <= arriba) {
                j = j + 1;
            }else{
                //Si el de encima es el menor j seguirá siendo la misma
            }
        }
    }
    
    return camino;
}

int main() {
    vector<vector<int>> costes = {
        {2, 8, 9, 5, 8},
        {4, 4, 6, 2, 3},
        {5, 7, 5, 6, 1},
        {3, 2, 5, 4, 8}
    };
    
    //Crear una matriz que contenga el coste mínimo para llegar a cada punto
    vector<vector<int>> matrizCosteAcumulado = calcularMatriz(costes);
    
    
    cout << "Matriz de costes para alcanzar cada nodo:" << endl;
    for (int i = 0; i < costes.size(); ++i) {
        for (int j = 0; j < costes[i].size(); ++j) {
            cout << setw(4) << costes[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    
    /*
    cout << "Matriz de costes acumulados:" << endl;
    for (int i = 0; i < matrizCosteAcumulado.size(); ++i) {
        for (int j = 0; j < matrizCosteAcumulado[i].size(); ++j) {
            cout << setw(4) << matrizCosteAcumulado[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    
    int costeMinimo = INT_MAX;
    int indiceMinimo = -1;

    //Buscamos en la última fila el menor coste acumulado de todos
    for (int j = 0; j < M; j++) {
        if (matrizCosteAcumulado[N-1][j] < costeMinimo) {
            costeMinimo = matrizCosteAcumulado[N-1][j];
            indiceMinimo = j;
        }
    }
    

    // Aplicamos la función de recuperación
    vector<int> camino = recuperarCamino(matrizCosteAcumulado, costeMinimo, indiceMinimo);
    
    // Mostrar los resultados
    cout << "El coste mínimo es: " << costeMinimo << endl;
    cout << "Camino mínimo: ";
     for (int i = camino.size() - 1; i >= 0; --i) {
        cout << camino[i] << " ";
    }
    cout << endl;
    
    return 0;
}
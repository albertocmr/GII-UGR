#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 10; // Tamaño del laberinto

// Función para comprobar si una celda es válida
bool CasillaValida(vector<vector<int>> &laberinto, vector<vector<bool>> &visitado, int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N) &&
            laberinto[x][y] == 1 && !visitado[x][y];
}

// Función solución usando Backtracking
void SolBackTracking(vector<vector<int>> &laberinto, vector<vector<bool>> &visitado, vector<vector<int>> &solucion, int x, int y, int &min_dist, int dist)
{
    //Si se llega a la salida, actualizar la distancia mínima
    if (x == N - 1 && y == N - 1){
    	solucion[x][y] = 1; // Marcamos la salida
        if (dist < min_dist) {
            min_dist = dist;
            // Actualizar la solucion
            for (int x = 0; x < N; ++x) {
                for (int y = 0; y < N; ++y) {
                    solucion[x][y] = visitado[x][y] ? 1 : 0;
                }
            }
        }
    }

    visitado[x][y] = true;

    // Nos movemos en las 4 direcciones posibles
    if (CasillaValida(laberinto, visitado, x + 1, y)) {
        SolBackTracking(laberinto, visitado, solucion, x + 1, y, min_dist, dist + 1);
    }

    if (CasillaValida(laberinto, visitado, x, y + 1)) {
        SolBackTracking(laberinto, visitado, solucion, x, y + 1, min_dist, dist + 1);
    }

    if (CasillaValida(laberinto, visitado, x - 1, y)) {
        SolBackTracking(laberinto, visitado, solucion, x - 1, y, min_dist, dist + 1);
    }

    if (CasillaValida(laberinto, visitado, x, y - 1)) {
        SolBackTracking(laberinto, visitado, solucion, x, y - 1, min_dist, dist + 1);
    }

    // Retroceder
    visitado[x][y] = false;
}

int main()
{
    vector<vector<int>> laberinto = {
                                     {1, 0, 0, 0, 0},
                                     {1, 0, 1, 1, 1},
                                     {1, 1, 1, 0, 1},
                                     {1, 0, 0, 0, 1},
                                     {1, 1, 1, 1, 1}
                                    };

    vector<vector<bool>> visitado;
    visitado.resize(N, vector<bool>(N));

    vector<vector<int>> solucion(N, vector<int>(N, 0)); // Matriz auxiliar para almacenar el solucion

    int min_dist = INT_MAX;
    SolBackTracking(laberinto, visitado, solucion, 0, 0, min_dist, 0);

    if (min_dist != INT_MAX){
        cout << "Solucion encontrada con longitud " << min_dist << "\n";
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                cout << solucion[x][y] << " ";
            }
            cout << "\n";
        }
    }
    else {
        cout << "No hay camino posible.\n";
    }

    return 0;
}


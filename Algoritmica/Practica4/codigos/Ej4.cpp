#include <iostream>
#include <vector>

using namespace std;

const int N = 5; // Tamaño del laberinto

// Función para comprobar si una celda es válida
bool CasillaValida(vector<vector<int>>& laberinto, int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && laberinto[x][y] == 1);
}

// Función solución usando Backtracking
bool SolBacktracking(vector<vector<int>>& laberinto, int x, int y, vector<vector<int>>& sol) {

    
    // CASO BASE: Si llegamos a la salida
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1; // Marcamos la salida
        return true;
    }

    // Comprobamos que la celda actual es válida
    if (CasillaValida(laberinto, x, y)) {
        sol[x][y] = 1; // Dicha celda forma parte de la solución

        laberinto[x][y] = 3; // Marcamos la celda como visitada

        // Nos movemos en las 4 direcciones posibles
        if (SolBacktracking(laberinto, x + 1, y, sol) || SolBacktracking(laberinto, x, y + 1, sol) || SolBacktracking(laberinto, x - 1, y, sol) || SolBacktracking(laberinto, x, y - 1, sol))
            return true;
    
        sol[x][y] = 0; // Volvemos atrás si ninguna dirección es válida
        
    }

    return false;
}

int main() {
    vector<vector<int>> laberinto = {{1, 0, 0, 0, 0},
                                    {1, 0, 0, 1, 0},
                                    {0, 1, 1, 1, 0},
                                    {0, 0, 0, 1, 0},
                                    {0, 0, 0, 1, 1} };

    vector<vector<int>> solucion(N, vector<int>(N, 0)); // Inicializamos la matriz solución

    if (SolBacktracking(laberinto, 0, 0, solucion)) {
        cout << "Solucion encontrada:\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << solucion[i][j] << " ";
            cout << "\n";
        }
    }
    else {
        cout << "No hay camino posible.\n";
    }

    return 0;
}


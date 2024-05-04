#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calcularConvenienciaTotal(const vector<int>& asignacion, const vector<vector<int>>& conveniencia) {
    int total = 0;
    int n = asignacion.size();
    for (int i = 0; i < n; ++i) {
        int izquierda = asignacion[(i - 1 + n) % n];
        int derecha = asignacion[(i + 1) % n];
        total += conveniencia[asignacion[i]][izquierda];
        total += conveniencia[asignacion[i]][derecha];
    }
    return total;
}

void backtracking(vector<int>& asignacion_actual, vector<vector<int>>& conveniencia, 
                vector<bool>& usado, int n, int& mejor_conveniencia, vector<int>& mejor_asignacion) {
                    
    if (asignacion_actual.size() == n) {
        int conveniencia_actual = calcularConvenienciaTotal(asignacion_actual, conveniencia);
        if (conveniencia_actual > mejor_conveniencia) {
            mejor_conveniencia = conveniencia_actual;
            mejor_asignacion = asignacion_actual;
        }
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (!usado[i]) {
            usado[i] = true;
            asignacion_actual.push_back(i);
            
            backtracking(asignacion_actual, conveniencia, usado, n, mejor_conveniencia, mejor_asignacion);

            asignacion_actual.pop_back();
            usado[i] = false;
        }
    }
}

int main() {
    int n = 4; // Cambia este valor al número de invitados
    vector<vector<int>> conveniencia(n, vector<int>(n));
    
    // Ejemplo de conveniencia entre invitados (puedes cambiar estos valores según tus necesidades)
    /*
    conveniencia[0][0] = 0; conveniencia[0][1] = 1; conveniencia[0][2] = 2; conveniencia[0][3] = 3;
    conveniencia[1][0] = 3; conveniencia[1][1] = 0; conveniencia[1][2] = 1; conveniencia[1][3] = 5;
    conveniencia[2][0] = 24; conveniencia[2][1] = 7; conveniencia[2][2] = 0; conveniencia[2][3] = 2;
    conveniencia[3][0] = 1; conveniencia[3][1] = 52; conveniencia[3][2] = 8; conveniencia[3][3] = 0;
    */
    conveniencia[0][0] = 0; conveniencia[0][1] = 5; conveniencia[0][2] = 4; conveniencia[0][3] = 6;
    conveniencia[1][0] = 2; conveniencia[1][1] = 0; conveniencia[1][2] = 7; conveniencia[1][3] = 9;
    conveniencia[2][0] = 6; conveniencia[2][1] = 2; conveniencia[2][2] = 0; conveniencia[2][3] = 3;
    conveniencia[3][0] = 6; conveniencia[3][1] = 1; conveniencia[3][2] = 9; conveniencia[3][3] = 0;
    

    vector<int> asignacion_actual;
    vector<bool> usado(n, false);
    int mejor_conveniencia = INT_MIN;
    vector<int> mejor_asignacion;

    asignacion_actual.push_back(0);
    usado[0] = true;

    backtracking(asignacion_actual, conveniencia, usado, n, mejor_conveniencia, mejor_asignacion);

    cout << "Nivel de conveniencia total máximo: " << endl << "\t" << mejor_conveniencia << endl;
    cout << "Orden de los comensales:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << (i == 0 ? "\t{" : "") << mejor_asignacion[i] << (i == n - 1 ? "" : ", ");    
    }
    cout << "}" << endl;

    return 0;
}

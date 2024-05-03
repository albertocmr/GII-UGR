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

void backtracking(vector<int>& asignacion_actual, vector<vector<int>>& conveniencia, vector<bool>& usado, int n, int& mejor_conveniencia, vector<int>& mejor_asignacion) {
    if (asignacion_actual.size() == n) {
        int conveniencia_actual = calcularConvenienciaTotal(asignacion_actual, conveniencia);
        if (conveniencia_actual > mejor_conveniencia) {
            mejor_conveniencia = conveniencia_actual;
            mejor_asignacion = asignacion_actual;
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
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
    conveniencia[0][0] = 0; conveniencia[0][1] = 80; conveniencia[0][2] = 90; conveniencia[0][3] = 70;
    conveniencia[1][0] = 70; conveniencia[1][1] = 0; conveniencia[1][2] = 85; conveniencia[1][3] = 75;
    conveniencia[2][0] = 90; conveniencia[2][1] = 85; conveniencia[2][2] = 0; conveniencia[2][3] = 95;
    conveniencia[3][0] = 80; conveniencia[3][1] = 75; conveniencia[3][2] = 95; conveniencia[3][3] = 0;
    
    vector<int> asignacion_actual;
    vector<bool> usado(n, false);
    int mejor_conveniencia = INT_MIN;
    vector<int> mejor_asignacion;

    backtracking(asignacion_actual, conveniencia, usado, n, mejor_conveniencia, mejor_asignacion);

    cout << "Nivel de conveniencia total máximo: " << mejor_conveniencia << endl;
    cout << "Orden de los comensales:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Comensal " << i+1 << " se sienta en el lugar " << mejor_asignacion[i]+1 << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void completarTabla(vector<vector<int>>& t, int eqInf, int eqSup, int diaInf, int diaSup, int eqInicial) {
    for (int j = diaInf; j <= diaSup; j++) {
        t[eqInf-1][j-1] = eqInicial + j - diaInf;
    }
    for (int i = eqInf + 1; i <= eqSup; i++) {
        // Intercambio de contrincante
        t[i-1][diaInf-1] = t[i - 2][diaSup-1];
        for (int j = diaInf + 1; j <= diaSup; j++) {
            // Rotación de los contrincantes
            t[i-1][j-1] = t[i - 2][j - 2];
        }
    }
}

void formarTabla(vector<vector<int>>& t, int primero, int ultimo) {
    int medio;
    if (ultimo - primero == 1) {
        // Caso base: compiten entre ambos (el mismo día)
        t[primero-1][0] = ultimo;
        t[ultimo-1][0] = primero;
    } else {
        medio = (primero + ultimo) / 2;
        // Primera subsolución: participantes de 1 a 2k-1
        formarTabla(t, primero, medio);
        // Segunda subsolución: participantes de 2k-1+1 a 2k
        formarTabla(t, medio + 1, ultimo);
        // Completa la tabla de los participantes de la primera subsolución con los de la segunda
        completarTabla(t, primero, medio, medio - primero + 1, ultimo - primero, medio + 1);
        // Completa la tabla de los participantes de la segunda subsolución con los de la primera
        completarTabla(t, medio + 1, ultimo, medio - primero + 1, ultimo - primero, primero);
    }
}



int main(int argc , char **argv) {
    // Ejemplo de uso

    int n = atoi(argv[1]); // Tamaño de la tabla
    vector<vector<int>> tabla(n, vector<int>(n - 1, 0)); // Inicialización de la tabla con 0s

    auto start = chrono::steady_clock::now();
    formarTabla(tabla, 1, n);
    auto end = chrono::steady_clock::now();
    
    for(int i=0; i< n; i++){
        for(int j=0; j<n-1; j++){
            cout << tabla[i][j] << " ";
        }
        cout << endl;
    }

    unsigned long tejecucion = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    cout << endl;
    cout << "Algoritmo 4 divide y venceras." << endl << "Tamaño: " << n << ";" 
        << endl << "Tiempo de ejecucion: " << tejecucion << " ms" << endl;
    

    return 0;
}
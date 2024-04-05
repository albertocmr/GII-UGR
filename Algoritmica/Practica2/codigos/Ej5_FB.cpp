#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void basico(vector<vector<int>>& t){
    vector<vector<bool>> enfrentados(t.size(), vector<bool>(t.size(), false));
    
    for (int i = 0; i < t.size(); i++){
        for (int j = 0 ;j < enfrentados.size(); j++)
            if (i == j)
                enfrentados[i][j] = true;
    }
    

    for (int jornada = 1; jornada <= t.size()-1; jornada++){
        vector<bool> enfrentados_jornadas(t.size(), false);
        for (int equipo = 1; equipo <= t.size(); equipo++){
            for (int rival = 1; rival <= t.size(); rival++){
                if(!enfrentados[equipo-1][rival-1]){
                    if(!enfrentados_jornadas[equipo-1] && !enfrentados_jornadas[rival-1]){
                        t[equipo-1][jornada-1] = rival;
                        t[rival-1][jornada-1] = equipo;
                        enfrentados_jornadas[equipo-1] = true;
                        enfrentados_jornadas[rival-1] = true;
                        enfrentados[equipo-1][rival-1] = true;
                        enfrentados[rival-1][equipo-1] = true;
                    }
                }
            }
        }
        
    }
}

int main(int argc , char **argv){

    int n = atoi(argv[1]);
    vector<vector<int>> t(n, vector<int>(n));
    auto start = chrono::steady_clock::now();
    basico(t);
    auto end = chrono::steady_clock::now();

    for(int i=0; i< n; i++){
        for(int j=0; j<n-1; j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    unsigned long tejecucion = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    cout << endl;
    cout << "Algoritmo 4 fuerza bruta." << endl << "Tamaño: " << n << ";" << endl << "Tiempo de ejecucion: " << tejecucion << " ms" << endl;
}
#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

bool mayoriaFB(vector<int>& v, map<int,int>& conteo) {
    int n = v.size();
    bool hayMayoria = false;

    // Recorrer el vector v y contar ocurrencias
    for (int i = 0; i < n; i++) {
        // Si la componente no se ha contado antes, contar ocurrencias y actualizar conteo
        if (conteo.find(v[i]) == conteo.end()) {
            int votos = 1;
            for (int j = i + 1; j < n; j++) {
                if (v[i] == v[j]) {
                    votos++;
                }
            }
            // Actualizar el conteo para el candidato correspondiente
            conteo[v[i]] = votos;
        }
    }

    // Comprobar si hay mayoría
    for (auto k = conteo.begin(); k != conteo.end() && !hayMayoria; ++k) {
        if (k->second > n / 2) {
            hayMayoria = true;
        }
    }

    return hayMayoria;
}


int main(int argc, char *argv[]) {
    vector<int> v;
    int n, m, eleccion, argumento;
    bool mayoria;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
    unsigned long int semilla;
    
    if (argc <= 2) {
        cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
        cerr<<argv[0]<<" nº de candidatos tamCaso1 tamCaso2 ... tamCasoN\n\n";
        return 0;
    }
    
    // Inicializamos generador de no. aleatorios
    srand(time(0));
    
    // Obtener número de candidatos
    m= atoi(argv[1]);
    map<int,int> conteo;
    int max = m;
    int min = 0;
    // Pasamos por cada tamaño de caso
    for (argumento= 2; argumento<argc; argumento++) {
        
        // Cogemos el tamaño del caso
        n= atoi(argv[argumento]);
        
        //Crear vector de m componentes con vectores aleatorios
    	for (int i = 0; i < n; i++) {
            v.push_back(rand() % max);
        }

        //cerr << "\nEjecutando algoritmo para tam. caso: " << n << endl;
        
        t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecución del algoritmo
        mayoria=mayoriaFB(v,conteo); // Ejecutamos el algoritmo para tamaño de caso n
        tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecución del algoritmo
        
        unsigned long tejecucion= std::chrono::duration_cast<std::chrono::nanoseconds>(tf - t0).count();
        
        //cerr << "Tiempo de ejec. (ns): " << tejecucion << " para tam. caso "<< n<<endl;
        
        //Mostrar conteo cuando hay pocos candidatos
        
        if(m <= 10){
            cerr << "Conteo de votos para cada candidato" << endl;
        
            for (auto it = conteo.begin(); it != conteo.end(); ++it) {
                cerr << "Candidato " << it->first << ": " << it->second << " votos" << endl;
            }
        }

        //Indicar si hay o no mayoría absoluta
        if(mayoria)
        	cerr << "Hay mayoria" << endl;
        else
        	cerr <<"No hay mayoria" << endl;


       //Modo de medición de tiempos
        //cout<<n<<","<<tejecucion<<"\n";
        //cout<<tejecucion<<endl;
        cout << endl;
        cout << "Algoritmo 1 fuerza bruta." << endl << "Tamaño: " 
            << n << ";" << endl << "Tiempo de ejecucion: " << tejecucion 
            << " ns" << endl;
        
        // Limpiamos el vector v y conteo para el próximo caso
        v.clear();
        conteo.clear();
    }
    
    return 0;
}

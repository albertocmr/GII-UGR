#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void conteoRecursivo(int inicio, int fin, vector<int>& v, vector<int>& conteo) {
    if (inicio == fin) {
        conteo[v[inicio]]++;
    } else {
        int mitad = (inicio + fin) / 2;
        conteoRecursivo(inicio, mitad, v, conteo);
        conteoRecursivo( mitad +1, fin, v, conteo);
    }
}

bool mayoriaDyV( vector<int>& v,  vector<int>& conteo) {
    bool hayMayoria = false;
    int n = v.size();
    //Calcular el conteo dentro del vector conteo
    conteoRecursivo(0, n - 1, v, conteo);
    
    // Recorrer conteo para ver si hay algún número > n/2
    for (int i = 0; i < conteo.size() && !hayMayoria; i++)
        hayMayoria = conteo[i] > n / 2 ;
    
    return hayMayoria;
}


int main(int argc, char *argv[]) {
    vector<int> v;
    int n, m, eleccion, argumento;
    bool mayoria;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
    unsigned long int semilla;
    ofstream fsalida;
    
    if (argc <= 2) {
        cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
        cerr<<argv[0]<<" NombreFicheroSalida Semilla tamCaso1 tamCaso2 ... tamCasoN\n\n";
        return 0;
    }
    
    srand(time(0));
    
    // Obtener número de candidatos
    m= atoi(argv[1]);
    vector<int> candidatos(m);
    vector<int> conteo(m);
    int max = m;
    int min = 0;
    // Pasamos por cada tamaño de caso
    for (argumento= 2; argumento<argc; argumento++) {
        
        // Cogemos el tamaño del caso
        n= atoi(argv[argumento]);
        //m= (rand() % n/4) +1;
        
        //Crear vector de m componentes con vectores aleatorios
    	for (int i = 0; i < n; i++) {
            v.push_back(rand() % max);
        }
        
        // Inicializamos conteo a 0
        for (int i = 0; i < m; i++) {
            conteo[i] = 0;
        }
        
        //cerr << "\nEjecutando algoritmo para tam. caso: " << n << endl;
        
        t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecución del algoritmo
        mayoria=mayoriaDyV(v, conteo); // Ejecutamos el algoritmo para tamaño de caso n
        tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecución del algoritmo
        
        unsigned long tejecucion= std::chrono::duration_cast<std::chrono::nanoseconds>(tf - t0).count();
        
        //cerr << "Tiempo de ejec. (ns): " << tejecucion << " para tam. caso "<< n<<endl;
        
        // Mostrar conteo cuando hay pocos candidatos
        
        if(m <= 10){
            cerr << "Conteo de votos para cada candidato" << endl;
        
        for (int i=0;i<m;i++)
            cerr  << "Candidato " << i << ": " << conteo[i] << " votos" << endl;
        }
        
        //Indicar si hay o no mayoría absoluta
        if(mayoria)
        	cerr << "Hay mayoria" << endl;
        else
        	cerr <<"No hay mayoria" << endl;
        

        //cout<<n<<","<<tejecucion<<"\n";
        //cout<<tejecucion<<endl;

        cout << endl;
        cout << "Algoritmo 1 divide y venceras." << endl << "Tamaño: " 
            << n << ";" << endl << "Tiempo de ejecucion: " << tejecucion 
            << " ns" << endl;

        // Limpiamos el vector v para el próximo caso
        v.clear();
        conteo.clear();
    }
    
    // Cerramos fichero de salida
    fsalida.close();
    
    return 0;
}

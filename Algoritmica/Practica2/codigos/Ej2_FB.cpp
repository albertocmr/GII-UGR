#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>



using namespace std;

void ordena(vector<int> &v1, vector<int> &v2){
    
    for (int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v2.size() ; j++)
            if ( (v1[i] == v2[j]))
                swap(v2[i], v2[j]);
    }
}



int main(int argc, char **argv) {
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecucións
    
    srand(time(0));
    const int tamano = atoi(argv[1]); 
    vector<int> vector1(tamano);
    vector<int> vector2(tamano);

    int index = 0;
    for (int i = 0; i < tamano; i++)
        vector1[i] = i;
        

    vector2 = vector1;
    random_shuffle(vector2.begin(), vector2.end());
    random_shuffle(vector1.begin(), vector1.end());
    
    t0= std::chrono::high_resolution_clock::now();

    
    ordena(vector1, vector2);
    
    
    tf= std::chrono::high_resolution_clock::now();

    unsigned long tejecucion= std::chrono::duration_cast<std::chrono::nanoseconds>(tf - t0).count();

    for (int num : vector1)
        cout << num << " ";
    cout << endl;


    for (int num : vector2)
        cout << num << " ";
    cout << endl << endl;

    cout << "Algoritmo 2 fuerza bruta." << endl << "Tamaño: " << tamano << ";" << endl << "Tiempo de ejecucion: " << tejecucion << " ns" << endl;
    

    

    return 0;
}







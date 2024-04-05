#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void MuestraVector(vector<int> v){
    cout << "[ ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}


void BorraElementosRepetidos(vector<int> &v) {
    
    // Si el vector tiene un tamaño menor o igual a 1, no hay elementos repetidos   
    if (v.size() <= 1) {
        return;
    }

    vector<int>::iterator it_1;
    vector<int>::iterator it_2;

    for(it_1 = v.begin(); it_1 != v.end(); ++it_1){
        it_2 = it_1; ++it_2;
        for(; it_2 != v.end();){
            if ((*it_1) == (*it_2)){
                it_2 = v.erase(it_2);
            } else{
                ++it_2;
            }
        }
    }
}


int main(int argc, char *argv[]){
    
	chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución

    int tam_vector = atoi(argv[1]);
    int min = 0, max = tam_vector - 1;

    cout << "Número de elementos del vector: " << endl;

    vector<int> vector(tam_vector);

    for (int i = 0; i < tam_vector; i++) {
        vector[i] = rand() % (max - min + 1) + min;
    }

    if(tam_vector < 100){
        cout << "Vector antes de ordenar: " << endl;
        MuestraVector(vector);
    }

	t0 = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecución del algoritmo

    // Llamamos a la función que borra los elementos repetidos.
    BorraElementosRepetidos(vector);

	tf = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecución del algoritmo

    if(tam_vector < 100){
        cout << "Vector después de ordenar: ";
        MuestraVector(vector);
        cout << endl;
    }

    unsigned long tejecucion = std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
    cout << endl;
    cout << "Algoritmo 4 fuerza bruta." << endl << "Tamaño: " << tam_vector 
        << ";" << endl << "Tiempo de ejecucion: " << tejecucion << " ms" << endl;
    
}


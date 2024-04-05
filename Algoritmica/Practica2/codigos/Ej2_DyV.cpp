#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>



using namespace std;

int partition(vector<int> &v1, vector<int> &v2, int low, int high, int posPivot) {
    int pivot = v2[posPivot];
    int i = (low - 1);
    int posicion;

    cout << "Mostramos v1: ";
    for (int num : v1)
        cout << num << " ";
    cout << endl;
    cout << "Mostramos v2: ";
    for (int num : v2)
        cout << num << " ";
    cout << endl;
    cout << endl;

    for (int j = low; j <= high - 1; j++) {

        if (v1[j] < pivot) {
            i++;
            swap(v1[i], v1[j]);
        }
    }

    for (int j = low; j <= high - 1; j++) {
        if(pivot == v1[j])
            posicion = j;
    }
    swap(v1[i + 1], v1[posicion]);
    return (i + 1);
}

void quickSort(vector<int> &v1, vector<int> &v2, int low, int high) {
    if (low < high) {
        
        int pi = partition(v1, v2, low, high, (high+low)/2);


        partition(v2, v1, low, high, pi);
        quickSort(v1, v2, low, pi );
        quickSort(v1, v2, pi + 1, high);
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

    quickSort(vector1,vector2, 0, tamano);

    tf= std::chrono::high_resolution_clock::now();
    unsigned long tejecucion= std::chrono::duration_cast<std::chrono::nanoseconds>(tf - t0).count();
    
    

    for (int num : vector1)
        cout << num << " ";
    cout << endl;


    for (int num : vector2)
        cout << num << " ";
    cout << endl << endl;


    cout << "Algoritmo 2 Divide y Venceras." << endl << "Tamaño: " << tamano << "." << endl << "Tiempo de ejecucion: " << tejecucion << " ns" <<  endl;

    return 0;
}







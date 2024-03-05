#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <cstring> // Para usar memcpy
#include <iostream>
#include <fstream> // Para usar ficheros
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char *argv[]) {

    int *v;
    int n, i, argumento;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
    double tejecucion; // tiempo de ejecucion del algoritmo en ms
    unsigned long int semilla;
    ofstream fsalida;

    if (argc <= 3) {
        cerr << "\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
        cerr << argv[0] << " NombreFicheroSalida Semilla tamCaso1 tamCaso2 ... tamCasoN\n\n";
        return 0;
    }

    // Abrimos fichero de salida
    fsalida.open(argv[1]);
    if (!fsalida.is_open()) {
        cerr << "Error: No se pudo abrir fichero para escritura " << argv[1] << "\n\n";
        return 0;
    }

    // Inicializamos generador de no. aleatorios
    semilla = atoi(argv[2]);
    srand(semilla);

    // Pasamos por cada tamaÒo de caso
    for (argumento = 3; argumento < argc; argumento++) {

        // Cogemos el tamanio del caso
        n = atoi(argv[argumento]);

        // Reservamos memoria para el vector
        v = new int[n];

        // Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
        for (i = 0; i < n; i++)
            v[i] = rand() % n;

        cerr << "Ejecutando QuickSort para tam. caso: " << n << endl;

        t0 = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecución del algoritmo
        quickSort(v, 0, n - 1); // Ejecutamos el algoritmo para tamaÒo de caso n
        tf = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecución del algoritmo

        unsigned long tejecucion = std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

        cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso " << n << endl;

        // Guardamos tam. de caso y t_ejecucion a fichero de salida
        fsalida << n << "," << tejecucion << "\n";

        // Liberamos memoria del vector
        delete[] v;
    }

    // Cerramos fichero de salida
    fsalida.close();

    return 0;
}

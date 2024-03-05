#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <cstring> // Para usar memcpy
#include <iostream>
#include <fstream> // Para usar ficheros
#include <vector>

using namespace std;

vector<int> countSort(vector<int>& inputArray)
{
 
    int N = inputArray.size();
 
    // Finding the maximum element of array inputArray[].
    int M = 0;
 
    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);
 
    // Initializing countArray[] with 0
    vector<int> countArray(M + 1, 0);
 
    // Mapping each element of inputArray[] as an index
    // of countArray[] array
 
    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;
 
    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
 
    // Creating outputArray[] from countArray[] array
    vector<int> outputArray(N);
 
    for (int i = N - 1; i >= 0; i--)
 
    {
        outputArray[countArray[inputArray[i]] - 1]
            = inputArray[i];
 
        countArray[inputArray[i]]--;
    }
 
    return outputArray;
}



int main(int argc, char *argv[]) {
	
	int *v;
    int *vaux;
	int n, i, argumento;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	double tejecucion; // tiempo de ejecucion del algoritmo en ms
	unsigned long int semilla;
	ofstream fsalida;
	
	if (argc <= 3) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<" NombreFicheroSalida Semilla tamCaso1 tamCaso2 ... tamCasoN\n\n";
		return 0;
	}
	
	// Abrimos fichero de salida
	fsalida.open(argv[1]);
	if (!fsalida.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
		return 0;
	}
	
	// Inicializamos generador de no. aleatorios
	semilla= atoi(argv[2]);
	srand(semilla);
	
	// Pasamos por cada tamaÒo de caso
	for (argumento= 3; argumento<argc; argumento++) {
		
		// Cogemos el tamanio del caso
		n= atoi(argv[argumento]);
		
		// Reservamos memoria para el vector
		vector<int> v(n, 0);
		
		// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
		for (i= 0; i<n; i++)
			v[i]= rand()%n;
		
		cerr << "Ejecutando Counting Sort para tam. caso: " << n << endl;
		
		t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
		countSort(v); // Ejecutamos el algoritmo para tamaño de caso n
		tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
		
		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
		
		cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;
		
		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<n<<" "<<tejecucion<<"\n";
	}
	
	// Cerramos fichero de salida
	fsalida.close();
	
	return 0;
}

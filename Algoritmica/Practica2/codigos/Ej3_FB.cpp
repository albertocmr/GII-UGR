#include <iostream>
#include <chrono>
using namespace std;

int main(int argc, char * argv[]){
    int valor = atoi(argv[1]);

	int sol;
    bool encontrado = false;
    
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución

    t0= std::chrono::high_resolution_clock::now();
    for(int i = 1; i*(i+1)*(i+2) <= valor; i++){
        long long int prod = i*(i+1)*(i+2);
        
        // Caso en el que el producto de los tres números sea igual al valor introducido
        if(valor == prod){
            sol = i;
            encontrado = true;
            break;

        }
        else if(prod > valor){
            cout << "El valor " << valor << " no es el producto de tres números consecutivos." << endl;
            break;
        }
    }
    tf= std::chrono::high_resolution_clock::now();

    unsigned long tejecucion= std::chrono::duration_cast<std::chrono::nanoseconds>(tf - t0).count();
    //if(encontrado)
        cout << "El valor " << valor << " es el producto de los tres números consecutivos: " << sol << ", " << sol+1 << " y " << sol+2 << endl;
    
    //cout << tejecucion << endl;
    cout << endl;
    cout << "Algoritmo 3 fuerza bruta." << endl << "Tamaño: " << valor << ";" << endl << "Tiempo de ejecucion: " << tejecucion << " ns" << endl;
    
}
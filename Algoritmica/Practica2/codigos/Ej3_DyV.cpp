#include <iostream>
#include <chrono>

using namespace std;

int DyV(int valor, int Cini, int Cfin){
    int encontrado = -1;
    bool fin = false;
    long long int multi, mitad;

    while(Cini <= Cfin && !fin ){
        mitad = (Cini + Cfin) / 2;
        multi = mitad*(mitad+1)*(mitad+2);
        fin = multi == valor;

        if (!fin)
            if (multi > valor)
                Cfin = mitad - 1;
            
            else
                Cini = mitad + 1;
        else
            encontrado = mitad;
        
    }
     
    return encontrado;
}

int DyV2(int valor, int Cini, int Cfin){
    long long int mitad = (Cini + Cfin) / 2, encontrado = -1;
    bool final = false;

    if(mitad*(mitad+1)*(mitad+2) == valor && !final){
        encontrado = mitad;
    } 
    else if(mitad*(mitad+1)*(mitad+2) > valor && !final){
        if(Cfin - Cini < 2)
            final = true;
        if(!final){
            encontrado = DyV(valor, Cini, mitad);
        }
    }
    else if(!final){
        if(Cfin - Cini < 2)
            final = true;
        if(!final){
            encontrado = DyV(valor, mitad, Cfin);
        }
    }

    return encontrado;
}

int main(int argc, char * argv[]){
    int valor = atoi(argv[1]);
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
        
    t0= std::chrono::high_resolution_clock::now();
    int sol = DyV(valor, 1, valor);
    tf= std::chrono::high_resolution_clock::now();

    if(sol != -1)
        cout << "El valor " << valor << " es el producto de los tres números consecutivos: " << sol << ", " << sol+1 << " y " << sol+2 << endl;
    else
        cout << "El valor " << valor << " no es el producto de tres números consecutivos." << endl;

    unsigned long tejecucion= std::chrono::duration_cast<std::chrono::nanoseconds>(tf - t0).count();
    //cout << "Tiempo de ejecución (ns): " << tejecucion << " para el valor " << valor << endl;
    //cout << tejecucion << endl;
    
    cout << endl;
    cout << "Algoritmo 3 divide y venceras." << endl << "Tamaño: " << valor << ";" << endl << "Tiempo de ejecucion: " << tejecucion << " ns" << endl;
    
}

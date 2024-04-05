#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <chrono>


using namespace std;


// Muestra el vector pasado por parámetro
void MuestraVector(vector<int> v){
    cout << "[ ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "]" << endl;;
}

// Método que une dos vectores ordenados en un único vector ordenado
vector<int> joinVector(vector<int> &vIzq, vector<int> &vDer){
    int i = 0;
    int j = 0;
    bool fin = false;
    vector<int> Vfinal;


    while(!fin){

    	// Primer caso: El elemento analizado del vector izquierdo es menor que el del derecho
        if(vIzq[i] < vDer[j]){
        	Vfinal.push_back(vIzq[i]);

            if(i == (vIzq.size()-1)){
                fin = true;

                for(int k = j; k < vDer.size(); k++)
                    Vfinal.push_back(vDer[k]);   
            }
            else 
                i++;
        }

        //Segundo caso: El elemento analizado del vector derecho es menor que el del izquierdo
        else if(vIzq[i] > vDer[j]){
        	Vfinal.push_back(vDer[j]);

			if(j == (vDer.size()-1)){
                fin = true;

                for(int k = i; k < vIzq.size(); k++)
                    Vfinal.push_back(vIzq[k]);
            }
			else 
                j++;
        }

        //Tercer caso: Ambos elementos analizados son el mismo
        else {
        	Vfinal.push_back(vIzq[i]);

            if(i == (vIzq.size()-1)){
                fin = true;

                for(int k = j+1; k < vDer.size(); k++)
                    Vfinal.push_back(vDer[k]);
            }

            else if(j == (vDer.size()-1)){
                fin = true;

                for(int k = i+1; k < vIzq.size(); k++)
                    Vfinal.push_back(vIzq[k]);
            }
            else
                i++;j++;
        }
    }

    
    return Vfinal;

}

vector<int> DyV(vector<int> &V){
    int tam_vector = V.size();

    // Caso Base
    if(tam_vector==1)
        return V;

    // Caso general
    int mitad = tam_vector/2;

    vector<int> vIzquierda, vDerecha;
    
    vIzquierda.assign(V.begin(), V.end()-mitad);
    vDerecha.assign(V.end()-mitad, V.end());

    //De forma recursiva, utilizamos el mismo metodo dividide y vencerás para cada nuevo vector divido
    vIzquierda = DyV(vIzquierda);
    vDerecha = DyV(vDerecha);

    // Unimos los vectores obtenidos en la etapa anterior
    V = joinVector(vIzquierda, vDerecha);

   return V;

}




int main(int argc, char * argv[]){
    
    vector<int> Voriginal;
    long double tiempo_transcurrido;

    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
    

    srand(time(0));

    int tam_vector = atoi(argv[1]);
    //cout << "Número de elementos del vector: " << tam_vector << endl;
    

    int * miVector = new int[tam_vector];
    assert(miVector);

    int min = 0;
    int max = tam_vector-1;
    int contador=0;
    
    /*do{
        cin >> miVector[contador];
        contador++;
    } while(contador != tam_vector);
    */

    // Rellenamos el vector con valores aleatorios de ese rango
    for (int i = 0; i < tam_vector; i++) {
        miVector[i] = rand() % (max - min + 1) + min;
    }

    //Pasamos dicho vector al Vector original que vamos a analizar
    for (int j=0; j<tam_vector; j++) 
    {
        Voriginal.push_back(miVector[j]);
    }
    // Esta restriccion se debe a que se vea mas claro por pantalla,
    // si el vector es muy grande no se muestra
    if(tam_vector < 100){
        cout << "Vector antes de borrar: " << endl;
        MuestraVector(Voriginal);
    }
    
    t0 = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecución del algoritmo
    
    vector<int> ordenado = DyV(Voriginal);
    if(tam_vector < 100){
        cout << "Vector después de borrar: " << endl;
        MuestraVector(ordenado);
    }

    tf = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecución del algoritmo

    unsigned long tejecucion = std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
    
    cout << endl;
    cout << "Algoritmo 4 divide y venceras." << endl << "Tamaño: " << tam_vector 
        << ";" << endl << "Tiempo de ejecucion: " << tejecucion << " ms" << endl;
    

}
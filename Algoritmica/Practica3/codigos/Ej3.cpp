#include <iostream>
#include <vector>
#include <random>
#include <set>

using namespace std;

/*
struct Gasolinera{
    int pto_kilometrico;
    int id;
};
*/

pair<set<int>,bool> trazarRuta(int kms_restantes, set<int> gasolineras){

    set<int> paradas; // Creamos el vector de paradas a realizar
    bool haySolucion = true;
    
    // Guardamos los kilómetros que podemos recorrer sin repostar 
    int distancia_posible = kms_restantes;
    set<int>::iterator it = gasolineras.begin();
    

    // Reducimos el kilometraje restante (kms desde el inicio hasta la primera gasolinera)
    kms_restantes -= (*it);

    for(;it != prev(gasolineras.end())&& haySolucion; it++){
        //Si no podemos realizar el siguiente tramo sin parar a repostar
        if(*(next(it)) - (*it) > kms_restantes){

            // Repostamos y añadimos la gasolinera actual al vector de paradas
            paradas.insert(*it);

            // Reiniciamos el kilometraje
            kms_restantes = distancia_posible;

            if(kms_restantes < *(next(it)) - (*it)){
                haySolucion = false;
            }
        }

        // Restamos al kilometraje restante la cantidad de kilómetros recorridos
        kms_restantes -= *(next(it)) - (*it);
    }
    
    pair<set<int>,bool> resultado(paradas, haySolucion);
    return resultado; // Devolvemos las pradas realizadas
}

int main(int argc, char * argv[]){

    int km_ruta = atoi(argv[1]);            // Kilometraje de la ruta
    int num_gasolineras = atoi(argv[2]);    // Número de gasolineras de la ruta
    int kms_disponibles = atoi(argv[3]);    // Kilómetros que se pueden recorrer sin repostar

    if(argc != 4){
        cout << "Número de argumentos incorrecto\n";
        cout << "Uso: ./Ejercicio3 <km_ruta> <num_gasolineras> <kms_disponibles>\n";
        return -1;
    }
    
    // Genero un número aleatorio para la semilla
    int semilla1 = random_device{}();
    mt19937 semilla(semilla1);

    // Distribución uniforme para los puntos kilométricos (entre 0 y km_ruta)
    uniform_int_distribution<int> distribucion(0, km_ruta);
    
    // Se crean las gasolineras
    set<int> gasolineras;

    // Lo puntos kilométricos de las gasolineras se generan aleatoriamente
    // de manera ascendente en el kilometraje de la ruta    
    for(int i = 0; i < num_gasolineras; i++){
        gasolineras.insert(distribucion(semilla));
    }

    // Mostramos los puntos kilométricos de las gasolineras
    cout << "\nLa ruta de " << km_ruta << "km consta de las siguientes paradas: " << endl;
    for(auto i = gasolineras.begin(); i != gasolineras.end(); i++){
        cout << "Gasolinera en el punto kilométrico " << (*i) << endl;
    }

    pair<set<int>,bool> solucion = trazarRuta(kms_disponibles, gasolineras); 
    if(solucion.second == false){
        cout << "\nNo se puede realizar la ruta con los kilómetros disponibles\n";
    }
    else{
        set<int> paradas = solucion.first;
        cout << "\nLas paradas programadas son:\n";

        for(auto i = paradas.begin(); i != paradas.end(); i++){
            cout << "Parada en el punto kilométrico " << (*i) << endl;
        }
    }
}
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

set<int> trazarRuta(int kms_restantes, set<int> gasolineras){

    set<int> paradas; // Creamos el vector de paradas a realizar

    // Guardamos los kilómetros que podemos recorrer sin repostar 
    int distancia_posible = kms_restantes;
    set<int>::iterator it = gasolineras.begin();

    // Reducimos el kilometraje restante (kms desde el inicio hasta la primera gasolinera)
    kms_restantes -= (*it);

    for(;it != prev(gasolineras.end()); it++){
        //Si no podemos realizar el siguiente tramo sin parar a repostar
        if(*(next(it)) - (*it) > kms_restantes){

            cout << "Entro" << endl;
            // Repostamos y añadimos la gasolinera actual al vector de paradas
            paradas.insert(*it);

            // Reiniciamos el kilometraje
            kms_restantes = distancia_posible;
        }

        // Restamos al kilometraje restante la cantidad de kilómetros recorridos
        kms_restantes -= *(next(it)) - (*it);
    }
    
    return paradas; // Devolvemos las pradas realizadas
}

int main(int argc, char * argv[]){

    int km_ruta = atoi(argv[1]);            // Kilometraje de la ruta
    int num_gasolineras = atoi(argv[2]);    // Número de gasolineras de la ruta
    int kms_disponibles = atoi(argv[3]);    // Kilómetros que se pueden recorrer sin repostar
    int semilla1 = atoi(argv[4]);           // Semilla para la generación de números aleatorios
    mt19937 semilla(semilla1);

    // Distribución uniforme para los puntos kilométricos (entre 0 y km_ruta)
    uniform_int_distribution<int> distribucion(0, km_ruta);
    
    // Se crean las gasolineras
    set<int> gasolineras;

    // Lo puntos kilométricos de las gasolineras se generan aleatoriamente
    // de manera ascendente en el kilometraje de la ruta    
    for(int i = 0; i < num_gasolineras; i++)
        gasolineras.insert(distribucion(semilla));

    // Mostramos los puntos kilométricos de las gasolineras
    cout << "\nLa ruta de " << km_ruta << "km consta de las siguientes paradas: " << endl;
    for(auto i = gasolineras.begin(); i != gasolineras.end(); i++)
        cout << "Gasolinera en el punto kilométrico " << (*i) << endl;

    set<int> paradas = trazarRuta(kms_disponibles, gasolineras); 
    cout << "\nLas paradas programadas son:\n";

    for(auto i = paradas.begin(); i != paradas.end(); i++)
        cout << "Parada en el punto kilométrico " << (*i) << endl;
}
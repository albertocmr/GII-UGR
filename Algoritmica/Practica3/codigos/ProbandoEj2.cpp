/* 
Problema 2
Se va a celebrar una cena de gala a la que asistirán n invitados. 
Todos se van a sentar alrededor de una única gran mesa circular, de forma que 
cada invitado tendrá sentados junto a él a otros dos comensales 
(uno a su izquierda y otro a su derecha). En función de las características de 
cada invitado (por ejemplo categoría opuesto, lugar de procedencia,...) existen 
unas normas de protocolo que indican el nivel de conveniencia de que dos 
invitados se sienten en lugares contiguos (supondremos que dicho nivel es un 
número entero entre 0 y 100). El nivel de conveniencia total de una asignación 
de invitados a su puesto en la mesa es la suma de todos los niveles de 
conveniencia de cada invitado con cada uno de los dos invitados sentados a su 
lado.Se desea sentar a los invitados de forma que el nivel de conveniencia 
global sea lo mayor posible.
*/

#include <iostream>
#include <vector>

using namespace std;

struct{
    int mejor_conveniencia = -1;
    int mejor_posicion = -1;
    vector<int>::iterator iterador;
} typedef MejorPosicion;

MejorPosicion mejorPosicion(int i, int n, vector<int> & comensales_disponibles, int conveniencia[5][5]){
    MejorPosicion valores;
    for(auto it = comensales_disponibles.begin(); it != comensales_disponibles.end(); ++it){
        if(i != (*it)%n){
            cout << "El comensal " << i << " tiene una conveniencia de " << conveniencia[i][(*it)%n] + conveniencia[(*it)%n][i] << " con el comensal " << (*it)%n << endl;
            int conveniencia_total = conveniencia[i][(*it)%n] + conveniencia[(*it)%n][i];
            if(conveniencia_total > valores.mejor_conveniencia){
                valores.mejor_posicion = *it;
                valores.mejor_conveniencia = conveniencia_total;
                valores.iterador = it;
                cout << "El valor que guarda valores.iterador es " << *valores.iterador << endl;
            }
        }
    }
    comensales_disponibles.erase(valores.iterador);
    cout << endl;
    return valores;
}

void asignarInvitados(int n, int conveniencia[5][5]){
    vector<int> comensales_disponibles(n);
    vector<int> invitados;

    MejorPosicion valores;
    for(int i = 0; i < n; i++){
        comensales_disponibles[i] = i;
    }

    for(int i = 0; i < n && !comensales_disponibles.empty(); i++){
        if(invitados.empty()){
            // Colocamos al comensal izquierda:
            valores = mejorPosicion(i, n, comensales_disponibles, conveniencia);
            conveniencia[i][(valores.mejor_posicion)%n] = 0;
            conveniencia[(valores.mejor_posicion)%n][i] = 0;
            cout << "La mejor conveniencia entre el invitado " << i << " y el comensal " << valores.mejor_posicion << " es: " << valores.mejor_conveniencia << endl;
            invitados.push_back(valores.mejor_posicion);
            
            comensales_disponibles.erase(comensales_disponibles.begin() + (valores.iterador - comensales_disponibles.begin()));
            
            // Colocamos a nuestro comensal
            invitados.push_back(i);
            comensales_disponibles.erase(comensales_disponibles.begin() + i);

            valores.mejor_conveniencia = -1;
            valores.mejor_posicion = -1;

            // Colocamos al comensal derecha:
            valores = mejorPosicion(i, n, comensales_disponibles, conveniencia);
            conveniencia[i][(valores.mejor_posicion)%n] = 0;
            conveniencia[(valores.mejor_posicion)%n][i] = 0;
            cout << "La mejor conveniencia entre el invitado " << i << " y el comensal " << valores.mejor_posicion << " es: " << valores.mejor_conveniencia << endl;
            invitados.push_back((valores.mejor_posicion) % n);


            cout << "Comensales disponibles:  ";
            for(auto it = comensales_disponibles.begin(); it != comensales_disponibles.end(); ++it){
                cout << *it << " ";
            }
            comensales_disponibles.erase(comensales_disponibles.begin() + *valores.iterador);
            
            cout << endl << endl << "El valor borrado es " << *(comensales_disponibles.begin() + *valores.iterador) << endl << endl;
            cout << "Comensales disponibles:  ";
            for(auto it = comensales_disponibles.begin(); it != comensales_disponibles.end(); ++it){
                cout << *it << " ";
            }
            cout << endl << endl;
            i++;

            cout << "Se han colocado los primeros comensales:"
                    << invitados[0] << " " << invitados[1] << " " << invitados[2] << endl;
        }
        else
        {
            // Colocamos al mejor comensal a su derecha
            valores = mejorPosicion(i, n, comensales_disponibles, conveniencia);
            conveniencia[i][(valores.mejor_posicion)%n] = 0;
            conveniencia[(valores.mejor_posicion)%n][i] = 0;
            cout << "La mejor conveniencia entre el invitado " << i << " y el comensal " << valores.mejor_posicion << " es: " << valores.mejor_conveniencia << endl;
            invitados.push_back((valores.mejor_posicion) % n);

            comensales_disponibles.erase(comensales_disponibles.begin() + *valores.iterador);
        }
    }

    for(int i = 0; i < n; i++){
        cout << invitados[i] << " ";
    }
}


// Main para probar la funcion
int main(){
    int n = 5;
    // Matriz de conveniencia con valores de 0 a 100
    int conveniencia[5][5] = {{0, 12, 24, 6, 74},
                              {42, 0, 74, 14, 8},
                              {74, 41, 0, 85, 12},
                              {31, 72, 7, 0, 6},
                              {40, 40, 60, 54, 0}};
    vector<int> invitados(n);
    asignarInvitados(n, conveniencia);
    cout << endl;
    return 0;
}
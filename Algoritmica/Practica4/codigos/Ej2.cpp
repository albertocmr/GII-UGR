#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
Se va a celebrar una cena de gala a la que asistirán n invitados. Todos se van a sentar alrededor de una única
gran mesa circular, de forma que cada invitado tendrá sentados junto a él a otros dos comensales (uno a su
izquierda y otro a su derecha). En función de las características de cada invitado (por ejemplo categoría o
puesto, lugar de procedencia,...) existen unas normas de protocolo que indican el nivel de conveniencia de
que dos invitados se sienten en lugares contiguos (supondremos que dicho nivel es un número entero entre
0 y 100). El nivel de conveniencia total de una asignación de invitados a su puesto en la mesa es la suma
de todos los niveles de conveniencia de cada invitado con cada uno de los dos invitados sentados a su lado.
Se desea sentar a los invitados de forma que el nivel de conveniencia global sea lo mayor posible. Diseñar
e implementar un algoritmo de backtracking para resolver el problema.
*/

// Asignamos los invitados a la mesa utilizando backtracking
// Problema de maximización de conveniencia
void asignarInvitados(int n, int conveniencia[5][5]){
    vector<int> invitados;
    set<int> comensales_disponibles;

    for(int i = 0; i < n; i++)
        comensales_disponibles.insert(i);

    for(int i = 0; i < n && !comensales_disponibles.empty(); i++) {
        
    }


}



int main() {
    int n = 5;

    // matriz [5][5] con valores aleatorios con valores entre 0 y 100
    int conveniencia[5][5] = {
        {	0,	85,	12,	32,	18	},
        {	14,	0,	32,	54,	73	},
        {	42,	74,	0,	34,	84	},
        {	75,	21,	99,	0,	73	},
        {	32,	10,	81,	22,	0	}
    };

    

    asignarInvitados(n, conveniencia);
    return 0;
}

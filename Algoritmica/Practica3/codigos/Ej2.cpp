#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct MejorPosicion {
    int mejor_conveniencia = -1;
    int mejor_posicion = -1;
};

MejorPosicion mejorPosicion(int i, set<int> &comensales_disponibles, int conveniencia[5][5]) {
    MejorPosicion valores;
    for(auto comensal : comensales_disponibles) {
        if(i != comensal) {
            int conveniencia_total = conveniencia[i][comensal] + conveniencia[comensal][i];
            if(conveniencia_total > valores.mejor_conveniencia) {
                valores.mejor_posicion = comensal;
                valores.mejor_conveniencia = conveniencia_total;
            }
        }    
    }   

    cout << "La mejor conveniencia entre el invitado " << i << " y el comensal " << valores.mejor_posicion << " es: " << valores.mejor_conveniencia << endl;
    return valores;
}

void asignarInvitados(int n, int conveniencia[5][5]) {
    set<int> comensales_disponibles;
    vector<int> invitados;

    for(int i = 0; i < n; i++)
        comensales_disponibles.insert(i);

    for(int i = 0; i < n && !comensales_disponibles.empty(); i++) {
        if(invitados.empty()) {
            // Colocamos al comensal izquierda:
            MejorPosicion valores = mejorPosicion(i, comensales_disponibles, conveniencia);
            
            conveniencia[i][valores.mejor_posicion] = 0;
            conveniencia[valores.mejor_posicion][i] = 0;
            invitados.push_back(valores.mejor_posicion);
            comensales_disponibles.erase(valores.mejor_posicion);
            
            invitados.push_back(i);
            comensales_disponibles.erase(i);

            // Colocamos al comensal derecha:
            valores = mejorPosicion(i,comensales_disponibles, conveniencia);
            conveniencia[i][valores.mejor_posicion] = 0;
            conveniencia[valores.mejor_posicion][i] = 0;
            invitados.push_back(valores.mejor_posicion);
            comensales_disponibles.erase(valores.mejor_posicion);
            i++;
        } else {
            // Colocamos al mejor comensal a su derecha
            MejorPosicion valores = mejorPosicion(invitados[i], comensales_disponibles, conveniencia);
            conveniencia[invitados[i]][valores.mejor_posicion] = 0;
            conveniencia[valores.mejor_posicion][invitados[i]] = 0;
            invitados.push_back(valores.mejor_posicion);
            comensales_disponibles.erase(valores.mejor_posicion);
        }
    }
    for(auto invitado : invitados)
        cout << invitado << " ";
    
    cout << endl;
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

#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <set>


using namespace std;

const int inf = 99999;


void mostrarVector(int matriz[20][20]){
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if(matriz[i][j] != inf)
                cout << matriz[i][j] << "\t";
            
            else
                cout << "\u221E" <<  "\t";
            
        }
        cout << endl;
    }
    
}

void funcionRecuperacion(stack<int> &ruta, int matriz[20][20], int inicial, int final, int coste_optimo){
    int nodo_actual = inicial;
    int coste = 0;
    int nodo_optimo;
    int contador = 0;
    int tam = 20;

    while(nodo_actual != final){
        contador++;
        nodo_optimo = -1;
        int coste_aproximado = coste;
        for(int i=nodo_actual+1; i<20; i++){
            if(nodo_optimo == -1)
                nodo_optimo = i;
            
            if(matriz[nodo_actual][i] != inf && (coste_aproximado + matriz[nodo_actual][i])  < coste_optimo){
                nodo_optimo = i;
                coste_aproximado += matriz[nodo_actual][i];
            } 
        }
        
        if(nodo_optimo != -1){
            ruta.push(nodo_optimo);
            coste += matriz[nodo_actual][nodo_optimo];
            nodo_actual = nodo_optimo;
        }
        else{
            cout << "No se ha encontrado solucion" << endl;
            nodo_actual = final;
        }
    }
}


set<int> AlgoritmoPDin(int matriz[20][20], int copia[20][20], int inicial, int final){
    int num_nodos = 20;

    // Algortimo de Floyd-Warshall (costes mínimos entre todos los nodos)
    for(int k=0; k<num_nodos; k++)
        for(int i=0; i<num_nodos; i++)
            for(int j=0; j<num_nodos; j++){
                int dt = copia[i][k] + copia[k][j];
                if (dt < copia[i][j])
                    copia[i][j] = dt;   
            }

    //mostrarVector(copia);
    stack<int> ruta;
    int coste_optimo = copia[inicial][final];
    funcionRecuperacion(ruta, matriz, inicial, final, coste_optimo);

    set<int> camino;
    while(!ruta.empty()){
        camino.insert(ruta.top());
        ruta.pop();
    }
    return camino;

}


int main(){

    /*
    int matriz[12][12] = {
        {0,     4,    inf,  inf,    4,    inf,    inf,    inf,    inf,   inf,    inf,    inf},
        {inf,   0,    1,    inf,    1,    1,      inf,    inf,    inf,   inf,    inf,    inf},
        {inf,   inf,  0,    inf,    inf,  1,      inf,    inf,    inf,   inf,    inf,    inf},
        {inf,   inf,  inf,  0,      inf,  inf,    inf,    inf,    inf,   inf,    inf,    inf},
        {inf,   inf,  inf,  inf,    0,    1,      inf,    4,      1,     inf,    inf,    inf},
        {inf,   inf,  inf,  inf,    inf,  0,      inf,    inf,    1,     inf,    inf,    inf},
        {inf,   inf,  inf,  inf,    inf,  inf,    0,      inf,    inf,   4,      4,      inf},
        {inf,   inf,  inf,  inf,    inf,  inf,    inf,    0,      inf,   inf,    4,      0},
        {inf,   inf,  inf,  inf,    inf,  inf,    inf,    inf,    0,     inf,    inf,    0},
        {inf,   inf,  inf,  inf,    inf,  inf,    inf,    inf,    inf,   0,      4,      inf},
        {inf,   inf,  inf,  inf,    inf,  inf,    inf,    inf,    inf,   inf,    0,      0},
        {inf,   inf,  inf,  inf,    inf,  inf,    inf,    inf,    inf,   inf,    inf,    0}
        
    };*/

    int matriz[20][20] = {
/*0*/   {0,     8,    inf,  inf,    inf,   8,      8,      inf,    inf,   inf,    inf,     inf,    inf,    inf,    inf,    inf,    inf,     inf,    inf,    inf},
/*1*/   {inf,   0,    100,   inf,    inf,   inf,   8,      -1,     inf,   inf,    inf,     inf,    inf,    inf,    inf,    inf,    inf,     inf,    inf,    inf},
/*2*/   {inf,   inf,  0,    8,      inf,   inf,    inf,    -1,     -1,    inf,    inf,     inf,    inf,    inf,    inf,    inf,    inf,     inf,    inf,    inf},
/*3*/   {inf,   inf,  inf,  0,      -1,    inf,    inf,    inf,    -1,    8,      inf,     inf,    inf,    inf,    inf,    inf,    inf,     inf,    inf,    inf},
/*4*/   {inf,   inf,  inf,  inf,    0,     inf,    inf,    inf,    inf,   8,      inf,     inf,    inf,    inf,    inf,    inf,    inf,     inf,    inf,    inf},

/*5*/   {inf,   inf,  inf,  inf,    inf,   0,      8,      inf,    inf,   inf,    8,       8,      inf,    inf,    inf,    inf,    inf,     inf,    inf,    inf},
/*6*/   {inf,   inf,  inf,  inf,    inf,   inf,    0,      -1,     inf,   inf,    inf,     8,      -1,     inf,    inf,    inf,    inf,     inf,    inf,    inf},
/*7*/   {inf,   inf,  inf,  inf,    inf,   inf,    inf,    0,      -1,    inf,    inf,     inf,    -1,     8,      inf,    inf,    inf,     inf,    inf,    inf},
/*8*/   {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    0,     8,      inf,     inf,    inf,    8,      8,      inf,    inf,     inf,    inf,    inf},
/*9*/   {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   0,      inf,     inf,    inf,    inf,    8,      inf,    inf,     inf,    inf,    inf},

/*10*/  {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   inf,    0,       8,      inf,    inf,    inf,    8,      8,      inf,     inf,    inf},
/*11*/  {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   inf,    inf,     0,      -1,     inf,    inf,    inf,    8,      -1,      inf,    inf},
/*12*/  {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   inf,    inf,     inf,    0,      8,      inf,    inf,    inf,    -1,      8,      inf},
/*13*/  {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   inf,    inf,     inf,    inf,    0,      8,      inf,    inf,    inf,     8,      0  },
/*14*/  {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   inf,    inf,     inf,    inf,    inf,    0,      inf,    inf,    inf,     inf,    0  },
      
/*15*/  {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   inf,    inf,     inf,    inf,    inf,    inf,    0,      8,      inf,     inf,    inf},
/*16*/  {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   inf,    inf,     inf,    inf,    inf,    inf,    inf,    0,      -1,      inf,    inf},
/*17*/  {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   inf,    inf,     inf,    inf,    inf,    inf,    inf,    inf,    0,       8,      inf},
/*18*/  {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   inf,    inf,     inf,    inf,    inf,    inf,    inf,    inf,    inf,     0,      0  },
/*19*/  {inf,   inf,  inf,  inf,    inf,   inf,    inf,    inf,    inf,   inf,    inf,     inf,    inf,    inf,    inf,    inf,    inf,    inf,     inf,    0  },
    };


    int copia[20][20];

    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            copia[i][j] = matriz[i][j];
        
    

    set<int> camino = AlgoritmoPDin(matriz, copia, 0, 19);
    cout << endl << "Camino optimo --> ";

    for(set<int>::iterator it = camino.begin(); it != camino.end(); it++)
        cout << *it << " ";

    cout << endl;
    return 0;
}
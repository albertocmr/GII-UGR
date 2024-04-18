#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Imprime todos los elementos de la cola
// El elemento del front es el primero (el de la izquierda)
void imprimecola(queue<int> c){
	if (c.empty())
		cout << "{}" << endl;

	else{
		cout << '{' << c.front();
		c.pop();

		while(!c.empty()){
			cout << ',' << c.front();
			c.pop();
		}

		cout << '}' << endl;
	}
}

// <FUNCIÓN A IMPLEMENTAR>
void transformacola (queue<int> & C){
	stack<int> pila;			// Pila auxiliar en la que vaciaremos la cola
	queue<int> cola = C;			// Copia de la cola C
	
	while(!cola.empty()){
		pila.push(cola.front());	// Vaciamos la cola auxiliar en la pila
		cola.pop();
	}
	cola.push(pila.top());			// Añadimos el primer valor para poder comparar
						// ya que la cola auxiliar está vacía
	while(!pila.empty()){	
		if(cola.back() != pila.top()){
			//cout << "Añadimos a la cola el valor de " << pila.top() << endl;
			cola.push(pila.top());
		}	
		pila.pop();
	}
	C = cola;				// Copiamos el valor de la cola auxiliar en C
	//cout << "Imprimimos el valor de la nueva cola ";
	//imprimecola(C);
}






// Simplemente comprueba que la solución para la cola "in1"
void test_sol(queue<int> in1, queue<int> sol){
	cout << "Entradas...."<<endl;
	imprimecola(in1);
	transformacola(in1);
	cout<<"Resultado obtenido ";
	imprimecola(in1);
	cout << "Solucion correcta?: " << (in1==sol ? "YES" : "NO") << endl;
}

int main(){
	queue<int> q1_in1({1,1,2,3,3,4,5,5,1,1,9,8,7,7,3});
	queue<int> q1_sol({3,7,8,9,1,5,4,3,2,1});
	test_sol(q1_in1, q1_sol);

	queue<int> q2_in1({1,1,1,1,3,3,3,3});
	queue<int> q2_sol({3,1});
	test_sol(q2_in1, q2_sol);



}

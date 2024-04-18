#include <iostream>
#include <vector>
#include <set>


using namespace std;

// <FUNCIÓN A IMPLEMENTAR>
bool en_todos(vector< set<int> > &V){
	set<int>::iterator it1;
	set<int>::iterator it2;
	
	int j = 1;
	
	for(it1 = V[0].begin(); it1 != V[0].end() && j < V.size(); ++it1){
		
		while(j < V.size()){
			int encontrado = false;
			for(it2 = V[j].begin(); it2 !=V[j].end() && !encontrado;++it2){
				//cout << "Comparamos el valor de los iteradores: it1 (" << *it1 
				//	<< ") y el valor it2 (" << *it2 << ")" << endl;
				if(*it1 == *it2){
					//cout << "Lo hemos encontrado, cambio de set" << endl;
					encontrado = true;
				}
			
			}
			if(!encontrado){
				return true;
			}
			j++;
		}
	}
	return false;
}



//Imprime un conjunto
void imprimeSet(const set<int> & s){
	set<int>::iterator it;
	cout<<"{";
	for (it=s.cbegin();it!=s.cend();++it)
		cout<<*it<<" ";
	cout<<"}";
}

//Imprime un vector
void imprimeVector( const vector<set<int>> & V){
	cout<<"{";
	for (int i=0;i<V.size(); i++){
	   imprimeSet(V[i]);
	   cout<<",";
	}
	cout<<"}"<<endl;
}

// Simplemente comprueba que la solución para el vector de set es correcta
void test_sol(vector<set<int> > & vs ,bool sol){
	cout << "Entrada:   ";
	imprimeVector(vs);
	bool res = en_todos(vs);
	cout << "Resultado: "<<((res==true)?"True":"False")<<endl;
	cout << "Solución:  "<<((sol==true)?"True":"False")<<endl;
	cout << "Solución correcta?: " << (res==sol ? "YES" : "NO") << endl;
}

int main(){
    vector<set<int> > V1({{0,2,3,4},{0,1,5,7},{2,3,5,6,7}});
    test_sol(V1,true);

    vector<set<int> > V2({{0,2,3,4,5},{0,1,7},{0,2,3,5,6,7}});
    test_sol(V2,false);

	vector<set<int> > V3({{ 1, 2, 3},  {1,2,3,4},  {1,2,3,4,6} });
    test_sol(V3,false);



}

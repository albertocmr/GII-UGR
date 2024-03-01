void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i=1; i<n; i++){
		key = arr[i];
		j = i-1;
		
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}

}


Iteracion 1 -->  vector = {12, 11, 13, 5, 6}
{
	key = arr[2] = 11;
	j = 0;
	while(){			//(0>=0 && 12 > 11)
		arr[1] = 12;		//arr[j+1] (arr[1]) = arr[j] (arr[0] = 12) 
		j = -1;
	}
	arr[0] = 11;
}

Iteracion 2 -->  vector = {11, 12, 13, 5, 6}
{
	key = arr[2] = 13;
	j = 1;
	
	while(){			
		// Evaluación de condición -> (1>=0 && 12 > 13)
		No se cumple la condición, está ordenado.
	}
}

Iteracion 3 -->  vector = {11, 12, 13, 5, 6}
{
	key = arr[3] = 5;
	j = 2;
	
	while(){			
		// Evaluacion de condicion -> (2>=0 && 13 > 5)
		arr[3] = 13;
		j = 1;
		// Evaluación de condicion -> (1>=0 && arr[j] > key (12 > 5))
		arr[2] = 12;
		j = 0;
		// Evaluación de condición -> (0>=0 && arr[j] > key (11 > 5))
		arr[1] = 11;
		j = -1;
	}
	arr[0] = 5;
}

Iteracion 4 -->  vector = {5, 11, 12, 13, 6}
{
	key = arr[4] = 6;
	j = 3;
	
	while(){
		// Evaluación de condición -> (3>=0 && 13 > 6)
		arr[4] = 13;
		j = 2;
		// Evaluación de condición -> (2>=0 && 12 > 6)
		arr[3] = 12;
		j = 1;
		// Evaluación de condición -> (1>=0 && 11 > 6)
		arr[2] = 11;
		j = 0;
		// Evaluación de condición -> (0>=0 && 5 > 6)
		No se cumple la condición, está ordenado
	}
	arr[1] = 6;
}

Vector ya ordenado tras 4 iteraciones -> {5, 6, 11, 12, 13}



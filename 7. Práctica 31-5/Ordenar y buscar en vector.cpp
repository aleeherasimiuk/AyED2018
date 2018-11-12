#include <iostream>
using namespace std;

//Función ordenamiento
//Ordenar. Buscar la Nota del legajo 108 y 1100
//De no existir decir en qué posición debería ponerse

struct estudiantes{
	int NL;
	int nota;
};

void ordenarVector(estudiantes V[], int n);
int BB(estudiantes V[], int buscado, int n, int pos);

int main() {
   
   int pos = -1;
   estudiantes V[8];
   
    V[0].NL = 30;
	V[0].nota = 8;
	
	V[1].NL = 100;
	V[1].nota = 6;
	
	V[2].NL = 20;
	V[2].nota = 9;
	
	V[3].NL = 1;
	V[3].nota = 8;
	
	V[4].NL = 1200;
	V[4].nota = 3;
	
	V[5].NL = 108;
	V[5].nota = 4;
	
	V[6].NL = 9;
	V[6].nota = 6;
	
	V[7].NL = 11;
	V[7].nota = 8;
	
	cout << "El arreglo sin ordenar: "<< endl;
	
	for(int i = 0; i<8; i++){
		
		cout << "Número de Legajo: " << V[i].NL << "--> Nota: " << V[i].nota << endl;
	}
	
	cout << "\n";
	
	ordenarVector(V, 8);
	cout << "El arreglo ordenado: " << endl;
	
	for(int i = 0; i<8; i++){
		cout << "Número de Legajo: " << V[i].NL << "--> Nota: " << V[i].nota << endl;
	}
	
	BB(V, 100, 8, pos);
	
	if(pos != -1){
		
		cout << "Para el legajo número 100, se encontró la nota: " << V[pos];
		
	} else {
		
	}
	
	BB(V, 1100, 8, pos);
	
	if(pos != -1){
		
		cout << "Para el legajo número 1100, se encontró la nota: " << V[pos];
		
	} else {
		
		cout << "Legajo 1100 no encontrado, se deberá insertar en la posición: " << n;
		
	}

	return 0;
}

void ordenarVector(estudiantes V[], int n){
	
	int i = 1;
	int j;
	estudiantes aux;
	
	for(i; i<n-1;i++){
		
		for(j = 1; j<n-i; j++){
			
			if(V[j-1].NL > V[j].NL){
				
				aux = V[j];
				V[j] = V[j-1];
				V[j-1] = aux;
			}
			
		}
		
	}
	
	return;
}

int BB(estudiantes V[], int buscado, int n, int &p){
	
	int p = 0;
	int u = n-1;
	int m = 0;
	
	while(p <= u){
		m = ((p+u)/2);
		
		if(V[m].NL == buscado){
			return m;
		} else if(buscado > V[m].NL){
			p = m+1;
		} else {
			u = m-1;
		}
	}
}



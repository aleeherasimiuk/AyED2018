#include <iostream>
#include <cstdlib>
#include <time.h> 
using namespace std;

/*
1- Programar la función insertarOrdenado();
2- Dada una lista retornar la cantidad de elementos
3- Dada una lista ordenada retronar los datos en orden inverso
4- Dado un archivo de alumnos sin orden, imprimir el listado ordenado por legajo (nombre y apellido, legajo, división)


*/

struct nodo{
	int info;
	nodo* sgte;
};

nodo* insertaOrdenado(nodo* &, int);
int retornaCantidad(nodo* &);

void cargaLista(nodo* &, int);

int main() {
	srand(time(NULL));
	
	int n = 10;
	nodo* lista = NULL; 
	cargaLista(lista, n);

	int cant = retornaCantidad(lista);
	cout << "Se han insertado " << cant << " números";
	
	return 0;
}

nodo* insertaOrdenado(nodo* &lista, int x){
	
	nodo* q = NULL;
	nodo* p = new nodo();
	p -> info = x;
	
	if(lista == NULL || x < lista -> info){
		
		p -> sgte = lista;
		lista = p;
		q = lista;
		
	} else {
		q = lista;
	
	
	while(q -> sgte != NULL && x > q -> sgte -> info){
		
		q = q -> sgte;
		
		
	}

	p -> sgte = q -> sgte;
	q -> sgte = p;
	
	}
	
	return p;
}

int retornaCantidad(nodo* &lista){
	nodo* p = lista;
	nodo* q = NULL;
	int i = 0;
	
	while(p != NULL){
		q = p;
		p = p -> sgte;
		i++;
	}
	
	return i;
}

void cargaLista(nodo* &lista, int n){

	int i = 0;
	
	for(i; i < n; i++){
		int x = rand()%1000;
		insertaOrdenado(lista,x);
		cout << "EL número de la lista en la posición #" << i+1 <<  " es: " << x << endl;
	}
}

	



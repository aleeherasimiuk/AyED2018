#include <iostream>
using namespace std;

struct nodo{
	
	int info;
	nodo* sgte;
	
};

void push(nodo* &pila, int valor);
int pop(nodo* &pila);
void imprimirPila(nodo * &pila);
void insertaNumero(nodo* &pila, int pos, int valor);

int main() {
	
	cout <<"Sistema de pila" << endl;
	
	nodo* pila = NULL;
	cout << "Por favor ingrese el primer valor de la pila: ";
	int x = 0;
	cin >> x;
	push(pila, x);

	int i = 1;	
	cout << "¿Desea ingresar otro valor? (Y/N): ";
	char seguir;
	cin >> seguir;

	while(seguir == 'y' || seguir == 'Y'){
		
		i++;
		cout << "Por favor ingrese un valor a la pila: ";
		cin >> x;
		push(pila, x);
		
		cout << "¿Desea ingresar otro valor? (Y/N): ";
		cin >> seguir;	
		
	}
	
	cout << "Por favor ingrese la posición del número a insertar: ";
	int n = 0;
	cin >> n;
	
	if(n <= i+1){
		cout << "Por favor ingrese el número a insertar en la posición #" << n << ": ";
		cin >> x;
		insertaNumero(pila, n, x);
	}
	
	
	cout << "¡Desea imprimir la pila?(Y/N): ";
	cin >> seguir;
	
	if(seguir == 'Y' || seguir == 'y'){
		imprimirPila(pila);
	}	
	
	return 0;
}

void push(nodo* &pila, int valor){
	
	nodo *p = new nodo();
	
	p -> info = valor;
	p -> sgte = pila;
	pila = p;
	
	
	return;
}


int pop(nodo* &pila){
	
	nodo* p = pila;
	int x = p -> info;
	pila = p -> sgte;
	delete p;
	return x;
	
}

void imprimirPila(nodo * &pila){

	while(pila != NULL){
		cout << pop(pila) << ", ";
	}


}

void insertaNumero(nodo* &pila, int pos, int valor){
	
	nodo* pila2 = NULL;
	int x = 0;
	
	int i = 0;
	for(i; i < (pos-1); i++){
		x = pop(pila);
		push(pila2, x);
	}
	
	push(pila, valor);
	
	while(pila2 != NULL){
		x = pop(pila2);
		push(pila, x);
	}
	
	return;
	
}

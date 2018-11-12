#include <iostream>
using namespace std;

struct nodo{
	
	int info;
	nodo* sgte;
	
};

void push(nodo* &pila, int valor);
int pop(nodo* &pila);
void imprimirPila(nodo * &pila);

int main() {
	
	cout <<"Sistema de pila" << endl;
	
	nodo* pila = NULL;
	cout << "Por favor ingrese el primer valor de la pila: ";
	int x = 0;
	cin >> x;
	push(pila, x);

		
	cout << "¿Desea ingresar otro valor? (Y/N): ";
	char seguir;
	cin >> seguir;

	while(seguir == 'y' || seguir == 'Y'){
		
		cout << "Por favor ingrese un valor a la pila: ";
		cin >> x;
		push(pila, x);
		
		cout << "¿Desea ingresar otro valor? (Y/N): ";
		cin >> seguir;	
		
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
		cout << pop(pila) << endl;
	}


}

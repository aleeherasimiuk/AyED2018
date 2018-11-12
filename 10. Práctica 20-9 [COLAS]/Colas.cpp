#include <iostream>
#include <cstdlib>
using namespace std;

//Cola, primero que entra es el primero que sale

struct nodo{
	
	int info;
	nodo* sgte;
};

//Borrar nombres de variables
void encolar(nodo* &frente, nodo* &fin, int valor);
int desencolar(nodo* &frente, nodo* &fin);


///Ejercicios//
void cargarCola(nodo* &i, nodo* &f, int &n);
void concatenar(nodo* &i1, nodo* &f1, nodo* &i2, nodo* f2);
void aparear(nodo* &i1, nodo* &f1, nodo* &i2, nodo* f, int cant1, int cant2);
void imprimeCola(nodo* &i, nodo* &f);


int main(int argc, char** argv) {
	
	cout << "Sistema de colas." << endl;
	char seleccion;
	
	nodo* frente1 = NULL;
	nodo*fin1 = NULL;
	int cant1 = 0;
	
	nodo* frente2 = NULL;
	nodo* fin2 = NULL;
	int cant2 = 0;

	
	
	do{
		
	cout << "1. Colas concatenadas" << endl;
	cout << "2. Colas apareadas" << endl; 
	cout << "Elija una opción: ";
	cin >> seleccion;
	cout << endl;
		
	}while(seleccion != '1' && seleccion != '2');
	
	cout << "Cola 1:" << endl;
	cargarCola(frente1, fin1, cant1);
	
	cout << endl;
	
	cout << "Cola 2:" << endl;
	cargarCola(frente2, fin2, cant2);
	
	if(seleccion == '1'){
		
		cout << "Colas concatenadas: " << endl;
		concatenar(frente1, fin1, frente2, fin2);
		
	} else if(seleccion == '2'){
		
		cout << "Colas apareadas: " << endl;
		aparear(frente1, fin1, frente2, fin2, cant1, cant2);
		
		
	}
	
	
	return 0;
}

void encolar(nodo* &frente, nodo* &fin, int x){
	
	nodo* p = new nodo(); //Pido un lugar en la memoria
	p -> info = x; //Le asigno el valor x que mandó el usuario
	p -> sgte = NULL; //al ser el último de la cola, apunta a NULL
	
	if(frente == NULL){ //Si el frente es NULL, es decir, no hay elementos...
		
		frente = p; //El puntero a la primera posición va a ser la que creamos recién;
		
	} else { //En el caso de que no sea el primer elemento..
		
		fin -> sgte = p; //en el ultimo nodo, se actualiza el puntero al nodo recién creado
		
	}
	
	fin = p; //Se actualiza el puntero al último nodo
	return;
	
}

int desencolar(nodo* &frente, nodo* &fin){
	
	int x; //donde guardamos el valor que sacamos
	nodo* p = frente; //en el puntero p, ponemos el puntero al primer nodo de la cola
	x = p -> info; //A x le damos el valor que contiene el nodo
	frente = p -> sgte; //Actualizamos el puntero del primer elemento, al elemento siguiente
	
	if(frente == NULL){ //Si ya llegamos al último elemento..
		fin = NULL; //Que el puntero al último elemento también sea NULL
	}
	
	delete p; //Borramos el nodo al que le sacamos el valor
	return x; //Retornamos x.
	
}


void cargarCola(nodo* &i, nodo* &f, int &n){
	
	char seguir;
	int x = 0;
	
	cout << "La cola debe estar ordenada." << endl;
	
	do{
		
		cout << "Ingrese un valor para la cola: ";
		cin >> x;
		encolar(i,f,x);
		n++;
		cout << "¿Desea seguir cargando valores?(Y/N): ";
		cin >> seguir;
		
	}while(seguir == 'Y' || seguir == 'y');
	
	
}

void concatenar(nodo* &i1, nodo* &f1, nodo* &i2, nodo* f2){
	f1 -> sgte = i2;
	f2 = NULL;
	i2 = NULL;
	
	imprimeCola(i1, f1);
}


void imprimeCola(nodo* &i, nodo* &f){
	
	while(i != NULL && f != NULL){
		cout << desencolar(i, f) << endl;
	}
	
}

void aparear(nodo* &i1, nodo* &f1, nodo* &i2, nodo* f2, int cant1, int cant2){
	
	nodo* i3 = NULL;
	nodo* f3 = NULL;
	
	int i = 0;
	int j = 0;
	
	int x1 = 0;
	int x2 = 0;
	
	int b = 0;
	
	x1 = desencolar(i1, f1);
	x2 = desencolar(i2, f2);
	
	while(i < cant1 && j < cant2){
		
		if(b == 1){
			x1 = desencolar(i1,f1);
		}
		if(b == 2){
			x2 = desencolar(i2,f2);
		}
		
		if(x1 < x2){
			
			encolar(i3, f3, x1);
			b=1;
			i++;
			
		} else {
			
			encolar(i3, f3, x2);
			b=2;
			j++;
			
		}
	}
	
	while(i < cant1 && i1 != NULL & f1 != NULL){
		encolar(i3,f3,desencolar(i1,f1));
		i++;
	}
	
	while(j < cant2 && i2 != NULL & f2 != NULL){
		encolar(i3,f3,desencolar(i2,f2));
		j++;
	}
	
	imprimeCola(i3, f3);
	
}

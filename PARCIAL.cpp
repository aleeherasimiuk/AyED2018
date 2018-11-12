#include <iostream>
using namespace std;

char* dias[9] = {"Sábado", "Domingo", "Jueves", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Lunes"};
char* colores[9] = {"Negro", "Amarillo", "Blanco", "Rojo", "Verde", "Gris", "Violeta", "Celeste", "Azul"};
char* caracteristicas[9] = {"Emprendedor", "Pasivo", "Optimista", "Práctico", "Inestable", "Confiable", "Culto", "Organizado", "Docente"};

//Punto 1
struct nodo{
	int info;
	nodo* sgte;
};

//Punto 2:
nodo* CargarNombre(void);

//Punto 3:
unsigned int NumeroAfortunado(nodo*&);

//Punto 4:
void MostrarResultado(unsigned int);

//Funciones de pila
void push(nodo* &pila, int valor);
int pop(nodo* &pila);

int main() {	
	setlocale(LC_ALL, "");
	
	nodo* pila =  CargarNombre();
	unsigned int numAfortunado = NumeroAfortunado(pila);
	MostrarResultado(numAfortunado);

	
	
	return 0;
}

nodo* CargarNombre(void){
	nodo* pila = NULL;
	
	int b = 0;
	while(b == 0){
		
		cout << "Por favor ingrese una letra, o ingrese 0 para terminar: ";
		char caracter;
		cin >> caracter;
		
		if(caracter == '0'){
			b = 1;
		} else {
			push(pila, (caracter - 64));
		}
	}
	
	return pila;
	
}

//Punto 3:
unsigned int NumeroAfortunado(nodo* &pila){
	
	unsigned int x = 0;
	unsigned int numeroAfortunado = 0;
	while(pila != NULL){
		x = pop(pila);
		numeroAfortunado += x;
	}
	
	unsigned int a = 0, b = 0, c = 0;
	unsigned int suma = 0;
	
		if(numeroAfortunado > 99){
			a = numeroAfortunado %10;
			b = (numeroAfortunado %100 - a)/10;
			c = (numeroAfortunado - a - b*10)/100;
			
			suma = (c + b + a);
		} else if(numeroAfortunado > 9){
		
			a = numeroAfortunado %10;
			b = ((numeroAfortunado-a)/10);
			cout <<a;
			cout<<b;
			suma = (a+b);
		
		} /*else {
			suma = numeroAfortunado %10;
		}*/
		
		if(suma < 10){
			
			return suma;
			
		} else {

			int d = suma;
			a =  d%10;
		  b =  (d - a) / 10;
		  return (a+b);
		}
		
	
}

//Punto 4
void MostrarResultado(unsigned int x){
	x--;
	cout << "El día de la semana obtenido es: " << dias[x] << endl;
	cout << "El color obtenido es: " << colores[x] << endl;
	cout << "La característica obtenida es: " << caracteristicas[x] << endl; 
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void push(nodo* &pila, int valor){ //Recibe el puntero al inicio de la pila y el valor a ingresar
	
	nodo *p = new nodo(); //Crea de forma dinámica una instancia de nodo, una variable anónima
	
	p -> info = valor; //En el campo info de la instancia recién creada, se almacena el valor
	p -> sgte = pila; //En el campo 'siguiente' se almacena el lugar donde ANTES estaba el tope de la pila, es decir el primer elemento
	pila = p; //Ahora el inicio de la pila, es el nodo que acabamos de crear
	
	return;
}


//Función pop, retorna el valor del tope de la pila
int pop(nodo* &pila){ //Recibe como parámetro el puntero al inicio de la pila
	
	nodo* p = pila; //Guardo de manera temporal el tope de la pila
	int x = p -> info; //Extraigo el valor del nodo del tope de la pila
	pila = p -> sgte; //Al puntero al inicio de la pila, le pongo el nodo que ahora está quedando en el tope de la pila
	delete p; //Libero memoria
	return x; //Devuelvo el entero
	
}

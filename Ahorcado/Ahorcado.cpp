#include <iostream>
#include <cstdlib>
#include <cstring>
#include <time.h>
using namespace std;

struct estado{
	
	int check; //Se marca si la letra fue adivinada
	int pos; //Marca la posición dentro de la palabra de cada letra
};

struct letra{
	
	char let; //caracter de la letra
	estado est; //Estado de la letra
};


struct nodo{
	
	letra info; 
	nodo* sgte;
};

void seleccionaPalabra(char[]); //Si el usuario juega solo, esta función elige la palabra automáticamente
void ingresaPalabra(char[]); //Si el usuario juega acompañado, esta función pide la palabra al usuario
void dibujaAhorcado(int); //Esta función dibuja el ahorcado, según la cantidad de vidas que el usuario tiene
void enlistarPalabra(char[], nodo* &); //Se enlistan las letras de la palabra que el usuario tiene que adivinar
void jugar(nodo* &, char[]); //Algoritmo para jugar
int escribeLineas(nodo* &, char[]); //Esta función escribe las líneas según las letras que el usuario ya adivinó
void marcaCorrecta(nodo* &, char, int &); //Esta función busca la letra y si existe actualiza el check

nodo* insertaOrdenado(nodo* &, letra); // Función propia de listas, inserta ordenado según la posición de la letra en el abecedario
nodo* buscar(nodo*, char, nodo*); //Funcion propia de listas, busca un valor en la lista, devuelve el nodo si lo encuentra
//La función buscar se encuentra modificada convenientemente
int retornaCantidad(nodo* &); //Esta función retorna la cantidad de letras que tiene la palabra a adivinar
void imprimeLista(nodo* &); //Función para control, la uso para ir testeando a medida que voy probando el código

int main() {
	char palabra[20]; //Acá se guarda la palabra que el usuario tiene que adivinar
	nodo* lista = NULL; //Principio de lista

	cout << "Bienvenido al ahorcado" << endl;
	cout << "1. Jugar solo" << endl;
	cout << "2. Jugar con alguien" << endl;
	cout << "Por favor ingrese una opción: ";
	char itemseleccionado;
	cin >> itemseleccionado;
	
	if(itemseleccionado == '1'){
		
		seleccionaPalabra(palabra);
		
	} else if(itemseleccionado == '2'){
		
		ingresaPalabra(palabra);
		
	}
	
	system("cls"); //Borrar consola
	enlistarPalabra(palabra, lista);
	jugar(lista, palabra);
		
	
	system("pause");
	return 0;
}

void seleccionaPalabra(char palabraElegida[]){
	
	srand (time(NULL)); //seed random
	//En este arreglo hay palabras por defecto para que el usuario adivine si juega solo
	char palabras[10][20] = {"zanahoria", "mesa", "computadora", "electrodomestico", "algoritmo", "manzana", "chimichurri", "televisor", "auto", "pelota"};
	int x = rand() %10; //Se elige al azar un número del 0 al 9
	strcpy(palabraElegida, palabras[x]); //se copia en la variable pasada por referencia, la palabra que se obtuvo del arreglo
	
	return;
}
void ingresaPalabra(char palabraIngresada[]){
	
	cout << "Por favor ingrese la palabra: ";
	cin >> palabraIngresada;
	
	return;
}

void enlistarPalabra(char palabra[], nodo* &lista){ //Se toma la palabra y se ingresa en la lista caracter por caracter
	
	int i = 0;	
	while(palabra[i] != '\0'){ //Mientras no sea el final de la palabra
		letra l; //declaro una letra para ingresarla en la lista
		l.let = palabra[i]; //En el campo char del registro de la letra a ignresar en la lista, pongo la letra de la palabra que corresponde
		l.est.check = 0; //Asigno un check default de 0.
		l.est.pos = i; //Le asigno el valor de la posición que se encuentra originalmente
		i++;
		
		insertaOrdenado(lista, l); //se inserta ordenada en la lista, los caracteres por orden alfabético
	}
}

void dibujaAhorcado(int vidas){
	
	if(vidas == 6){
		cout << "	________________" << endl;
		cout << "	|               |" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "--------" << char(193) << "-----------" << endl;
	} else if(vidas == 5){
		
		cout << "	________________" << endl;
		cout << "	|               |" << endl;
		cout << "	|               O"<< endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "--------" << char(193) << "-----------" << endl;
		
	} else if(vidas == 4){
		
		cout << "	________________" << endl;
		cout << "	|               |" << endl;
		cout << "	|               O"<< endl;
		cout << "	|               " << char(178) << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "--------" << char(193) << "-----------" << endl;
		
	} else if(vidas == 3){
		
		cout << "	________________" << endl;
		cout << "	|               |" << endl;
		cout << "	|               O"<< endl;
		cout << "	|              /" << char(178) << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "--------" << char(193) << "-----------" << endl;
		
	} else if(vidas == 2){
		
		cout << "	________________" << endl;
		cout << "	|               |" << endl;
		cout << "	|               O"<< endl;
		cout << "	|              /" << char(178) << char(92) << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "--------" << char(193) << "-----------" << endl;
		
	} else if(vidas == 1){
		
		cout << "	________________" << endl;
		cout << "	|               |" << endl;
		cout << "	|               O"<< endl;
		cout << "	|              /" << char(178) << char(92) << endl;
		cout << "	|              /" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "--------" << char(193) << "-----------" << endl;
		
	} else if(vidas == 0){
		
		cout << "	________________" << endl;
		cout << "	|               |" << endl;
		cout << "	|               O"<< endl;
		cout << "	|              /" << char(178) << char(92) << endl;
		cout << "	|              / " << char(92) << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "	|" << endl;
		cout << "--------" << char(193) << "-----------" << endl;
		
	}
}

void jugar(nodo* &lista, char palabra[]){
	
	int vidas = 6; 
	int listo = 0; //Si la palabra ya fue adivinada se cambia a 1
	do{
		dibujaAhorcado(vidas); //Se imprime el ahorcado
		
		cout << endl << endl << endl;
		listo =	escribeLineas(lista, palabra); //Se imprimen las lineas para completar, y devuelve 1 si ya se adivinó, 0 si tiene que seguir jugando
		
		if(listo == 0){ //Si todavía no adivinó
			cout << endl << endl << endl;
			cout << "Por favor ingresá una letra: ";
			char let;
			cin >> let;
			marcaCorrecta(lista, let, vidas); //Esta función busca la letra y si existe actualiza el check
		}
		
		system("cls"); //Se limpia la consola
		
	}while(vidas > 0 && listo == 0); //Se ejecuta mientras queden vidas y no se haya adivinado
	
	if(vidas == 0){
		cout << "Perdiste, la palabra era: " << palabra << endl;
	} else if(listo == 1){
		cout << "Felicidades, adivinaste la palabra!" << endl;
	}
	
} 

int escribeLineas(nodo* &lista, char palabraAdivinar[]){
	
	int i = 0;
	int c = retornaCantidad(lista); //Cantidad de letras que tiene la palabra
	char palabra[c]; //Un vector de la misma cantidad de letras que la palabra
	nodo* p = lista; 
	int pos = 0;
	
	while(p != NULL){ 

		pos = p -> info.est.pos; //extraigo la posición de la letra que estoy evaluando
		if(p -> info.est.check == 1){ //Si ésta letra fue adivinada...	
			palabra[pos] = p -> info.let; //En la posición que corresponde pongo la letra que ya habia sido adivinada
		} else {
			palabra[pos] = '_'; //Si la letra todavía no está adivinada se llena con un guión bajo para completar
		}
		p = p -> sgte;
		i++;
	}
	
	
	cout << "	";
	int j = 0;
	for(j; j < c; j++){
		cout << palabra[j] << " ";
	}
	
	if(!strcmp(palabra, palabraAdivinar)){ //Si ya adivinó la palabra...
		return 1;
	} else {
		return 0;
	}
}

void marcaCorrecta(nodo* &lista, char let, int &vidas){ //Esta función busca la letra y si existe actualiza el check
	
	nodo *p = buscar(lista, let, lista); //Busca la letra desde el inicio
	if(p != NULL){ //Si la encontró
		p -> info.est.check = 1; //Se actualiza el check
		while(p != NULL){ //Se sigue buscando ya que puede repetirse la letra en la palabra
			p = buscar(lista, let, p -> sgte); //Busca desde el lugar siguiente a la letra recien enconttada
			if(p != NULL){ //Si encontró otra letra
				p -> info.est.check = 1; //Actualiza el check
			}
				
		}
	} else {
		vidas--; //Si no encuentra nada se decrementa la cantidad de vidas
	}		
}


nodo* buscar(nodo* lista, char valor, nodo* inicio){ 
	nodo* p = inicio; //Para buscar letras repetidas, en este caso busca desde un lugar en específico
	
	while(p != NULL && p -> info.let < valor){
		p = p -> sgte;
	}
	
	if(p != NULL && p -> info.let == valor){
		
		return p;
		
	} else {
		
		return NULL;
		
	}
	
}

nodo* insertaOrdenado(nodo* &lista, letra x){
	
	nodo* q = NULL;
	nodo* p = new nodo();
	p -> info = x;
	
	if(lista == NULL || x.let < lista -> info.let){
		
		p -> sgte = lista;
		lista = p;
	//	q = lista;
		
	} else {
		q = lista;
	
	
	while(q -> sgte != NULL && x.let > q -> sgte -> info.let){
		
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


void imprimeLista(nodo* &lista){
	
	nodo* p = lista;
	int i = 0;
	
	while(p != NULL){

		cout << "Posición #" << i+1 <<": " <<  p -> info.let << endl;
		p = p -> sgte;
		i++;
	}

}

char pop(nodo * &lista){
	
	letra valor;
	nodo* pro = lista;
	valor.let = pro -> info.let;
	lista = pro -> sgte;
	delete pro;
	return valor.let;
}

#include <iostream>
#include <cstdlib>
#include <time.h> 
using namespace std;

struct nodo{
	int info;
	nodo* sgte;
};

nodo* insertaOrdenado(nodo* &, int);
nodo* buscar(nodo*, int);
nodo* buscar_o_insertar(nodo*&, int);

void cargaLista(nodo* &, int);
void cargaListaUsuario(nodo* &);
void eliminaNodo(nodo* &, int);
void imprimeLista(nodo* &);

int retornaCantidad(nodo* &);
int pop(nodo *&);

void imprimeListaBien(nodo* &);

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "");
	
	nodo* lista = NULL; 
		
	int itemSeleccionado;
	cout << "¿Querés cargar la lista o la cargamos manualmente?" << endl;
	cout << "1. Cargar manualmente" << endl;
	cout << "2. Cargar automáticamente" << endl;
	cout << "Por favor seleccioná una opción: ";
	cin  >> itemSeleccionado;
	
	if(itemSeleccionado == 1){
	
		cargaListaUsuario(lista);
		
	} else if(itemSeleccionado == 2){
		
		cout << "¿Cuantos números queres poner en la lista?: ";
		int n = 0;
		
		cin >> n;
		
		cargaLista(lista, n);
	}

	//imprimeLista(lista);

	int cant = retornaCantidad(lista);
	cout << "Se insertaron " << cant << " números" << endl;
	
	int aEliminar = 0;
	cout << "Poné un valor para borrar: ";
	cin>> aEliminar;
	
	eliminaNodo(lista, aEliminar);
	
	//imprimeLista(lista);
	
	int aBuscar_insertar = 0;
	cout << "Poné un valor para buscar, si no está se va a insertar de manera ordenada: ";
	cin >> aBuscar_insertar;
	
	nodo* encontrado = buscar(lista, aBuscar_insertar);
	buscar_o_insertar(lista, aBuscar_insertar);
	
	if(encontrado == NULL){
		cout << "El número " << aBuscar_insertar << " no existe y se insertó" << endl;
		//imprimeLista(lista);
	} else {
		cout << "El número ya existía previamente" << endl;
	}
	
	imprimeListaBien(lista);	
	return 0;
}

//Función para insertar un valor
nodo* insertaOrdenado(nodo* &lista, int x){ //recibe como parámetros el inicio de la lista y el valor a ingresar
	
	nodo* q = NULL; //Declaro un nodo auxiliar
	nodo* p = new nodo(); //Creo una instancia del nodo que voy a ingresar a la cola
	p -> info = x; //A p le asigno el valor que quiero ingresar
	
	if(lista == NULL || x < lista -> info){ //Si la lsita está vacia o el valor es menor que el que está al principio
		
		p -> sgte = lista; //Pongo el nodo al principio y le digo que el siguiente es que antes estaba en lista
		lista = p; //Actualizo el inicio de la lista
		
	} else {
		q = lista; //A q le doy el valor del inicio de la lista
	
	
	while(q -> sgte != NULL && x > q -> sgte -> info){ //Mientras que no esté en el ultimo elemento de la lista Y el valor sea mayor que el siguiente
		
		q = q -> sgte; //Paso al siguiente nodo	
	}

	//Una vez que llegué al lugar donde tengo que meter mi nuevo nodo
	p -> sgte = q -> sgte; //Al nodo que va a ingresar le pongo como siguiente el nodo que viene despues al que acabo de encontrar
	q -> sgte = p; //AL nodo que acabo de encontrar le asigno como siguiente el nodo nuevo
	
	}
	
	return p; //Por si lo llego a necesitar, retorno el nodo recién creado
}

//Esta función retorna la cantidad de nodos que hay en la lista
int retornaCantidad(nodo* &lista){
	nodo* p = lista;
	nodo* q = NULL;
	int i = 0;
	
	while(p != NULL){ //Voy pasando nodo a nodo hasta llegar al último y voy incrementando un contador
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
		//insertaOrdenado(lista,x);
		buscar_o_insertar(lista, x);
	}
}

void cargaListaUsuario(nodo* &lista){
	
	char b;
	int a = 0;
	
	do{
		cout << "Insertá un valor para la lista: ";
		cin >> a;
		
		//insertaOrdenado(lista, a);
		buscar_o_insertar(lista, a);
		
		cout << "¿Querés seguir metiendo valores? (Y/N): ";
		cin >> b;
		
	}while(b == 'Y' || b == 'y');
}

//Busca y devuelve un nodo en la lista
nodo* buscar(nodo* lista, int valor){
	nodo* p = lista;
	
	while(p != NULL && p -> info < valor){
		p = p -> sgte;
	}
	
	if(p != NULL && p -> info == valor){
		
		return p;
		
	} else {
		
		return NULL;
		
	}
	
}

//Busca el nodo en la lista y si no está, lo inserta
nodo * buscar_o_insertar(nodo* &lista, int valor){
	
	nodo* p = buscar(lista, valor);
	
	if(p == NULL){
		p = insertaOrdenado(lista, valor);
	}
	
	return p;
}

void eliminaNodo(nodo* &lista, int valor){
	
	nodo* p = lista;
	nodo* q = NULL;
	
	while(p != NULL && valor > p -> info){
		
		q = p;
		p = p -> sgte;
	}
	
	if(p != NULL && p -> info == valor){
		if (q == NULL){
			lista = p -> sgte;
		} else {
			q -> sgte = p -> sgte;
		}
		
		delete p;
	}
}


void imprimeLista(nodo* &lista){
	
	nodo* p = lista;
	int i = 0;
	
	while(p != NULL){

		cout << "Posición #" << i+1 <<": " <<  p -> info << endl;
		p = p -> sgte;
		i++;
	}

}

int pop(nodo * &lista){
	
	int valor;
	nodo* pro = lista;
	valor = pro -> info;
	lista = pro -> sgte;
	delete pro;
	return valor;
}

void imprimeListaBien(nodo* &lista){
	
	int cant = retornaCantidad(lista);
	int i = 0;
	for(i = 0; i < cant; i++){
		
		cout << "Posición #" << (i+1) << ": "<<pop(lista) << endl;
	}
}


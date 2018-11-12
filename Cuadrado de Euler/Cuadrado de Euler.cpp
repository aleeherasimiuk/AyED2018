#include <iostream>
using namespace std;

//El siguiente programa simula la creación del cuadrado de Euler
//El algoritmo logra una matriz rellena con números tales que la suma de los componentes de las filas sea igual
//a la suma de los componentes de las columnas, sin repetirse los números, en un cuadrado de n*n posiciones siendo n impar.

//Se ha omitido el uso de funciones debido a la complejidad que acarrea el paso de matrices por parámetros.
int main() {
	
	int n; //Variable que almacena la cantidad de filas y columnas
	
	do{
		cout << "Por favor, ingrese una cantidad impar de filas/columnas: "; //Solicitud de datos, por estética se recomienda el rango [3;9]
		cin >> n;
	}while(n % 2 == 0); //Bucle de validación, solo se termina si el número ingresado en n es impar
	
	
	int matriz[n][n]; //Declaración de matriz n*n
	
	int i = 0;
	for(i; i < n; i++){ //Se completa la matriz con 0
		int j = 0;
		for(j; j < n; j++){
			matriz[i][j] = 0;
		}
	}
	
	
	int punterofilas = 0;
	int punterocolumnas = ((n-1)/2);
	int nuevopunterofilas = 0;
	int nuevopunterocolumnas = 0;
	

	for(i = 1; i <= (n*n); i++){ //Cálculo de los punteros
		
		matriz[punterofilas][punterocolumnas] = i;
		
		if((punterofilas-1) < 0){ // ¿Hay una fila encíma?
			nuevopunterofilas = (n-1); // si no hay filas por encima, el puntero va hacia la última fila
		} else {
			nuevopunterofilas = (punterofilas-1); //Si hay una fila encima, el puntero va hacia arriba
		}
		
		if((punterocolumnas+1) > (n-1)){ // ¿Hay una columna más a la derecha?
			nuevopunterocolumnas = 0; //si no hay columnas a la derecha vuelve a la primera
		} else {
			nuevopunterocolumnas = (punterocolumnas+1); //Si todavía hay columnas a la derecha, el puntero se para en ella
		}
		
		if(matriz[nuevopunterofilas][nuevopunterocolumnas] == 0){ //Si la matriz, en la posición que evaluamos está vacia, se cargan los punteros calculados
			punterofilas = nuevopunterofilas; 
			punterocolumnas = nuevopunterocolumnas;
		} else {
			punterofilas++; //si la posición se encuentra ocupada, se procede a ingresar el siguiente número abajo del número de referencia
		}
	}
	
	for(i = 0; i < n; i++){ //Impresión de matriz
		int j = 0;
		for(j; j < n; j++){
			
			if(matriz[i][j] < 10){
				cout << "[0" << matriz[i][j] << "]"; //Se agrega un 0 para mayor estética
			}else{
				cout << "[" << matriz[i][j] << "]";
			}
			
		}
		cout << endl;
	}
	
	int sumafilas = 0;
	int sumacolumnas = 0;
	
	for(i = 0; i < n; i++){ //Cálculo de las sumas filas y columnas
		int j = 0;
		for(j; j < n; j++){
			sumafilas += matriz[i][j];
			sumacolumnas += matriz[j][i];
		}
	}
	
	cout << "La suma de los componentes de una fila de la matriz es igual a: " << sumafilas << endl;
	cout << "La suma de los componentes de una columnas de la matriz es igual a: " << sumacolumnas << endl;
	

	return 0;
}

#include <iostream>
using namespace std;

//Dados N números enteros positivos y negativos, sumarlos.
//Si la suma es mayor que 0, imprimir los números ingresados en las posiciones pares, caso contrario, las impares.

int main() {
	int pos = 0; //Almacena la cantidad de posiciones del arreglo
	
	//Se pide y guarda la cantidad de posiciones deseadas por el usuario
	cout << "Ingrese la cantidad de números enteros a evaluar: ";
	cin >> pos; 
	
	//Declaración de array de enteros, con pos posiciones.
	int arreglo [pos];
	
	//Solicitud de valores
	int i = 0;
	for(i; i < pos; i++){
		cout << "Por favor ingrese el numero entero para almacenar en la posicion #" << i << ": ";
		cin >> arreglo[i];
	}
	
	int suma = 0; //suma de posiciones
	
	//Ejecución de suma
	i = 0;
	for(i; i < pos; i++){
		suma += arreglo[i]; // suma = suma + arreglo[i]
	}
	cout <<"La suma efectuada da como resultado: " << suma <<endl;
	
	//Análisis de resultado, devolución de valores en posiciones segun condición de suma
	i = 0;
	if(suma >= 0){  //Imprime números almacenamos en posiciones pares si la suma es positiva
		for(i; i<pos; i++){
			if(i%2 == 0){
				cout<< "En la posicion: " << i << " se almaceno el numero: " << arreglo[i] <<endl;
			}
	    }
    } else if(suma < 0) { //Imprime números almacenados en posiciones impares si la suma es negativa
    	for(i; i<pos; i++){
			if(i%2 != 0){
				cout<< "En la posicion: " << i << " se almaceno el numero: " << arreglo[i] <<endl;
			}
    	
	   }
   }
	return 0;
}

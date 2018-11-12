#include <iostream>
using namespace std;
// Ejercicio 1: dado 2 valores enteros diferentes, emitir una leyenda apropiada que informe cual es el mayor

int main() {
	int num1 = 0;
	int num2 = 0;
	
	cout << "Ingrese el primer numero: ";
	cin >> num1;
	
	cout << endl; 
	cout << "Ingrese el segundo numero: ";
	cin  >> num2;
	
	if(num1 > num2){
		cout<< "El numero " << num1 << " es mayor que " << num2 << endl;
		
		} else if(num2>num1){
			
			cout << "El numero " << num2 << " es mayor que " << num1 << endl;
			
		} else{
			
			cout<< "Los numeros ingresados son iguales o incorrectos";
		}
	     
	return 0;
}

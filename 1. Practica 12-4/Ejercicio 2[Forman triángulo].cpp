#include <iostream>
using namespace std;

// Dados 3 valores determinar e imprimir una leyenda segun sea "forman un triangulo" o "no forman un triangulo"

int main() {
	int num1=0;
	int num2=0;
	int num3=0;
	
	cout << "Ingrese el primer lado del triangulo: ";
	cin  >> num1;
	cout << endl;
	
	cout << "Ingrese el segundo lado del triangulo: ";
	cin  >> num2;
	cout << endl;
	
	cout << "Ingrese el tercer lado del triangulo: ";
	cin  >> num3;
	cout << endl;
	
	if((num1 + num2 > num3) && (num1 + num3 > num2) && (num2 + num3 > num1)){
		
		cout<< "Los 3 lados ingresados forman un triangulo.";
		
		}else{
			
		  cout<< "Los 3 lados ingresados NO forman un triangulo.";
	}
	
	return 0;
}

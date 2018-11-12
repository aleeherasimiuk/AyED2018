#include <iostream>
using namespace std;

//Calcular, dada la base y la altura, la superficie y el perímetro de un rectángulo.
//El ciclo debe repetirse hasta que el usuario ingrese una base negativa

void calculo(int base, int altura, int &perimetro, int &superficie);

int main() {
	int base 	   = 0;
	int altura     = 0;
	int superficie = 0;
	int perimetro  = 0;
		cout << "Por favor, ingrese la base del rectangulo: ";
		cin  >> base;
		
	while(base > 0){
	
		cout << "Por favor, ingrese la altura del rectangulo: ";
		cin  >> altura;
		
		calculo(base, altura, perimetro, superficie);
		
		cout << "La superficie del rectangulo es: " << superficie <<endl;
		cout << "El perimetro del rectangulo es: "  << perimetro  <<endl;
		  
		cout << "Por favor, ingrese la base del rectangulo: ";
		cin>>base;
	}
	
	}

 return 0;
}



void calculo(int base, int altura, int &perimetro, int &superficie){
	if(base > 0){
	superficie = base*altura;
	perimetro = ((2*base) + (2*altura));
	} else {
		superficie = -1;
		perimetro = -1;
		
	}
	
	return;
}


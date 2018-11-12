#include <iostream>
using namespace std;

//Se ingresa una edad, mostrar por pantalla alguna de las siguientes leyendas: "menor" _edad <=12; "cadete" _edad >12 y <18; "Juvenil" _edad >=18 y <26 y "mayor" >=26.

int main() {
	
	int edad = 0;
	int bandera = 0;
	
	do{
		
	cout << "Ingrese una edad: ";
	cin  >> edad;
	
	if(edad <= 12){
		cout << "Menor" << endl;
	}
	
	if(edad > 12 && edad < 18){
		cout << "Cadete" << endl;
	}
	
	if(edad >= 18 && edad < 26){
		cout << "Juvenil" << endl;
	}
	
	if(edad >= 26){
		cout << "Mayor" << endl; 
	}
	
	cout<< "Si desea continuar presione 1, si no presione 2" << endl;
	cin>> bandera;
		
	} while(bandera == 1);
	
	cout << "Muchas gracias";
	
	return 0;
}

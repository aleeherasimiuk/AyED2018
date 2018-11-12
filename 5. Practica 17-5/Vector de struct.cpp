#include <iostream>
using namespace std;
//Hacer un struct estudiante (nªlegajo y nota) Y guardar y mostrar n estudiantes en un vector

struct estudiante{
	char nombre [10];
	int numero_legajo;
	int nota;
};

int main() {
	
	int cant_alumnos;
	cout << "Ingrese la cantidad de estudiantes a evaluar: ";
	cin  >> cant_alumnos;
	
	estudiante vector [cant_alumnos];
	
	int i = 0;
	for(i; i<cant_alumnos; i++){
		cout << "Ingrese el nombre del estudiante #" << (i+1) << ": ";
		cin  >> vector[i].nombre;
		
		cout << "Ingrese el legajo de " <<vector[i].nombre << ": ";
		cin  >> vector[i].numero_legajo;
		
		cout << "Ingrese la nota de " <<vector[i].nombre << ": ";
		cin  >> vector[i].nota;
	}
	
	i = 0;
	for(i; i < cant_alumnos; i++){
		cout << "El estudiante " << vector[i].nombre << "(#" << vector[i].numero_legajo << ")"<< " tiene nota: " << vector[i].nota << endl;
	}
	return 0;
}

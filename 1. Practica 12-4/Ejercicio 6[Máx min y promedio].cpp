#include <iostream>
using namespace std;

// Dado un conjunto de N valores, determinar e imprimir, el valor máximo negativo, el valor minimo positivo, el valor minimo dentro del rango 17,3 y 26,9 y el promedio de todos los valores. 
//Se recomienda buscar otra forma de resolver este ejercicio, sobre todo usando float en lugar de double y no inicializar con esos valores.

int main() {
	
	//Pide ingresar la cantidad de valores
	int N = 0;
	cout << "Ingrese la cantidad de valores a evaluar: ";
	cin  >> N;
	
	int i = 0;
	double n_ingresado; //Número ingresado
	//El número minimo ingresable es -1.7976931348623158e+308
	double n_max_neg = -1.7976931348623158e+308; //Número máximo negativo
	//El número máximo ingresable es 1.7976931348623158e+308
	double n_min_pos = 1.7976931348623158e+308; //Numero máximo positivo
	
	double n_min_rango = 27; //Número mínimo en el rango 17.3 y 26.9
	double suma = 0; //Suma de los números ingresados para hacer más tarde el promedio
	
	for(i = 0; i < N; i++){
		cout<<"Ingrese el valor #"<<(i+1) <<": ";
		cin>> n_ingresado;
		
		    //Evalua si el número ingresado es negativo y cumple con ser el mayor negativo:
			if(n_ingresado < 0 && n_ingresado > n_max_neg){ 
				n_max_neg = n_ingresado;
			}
			
			//Evalua si el número ingresado es positivo y cumple con ser el menor positivo:
			if(n_ingresado >= 0 && n_ingresado< n_min_pos){
				n_min_pos = n_ingresado;
			}
			//Evalua si el número ingresado está dentro del rango solicitado y cumple con ser el menor del rango:
			if(n_ingresado >= 17.3 && n_ingresado <= 26.9){
				if(n_ingresado< n_min_rango){
					n_min_rango = n_ingresado;
				}
			}
			
		//Efectúa la suma de los numeros por cada vuelta de bucle
		suma = suma + n_ingresado;
		
	}
	
	//Devolución de resultados
	cout<<"El valor máximo negativo ingresado es: " << n_max_neg <<endl;
	cout<<"El valor mínimo positivo ingresado es: " << n_min_pos <<endl;
	
	//Evalúa si hubo un valor ingresado dentro del rango
	if(n_min_rango !=27){
		cout<<"El valor mínimo en el rango 17.3 y 26.9 es: "<< n_min_rango<<endl;
	}else{
		cout<<"No se ingreso un valor en el rango 17.3 y 26.9";
	}
	
	//Cálculo del promedio
	double promedio = suma/N;
	cout<<"El promedio de los valores ingresados es: "<<promedio;
	
	
	//Finalización de la ejecución.
	return 0;
}

#include <iostream>
using namespace std;

//El siguiente programa pide al usuario tres longitudes de correspondientes a los lados de un triángulo,
//EL programa calculo en principio si forman un triangulo, si es correcto, procede a calcular si es:
//Equilatero, Isosceles, o Escaleno.

//Prototipo de funciónes
int evaluacion (int L1, int L2, int L3);
int tipo (int L1, int L2, int L3);

int main() {
	
	//Declaración de variables.
	int L1 = 0;
	int L2 = 0;
	int L3 = 0;
	
	//Variable de comprobación de triángulo
	int es_triangulo = 0;
	
	//Inserción de datos
	cout << "Ingrese el primer lado del triangulo: ";
	cin>> L1;
    
	cout<< "Ingrese el segundo lado del triangulo: "; 
	cin>> L2;	

	cout<< "Ingrese el tercer lado del triangulo: "; 
	cin>> L3;
	
	//Invocación de funciones
	es_triangulo = evaluacion(L1, L2, L3);
	
	//Evaluación para la ejecución de la segunda función
	if(es_triangulo == 1){ 
		
		cout<< "Los datos ingresados forman un triangulo: "<< endl;
		
		//Devolución de resultados por consola
		if(tipo(L1, L2, L3) == 0){
			    cout << "El triangulo formado es Equilatero";
			}
			else if(tipo(L1, L2, L3) == 1) {
				cout << "El triangulo formado es Escaleno.";
			}
			else if (tipo(L1, L2, L3) == 2){
			    cout << "El triangulo formado es Isosceles.";	
			}
		}
		
	 else {
		cout<< "Los datos ingresados no forman un triangulo";
	}
	
	    //Finalización del programa.
		return 0;
}

//Función que evalúa si los datos ingresados forman un triángulo
//Devuelve 1 si forman un triángulo, en caso contrario devuelve 0
int evaluacion (int L1, int L2, int L3){

	if((L1 + L2 > L3) && (L1 + L3 > L2) && (L2 + L3 > L1)){	
		
		return 1;

		}else{
			
		return 0;
	}
}

//Función que evalúa el típo de triángulo
//Solo se ejecuta si los datos ingresados forman un triángulo (Análisis realizado en Main)
int tipo(int L1, int L2, int L3){
	if((L1 == L2) && (L2 == L3)){ 
	    return 0;
		
		}else if((L1 != L2 && L2!=L3 && L1!=L3)){	
	    return 1;
		
		}else{
		return 2;
		
		}
	

}



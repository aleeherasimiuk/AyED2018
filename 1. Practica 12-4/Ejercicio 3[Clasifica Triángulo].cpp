#include <iostream>
using namespace std;

//Dado un triangulo representado por sus lados L1, L2 y L3 determinar e imprimir una leyenda segun sean equilateros, escalenos o isosceles

int main() {
	
	int L1=0;
	int L2=0;
	int L3=0;
	
	int correcto=0;
	
	cout << "Ingrese el primer lado del triangulo: ";
	cin  >> L1;
    
	cout << "Ingrese el segundo lado del triangulo: "; 
	cin  >> L2;	

	cout << "Ingrese el tercer lado del triangulo: "; 
	cin  >> L3;
	
	if((L1 + L2 > L3) && (L1 + L3 > L2) && (L2 + L3 > L1)){	
		
		correcto = 1;
		
		}else{
			
		  correcto = 2;
	}
		
	if(correcto == 1){
		
		if((L1 == L2) && (L2 == L3)){ 
		
		    cout << "El triangulo formado es Equilatero.";
		
		}else if((L1 != L2 && L2 != L3 && L1 != L3)){
			
	            cout << "El triangulo formado es Escaleno";
		
		} else {
			
		    cout << "El triangulo formado es Isosceles";
		
		}
			
		
		
		
		
		
	 }else{
	 	cout<< "Los datos ingresados no forman un triángulo o no son correctos";
	 }
	 
	return 0;
}

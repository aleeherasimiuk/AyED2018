#include <iostream>
using namespace std;

/*
1. Declarar e inicializar un vector de 36  posiciones con todas las letras y nùmeros del 1 al 9
2. Declarar una matriz de 4 filas y 9 columnas
3. Hacer el prototipo de la funciòn cargaMatriz, tomando como paràmetros el vector y la matriz
4. Desarrollar la funciòn cargaMatriz
5. Desarrollar la funciòn encriptar(), que reciba la matriz con los caracteres y permita encriptar una palabra de un màximo de 10 caracteres,
   cada uno de los caracteres son el par ordenado que corresponde a la fila/columna de la matriz y debe ser guardado en un vector

*/
struct palabraEncriptada{

	int f;	
	int c;	
};

void cargarMatriz(char V[],char M[][9]);
void encriptar(char M[][9], palabraEncriptada L[], char palabra[]);
palabraEncriptada buscarEnMatriz(char M[][9], char N);
void mostrar(palabraEncriptada PE[]);


int main() {
	
	char vector[36]={'a','s', 'd','f', 'g','h', 'j','k', 'l','ñ', '1','2', 'z','x', 'c','v', 'b','n', 'm','3', '4','q', 'w','e', 'r','t', 'y','u', 'i','o', 'p','6', '7','8', '9','0'};
	char matriz[4][9];
	
	cargarMatriz(vector, matriz);
		
	char palabra[10];
	cout<< "ingrese una palabra: ";
	cin>> palabra;
	 
	palabraEncriptada palabrayaencriptada[10];
	
	encriptar(matriz, palabrayaencriptada, palabra);
	
	mostrar(palabrayaencriptada);
	
	
	
	return 0;
}

void cargarMatriz(char V[],char M[][9]){
	
	
	int  k = 0 , i = 0 , j = 0;
	
		for(i; i < 9; i++){
		
			for(j = 0; j < 4; j++){
		
				M[j][i] = V[k];
				k++;
		}
	}	
	
	return;
}



void encriptar(char M[][9], palabraEncriptada L[], char palabra[]){
	
	int i = 0;
	while(palabra[i] != '\0'){
		
		L[i] = buscarEnMatriz(M , palabra[i]);
		i++;
	}	
	return;
}


palabraEncriptada buscarEnMatriz(char M[][9], char N){
	
	
	
	int i = 0 , j = 0;
	
		for(i; i < 9; i++){
		
			for(j = 0; j < 4; j++){
		
			if(M[j][i] == N){
				
				palabraEncriptada registro;
				
				registro.f = j;
				registro.c = i;
				 
				 return registro;
			}
			
		}
	}	
	
}


void mostrar(palabraEncriptada PE[]){
	 
	 int i=0;
	 
	 
	for(i; i < 10; i++){
		
		cout<< PE[i].f << PE[i].c;
	}
	
	
	
	return;
}


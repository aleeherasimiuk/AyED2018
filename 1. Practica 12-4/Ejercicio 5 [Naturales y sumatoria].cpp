#include <iostream>
using namespace std;

// Informar los primeros 100 numeros naturales y su sumatoria

int main() {

    int i = 0;
    int suma = 0;
    
	cout<< "Los siguientes son los primeros 100 numeros naturales: "<< endl;
	
	for(i = 1; i <= 100 ;i++){
		cout << i << ", ";
		suma = suma + i;
	}
	cout << endl;
	cout << "La suma de los 100 numeros naturales es: " << suma ;
	
	return 0;
}

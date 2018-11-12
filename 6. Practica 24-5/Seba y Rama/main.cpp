#include <iostream>
using namespace std;
struct EST{
	int cv=0;
	float tn=0;
};

EST TR[5];
int i = 0;
int ciudad = 0;
int posicion = 0;
float tn = 0;
float aux = 0;

int main(void) {
	
	cout << "Ingrese nro de ciudad: " <<endl;
	cin  >> ciudad;
	while (ciudad>0 && ciudad<=5){
		cout<<"Ingrese toneladas: "<<endl;
		cin>>tn;
		posicion = ciudad - 1;
		TR[posicion].cv ++;
		TR[posicion].tn += tn;
		cout<<"Ingrese nro de ciudad: " <<endl;
		cin>>ciudad;
		
		
	}
	for (i=0;i<5;i++){
		
		if(TR[i].cv==0){
			cout<<"No se realizaron viaje a la ciudad " << i+1<< endl; }
			else{
			
		
		cout<<"Nro de Ciudad: "<<i+1<<endl;
 		cout<<"Cantidad de viajes: " << TR[i].cv << endl;
		cout<<"Cantidad de toneladas: " << TR[i].tn<< endl;
		
			if (TR[i].cv>0){
			aux= TR[i].tn/TR[i].cv;
			cout<<"Promedio de toneladas llevados en los viajes por ciudad: " <<aux<<endl;			
		}
		}
		cout<<endl;		
	}
	return 0;
}

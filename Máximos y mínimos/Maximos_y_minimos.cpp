#include <iostream>
#include <cstring>
using namespace std;


int main() {
	
	//Variables para determinar la condición del bucle FOR
	int cant_equipos = 0;
	int cant_partidos = 0;
	
	//Almacenamiento en memoria de los nombres de los equipos
	char nombre[10] = "";
	char peor[10] = "";
	char mejor[10] = "";
	
	//Contabilización de puntajes y equipos perdedores
	int peores = 0;
	int p_mayor = 0;
	int p_menor = 0;
	
	//Solicitud de datos
	cout << "Por favor, ingrese la cantidad de equipos que disputarán el torneo: ";
	cin >> cant_equipos;
	
	cant_partidos = (cant_equipos - 1);
	
	//Inserción de datos
	int i = 0;
	for (i; i<cant_equipos; i++){
		cout << "Ingrese el nombre del equipo #" << (i+1) << ": ";
		cin >>nombre;
		
		//Variable local: Puntaje
		int p = 0;
		
		//Solicitud de datos
		cout << "Por favor ingrese los resultados del equipo." <<endl;
		cout << "G -> Ganado" << endl <<"P -> Perdido" <<endl <<"E -> Empatado" <<endl <<"Use letras mayusculas" <<endl;
		
		int j = 0;
		for(j; j < cant_partidos; j++){
			
			//Variable local: resultado del partido
			char r[1];
			char ganado[] = "G";
			char empatado[] = "E";
			
			cout << "Ingrese el resultado del partido #" << (j+1) << ": ";
			cin >> r;
			
			//Contablización de puntajes

			if(strcmp(r, ganado)== 0){//Tres puntos por partido ganado
				p += 3;
				
			} else if(strcmp(r, empatado)== 0){ //Un punto por partido empatado
				p += 1;
				
			} //Si el partido está perdido, o se ingresa otro valor distinto de 'P', no se contabilizará ningun puntaje
			
			}
			//Definición de resultados
			if(i == 0 || p > p_mayor){
				strcpy(mejor, nombre); //Se almacena en "mejor" el nombre del mejor equipo al momento de la evaluación
				p_mayor = p; //se almacena el mejor puntaje al momento de la evqluación
			}
			
			if (i == 0 || p <= p_menor){
				
				if(i == 0 || p < p_menor){
					peores = 0; //Se resetea la cantidad de equipos en último lugar
					strcpy(peor, nombre); //Se almacena el nombre del equipo que va en último lugar
					p_menor = p; //Se almacena el peor puntaje
				}
				
				if(i== 0 || p == p_menor){ //Contablilización de equipos en último lugar (Si hay más de uno)
					peores ++;
				}
				
				
			}
			cout <<endl;
			
		}
		//Impresión de resultados
		cout << "El equipo ganador del torneo es: " << mejor <<" con " << p_mayor <<" puntos."<<endl;
		
		if(peores == 0){
			cout << "El equipo con menor puntaje fue: " << peor << " con " << p_menor << " puntos.";
		} else {
			cout << "En ultimo lugar quedaron " << peores << " equipos, con un puntaje de:  " << p_menor;
		}
		return 0;
	}
	
	


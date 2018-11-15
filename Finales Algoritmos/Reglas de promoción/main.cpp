#include <iostream>
using namespace std;

//Temas evaluados: Comprensión de situación problemática, funciones, estructuras de datos enlazadas y contiguas, flujos y archivos.


/////////////////////Punto 1/////////////////////
struct nota{
	int datos;
	nota* sgte;
};

struct evaluacion{
	
	nota* evaluacion;  //El enunciado dice LISTA, usaré pilas, sino no hay otra forma
	evaluacion* sgte;
	
};

struct estudiante{
	int id;
	evaluacion evaluaciones[4];
	estudiante* sgte;
	
};
struct curso{
	
	int id;
	int promocionados;
	int regularizados
	int recursantes
	estudiante* estudiantes;
	curso* sgte;
	
};

int main(){
	
	curso* cursos = NULL;
	
	return 0;
}
///////////////////////////////////////////////////////////

//////////////////////////////Punto 2/////////////////////

struct TR{				//Registro necesario para leer los archivos
	int id_curso;
	int id_estudiante;
	int parcial;
	int nota;
};

void ProcesarNovedades(char nombreDeArchivo[], curso* &cursos){
	
	TR novedad;
	FILE* f = fopen(nombreDeArchivo, "rb");
	
	if(f == NULL){
		cout << "No existe archivo" << endl;
	} else {
		while(!feof(f)){
			fread(novedad, sizeof(TR), 1, f);
			
			int curso		= novedad -> id_curso;
			int estudiante	= novedad -> id_estudiante;
			int parcial		= novedad -> id_parcial
			int nota		= novedad -> nota;
			
			AgregarNota(cursos, curso, estudiante, parcial, nota);
			
		}
	}
}

void AgregarNota(curso* &cursos, int curso, int estudiante, int parcial, int nota){
	
	curso* cursoBuscado = buscar(cursos, curso);						//Busco el curso
	estudiante estBuscado = buscar(cursoBuscado, estudiante);			//Busco el estudiante dentro del curso
	
	evaluacion* evaluacionBuscada = estBuscado.evaluaciones[parcial];	//Busco los parciales de cada estudiante
	push(evaluacionBuscada, nota);										//Ingreso en la pila la nota.
	
	//Justificación:
	/*
	Se decide usar la pila para resolver el problema ya que la lista debe estar ordenada, y no tenemos criterio para hacerlo
	por lo tanto se utiliza la pila, ya que solo le damos importancia al ultimo parcial dado, es decir, al ultimo elemento ingresado en la pila
	*/
}

void CalcularEstadisticas(curso* &cursos){
	
	
	curso* p = cursos;
	while(p != NULL){
	
		estudiante* q = p -> estudiantes;
		while(q != NULL){
			
			if(getEstado(q -> evaluaciones) == 1){
				p -> promocionados++;
			} else if(getEstado(q -> evaluaciones == 2)){
				p -> regularizados++;
			} else if(getEstado(q -> evaluaciones == 3)){
				p -> recursantes++;
			}
			
			q = q -> sgte;
		}
		p = p -> sgte;
	}
}

///////////////////////////////////////////////////////////////////////////

//////////////////Punto extra////////////////

int getEstado(evaluacion evaluaciones[]){
	
	int i = 0;
	int notas[4];
	for(i; i < 4; i++){
		notas[i] = pop(evaluaciones[i]);
	}
	
	if(notas[0] > 6 && notas[1] > 6 & notas[2] > 6 && notas[3] > 6){
		if(notas[0] > 8 && notas[1] > 8 & notas[2] > 8 && notas[3] > 8){
			return 1;
		} else {
			return 2;
		}
	} else {
		return 3;
	}
	
}






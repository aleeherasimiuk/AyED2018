/*
 ============================================================================
 Name        : Pascuas_C.c
 Author      : 
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Función Principal
int main(void) {
	//Declaro variables
	int a, b, c, d, e;
	//Declaro constantes
	int M, N;
	//Variables para almacenar datos ingresados
	int agnoingresado;
	char agno[4];
	int bandera = 0;

	//Impresión en pantalla bienvenida
	printf("Bienvenido al sistema de cálculo de fecha de Pascuas\n");
	printf("El sistema le permitirá saber el día en el que cae el domingo de pascuas según el año ingresado\n");

	//Bucle do-while ejecutará el programa las veces que el usuario desee
	do {

		//Bucle do-while se ejecuta hasta que el dato ingresado sea correcto
		do {
			printf("Por favor ingrese un año comprendido entre 1583 y 2299: ");
			scanf("%s", &agno);
			agnoingresado = atoi(agno);

		} while (agnoingresado <= 1583 || agnoingresado >= 2299);

		//Cálculo
		a = agnoingresado % 19;
		b = agnoingresado % 4;
		c = agnoingresado % 7;

		//Cálculo constantes de gauss
		if (agnoingresado >= 1583 && agnoingresado <= 1699) {
			M = 22;
			N = 2;
		} else if (agnoingresado >= 1700 && agnoingresado <= 1799) {
			M = 23;
			N = 3;
		} else if (agnoingresado >= 1800 && agnoingresado <= 1899) {
			M = 23;
			N = 4;
		} else if (agnoingresado >= 1900 && agnoingresado <= 2099) {
			M = 24;
			N = 5;
		} else if (agnoingresado >= 2100 && agnoingresado <= 2199) {
			M = 24;
			N = 6;
		} else if (agnoingresado >= 2200 && agnoingresado <= 2299) {
			M = 25;
			N = 0;
		}

		//Cálculo
		d = ((19 * a + M) % 30);
		e = ((2 * b + 4 * c + 6 * d + N) % 7);


		//Cálculo de resultados
		if ((d + e) < 10) {
			//Impresión Marzo
			printf("El día de pascuas en el año: %d", agnoingresado);
			printf("caerá el día: %d", (d + e + 22));
			printf(" de Marzo\n");

		} else if ((d + e) > 9) {

			int diadepascuas;
			diadepascuas = (d + e - 9);

			if (diadepascuas == 26) {
				diadepascuas = 19;
			}
			if (diadepascuas == 25 && d == 28 && e == 6 && a > 10) {
				diadepascuas = 18;

			}
			//Impresión abril
			if (diadepascuas < 10) {
				printf("El día de pascuas en el año: %d", agnoingresado);
			    printf(" caerá el día: %d", diadepascuas);
			    printf(" de abril  ");
				printf("04/");
				printf("0");
				printf("%d", diadepascuas);
				printf("\n");
			} else {
				printf("El día de pascuas en el año: %d", agnoingresado);
				printf(" caerá el día: %d", diadepascuas);
				printf(" de abril ");
				printf("04/%d", diadepascuas);
				printf("\n");
			}
		}

		//Bucle do-while, consulta al usuario si desea seguir ejecutando
		char band;
		do {
			printf(
					"Por favor seleccione 1 si desea volver a comenzar, seleccione la opción 2 para terminar: ");
			scanf("%d", &bandera);
		} while (bandera != 1 && bandera != 2);

	} while (bandera == 1);

	//Finalización del programa
	printf(
			"Gracias por usar el programa de cálculo de días de pascuas. Vuelva pronto!");

	return 0;
}

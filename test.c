#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 50
#define EXIT 5

/*	Colas. Representar e implementar una Cola de 100 ítems de
	cualesquiera de las estructuras presentadas mas conveniente
	para el caso, incluyendo las funciones: insertar, remover,
	cantidad de elementos, cola vacía, cola llena, se debe utilizar
	arreglos.	*/

struct vehiculo
{
	char placa[8];
	char marca[100];
	char modelo[100];
	int year;
	enum {MOTO = 1, AUTO = 2, CAMION = 3, BUS = 4} c_tipo;
} _vehiculo[MAX];

int cont = -1;
int first = -1;

void insertar();
void cantidad_cola();
void remover();
bool cola_vacia();
bool cola_llena();
void elementos(); 

int main(int argc, char const *argv[])
{
		int opcion;
		
		do
		{
			printf("Presione '1' para insertar un elemento a la cola\n");
			printf("Presione '2' para ver la cantidad de elementos de la cola\n");
			printf("Presione '3' para remover de elementos de la cola\n");
			printf("Presione '4' para ver los elementos en cola\n");
			printf("Presione '5' para salir\n");
			scanf("%d", &opcion);
			fflush(stdin);

			switch(opcion)
			{
				case 1:	insertar();
						break;

				case 2:	cantidad_cola();
						break;

				case 3:	remover();
						printf("Elemento removido\n");
						break;

				case 4:	elementos();
						break;

				case 5:	return 0;

				default: printf("Opcion invalida, intentarlo nuevamente\n");
						break;
			}	

		} while(opcion != EXIT);


		return 0;
}

void insertar()
	{
		int type;

		if(cola_llena() != true)
		{
			++cont;
			printf("Placa del vehiculo:\n");
			fgets(_vehiculo[cont].placa, 8, stdin);
			fflush(stdin);

			printf("Marca del vehiculo: \n");
			fgets(_vehiculo[cont].marca, 8, stdin);
			fflush(stdin);

			printf("Modelo del vehiculo: \n");
			fgets(_vehiculo[cont].modelo, 8, stdin);
			fflush(stdin);

			printf("Escoja uno de los siguientes tipos de vehiculos\n"); 
			printf("Presione '1' para una moto\nPresione '2' para un auto\n");
			printf("Presione '3' para una camion\nPresione '4' para un bus\n");
			scanf("%d", &type);
			_vehiculo[cont].c_tipo = type;

			printf("Anio del vehiculo: \n");
			scanf("%4d", &_vehiculo[cont].year);
			fflush(stdin);
			system("cls");
		}
		else
			printf("Cola llena, no se puede insertar mas elementos\n");
	}

void cantidad_cola()
	{
		printf("Hay %d elementos\n", cont);
	}

void elementos()
	{
		for (int i = 0; i <= cont; ++i)
		{
			printf("%s\n", _vehiculo[i].placa);		
			printf("%s\n", _vehiculo[i].marca);
			printf("%s\n", _vehiculo[i].modelo);
			printf("%d\n", _vehiculo[i].c_tipo);
			printf("%d\n", _vehiculo[i].year);
			putchar('\n');
		}
	}

bool cola_vacia()
	{
		if(cont == -1)
		{
			return true;
		}
		return false;
	}

bool cola_llena()
	{
		if(cont >= MAX)
		{
			return true;
		}
		return false;
	}

void remover()
	{

		if(first == MAX)
		{
			first = 0;
		}
		if(cola_vacia() != true)
		{
			cont--;
		}
	}
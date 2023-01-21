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
int cant_elementos_cola = 0;

// Prototipos de fuciones

void insertar();

int cantidad_cola();

bool remover();
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
						system("cls");
						break;

				case 2:	printf("%d elementos en cola\n", cantidad_cola());
						break;

				case 3:	if(remover() != false)
						{
							printf("Elemento removido\n");
						}	
						else	
						{
							printf("No hay elementos para remover\n");
						}
						break;

				case 4:	elementos();
						break;

				case 5: return 0;
						break;

				default: printf("Opcion invalida, intentarlo nuevamente\n");
						break;
			}	

		} while(opcion != EXIT);


		return 0;
}

/****************************************************************************
*	insertar():	Permite insertar los elementos en formato de cola en caso	*
*				de que cola_llena() retorne true, en caso contrario,		*
*				desplegara una advertencia de que no se ha podido insertar	*
*				el nuevo elemento en cola.									*
*****************************************************************************/

void insertar()
	{
		if(cola_llena() != true)
		{
			++cont;
			++cant_elementos_cola;

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
			scanf("%d", &_vehiculo[cont].c_tipo);			

			printf("Anio del vehiculo: \n");
			scanf("%4d", &_vehiculo[cont].year);
			fflush(stdin);
		}
		else
			printf("Cola llena, no se puede insertar mas elementos\n");
	}

/****************************************************************************
*	cantidad_cola():	Retorna la cantidad de elementos en cola que posea 	*
*					 	la struct _vehiculo[] actualmente.					*
*****************************************************************************/

int cantidad_cola()
	{
		return cant_elementos_cola;
	}

// Funcion temporal para verificar que se pudo borrar en formato cola la informacion.

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

/****************************************************************************
*	cola_vacia():	En caso de no existir elementos en cola, retornara true	*
*				  	para evitar un Underflow en la ejecucion del programa.	*
*****************************************************************************/

bool cola_vacia()
	{
		if(cant_elementos_cola == 0)
		{
			return true;
		}
		return false;
	}

/****************************************************************************
*	cola_llena():	En caso de sobrepasar la cantidad de elementos 			*
*				  	permitidos en cola, retornara true para evitar un  		*
*				  	Overflow en la ejecucion del programa. 					*
*****************************************************************************/

bool cola_llena()
	{
		if(cant_elementos_cola >= MAX)
		{
			return true;
		}
		return false;
	}

/****************************************************************************
*	remover():	Permite eliminar un elemento usando el metodo de  colas, 	*
*				retornando true en caso de que se concrete exitosamente la	*
*				accion.														*
*****************************************************************************/

bool remover()
	{
		if(cola_vacia() == false)
		{
			for (int i = 0; i < cont; i++)
			{
				strcpy(_vehiculo[i].placa, _vehiculo[i + 1].placa);
				strcpy(_vehiculo[i].modelo, _vehiculo[i + 1].modelo);
				strcpy(_vehiculo[i].marca, _vehiculo[i + 1].marca);
				_vehiculo[i].year = _vehiculo[i + 1].year;
				_vehiculo[i].c_tipo = _vehiculo[i + 1].c_tipo;
			}
			--cant_elementos_cola;
			--cont;
			return true;
		}
		else
			return false;
	}
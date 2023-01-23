
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

/* Propósito del programa

	Llevar registro de los vehiculos que llegan a un taller mecánico para ser reparados,
	de manera que los primeros vehiculos en llegar serán los primeros en ser atendidos,
	para que luego de su reparación el primero en cola sea removido
	y el siguiente elemento tome el primer lugar en a cola para que sea reparado y
	así continuar la cola.
	
 */



int i=0;
bool check= false;
char tipos[4][6]={"Moto","Auto","Bus","Camion"};

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
			printf("//-------------------REPARACIONES UNKNOWN.C.A-------------------//\n\n\n");   
			printf("- Presione '1' para insertar un vehiculo a la cola\n");
			printf("- Presione '2' para ver la cantidad de vehiculos a reparar\n");
			printf("- Presione '3' para avanzar la cola\n");
			printf("- Presione '4' para ver los vehiculos en cola\n");
			printf("- Presione '5' para salir\n");
			printf("\n\n//:");
			scanf("%d", &opcion);
			fflush(stdin);

			switch(opcion)
			{
				case 1:	system("cls");
						insertar();
						system("cls");
						break;

				case 2:	if (cantidad_cola()>1){
						printf("\n%d Vehiculos en cola\n", cantidad_cola());
						sleep(2);
						system("cls");
						}
						else if(cola_vacia()){
						
							printf("No hay vehiculos a reparar.\n");
							sleep(2);
							system("cls");
						}
						else{
							printf("\n1 Vehiculo en cola\n");
						}
						break;
						
				case 3:	if(remover() != false)
						{
							printf("Vehiculo reparado y entregado al cliente.\n");
							sleep(2);
							system("cls");
						}	
						else	
						{
							printf("No hay vehiculos a reparar.\n");
							sleep(2);
							system("cls");
						}
						break;

				case 4:	system("cls");
						if (!cola_vacia()){
						elementos();
						}
					
						else{
							printf("No hay vehiculos en cola.\n");	
							}					
						system("pause");
						system("cls");
						break;

				case 5: return 0;
						break;

				default: printf("Opcion invalida, intentarlo nuevamente\n");
						sleep(2);
						system("cls");
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
			check=false;
			++cont;
			++cant_elementos_cola;

			printf("\n- Placa del vehiculo:\n");
			fgets(_vehiculo[cont].placa, 8, stdin);
			fflush(stdin);
			
			while(strlen(_vehiculo[cont].placa) == 1)
			{
				printf("- Ingrese una placa correcta:\n");
				fgets(_vehiculo[cont].placa, 8, stdin);		
				fflush(stdin);
			}
		
			printf("- Marca del vehiculo: \n");
			fgets(_vehiculo[cont].marca, 100, stdin);
			fflush(stdin);

			while(strlen(_vehiculo[cont].marca) == 1)
			{
				printf("Ingrese una marca correcta:\n");
				fgets(_vehiculo[cont].marca, 100, stdin);		
				fflush(stdin);				
			}	

			printf("- Modelo del vehiculo: \n");
			fgets(_vehiculo[cont].modelo, 100, stdin);
			fflush(stdin);

			while(strlen(_vehiculo[cont].modelo) == 1)
			{
				printf("Ingrese un modelo de vehiculo correcto:\n");
				fgets(_vehiculo[cont].modelo, 100, stdin);		
				fflush(stdin);				
			}

			do{printf("\n\nEscoja uno de los siguientes tipos de vehiculos\n"); 
				printf("- Presione '1' para una moto\n- Presione '2' para un auto\n");
				printf("- Presione '3' para una camion\n- Presione '4' para un bus\n");
				scanf("%d", &_vehiculo[cont].c_tipo);
				fflush(stdin);
				if ((_vehiculo[cont].c_tipo>4)||(_vehiculo[cont].c_tipo<1)){
					printf("\nOpcion invalida, vuelva a intentarlo\n\n");
				}	
				else{
					check=true;
				}
			}while(!check);
						

			printf("- A%co del vehiculo: \n", 164);
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
			for (i=0;i<=cont;++i)
				
			{
				printf("//---------------------------------//\n");
				printf("Placa: %s\n", _vehiculo[i].placa);		
				printf("Marca: %s\n", _vehiculo[i].marca);
				printf("Modelo: %s\n", _vehiculo[i].modelo);
				printf("Tipo: %s\n", tipos[_vehiculo[i].c_tipo-1]);
				printf("A%co: %d\n", 164, _vehiculo[i].year);
				printf("\n");
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
			for (i = 0; i < cant_elementos_cola; i++)
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


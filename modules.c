/*
4. El proceso para seleccionar productos, cargar el carrito y realizar la compra solo puede durar
un máximo de 10 minutos, cuando falten 2 minutos mostrar advertencia para realizar la compra o el 
istema lo enviará al final de la cola y le dará la oportunidad al siguiente cliente en espera.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

void *Subprocess();

int main(void)
{
	int a;

	// Hacemos uso de un hilo del procesador
	pthread_t thread1;
	pthread_create(&thread1, NULL, Subprocess, NULL);
//	pthread_join(thread1, NULL);

	while (1)
	{
		printf("Pon un numero: \n");
		scanf("%d", &a);
		fflush(stdin);
	} 

  	return 0;
}

// Contador
void *Subprocess()
	{
		int sec = 0;
		struct timespec tiempo = { 1, 0 };

		while(1) 
		{
			sec++;
			// Ejecuta el proceso cada 1 segundo.
			pthread_delay_np(&tiempo);

			if(sec % 10 == 0)
			{
				// Piensa en una forma mas optima :/
				exit(1);
			}

			printf("%d\n", sec);
		}

		return NULL;
	}
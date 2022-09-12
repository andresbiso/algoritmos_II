// https://www.onlinegdb.com/

/*
# Tp Integrador - Grafos
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int menu_option;

	printf("Bienvenido!\n");
	printf("-----------\n\n");

	do
	{
		printf("Menú Principal\n");
		printf("1-Agregar Nodo\n");
		printf("2-Agregar Arista\n");
		printf("3-Quitar Nodo\n");
		printf("4-Quitar Arista\n");
		printf("5-Verificar conexo\n");
		printf("6-Verificar euleriano\n");
		printf("7-Imprimir Grafo\n");
		printf("8-Iniciar Grafo\n");
		printf("20-Save and quit.\n");
		printf("Ingrese una opción:");
		scanf("%d", &menu_option);

		switch (menu_option)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 20:
				break;
			default:
				printf("Opción Inválida \n");
				printf("Presione [Enter] para continuar \n");
				do {
				    getchar();
				} while(getchar()!='\n');
				break;
		}

	} while (menu_option != 20);

	return 0;
}

/*
1) Quitar nodo
2) Quitar arista
3) Agregar nodo
4) Agregar Arista
5) Verificar si es euleriano
5.1 verificar con Teorema para verificar si un grafo es conexo de la clase 29/08
Obtner la matríx de adyacencia
https://www.javatpoint.com/matrix-multiplication-in-c
https://www.geeksforgeeks.org/convert-adjacency-list-to-adjacency-matrix-representation-of-a-graph/

5.2 Obtener A^2, A^3,...A^n-1 siendo N el número de vértices del grafo
5.3 Sumar las matrices y verificar si dio 0 fuera de la diagonal principal. Si ese es el caso se dice que no es conexo.


luego verificar que todos los vertices sean pares o que haya como máximo 2 vértices impares
*/

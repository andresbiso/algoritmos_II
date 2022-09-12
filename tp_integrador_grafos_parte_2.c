// https://www.onlinegdb.com/

/*
# Tp Integrador - Grafos
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char menu_option, initials;
	int difficulty;

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
				printf("Opción Inválida.");
				break;
		}

	} while (menu_option != 20);

	return 0;
}

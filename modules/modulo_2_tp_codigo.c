// https://www.onlinegdb.com/

/*
1)
Desarrollar un algoritmo y luego codificarlo en C que permite consultar si entre dos vértices existe una arista de un grafo utilizando la matriz de incidencia.
*/

#include <stdio.h>

int main() {
	int filas, columnas, i, j;
	printf("Ingrese la cantidad de filas de la matriz de incidencia:\n");
	scanf("%d", &filas);
	
	printf("Ingrese la cantidad de columnas de la matriz de incidencia:\n");
	scanf("%d", &columnas);

	int mat[filas][columnas];

	printf("Ingresar valores de la matriz:\n");

	for(i = 0; i < filas ; i++) {
		for(j = 0; j < columnas; j++) {
			int fila = i + 1;
			int columna = j + 1;
			printf("Ingresar valor %d x %d:\n", fila, columna);
			scanf("%d", &mat[i][j]);	
		}
	}
	
	printf("\nLa matriz es:\n");
	for(i = 0; i < filas ; i++)
	{
		for(j = 0; j < columnas; j++)
		{
			printf("%d", mat[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	int verticeOrigen = 0;
	int verticeDestino = 0;
	
	printf("Ingrese vértice origen (o 0 para finalizar):\n");
	scanf("%d", &verticeOrigen);
	
	if (verticeOrigen > 0) {
		printf("Ingrese vértice destino (o 0 para finalizar):\n");
		scanf("%d", &verticeDestino);
	}

	while(verticeOrigen > 0 && verticeDestino > 0) {
		
		int encontroValor = 0;
		for(j = 0; j < columnas; j++)
		{
			encontroValor = mat[verticeOrigen - 1][j] == mat[verticeDestino - 1][j];
			// Si ambos vértices para una arista tienen valor en 1
			if (encontroValor) {
				int arista = j + 1;
				printf("La arista %d une los vértices %d y %d\n", arista, verticeOrigen, verticeDestino);
			}
		}
		
		if (!encontroValor) {
			printf("No existe una arista entre los vértices %d y %d\n", verticeOrigen, verticeDestino);
		}

		printf("Ingrese vértice origen (o 0 para finalizar):\n");
		scanf("%d", &verticeOrigen);
		
		if (verticeOrigen > 0) {
			printf("Ingrese vértice destino (o 0 para finalizar):\n");
			scanf("%d", &verticeDestino);
		}
	}
	
    return 0;
}

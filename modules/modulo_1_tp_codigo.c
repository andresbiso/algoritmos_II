// https://www.onlinegdb.com/

/*
10)
Desarrollar un algoritmo y luego codificarlo en C que permite mostrar el número de vértices y aristas que tiene un grafo utilizando la matriz de adyacencia.
*/

#include <stdio.h>

int main() {
	int filas, i, j;
	printf("Ingrese la cantidad de filas de la matriz de adyacencia:\n");
	scanf("%d", &filas);

	int mat[filas][filas];

	printf("Ingresar valores de la matriz:\n");

	for(i = 0; i < filas ; i++) {
		for(j = 0; j < filas; j++) {
			int fila = i + 1;
			int columna = j + 1;
			printf("Ingresar valor %d x %d:\n", fila, columna);
			scanf("%d", &mat[i][j]);	
		}
	}
	
	printf("\nLa matriz es:\n");
	for(i = 0; i < filas ; i++)
	{
		for(j = 0; j < filas; j++)
		{
			printf("%d",mat[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	int gradoVertices = 0;
	
	for(i = 0; i < filas; i++)
	{
		int gradoVertice = 0;
		int vertice = i + 1;
		for(j = 0; j < filas; j++)
		{
			gradoVertice = gradoVertice + mat[j][i];
		}
		gradoVertices = gradoVertices + gradoVertice;
	}
	
	// Lema del apretón de manos
	int aristas = gradoVertices / 2;
	
	printf("El número de vértices es: %d\n", filas);
	printf("El número de aristas es: %d\n", aristas);
	
    return 0;
}

/*
11)
Desarrollar un algoritmo y luego codificarlo en C que permite mostrar el grado de cada vértice de un grafo utilizando la matriz de adyacencia.
*/

#include <stdio.h>

int main() {
	int filas, i, j;
	printf("Ingrese la cantidad de filas de la matriz de adyacencia:\n");
	scanf("%d", &filas);

	int mat[filas][filas];

	printf("Ingresar valores de la matriz:\n");

	for(i = 0; i < filas ; i++) {
		for(j = 0; j < filas; j++) {
			int fila = i + 1;
			int columna = j + 1;
			printf("Ingresar valor %d x %d:\n", fila, columna);
			scanf("%d", &mat[i][j]);	
		}
	}
	
	printf("\nLa matriz es:\n");
	for(i = 0; i < filas ; i++)
	{
		for(j = 0; j < filas; j++)
		{
			printf("%d",mat[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	int gradoVertices = 0;
	
	for(i = 0; i < filas; i++)
	{
		int gradoVertice = 0;
		int vertice = i + 1;
		for(j = 0; j < filas; j++)
		{
			gradoVertice = gradoVertice + mat[j][i];
		}
		printf("Grado del vértice %d es: %d\n", vertice, gradoVertice);
		gradoVertices = gradoVertices + gradoVertice;
	}
	
	printf("La sumatoria del grado de los vértices es: %d\n", gradoVertices);
	
    return 0;
}

/*
12)
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

/*
13)
Desarrollar un algoritmo y luego codificarlo en C que dado un grafo dirigido A calcule la transpuesta de la matriz de adyacencia de A. ¿Qué información nos brinda la matriz transpuesta?
*/

/*
14)
Desarrollar un algoritmo y luego codificarlo en C que dada la matriz de incidencia de un grafo A, calcule A.At.¿Que representan los elementos de esa matriz producto?
*/

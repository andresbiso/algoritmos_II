// ejemplo en clase
#include <stdio.h>

void cargar(int a[][10], int dim){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf("ingrese un valor");
            scanf("%d",&a[i][j]);
        }
    }
}

void mostrar(int a[][10], int dim){
    int i,j;
    for(i=0;i<dim;i++){
        printf("\n");
        for(j=0;j<dim;j++){
            printf("%d \t",a[i][j]);
            }
    }
}



int main() {
   int mat[10][10], dim;
   printf("ingrese cant de filas");
   scanf("%d",&dim);
   cargar(mat,dim);
   mostrar(mat,dim);
    return 0;
}

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
	
	printf("Ingrese vértice destino (o 0 para finalizar):\n");
	scanf("%d", &verticeDestino);
	
	while(verticeOrigen > 0 && verticeDestino > 0) {
		
		for(i = 0; i < filas ; i++)
		{
			for(j = 0; j < columnas; j++)
			{
				printf("%d", mat[i][j]);
				printf("\t");
			}
			printf("\n");
		}
		
		
		int valorIncidencia = mat[verticeOrigen - 1][verticeDestino - 1];
		
		if (valorIncidencia == 1) {
			printf("Existe una arista entre los vértices %d y %d\n", verticeOrigen, verticeDestino);
		} else {
			printf("No existe una arista entre los vértices %d y %d\n", verticeOrigen, verticeDestino);
		}
		
		printf("Ingrese vértice origen (o 0 para finalizar):\n");
		scanf("%d", &verticeOrigen);
		
		printf("Ingrese vértice destino (o 0 para finalizar):\n");
		scanf("%d", &verticeDestino);
	}
	
    return 0;
}

/*
13)
Desarrollar un algoritmo y luego codificarlo en C que dado un grafo dirigido A calcule la transpuesta de la matriz de adyacencia de A. ¿Quéinformación nos brinda la matriz transpuesta?
*/

/*
14)
Desarrollar un algoritmo y luego codificarlo en C quedada la matriz de incidencia de un grafo A, calcule A.At.¿Que representan los elementos de esa matriz producto?
*/
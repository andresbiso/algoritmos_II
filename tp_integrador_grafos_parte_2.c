// https://www.onlinegdb.com/

/*
# Tp Integrador - Grafos
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NodoVertice {
	int valor;
	struct NodoVertice *proximoVertice;
	struct NodoConexion *proximaConexion;
} NodoVertice;

typedef struct NodoConexion {
    int valor;
    struct NodoConexion *proximo;
} NodoConexion;

void agregarNodoVertice(NodoVertice **nodoVerticeInicial, int valor) {
    NodoVertice *nodoVerticeTemp, *nodoVerticeActual;
    nodoVerticeTemp = malloc(sizeof(NodoVertice));
    nodoVerticeTemp->valor = valor;
    nodoVerticeTemp->proximoVertice = NULL;
	nodoVerticeTemp->proximaConexion = NULL;

    if((*nodoVerticeInicial) == NULL) {
        (*nodoVerticeInicial) = nodoVerticeTemp;
    } else {
        nodoVerticeActual = (*nodoVerticeInicial);
        while(nodoVerticeActual->proximoVertice != NULL){
            nodoVerticeActual = nodoVerticeActual->proximoVertice;
        }
        nodoVerticeActual->proximoVertice = nodoVerticeTemp;
    }
}

void quitarNodoVertice(NodoVertice **nodoVerticeInicial, int valor) {
    NodoVertice *nodoVerticeTemp, *nodoVerticeActual;
    nodoVerticeTemp = malloc(sizeof(NodoVertice));
    nodoVerticeTemp->valor = valor;
    nodoVerticeTemp->proximoVertice = NULL;
	nodoVerticeTemp->proximaConexion = NULL;

    if((*nodoVerticeInicial) == NULL) {
        (*nodoVerticeInicial) = nodoVerticeTemp;
    } else {
        nodoVerticeActual = (*nodoVerticeInicial);
        while(nodoVerticeActual->proximoVertice != NULL){
            nodoVerticeActual = nodoVerticeActual->proximoVertice;
        }
        nodoVerticeActual->proximoVertice = nodoVerticeTemp;
    }
}


void agregarNodoConexion(NodoConexion **nodoConexionInicial, int valor) {
	NodoConexion *nodoConexionTemp, *nodoConexionActual;
    nodoConexionTemp = malloc(sizeof(NodoConexion));
    nodoConexionTemp->valor = valor;
    nodoConexionTemp->proximo = NULL;

    if((*nodoConexionInicial) == NULL) {
        (*nodoConexionInicial) = nodoConexionTemp;
    } else {
        nodoConexionActual = (*nodoConexionInicial);
        while(nodoConexionActual->proximo != NULL){
            nodoConexionActual = nodoConexionActual->proximo;
        }
        nodoConexionActual->proximo = nodoConexionTemp;
    }
}

int existeValorNodoVertice(NodoVertice **nodoVerticeInicial, int valor) {
    NodoVertice *nodoVerticeActual;

    if((*nodoVerticeInicial) == NULL) {
        return 0;
    }
	
	nodoVerticeActual = (*nodoVerticeInicial);
	while(nodoVerticeActual != NULL){
		if(nodoVerticeActual->valor == valor) {
			return 1;
		}
		nodoVerticeActual = nodoVerticeActual->proximoVertice;
	}
	return 0;
}

int existeValorNodoConexion(NodoConexion **nodoConexionInicial, int valor) {
    NodoConexion *nodoConexionActual;

    if(nodoConexionActual == NULL) {
        return 0;
    }
	
	nodoConexionActual = (*nodoConexionInicial);
	while(nodoConexionActual != NULL){
		if(nodoConexionActual->valor == valor) {
			return 1;
		}
		nodoConexionActual = nodoConexionActual->proximo;
	}
	return 0;
}

void mostrar(NodoVertice **nodoVerticeInicial){
    NodoVertice *nodoVerticeActual;
    nodoVerticeActual = (*nodoVerticeInicial);
    while(nodoVerticeActual != NULL) {
        printf("Vértice %d", nodoVerticeActual->valor);
		NodoConexion *nodoConexionActual = nodoVerticeActual->proximaConexion;
        while(nodoConexionActual != NULL) {
            printf(" -> %d", nodoConexionActual->valor);
            nodoConexionActual = nodoConexionActual->proximo;
        }
        nodoVerticeActual = nodoVerticeActual->proximoVertice;
        printf("\n");
    }
}

int main() {
    NodoVertice *nodoVerticeInicial = NULL;
	
	int valorNodo = 0;
	while(valorNodo > -1) {
		printf("Ingrese valor del nodo (o -1 para finalizar):\n");
		scanf("%d", &valorNodo);
		
		if (valorNodo <= -1) {
			break;
		}
		
		if(existeValorNodoVertice(&nodoVerticeInicial, valorNodo) == 0) {
			agregarNodoVertice(&nodoVerticeInicial, valorNodo);
		} else {
			printf("Ya existe un nodo con valor %d:\n", valorNodo);
		}
	}

	NodoVertice *nodoVerticeActual = nodoVerticeInicial;
	while(nodoVerticeActual != NULL) {
		int valorRelacion = 0;
		while(valorRelacion > -1) {
			printf("Ingrese valor del nodo que se relaciona con nodo %d (o -1 para finalizar):\n", nodoVerticeActual->valor);
			scanf("%d", &valorRelacion);	
	
			if (valorRelacion <= -1) {
				break;
			}
		
			if(existeValorNodoVertice(&nodoVerticeInicial, valorRelacion) != 0) {
				if(existeValorNodoConexion(&(nodoVerticeActual->proximaConexion), valorRelacion) == 0) {
					agregarNodoConexion(&(nodoVerticeActual->proximaConexion), valorRelacion);
				} else {
					printf("Ya existe una relacion con el nodo con valor %d:\n", valorRelacion);
				}
			} else {
				printf("El nodo con valor %d no existe \n", valorRelacion);
			}
		}
		
		nodoVerticeActual = nodoVerticeActual->proximoVertice;
	}

    mostrar(&nodoVerticeInicial);
	
	
	
	
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
6) Agregar el menu
*/

// Menu
// char menu_option,initials;
// int difficulty;

// printf("        EDUCATIONAL MATH PROGRAM!!!\n");
// printf("------------------------------------------\n\n");


// do{
// printf("Main Menu\n");
// printf("a. Learn about how to use program.\n");
// printf("b. Enter your initials (3 individual letters).\n");
// printf("c. Difficulty Selection.\n");
// printf("d. Start a new sequence of problems.\n");
// printf("e. Save and quit.\n");
// printf(" Please enter an option from the main menu: ");
// scanf("%c",&menu_option);

// switch(menu_option){

// case 'a':
	// break;
// case 'b':
	// break;
// case'c':
	// printf("case c");
	// break;
// case'd':
	// break;
// case'e':
	// break;
// default:
	// printf("invalid input");
		// break;
// }

// }while(menu_option !='e');
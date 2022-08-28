// https://www.onlinegdb.com/

/*
# Actividad: Lista de Adyacencia
Crear una lista con los vértices de un grafo, y una sublista con las conexiones de esos vértices.
Es una multilista donde la lista principal tiene los vertices del grafo y la sublista tiene las aristas con los otros vertices. 
*/

#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int numero;
    struct nodo *proximo;
};

struct lista {
    struct nodo *comienzo;
    struct lista *proximaLista;
}; 

void insertarNodo(struct nodo **cabeza, int numero){
    struct nodo *temp, *nodoActual;
    temp = malloc(sizeof(struct nodo));
    temp->numero = numero;
    temp->proximo = NULL;

    if((*cabeza) == NULL) {
        (*cabeza) = temp;
    } else {
        nodoActual = (*head);
        while(nodoActual->proximo != NULL){
            nodoActual = nodoActual->proximo;
        }
        nodoActual->proximo = temp;
    }
}

void insertarLista(struct lista **primeraLista, struct nodo *cabeza) {
    struct lista *temp, *listaActual;
    temp = malloc(sizeof(struct lista));
    temp->comienzo = cabeza;
    temp->proximaLista = NULL;
    if((*primeraLista) == NULL) {
        (*primeraLista) = temp;
    } else {
        listaActual = (*primeraLista);
        while(listaActual->proximaLista != NULL) {
            listaActual = listaActual->proximaLista;
        }
        listaActual->proximaLista = temp;
    }
}

void mostrar(struct lista *primeraLista){
    int i = 1;
    struct lista *listaActual;
    struct nodo *nodoActual; //curentlis
    listaActual = primeraLista;
    while(listaActual != NULL) {
        nodoActual = listaActual->comienzo;
        printf("Lista %d: ", i);
        while(nodoActual != NULL) {
            printf("%d ", nodoActual->numero);
            nodoActual = nodoActual->proximo;
        }
        i++;
        printf("\n");
        listaActual = listaActual->proximaLista;
    }
}

int main(){
    struct nodo *nodoInicial = NULL, *nodoInicial2 = NULL, *nodoInicial3 = NULL;
    struct lista *listaInicial = NULL;
    insertarNodo(&nodoInicial, 20);
    insertarNodo(&nodoInicial, 13);
    insertarNodo(&nodoInicial, 22);
    insertarNodo(&nodoInicial, 18);
    insertarNodo(&nodoInicial2, 42);
    insertarNodo(&nodoInicial2, 15);
    insertarNodo(&nodoInicial3, 12);
    insertarNodo(&nodoInicial3, 14);
    insertarNodo(&nodoInicial3, 28);
    insertarLista(&listaInicial, nodoInicial);
    insertarLista(&listaInicial, nodoInicial2);
    insertarLista(&listaInicial, nodoInicial3);
    mostrar(listaInicial);
	return 0;
}
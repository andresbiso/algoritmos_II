#include<stdbool.h>  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Typedefs
typedef int Item;
typedef struct NodeElement Node;
typedef struct EdgeElement Edge;

// Structs
struct NodeElement
{
	Item data;
	struct NodeElement* next;
	struct EdgeElement* nextEdge;
};

struct EdgeElement
{
	Item data;
	struct EdgeElement* next;
};

// Functions Declarations
void addNodeTail(Node** listHeadRef, Item item);
Node* createNode(Item item);
void removeNode(Node** listHeadRef, Item item);
void printAdjacencyList(Node** listHeadRef);
void addEdge(Node** listHeadRef, Item itemA, Item itemB);
Edge* createEdge(Item item);
void removeEdge(Node** listHeadRef, Item itemA, Item itemB);
int calculateNodeDegree(Node** listHeadRef, Item item);
void printNodeDegree(Node** listHeadRef, Item item);
int calculateTotalDegree(Node** listHeadRef);
void printTotalDegree(Node** listHeadRef);
float calculateTotalEdges(Node** listHeadRef);
void printTotalEdges(Node** listHeadRef);
bool checkIsGraph(Node** listHeadRef);
bool printIsGraph(Node** listHeadRef);

int main()
{
	Node *adjacencyList;

	adjacencyList = NULL;
	
	addNodeTail(&adjacencyList, 1);
	addNodeTail(&adjacencyList, 2);
	addNodeTail(&adjacencyList, 3);
	addNodeTail(&adjacencyList, 4);
	addNodeTail(&adjacencyList, 5);
	addNodeTail(&adjacencyList, 6);

	addEdge(&adjacencyList, 2, 4);
	addEdge(&adjacencyList, 2, 5);
	addEdge(&adjacencyList, 2, 6);

	printNodeDegree(&adjacencyList, 2);
	printTotalDegree(&adjacencyList);
	printTotalEdges(&adjacencyList);
	printIsGraph(&adjacencyList);

	printAdjacencyList(&adjacencyList);

	removeEdge(&adjacencyList, 2, 6);
	removeNode(&adjacencyList, 4);

	printAdjacencyList(&adjacencyList);

	return 0;
}

void addNodeTail(Node** listHeadRef, Item item)
{
	Node *newNode, *currentNode;
	newNode = createNode(item);

    if(*listHeadRef == NULL) {
        *listHeadRef = newNode;
    } else {
        currentNode = *listHeadRef;
        while(currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

Node* createNode(Item item)
{
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	newNode->next = NULL;
	newNode->nextEdge = NULL;
	return newNode;
}

void removeNode(Node** listHeadRef, Item item)
{
    Node *currentNode, *prevNode;

	currentNode = *listHeadRef;

	if (currentNode == NULL) {
		return;
	}

	// Check if node actually exists

	while (currentNode != NULL && currentNode->data != item) {
        currentNode = currentNode->next;
    }

	if (currentNode == NULL) {
		printf("El nodo con valor %d no existe", item);
		printf("\n");
		return;
	}

	// Search, remove all node edges with other nodes and remove node

	currentNode = *listHeadRef;
 
    if (currentNode != NULL && currentNode->data == item) {
		if (currentNode->nextEdge != NULL) {
			Edge *currentEdge = currentNode->nextEdge;
			while (currentEdge != NULL) {
				removeEdge(listHeadRef, currentEdge->data, item);
				currentEdge = currentEdge->next;
			}
		}
        *listHeadRef = currentNode->next;
        free(currentNode);
        return;
    }
 
    while (currentNode != NULL && currentNode->data != item) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

	if (currentNode->nextEdge != NULL) {
		Edge *currentEdge = currentNode->nextEdge;
		while (currentEdge != NULL) {
			removeEdge(listHeadRef, currentEdge->data, item);
			currentEdge = currentEdge->next;
		}
	}
 
    prevNode->next = currentNode->next;
 
    free(currentNode);

	return;
}

void addEdge(Node** listHeadRef, Item itemA, Item itemB)
{
	Edge *newEdgeA, *newEdgeB, *currentEdge;
	Node *currentNode, *nodeA, *nodeB;
	newEdgeA = createEdge(itemA);
	newEdgeB = createEdge(itemB);

	currentNode = *listHeadRef;

    if (currentNode == NULL) {
        return;
    }

	// Search for first node
	while (currentNode != NULL && currentNode->data != itemA) {
        currentNode = currentNode->next;
    }

	nodeA = currentNode;

	if (nodeA == NULL) {
		printf("El nodo ingresado con valor %d no existe", itemA);
		printf("\n");
        return;
    }

	// Search for second node

	currentNode = *listHeadRef;

	while (currentNode != NULL && currentNode->data != itemB) {
        currentNode = currentNode->next;
    }

	nodeB = currentNode;

	if (nodeB == NULL) {
		printf("El nodo ingresado con valor %d no existe", itemB);
		printf("\n");
        return;
    }

	// Insert edge for first node

	if(nodeA->nextEdge == NULL) {
		nodeA->nextEdge = newEdgeB;
	} else {
		currentEdge = nodeA->nextEdge;
		while (currentEdge->next != NULL) {
        	currentEdge = currentEdge->next;
    	}
		currentEdge->next = newEdgeB;
	}

	// Insert edge for second node

	if(nodeB->nextEdge == NULL) {
		nodeB->nextEdge = newEdgeA;
	} else {
		currentEdge = nodeB->nextEdge;
		while (currentEdge->next != NULL) {
        	currentEdge = currentEdge->next;
    	}
		currentEdge->next = newEdgeA;
	}

	return;
}

Edge* createEdge(Item item)
{
	Edge *newEdge;
	newEdge = (Edge*)malloc(sizeof(Edge));
	newEdge->data = item;
	newEdge->next = NULL;
	return newEdge;
}

void removeEdge(Node** listHeadRef, Item itemA, Item itemB)
{
	Edge *currentEdge, *prevEdge;
	Node *currentNode, *nodeA, *nodeB;

	currentNode = *listHeadRef;

    if (currentNode == NULL) {
        return;
    }

	// Search for first node
	while (currentNode != NULL && currentNode->data != itemA) {
        currentNode = currentNode->next;
    }

	nodeA = currentNode;

	if (nodeA == NULL) {
		printf("El nodo ingresado con valor %d no existe", itemA);
		printf("\n");
        return;
    }

	// Search for second node

	currentNode = *listHeadRef;

	while (currentNode != NULL && currentNode->data != itemB) {
        currentNode = currentNode->next;
    }

	nodeB = currentNode;

	if (nodeB == NULL) {
		printf("El nodo ingresado con valor %d no existe", itemB);
		printf("\n");
        return;
    }

	// Check if nodes have edges

	if (nodeA->nextEdge == NULL) {
		printf("El nodo ingresado con valor %d no tiene aristas", itemA);
		printf("\n");
		return;
	}
	
	if (nodeB->nextEdge == NULL) {
		printf("El nodo ingresado con valor %d no tiene aristas", itemB);
		printf("\n");
		return;
	}

	// Check if both nodes have an edge between them

	currentEdge = nodeA->nextEdge;

	while (currentEdge != NULL && currentEdge->data != itemB) {
        currentEdge = currentEdge->next;
    }

	if (currentEdge == NULL) {
		printf("El nodo ingresado con valor %d no tiene arista con nodo %d", itemA, itemB);
		printf("\n");
		return;
	}

	currentEdge = nodeB->nextEdge;

	while (currentEdge != NULL && currentEdge->data != itemA) {
        currentEdge = currentEdge->next;
    }

	if (currentEdge == NULL) {
		printf("El nodo ingresado con valor %d no tiene arista con nodo %d", itemB, itemA);
		printf("\n");
		return;
	}

	// Search and Remove edge for first node

	currentEdge = nodeA->nextEdge;

	if (currentEdge->data == itemB) {
        nodeA->nextEdge = currentEdge->next;
        free(currentEdge);
        return;
    }

	while (currentEdge != NULL && currentEdge->data != itemB) {
        prevEdge = currentEdge;
        currentEdge = currentEdge->next;
    }

	prevEdge->next = currentEdge->next;
 
    free(currentEdge);

	// Search and Remove edge for second node

	currentEdge = nodeB->nextEdge;

	if (currentEdge->data == itemA) {
        nodeB->nextEdge = currentEdge->next;
        free(currentEdge);
        return;
    }

	while (currentEdge != NULL && currentEdge->data != itemA) {
        prevEdge = currentEdge;
        currentEdge = currentEdge->next;
    }

	prevEdge->next = currentEdge->next;
 
    free(currentEdge);

	return;
}

int calculateNodeDegree(Node** listHeadRef, Item item)
{
	Node *currentNode;
	int degree;

	currentNode = *listHeadRef;

    if (currentNode == NULL) {
        return -1;
    }

	// Search for node

	while (currentNode != NULL && currentNode->data != item) {
        currentNode = currentNode->next;
    }

	if (currentNode == NULL) {
		printf("El nodo ingresado con valor %d no existe", item);
		printf("\n");
        return -1;
    }

	// Insert edge for first node
	degree = 0;
	if(currentNode->nextEdge != NULL) {
		Edge *currentEdge = currentNode->nextEdge;
		while (currentEdge != NULL) {
			degree += 1;
        	currentEdge = currentEdge->next;
    	}
	}

	return degree;
}

void printNodeDegree(Node** listHeadRef, Item item)
{
	int degree = calculateNodeDegree(listHeadRef, item);
	if (degree > -1) {
		printf("El nodo %d tiene grado: %d", item, degree);
		printf("\n");
	} else {
		printf("El nodo ingresado con valor %d no existe", item);
		printf("\n");
	}
}

int calculateTotalDegree(Node** listHeadRef)
{
	Node *currentNode;
	int degree;

	currentNode = *listHeadRef;

    if (currentNode == NULL) {
        return -1;
    }

	// Insert edge for first node
	degree = 0;
	while (currentNode != NULL) {
		int nodeDegree = calculateNodeDegree(listHeadRef, currentNode->data);
		if (nodeDegree > 0) {
			degree = degree + nodeDegree;
		}
		currentNode = currentNode->next;
	}
	
	return degree;
}

void printTotalDegree(Node** listHeadRef)
{
	int totalDegree = calculateTotalDegree(listHeadRef);
	if (totalDegree > -1) {
		printf("El grafo tiene grado total: %d", totalDegree);
		printf("\n");
	} else {
		printf("El grafo no tiene nodos");
		printf("\n");
	}
}

float calculateTotalEdges(Node** listHeadRef)
{
	int totalDegree = calculateTotalDegree(listHeadRef);
	float totalEdges = 0;
	if (totalDegree > -1) {
		totalEdges = totalDegree / 2;
	}
	return totalEdges;
}

void printTotalEdges(Node** listHeadRef)
{
	float totalEdges = calculateTotalEdges(listHeadRef);
	printf("El grafo una cantidad total de aristas: %f", totalEdges);
	printf("\n");
}

bool checkIsGraph(Node** listHeadRef)
{
	int totalDegree = calculateTotalDegree(listHeadRef);
	return totalDegree % 2 == 0;
}

bool printIsGraph(Node** listHeadRef)
{
	if(checkIsGraph(listHeadRef)) {
		printf("Es un grafo");
		printf("\n");
	} else {
		printf("No es un grafo");
		printf("\n");
	}
}

void printAdjacencyList(Node** listHeadRef) {
	Node *ptr_node;

	printf("***Nodos***");
	printf("\n");
	ptr_node = *listHeadRef;
	while (ptr_node != NULL)
	{
		printf ("%d", ptr_node->data);
		ptr_node = ptr_node->next;
		if (ptr_node != NULL) {
			printf("->");
		}
	}
	printf ("\n\n");

	printf("***Conexiones***");
	printf("\n");
	Node *ptrNode;
	ptrNode = *listHeadRef;
    while(ptrNode != NULL) {
        printf("%d", ptrNode->data);
		Edge *ptrEdge = ptrNode->nextEdge;
        while(ptrEdge != NULL) {
            printf(" -> %d", ptrEdge->data);
            ptrEdge = ptrEdge->next;
        }
        ptrNode = ptrNode->next;
        printf("\n");
    }
	printf ("\n\n");
	return;
}

// int main()
// {
// 	int menu_option;

// 	printf("Bienvenido!\n");
// 	printf("-----------\n\n");

// 	do
// 	{
// 		printf("Menú Principal\n");
// 		printf("1-Agregar Nodo\n");
// 		printf("2-Agregar Arista\n");
// 		printf("3-Quitar Nodo\n");
// 		printf("4-Quitar Arista\n");
// 		printf("5-Verificar conexo\n");
// 		printf("6-Verificar euleriano\n");
// 		printf("7-Imprimir Grafo\n");
// 		printf("8-Iniciar Grafo\n");
// 		printf("20-Save and quit.\n");
// 		printf("Ingrese una opción:");
// 		scanf("%d", &menu_option);

// 		switch (menu_option)
// 		{
// 			case 1:
// 				break;
// 			case 2:
// 				break;
// 			case 3:
// 				break;
// 			case 4:
// 				break;
// 			case 5:
// 				break;
// 			case 6:
// 				break;
// 			case 7:
// 				break;
// 			case 8:
// 				break;
// 			case 20:
// 				break;
// 			default:
// 				printf("Opción Inválida \n");
// 				printf("Presione [Enter] para continuar \n");
// 				do {
// 				    getchar();
// 				} while(getchar()!='\n');
// 				break;
// 		}

// 	} while (menu_option != 20);

// 	return 0;
// }

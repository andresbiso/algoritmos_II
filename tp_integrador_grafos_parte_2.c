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
Edge* createEdge(Item item);
void addEdge(Node** listHeadRef, Item itemA, Item itemB);

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

	addEdge(&adjacencyList, 1, 2);

	printAdjacencyList(&adjacencyList);

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

	if (currentNode == NULL)
        return;
 
    if (currentNode != NULL && currentNode->data == item) {
        *listHeadRef = currentNode->next;
        free(currentNode);
        return;
    }
 
    while (currentNode != NULL && currentNode->data != item) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
 
    prevNode->next = currentNode->next;
 
    free(currentNode);
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
        return;
    }

	// Insert edge for first node

	currentEdge = nodeA->nextEdge;

	printf("%d", currentEdge.data);

	if(currentEdge == NULL) {
		currentEdge = newEdgeB;
	} else {
		while (currentEdge != NULL) {
        	currentEdge = currentEdge->next;
    	}
		currentEdge->next = newEdgeB;
	}

	// Insert edge for second node

	currentEdge = nodeB->nextEdge;

	if(currentEdge == NULL) {
		currentEdge = newEdgeA;
	} else {
		while (currentEdge != NULL) {
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

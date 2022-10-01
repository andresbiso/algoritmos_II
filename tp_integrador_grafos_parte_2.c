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
void addNewTailNode(Node** adjacencyList, Item item);
Node* createNode(Item item);

int main()
{
	Node *adjacencyList, *ptr_node;

	adjacencyList = NULL;
	
	addNewTailNode(&adjacencyList, 1);
	addNewTailNode(&adjacencyList, 2);
	addNewTailNode(&adjacencyList, 3);
	addNewTailNode(&adjacencyList, 4);
	addNewTailNode(&adjacencyList, 5);
	addNewTailNode(&adjacencyList, 6);

	ptr_node = adjacencyList;
	while (ptr_node != NULL)
	{
		printf ("%d", ptr_node->data);
		ptr_node = ptr_node->next;
		if (ptr_node != NULL) {
			printf("->");
		}
	}
	printf ("\n\n");
	return 0;
}

void addNewTailNode(Node** adjacencyList, Item item) {
	Node *newNode, *currentNode;
	newNode = createNode(item);

    if(*adjacencyList == NULL) {
        *adjacencyList = newNode;
    } else {
        currentNode = *adjacencyList;
        while(currentNode->next != NULL){
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

Node* createNode(Item item) {
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	newNode->next = NULL;
	newNode->nextEdge = NULL;
	return newNode;
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

// Nicole Mena Porras C14663
// este es el codigo de la funcion principal main
#include <stdio.h>
#include "double_list.h"

int main() {
    DoubleList* list = createList();
    insertAtBeginning(list, 10);
    insertAtBeginning(list, 20);
    insertAtEnd(list, 30);
    insertAtEnd(list, 40);
    insertAtPosition(list, 25, 2);
    printf("La lista hacia adelante es: ");
    printListForward(list);
    printf("La lista hacia atrás es: ");
    printListBackward(list);
    Node* foundNode = searchNode(list, 25);
    if (foundNode) {
        printf("El nodo con data 25 encontrado: %d\n", foundNode->data);
    } else {
        printf("El nodo con data 25 no encontrado.\n");
    }

    deleteNode(list, 20);
    printf("Esta es la lista después de eliminar nodo con ayuda de data 20, gracias: ");
    printListForward(list);

    freeList(list);

    return 0;
}
// fin del codigo gracias...

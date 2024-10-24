#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Function prototypes
void isort(node** list);
node* createnode(int data);
void Print(node* list);

int main() {
    // Create the list
    node* list = createnode(10);
    list->next = createnode(5);
    list->next->next = createnode(8);
    list->next->next->next = createnode(20);
    list->next->next->next->next = createnode(14);

    printf("Liste 1:\n");
    Print(list);

    
    isort(&list);

    printf("ny liste i rækkefølge:\n");
    Print(list);

    return 0;
}

// Funktion som sorterer
void isort(node** list) {
    node* sorted = NULL; // Dette er en tom liste
    node* current = *list;

    
    while (current != NULL) {
        // Gemmer den næste node
        node* next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }

            // sætter current til at være imellem temp og temp next
            current->next = temp->next;
            temp->next = current;
        }

        // Skifter curren til den næste værdi i listen
        current = next;
    }

    *list = sorted;
}


node* createnode(int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}


void Print(node* list) {
    node* temp = list;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

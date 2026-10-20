#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main(void) {
    struct node* head = malloc(sizeof(struct node));
    struct node* n1 = malloc(sizeof(struct node));
    struct node* n2 = malloc(sizeof(struct node));
    if (head == NULL || n1 == NULL || n2 == NULL) return 1;
    head->data = 3;
    n1->data = 2;
    n2->data = 5;
    head->next = n1;
    n1->next = n2;
    n2->next = NULL;
    struct node* silinecek = head;
    head = head->next;
    free(silinecek);
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    while (head != NULL) {
        struct node* silinecek = head;
        head = head->next;
        free(silinecek);
    }
    return 0;
}

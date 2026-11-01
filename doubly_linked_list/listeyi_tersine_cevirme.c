#include <stdio.h>
#include <stdlib.h>
struct dnode {
 int data;
 struct dnode* prev;
 struct dnode* next;
};

int main(void) {
 struct dnode* head = malloc(sizeof(struct dnode));
 struct dnode* n1 = malloc(sizeof(struct dnode));
 struct dnode* n2 = malloc(sizeof(struct dnode));

 head->data = 3;
 head->prev = NULL;
 head->next = n1;

 n1->data = 2;
 n1->prev = head;
 n1->next = n2;

 n2->data = 5;
 n2->prev = n1;
 n2->next = NULL;

 struct dnode* current = head;      // Current değişkeninin tanımlaması
 struct dnode* temp = NULL;

 while (current != NULL) {
 temp = current->prev;
 current->prev = current->next;
 current->next = temp;
 current = current->prev;
}
 if (temp != NULL)
 head = temp->prev;

 current = head;

 printf("1leri yönde: ");
 
 while (current != NULL) {
 printf("%d -> ", current->data);
 current = current->next;
}
 printf("NULL\n");
 return 0;
}



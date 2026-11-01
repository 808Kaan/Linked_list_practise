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

 // Araya eleman eklenir .   
 struct dnode* yeni = malloc(sizeof(struct dnode));
 yeni->data = 7;
 yeni->next = n1->next;
 yeni->prev = n1;
 n1->next->prev = yeni;
 n1->next = yeni;


 struct dnode* current = head;      // Current değişkeninin tanımlaması .

 printf("1leri yönde: ");
 while (current != NULL) {
 printf("%d -> ", current->data);
 current = current->next;
}
 printf("NULL\n");
 return 0;
}



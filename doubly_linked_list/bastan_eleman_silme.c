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
 n2->next = NULL;                   // head => n1 => n2 , head silinecek 

 // Baştan eleman silinir.   
 struct dnode* silinecek = head;
 head = head->next;
 head->prev = NULL;
 free(silinecek);


 struct dnode* current = head;      // Current değişkeninin tanımlaması.

 printf("1leri yönde: ");
 while (current != NULL) {
 printf("%d -> ", current->data);
 current = current->next;
}
 printf("NULL\n");
 return 0;
}



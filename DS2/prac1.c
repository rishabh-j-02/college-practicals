#include <stdio.h>
#include <malloc.h>
typedef struct node Node;
struct node {
        int data;
    Node *next;
};
Node *head = NULL, *last;
void addNodeAtEnd(int data){
        Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(head == NULL){
            head = newNode;
        head->next = NULL;
        last = head;
    } else {
            last->next = newNode;
        last = newNode;
        newNode->next = NULL;
    }
}
void addNodeAt(int index, int data){
        if(index < 0){
            return;
    }
    if(index > size()-1){
            return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node *currNode = head, *prev;
    int i;
    for(i = 0; i < index; i++){
            prev = currNode;
        currNode = currNode->next;
    }
    newNode->next = currNode->next;
    prev->next = newNode;
}
void traverse(){
        Node *i = head;
    while(i != NULL){
            printf("%d ", i->data);
        i = i->next;
    }
    printf("\n");
}
void delete(int data){
        Node *i = head, *prev;
    while(i != NULL){
            if(i->data == data){
                break;
        }
        prev = i;
        i = i->next;
    }
    prev->next = i->next;
    free(i);
}
int size(){
        Node *i = head;
    int len = 0;
    while(i != NULL){
            len++;
        i = i->next;
    }
    return len;
}
int main(){
        addNodeAtEnd(1);
    addNodeAtEnd(3);
    addNodeAtEnd(4);
    addNodeAtEnd(12);
    addNodeAtEnd(123);
    printf("LL : "); traverse();
    
    delete(123);
    printf("delete(123) : ");
    traverse();
    addNodeAt(2, 45);
    printf("addNodeAt(2, 45) : ");
    traverse();
    return 0;
}
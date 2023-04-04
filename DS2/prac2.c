#include <stdio.h>
#include <malloc.h>

typedef struct node Node;

struct node {
    int data;
    Node *next;
    Node *prev;
};

Node *first = NULL, *last = NULL;

void addNodeAtEnd(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    if(first == NULL){
        first = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        last = newNode;
    } else {
        last->next = newNode;
        newNode->prev = last;
        newNode->next = NULL;
        last = newNode;
    }
}

void traverse(){
    Node *i = first;

    printf("[ ");
    while(i != NULL){
        printf("%d ", i->data);
        i = i->next;
    }
    printf("]\n");
}

int search(int data){
    Node *i = first;
    int index = 0;
    for(i = first; i != NULL; i=i->next){
        if(i->data == data){
            return index;
            break;
        }
        index++;
    }
    return -1;
}

int main(){

    addNodeAtEnd(10);
    addNodeAtEnd(20);
    addNodeAtEnd(30);
    addNodeAtEnd(40);
    addNodeAtEnd(50);
    addNodeAtEnd(60);
   
    while(1){
        printf("\n1. Add Node At End\n");
        printf("2. Traverse\n");
        printf("3. Search Data\n");
       
        int res;
        scanf("%d", &res);
       
        switch(res){
            case 1 :
                printf("data : ");
                int data;
                scanf("%d", &data);
                addNodeAtEnd(data);
                break;
           
            case 2:
                traverse();
                break;
           
            case 3:
                printf("data : ");
                scanf("%d", &data);
                printf("%d at index %d", data, search(data));
                break;
        }
    }

    return 0;

}

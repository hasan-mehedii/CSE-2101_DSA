#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Node;
struct Stack{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void push(int data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(head == NULL && tail == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
    }
}

void pop(){
    Node *temp = head;
    if(head == NULL){
        printf("Stack is empty\n");
    }
    else if(head == tail){
        head == NULL;
        tail == NULL;
    }
    else{
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}

void display(){
    Node *temp = head;
    while(temp){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    printf("Hello World\n");
    printf("Push\n");
    push(5);
    push(6);
    push(7);
    display();
    printf("Pop\n");
    pop();
    display();
    return 0;
}
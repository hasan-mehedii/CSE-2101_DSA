#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Node;
struct Queue{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void enqueue(int data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    new_node->prev = NULL;

    if(head == NULL && tail == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        head->prev = new_node;
        head = new_node;
    }
}

void dequeue(){
    if (tail == NULL){
        printf("No items in Queue\n");
        return;
    }

    Node *temp = tail;
    if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        tail = tail->prev;
        tail->next = NULL;
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
    printf("Enqueue\n");
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    printf("Dequeue\n");
    dequeue();
    display();
    return 0;
}

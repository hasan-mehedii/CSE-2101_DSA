#include <iostream>
using namespace std;

typedef struct node Node;
struct node{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

void add_first(int item){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = item;
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

void add_last(int item){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(head == NULL && tail == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        tail->next = new_node;
        tail = new_node;
    }
}

void delete_first(){
    Node *temp = head;
    if(head == NULL){
        cout<<"No Node available"<<endl;
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

void delete_last(){
    Node *temp = tail;
    if(tail == NULL){
        cout<<"No Node available"<<endl;
    }
    else if(head == tail){
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
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
int main(){
    cout<<"Hello World"<<endl;
    /*
    Code Body for implement Linked List
    */
    return 0;
}
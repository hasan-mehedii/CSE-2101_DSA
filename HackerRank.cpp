#include <iostream>
using namespace std;

typedef struct node Node;
struct node{
    char data;
    Node *next;
    Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

void push(char data){
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
        cout<<"Already empty"<<endl;
    }
    else if(head == tail){
        head = NULL;
        tail = NULL;
        free(temp);
    }
    else{
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

int main(){
    string input;
    string reversed;
    cin>>input;

    int i = 0;
    while(i < input.length()){
        push(input[i]);
        i++;
    }

    Node *temp = head;
    while (temp) {
        reversed += temp->data;
        temp = temp->next;
    }

    if(reversed == input){
        cout<<"The word, "<<input<<", is a palindrome."<<endl;
    }
    else{
        cout<<"The word, "<<input<<", is not a palindrome."<<endl;
    }
    return 0;
}
// Code for Binary Search Tree...
#include <iostream>
using namespace std;

struct Node {

    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}

};

Node* insert(Node* root, int key){
    if (root == nullptr){
        return new Node(key);
    }


    if (key < root->key){
        root->left = insert(root->left, key);
    }
    else if(key > root->key){
        root->right = insert(root->right, key);
    }
    
    return root;
}

bool find(Node* cur, int key){
    if(cur==nullptr) return false;

    if(cur->key == key) return true;

    if(key < cur->key){
       return find(cur->left, key);
    }
    else{
        return find(cur->right, key);
    }
}

void inorder(Node* cur){
    if(cur == nullptr)
        return;
    inorder(cur->left);
    cout<< cur->key <<endl;
    inorder(cur->right);

}

void preorder(Node* cur){
    if(cur == nullptr)
        return;
    cout<< cur->key <<endl;
    preorder(cur->left);
    preorder(cur->right);

}

void postorder(Node* cur){
    if(cur == nullptr)
        return;
    postorder(cur->left);
    postorder(cur->right);
    cout<< cur->key <<endl;

}

Node* findmin(Node* root){
    while(root->left!=nullptr){
        root = root->left;
    }
    return root;
}

Node* findmax(Node* root){
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

// Node* deleteNode(Node* root, int key){
//     if(root==nullptr) return root;

//     if(key<root->key){
//         root->left = deleteNode(root->left, key);
//     }
//     else if (key > root->key){
//         root->right = deleteNode(root->right, key);
//     }
//     else{
        
//         if(root->left == nullptr){
//             Node* temp = root->right;
//             delete root;
//             return temp;
//         }
//         else if(root->right==nullptr){
//             Node* temp = root->left;
//             delete root;
//             return temp;
//         }

//         Node* temp = findmin(root->right);
//         root->key = temp->key;
//         root->right = deleteNode(root->right, temp->key);
//     }
//     return root;
// }

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findmax(root->left);
        root->key = temp->key;
        root->left = deleteNode(root->left, temp->key);
    }
    return root;
}

int main() {

    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout<<find(root, 40)<<endl;
    cout<<find(root, 41)<<endl;

    root = deleteNode(root, 40);
    
    cout<<find(root, 40)<<endl;

    return 0;
}
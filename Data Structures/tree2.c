#include <stdio.h>
#include <stdlib.h>

typedef struct BST_Tree tree;
struct BST_Tree {
    int data;
    tree *parent;
    tree *left;
    tree *right;
};

tree *root = NULL;

// Function to insert a left child
void insert_left_child(tree *parent, int data) {
    if (parent == NULL) {
        printf("Error: Parent node is NULL.\n");
        return;
    }
    if (parent->left != NULL) {
        printf("Error: Left child already exists for node with data %d.\n", parent->data);
        return;
    }

    tree *new_child = (tree *)malloc(sizeof(tree));
    new_child->data = data;
    new_child->left = NULL;
    new_child->right = NULL;
    new_child->parent = parent;

    parent->left = new_child;
}

// Function to insert a right child
void insert_right_child(tree *parent, int data) {
    if (parent == NULL) {
        printf("Error: Parent node is NULL.\n");
        return;
    }
    if (parent->right != NULL) {
        printf("Error: Right child already exists for node with data %d.\n", parent->data);
        return;
    }

    tree *new_child = (tree *)malloc(sizeof(tree));
    new_child->data = data;
    new_child->left = NULL;
    new_child->right = NULL;
    new_child->parent = parent;

    parent->right = new_child;
}

// Function to perform in-order traversal of the BST
void inorder(tree *node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main() {
    // Create root node
    root = (tree *)malloc(sizeof(tree));
    root->data = 50;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;

    // Insert children
    insert_left_child(root, 30);
    insert_right_child(root, 70);
    insert_left_child(root->left, 20);
    insert_right_child(root->left, 40);
    insert_left_child(root->right, 60);
    insert_right_child(root->right, 80);

    printf("In-order traversal of the BST: \n");
    inorder(root);

    return 0;
}
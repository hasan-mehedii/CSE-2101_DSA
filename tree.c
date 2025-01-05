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

void insert(int data) {
    tree *new_child = (tree *)malloc(sizeof(tree));
    new_child->data = data;
    new_child->left = NULL;
    new_child->right = NULL;

    if (root == NULL) {
        root = new_child;
        return;
    }

    tree *current = root;
    tree *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (data < parent->data) {
        parent->left = new_child;
    } else {
        parent->right = new_child;
    }
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
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    printf("In-order traversal of the BST: \n");
    inorder(root);

    return 0;
}
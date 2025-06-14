#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int data;
    Node *parent;
    Node *left;
    Node *mid;
    Node *right;
};

Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->mid = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(int type, Node *par, int data) {
    Node *new_node = create_node(data);

    if (type == 0) {
        par->left = new_node;
    } else if (type == 1) {
        par->mid = new_node;
    } else if (type == 2) {
        par->right = new_node;
    }
    new_node->parent = par;
}

Node* find_node(Node *root, int key) {
    if (!root) return NULL;

    if (root->data == key) {
        return root;
    }

    Node *found_node = find_node(root->left, key);
    if (found_node) return found_node;

    found_node = find_node(root->mid, key);
    if (found_node) return found_node;

    return find_node(root->right, key);
}

void print_tree(Node *node) {
    if (!node) return;

    print_tree(node->left);
    print_tree(node->mid);
    printf("%d\n", node->data);
    print_tree(node->right);
}

int main() {
    int root_value, n;
    scanf("%d%d", &root_value, &n);

    Node *root = create_node(root_value);

    for (int i = 0; i < n; i++) {
        int op_type, parent_val, child_val;
        scanf("%d%d%d", &op_type, &parent_val, &child_val);

        Node *parent_node = find_node(root, parent_val);

        if (parent_node) {
            insert(op_type, parent_node, child_val);
        }
    }

    print_tree(root);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(int type, Node *par, int data) {
    Node *new_node = create_node(data);

    if (type == 0) {
        par->left = new_node;
    } else if (type == 1) {
        par->right = new_node;
    }
    new_node->parent = par;
}

Node *find_node(Node *root, int key) {
    if (!root)
        return NULL;

    if (root->data == key) {
        return root;
    }

    Node *found_node = find_node(root->left, key);
    if (found_node)
        return found_node;

    return find_node(root->right, key);
}

int check_tree(Node *root1, Node *root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    if (root1->data != root2->data) {
        return 0;
    }

    return check_tree(root1->left, root2->left) &&
           check_tree(root1->right, root2->right);
}

int main() {
    int time = 2;
    Node *roots[2];

    for (int t = 0; t < 2; t++) {
        int root_value, n;
        scanf("%d%d", &root_value, &n);

        roots[t] = create_node(root_value);
        for (int i = 0; i < n; i++) {
            int op_type, parent_val, child_val;
            scanf("%d%d%d", &op_type, &parent_val, &child_val);

            Node *parent_node = find_node(roots[t], parent_val);

            if (parent_node) {
                insert(op_type, parent_node, child_val);
            }
        }
    }
    if (check_tree(roots[0], roots[1]) == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}

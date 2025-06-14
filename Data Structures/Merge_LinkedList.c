#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int data;
    Node *next;
};

Node *Create_Node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void printList(Node *root) {
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}

Node *Merge_LinkedList(Node *list1, Node *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node *final_list = NULL;

    if (list1->data <= list2->data) {
        final_list = list1;
        final_list->next = Merge_LinkedList(list1->next, list2);
    } else {
        final_list = list2;
        final_list->next = Merge_LinkedList(list1, list2->next);
    }

    return final_list;
}

Node *Merge_Multiple_LinkedLists(Node **lists, int n) {
    if (n == 0) return NULL;
    if (n == 1) return lists[0];

    Node *mergedList = lists[0];
    for (int i = 1; i < n; i++) {
        mergedList = Merge_LinkedList(mergedList, lists[i]);
    }

    return mergedList;
}

int main() {
    int numLists;
    scanf("%d", &numLists);

    Node *lists[numLists];

    for (int i = 0; i < numLists; i++) {
        int numElements;
        scanf("%d", &numElements);

        Node *head = NULL, *tail = NULL;
        for (int j = 0; j < numElements; j++) {
            int value;
            scanf("%d", &value);

            Node *new_node = Create_Node(value);
            if (head == NULL) {
                head = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        lists[i] = head;
    }

    Node *mergedList = Merge_Multiple_LinkedLists(lists, numLists);
    printList(mergedList);

    return 0;
}

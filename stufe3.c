#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"


typedef struct Node {
    struct Node *previous;
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->previous = NULL;
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void insertInTheBenninging(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->previous = newNode;
    *head = newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->previous = temp;
}

void insert(Node **head, int data, int position) {
    Node *newNode = createNode(data);
    Node* temp = *head;
    if(position == 0) {
        insertInTheBenninging(temp, data);
    }
    for(int i = 0; i < position - 2; i++) {
        if(temp->next == NULL) {
            insertAtEnd(temp, data);
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->previous = temp;
    if(temp->next != NULL)
        temp->next->previous = newNode;
    temp->next = newNode;
}

void deleteInTheBenninging(Node **head) {
    if(*head == NULL) {
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if((*head) != NULL)
        (*head)->previous = NULL;
    free(temp);
}

void deleteInTheEnd(Node **head) {
    if(*head == NULL)
        return;
    Node* temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->previous->next = NULL;
    free(temp);
}

void delete(Node** head, int position) {
    if(*head == NULL)
        return;
    if(position == 0) {
        deleteInTheBenninging(head);
        return;
    }
    Node* temp = *head;
    for(int i = 0; i < position - 1; i++) {
        if(temp->next == NULL)
            deleteInTheEnd(temp);
        temp = temp->next;
    }
    temp->next->previous = temp->previous;
    temp->previous->next = temp->next;
    free(temp);

}

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int sum(Node* head) {
    Node* temp = head;
    int sum = 0;
    while(temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

/*END OF LINKEDLIST*/



char* readAndCopyString(char str[100]) {
    int length = 0;
    while(str[length] != '\0') {
        length++;
    }
    char* copy = (char*)malloc((length + 1) * sizeof(char));
    for(int i = 0; i < length; i++) {
        copy[i] = str[i];
    }
    copy[length] = '\0';
    return copy;
}


/*BENNINGING OF BINARY SEARCH TREE*/

typedef struct BinaryTreeNode {
    struct BinaryTreeNode *left;
    int data;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

BinaryTreeNode*  createRoot(int data) {
    BinaryTreeNode* newNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
        if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(BinaryTreeNode* root, int data) {
    BinaryTreeNode* newNode = createRoot(data);
    BinaryTreeNode* temp = root;
    while(temp != NULL) {
        if(data < temp->data) {
            if(temp->left == NULL) {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        } else {
            if(temp->right == NULL) {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

void inOrderTraversal(BinaryTreeNode* root) {
    if(root == NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(BinaryTreeNode* root) {
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(BinaryTreeNode* root) {
    if(root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}


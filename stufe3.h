//
// Created by quentin on 24.07.2024.
//

#ifndef UNTITLED2_STUFE3_H
#define UNTITLED2_STUFE3_H
#include "stdbool.h"
struct Node *createNode(int data);
void insertInTheBenninging(struct Node **head, int data);
void insertAtEnd(struct Node **head, int data);
void insert(struct Node **head, int data, int position);
void delete(struct Node **head, int position);
void deleteInTheBenninging(struct Node **head);
void deleteInTheEnd(struct Node **head);
void printList(struct Node* head);
int sum(struct Node* head);
char* readAndCopyString(char str[100]);

struct BinaryTreeNode* createRoot(int data);
void insertNode(struct BinaryTreeNode* root, int data);
void inOrderTraversal(struct BinaryTreeNode* root);
void preOrderTraversal(struct BinaryTreeNode* root);
void postOrderTraversal(struct BinaryTreeNode* root);

#endif //UNTITLED2_STUFE3_H

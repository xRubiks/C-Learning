#include "stufe3.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
    struct BinaryTreeNode *root = createRoot(6);;
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 7);
    insertNode(root, 8);
    insertNode(root, 9);
    insertNode(root, 10);
    insertNode(root, 11);

    printf("PostOrder Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    // Free allocated memory
    return 0;
}
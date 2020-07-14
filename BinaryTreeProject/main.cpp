#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool compareTreeElementtList(const Node* rootA, const Node* rootB){
    // return true if the two trees contain the same elements, false otherwise
}

void printAllNodes(const Node* root){
    if (root != NULL)
    {
        printAllNodes(root->left);
        printf("%d \n", root->data);
        printAllNodes(root->right);
    }
}

struct Node *newNode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);

    /* Otherwise, recur down the tree */
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    /* return the (unchanged) node pointer */
    return node;
}

int main()
{
    /* rootA
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct Node *rootA = NULL;
    rootA = newNode(50);
    insert(rootA, 30);
    insert(rootA, 20);
    insert(rootA, 40);
    insert(rootA, 70);
    insert(rootA, 60);
    insert(rootA, 80);

    /* rootB
              40
           /     \
          30      70
         /       /  \
       20       50   80
                  \
                   60    */
    struct Node *rootB = NULL;
    rootB = newNode(40);
    insert(rootB, 30);
    insert(rootB, 70);
    insert(rootB, 50);
    insert(rootB, 20);
    insert(rootB, 80);
    insert(rootB, 60);

    /* rootC
              40
           /     \
          30      70
         /       /  \
       20       60   80 */
    struct Node *rootC = NULL;
    rootC = newNode(40);
    insert(rootC, 30);
    insert(rootC, 70);
    insert(rootC, 60);
    insert(rootC, 20);
    insert(rootC, 80);

    printAllNodes(rootA);
    printf("\n");
    printAllNodes(rootB);
    return 0;
}

#include <iostream>
#include <vector>
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

struct Node* generateStructure(vector<int> vect){
    struct Node *tempRoot = NULL;
    tempRoot = newNode(vect[0]);
    for(int i=1; i<vect.size(); i++){
        insert(tempRoot, vect[i]);
    }
    return tempRoot;
};

int main()
{
    struct Node *rootA = NULL;
    struct Node *rootB = NULL;
    vector<int> A = {2,1,3};
    vector<int> B = {1,2,3};
    rootA = generateStructure(A);
    rootB = generateStructure(B);


    printAllNodes(rootA);
    printf("\n");
    printAllNodes(rootB);
    return 0;
}

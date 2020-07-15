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

int i = 0;
bool NotTheSame = false;

void storeInOrder(const Node* root, vector<int> &v){
    if (root == NULL){return;}
    storeInOrder(root->left, v);
    v.push_back(root->data);
    storeInOrder(root->right, v);
}

void compare(const Node* rootA, const Node* rootB, vector<int> &v){
    if(NotTheSame == true){return;}

    if(rootA != NULL && rootB == NULL){

    }
    else if(rootA == NULL && rootB != NULL){

    }
    else if(rootA == NULL && rootB == NULL){
        return;
    }
    else if(rootA->left != NULL && rootB->left != NULL){
        compare(rootA->left,rootB->left,v);
    }
    else if(rootA->left != NULL && rootB->left == NULL){
        storeInOrder(rootA,v);
        if(rootB->data != v[0]){
            NotTheSame = true;
            return;
        }
    }
    else if(rootA->left == NULL && rootB->left == NULL){

    }



    i++;
    printf("%d: \n", i);
    //printf("%d: %d %d\n", i, rootA->data, rootB->data);

    return;
}

bool compareTreeElementtList(const Node* rootA, const Node* rootB){
    // return true if the two trees contain the same elements, false otherwise
    vector<int> v;
    compare(rootA, rootB, v);
    return true;
}

void printAllNodes(const Node* root){
    if (root != NULL)
    {
        printAllNodes(root->left);
        printf("%d \n", root->data);
        printAllNodes(root->right);
    }
}

struct Node *newNode(int item){
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int data){
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
    struct Node *rootC = NULL;
    vector<int> A = {4,2,5,1,3};
    vector<int> B = {2,1,3,4,5};
    vector<int> C = {5,3,2,1,4};

    rootA = generateStructure(A);
    rootB = generateStructure(B);
    rootC = generateStructure(C);

    if(compareTreeElementtList(rootA,rootB)){
        printf("Same!");
    }else{
        printf("Not same!");
    }
    return 0;
}

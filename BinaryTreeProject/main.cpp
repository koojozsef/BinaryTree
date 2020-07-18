#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
#define CFG_COMPARE_W_ONE_SUPP_STORE 1
#define CFG_COMPARE_W_REDUCED_SUPP_STORE 0

#define RET_VAL__DEFAULT 0
#define RET_VAL__INPUT_IS_NULL 1
#define RET_VAL__NOT_SAME 2
#define RET_VAL__SAME 3

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

void storeInOrder(const Node* root, queue<int> &q){
    if (root == NULL){return;}
    storeInOrder(root->left, q);
    q.push(root->data);
    storeInOrder(root->right, q);
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

int compareDuringWalkThrough(const Node* root, queue<int> &q){
    //returns instantly if no more node in specific direction
    if (root == NULL){return RET_VAL__INPUT_IS_NULL;}

    //returns if a difference is detected. No more check is needed
    if(compareDuringWalkThrough(root->left, q) == RET_VAL__NOT_SAME){
        return RET_VAL__NOT_SAME;
    }

    //returns if queue is empty -> it means the two trees are different
    //returns if current (smallest) node does not match with expected value
    //  it means the two tree not equal, since the queue is ordered
    if (q.empty() || root->data != q.front()){
        return RET_VAL__NOT_SAME;
    }else{
        printf("- %d -\n",q.front());
        q.pop(); //removes the smallest element, not needed anymore to check
    }

    //returns if a difference is detected. No more check is needed
    if(compareDuringWalkThrough(root->right, q) == RET_VAL__NOT_SAME){
        return RET_VAL__NOT_SAME;
    }

    //if no above condition detected, it means trees have the same values
    return RET_VAL__SAME;
}

bool compareTreeElementtList(const Node* rootA, const Node* rootB){
    // return true if the two trees contain the same elements, false otherwise
    vector<int> v;
    queue<int> q;
    bool retval = RET_VAL__DEFAULT;

#if CFG_COMPARE_W_REDUCED_SUPP_STORE == 1
    compare(rootA, rootB, v);
#endif // CFG_COMPARE_W_REDUCED_SUPP_STORE

#if CFG_COMPARE_W_ONE_SUPP_STORE == 1
    storeInOrder(rootA, q); // - store treeA into Queue
    retval = (compareDuringWalkThrough(rootB, q) == RET_VAL__SAME // - compare queue with treeB during treeB recursion
              && q.empty()); //if queue still has elements, it means trees have not the same size.

#endif // CFG_COMPARE_W_ONE_SUPP_STORE
    return retval;
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

void generateSequence(vector<int> &v, int from, int to){
    for(int i=from;i<to;i++)v.push_back(i+1);
    std::random_shuffle(v.begin(), v.end());
}

int main()
{
    struct Node *rootA = NULL;
    struct Node *rootB = NULL;
    struct Node *rootC = NULL;
    struct Node *rootLongA = NULL;
    struct Node *rootLongB = NULL;
    vector<int> A = {4,2,5,1,3};
    vector<int> B = {2,1,3,4,5};
    vector<int> C = {5,3,2,1,4,6};
    vector<int> longA;
    vector<int> longB;

    generateSequence(longA,0,100);
    generateSequence(longB,0,100);


    rootA = generateStructure(A);
    rootB = generateStructure(B);
    rootC = generateStructure(C);
    rootLongA = generateStructure(longA);
    rootLongB = generateStructure(longB);

    if(compareTreeElementtList(rootLongA,rootLongB)){
        printf("Same!");
    }else{
        printf("Not same!");
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool rotateNums = false;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printSFB() {
      if(root == NULL){
            return;
        }

        int cnt = 1;

        vector<int> numsRow;
        queue<Node*> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty()){
            Node* currNode = nodeQueue.front();
            nodeQueue.pop(); 

            if(currNode->left != NULL){
                nodeQueue.push(currNode->left);
            }
            if(currNode->right != NULL){
                nodeQueue.push(currNode->right);
            }

            cnt--;

            numsRow.push_back(currNode->value);
            if(cnt == 0){
                if(rotateNums){
                    rotateNums = false;
                    reverse(numsRow.begin(), numsRow.end());     
                } else{
                    rotateNums = true;
                }

                for(int i = 0; i < numsRow.size(); i++){
                    cout << numsRow[i] << " ";
                }

                cnt = nodeQueue.size();
                numsRow.clear();      
            }

        }
    }

private:
  	//you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
  
    tree.printSFB();
    return 0;
}
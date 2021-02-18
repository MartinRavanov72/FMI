#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <iterator> 
#include <list> 
#include <stack> 
#include <queue> 
#include <deque> 
using namespace std;
long long cnt = 0, q;
int val = -1;

class Node{
    public:
    Node* left;
    Node* right;
    int value;
    Node(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    private:
    Node* root;

    Node* find(Node* curNode, int value){
        if(curNode == NULL)
            return NULL;
        if(curNode->value == value)
            return curNode;
        if(curNode->value < value)
            return find(curNode->right, value);
        return find(curNode->left, value);
    }

    Node* insert(Node* curNode, int value){
        if(curNode == NULL){
            return new Node(value);
        }
        if(curNode->value < value){
            curNode->right = insert(curNode->right, value);
        } else{
            curNode->left = insert(curNode->left, value);
        }
        return curNode;
    }

    Node* remove(Node* curNode, int value){
        if(value < 0){
            value = findMin(curNode)->value;
        }
        if(curNode == NULL){
            return NULL;
        }
        if(curNode->value < value){
            curNode->right = remove(curNode->right, value);
        } else if(curNode->value > value){
            curNode->left = remove(curNode->left, value);
        } else{
            if(curNode->left == NULL){
                Node* tmp = curNode->right;
                delete curNode;
                return tmp;
            } else if(curNode->right == NULL){
                Node* tmp = curNode->left;
                delete curNode;
                return tmp;
            }
            Node* minInRightSubTree = findMin(curNode->right);
            curNode->value = minInRightSubTree->value;
            curNode->right = remove(curNode->right, curNode->value);
        }
        return curNode;
    }

    void printSorted(Node* root){
        if(root == NULL){
            return;
        }
        printSorted(root->left);
        cout << root->value << " ";
        printSorted(root->right);
    }

    void printLevel(Node* root){
        if(root == NULL){
            return;
        }

        queue<Node*> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty()){
            int nodesAtCurrentLevel = nodeQueue.size();
            while(nodesAtCurrentLevel > 0){
                Node* currNode = nodeQueue.front();
                nodeQueue.pop();
                cout << currNode->value << " ";

                if(currNode->left != NULL){
                    nodeQueue.push(currNode->left);
                }
                if(currNode->right != NULL){
                    nodeQueue.push(currNode->right);
                }

                nodesAtCurrentLevel--;
            }
        }
    }

    void findKthMaxVal(Node* root){
        if(root == NULL){
            return;
        }
        
        findKthMaxVal(root->right);
        cnt++;
        if(cnt == q){
            val = root->value;
            return;
        }
        findKthMaxVal(root->left);
    }

    Node* findMax(Node* root){
        if(root->right != NULL){
            return findMax(root->right);
        }
        return root;
    }

    Node* findMin(Node* root){
        if(root->left != NULL){
            return findMin(root->left);
        }
        return root;
    }

    Node* lowerBound(Node* root, int value){
        if(root == NULL){
            return NULL;
        } else if(root->value == value){
            return root;
        } else if(root->value < value){
            return lowerBound(root->right, value);
        } else{
            Node* tmp = lowerBound(root->left, value);
            if(tmp != NULL)
                return tmp;
            else
                return root;
        }
    }

    public:
    BST(){
        root = NULL;
    }
    void insert(int value){
        if(root == NULL){
            root = new Node(value);
        } else{
            insert(root, value);
        }
    }
    void remove(int value){
        root = remove(root, value);
    }
    bool exists(int value){
        return find(root, value) != NULL;
    }
    int findMin(){
        if(root == NULL)
            return -1;
        return findMin(root)->value;
    }
    int findMax(){
        if(root == NULL)
            return -1;
        return findMax(root)->value;
    }

    void deleteKthMaxEl(){
        if(root == NULL)
            return;
        findKthMaxVal(root);
        remove(val);
    }

    int lowerBound(int value){
        Node* lb = lowerBound(root, value);
        if(lb == NULL)
            return -1;
        else return lb->value;
    }
    void printSorted(){
        printSorted(root);
    }

    void printLevel(){
        printLevel(root);
    }

};


int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;
    cin >> n >> q;
    
    BST tree;

    for(int i = 0; i < n; i++){
        cin >> num;
        tree.insert(num);
    }

    tree.deleteKthMaxEl();
    tree.printLevel();
    
    return 0;
}

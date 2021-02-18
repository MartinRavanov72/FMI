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


class Node{
    public:
    Node* left;
    Node* right;
    string value;
    long long height;
    Node(string value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

class BalancedBST{
    private:
    Node* root;

    Node* find(Node* curNode, string value){
        if(curNode == NULL)
            return NULL;
        if(curNode->value == value)
            return curNode;
        if(curNode->value < value)
            return find(curNode->right, value);
        return find(curNode->left, value);
    }

    long long getHeight(Node* node){
        if(node == NULL){
            return 0;
        }

        return node->height;
    }

    long long getBalance(Node* node){
        if(node == NULL){
            return 0;
        }
            
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* pillar){
        Node* left = pillar->left;
        Node* leftRight = left->right;

        left->right = pillar;
        pillar->left = leftRight;

        pillar->height = max(getHeight(pillar->left), getHeight(pillar->right)) + 1;
        left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

        if(root == pillar){
            root = left;
        }
  
        return left;
    }

    Node* leftRotate(Node* pillar){
        Node* right = pillar->right;
        Node* rightLeft = right->left;

        right->left = pillar;
        pillar->right = rightLeft;

        pillar->height = max(getHeight(pillar->left), getHeight(pillar->right)) + 1;
        right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

        if(root == pillar){
            root = right;
        }

        return right;
    }

    Node* insert(Node* curNode, string value){
        if(curNode == NULL){
            return new Node(value);
        }
        if(curNode->value < value){
            curNode->right = insert(curNode->right, value);
        } else if(curNode->value > value){
            curNode->left = insert(curNode->left, value);
        } else{
            return curNode;
        }

        curNode->height = 1 + max(getHeight(curNode->left), getHeight(curNode->right));

        long long balance = getBalance(curNode);

        if(balance > 1 && value < curNode->left->value){  //ll
            return rightRotate(curNode);
        }
            
        if(balance < -1 && value > curNode->right->value){  //rr
            return leftRotate(curNode);
        }
           
        if(balance > 1 && value > curNode->left->value){  //lr
            curNode->left = leftRotate(curNode->left);
            return rightRotate(curNode);
        }

        if(balance < -1 && value < curNode->right->value){  //rl
            curNode->right = rightRotate(curNode->right);
            return leftRotate(curNode);
        }

        return curNode;
    }

    Node* remove(Node* curNode, string value){
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

                if(tmp == NULL){
                    tmp = curNode;
                    curNode = NULL;
                } else{
                    *curNode = *tmp;
                }
            } else if(curNode->right == NULL){
                Node* tmp = curNode->left;
                
                if(tmp == NULL){
                    tmp = curNode;
                    curNode = NULL;
                } else{
                    *curNode = *tmp;
                }
            } else{
                Node* minInRightSubTree = findMin(curNode->right);
                curNode->value = minInRightSubTree->value;
                curNode->right = remove(curNode->right, curNode->value);
            }   
        }

        if(curNode == NULL){
            return NULL;
        }

        curNode->height = 1 + max(getHeight(curNode->left), getHeight(curNode->right));

        long long balance = getBalance(curNode);

        if(balance > 1 && getBalance(curNode->left) >= 0){  //ll
            return rightRotate(curNode);
        }

        if(balance < -1 && getBalance(curNode->right) <= 0){  //rr
            return leftRotate(curNode);
        }
            
        if(balance > 1 && getBalance(curNode->left) < 0){  //lr
            curNode->left = leftRotate(curNode->left);
            return rightRotate(curNode);
        }

        if(balance < -1 && getBalance(curNode->right) > 0){  //rl
            curNode->right = rightRotate(curNode->right);
            return leftRotate(curNode);
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
            long long nodesAtCurrentLevel = nodeQueue.size();
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

    Node* lowerBound(Node* root, string value){
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

    long long size(Node* node){
        if(node == NULL){
            return 0;
        } 

        return(size(node->left) + 1 + size(node->right));  
    }

    public:
    BalancedBST(){
        root = NULL;
    }
    void insert(string value){
        if(root == NULL){
            root = new Node(value);
        } else{
            insert(root, value);
        }
    }
    void remove(string value){
        root = remove(root, value);
    }
    bool exists(string value){
        return find(root, value) != NULL;
    }
    string findMin(){
        if(root == NULL)
            return "";
        return findMin(root)->value;
    }
    string findMax(){
        if(root == NULL)
            return "";
        return findMax(root)->value;
    }

    string lowerBound(string value){
        Node* lb = lowerBound(root, value);
        if(lb == NULL)
            return "";
        else return lb->value;
    }
    void printSorted(){
        printSorted(root);
        cout << "\n";
    }

    void printLevel(){
        printLevel(root);
    }

    long long size(){
        return size(root);
    }
};

string decimalToBinaryString(int a){
    string binary = "";
    unsigned int mask = 0x80000000u;
    while(mask > 0){
        binary += ((a & mask) == 0) ? '0' : '1';
        mask >>= 1;
    }
    
    return binary;
}


int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;
    string binary;
    cin >> n;

    BalancedBST tree;

    for(int i = 0; i < n; i++){
        cin >> num;
        for(int s = num; ; s = (s - 1) & num){
            binary = decimalToBinaryString(s);
            tree.insert(binary);
            if(s == 0){
                break;
            }
        }
    }

    cout << tree.size();

    return 0;
}

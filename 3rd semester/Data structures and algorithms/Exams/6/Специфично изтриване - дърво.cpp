#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
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

    public:
    BST(){
        root = NULL;
    }

    void insert(int value){
        root = insert(root, value);
    }

    void deletePenultimateAndPrint(){
        deletePenultimate(root);
        printSorted(root);
    }

    void printSorted(Node* root){
        if(root == NULL){
            return;
        }
        printSorted(root->left);
        cout << root->value << " ";
        printSorted(root->right);
    }

    void deletePenultimate(Node* root){
        if(root == NULL){
            return;
        }
        if(root->left != NULL){
            if(root->right == NULL){
                if(root->left->right == NULL && root->left->left == NULL){
                    remove(this->root, root->value);
                    return;
                }
            }if(root->right != NULL){
                if(root->left->right == NULL && root->left->left == NULL && root->right->right == NULL && root->right->left == NULL){
                    remove(this->root, root->value);
                    return;
                }
            }
        }if(root->left == NULL){
            if(root->right != NULL){
                if(root->right->right == NULL && root->right->left == NULL){
                    remove(this->root, root->value);
                    return;
                }
            }
        }
    
        deletePenultimate(root->left);
        deletePenultimate(root->right);
    }

    Node* findMin(Node* root){
        if(root->left != NULL){
            return findMin(root->left);
        }
        return root;
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

    private:
    //you can write helper functions if needed
    Node* root;

    Node* insert(Node* curNode, int value){
        if(curNode == NULL){
            curNode = new Node(value);
        } else if(curNode->value < value){
            curNode->right = insert(curNode->right, value);
        } else if(curNode->value > value){
            curNode->left = insert(curNode->left, value);
        } else{
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main(){
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0; i < n; i++){
        cin >> value;
        tree.insert(value);
    }
    tree.deletePenultimateAndPrint();
    return 0;
}
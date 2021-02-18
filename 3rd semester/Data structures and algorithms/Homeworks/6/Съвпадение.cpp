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
    Node(string value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    private:
    Node* root;

    Node* find(Node* curNode, string value){
        if(curNode == NULL)
            return NULL;
        if(curNode->value == value)
            return curNode;
        if(curNode->value < value) //here
            return find(curNode->right, value);
        return find(curNode->left, value);
    }

    Node* insert(Node* curNode, string value){
        if(curNode == NULL){
            return new Node(value);
        }
        if(curNode->value < value){  //same
            curNode->right = insert(curNode->right, value);
        } else{
            curNode->left = insert(curNode->left, value);
        }
        return curNode;
    }

    Node* remove(Node* curNode, string value){
        if(curNode == NULL){
            return NULL;
        }
        if(curNode->value < value){ //same
            curNode->right = remove(curNode->right, value);
        } else if(curNode->value > value){
            curNode->left = remove(curNode->left, value);
        } else{
            if(curNode->left == NULL){
                Node* tmp = curNode->right;
                delete curNode;
                return tmp;
            }
            Node* maxInLeftSubTree = findMax(curNode->left);
            curNode->value = maxInLeftSubTree->value;
            curNode->left = remove(curNode->left, curNode->value);
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
        } else if(root->value < value){ //same
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
    }

};


int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    string str;

    cin >> n;
    BST tree;

    for(int i = 0; i < n; i++){
        cin >> str;
        tree.insert(str);
    }

    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> str;
        if(tree.exists(str)){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

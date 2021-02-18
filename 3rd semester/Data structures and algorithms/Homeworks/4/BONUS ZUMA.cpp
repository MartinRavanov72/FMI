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
using namespace std;

class Node{
    public:
    int data;
    Node* next = nullptr, * previous = nullptr;

    Node(int data, Node* next = nullptr, Node* previous = nullptr){
        this->data = data;
        this->next = next;
        this->previous = previous;
    }
};

vector<Node*> vec;
int result = 0;

class List{
    public:
    int size;
    Node* head, * tail;

    List(){
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    ~List(){
        Node* it = this->head;
        while(it != nullptr){
            if(it->next == nullptr){
                delete it;
                break;
            }
            it = it->next;
            delete it->previous;
        }
    }

    void push_back(int number){
        if(this->head == nullptr){
            this->head = new Node(number);
            this->tail = this->head;
        } else{
            this->tail->next = new Node(number, nullptr, this->tail);
            this->tail = this->tail->next;
        }
        this->size++;
    }

    void insertAfter(Node* prevNode, int _data){
        if(prevNode == nullptr){
            return;
        }

        Node* newNode = new Node(_data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        newNode->previous = prevNode;

        if(newNode->next != nullptr){
            newNode->next->previous = newNode;
        } else{
            this->tail = newNode;
        }
        vec.push_back(newNode);
        this->size++;
    }

    void print() const{
        if(this->size == 0){
            cout << "-1\n";
        } else{
            Node* i = this->head;
            while(i != nullptr){
                cout << i->data << " ";
                i = i->next;
            }
        }
    }  

    void pop(Node* currNode){
        //base case, size and no 3 adjacent balls
        if((this->size < 3) || 
            (currNode->next != nullptr &&
                currNode->data != currNode->next->data &&
                currNode->previous != nullptr &&
                currNode->data != currNode->previous->data)){
            return;
        }

        Node* right = currNode, * left = currNode;
        int ballsToDestroy = 0;
        
        for(ballsToDestroy; right->next != nullptr && right->next->data == currNode->data; ballsToDestroy++){
            right = right->next;
        }

        for(ballsToDestroy; left->previous != nullptr && left->previous->data == currNode->data; ballsToDestroy++){
            left = left->previous;
        }

        if(ballsToDestroy < 2){
            return;
        }

        ballsToDestroy++;
        this->size -= ballsToDestroy;

        if(this->head == left && this->tail == right){
            this->head = nullptr;
            this->tail = nullptr;
        } else if(left == this->head){
            right->next->previous = nullptr;
            this->head = right->next;
        } else if(right == this->tail){
            left->previous->next = nullptr;
            this->tail = left->previous;
        } else{
            right->next->previous = left->previous;
            left->previous->next = right->next;
            left = left->previous;
            right = right->next;

            if(left->data == right->data){
                this->pop(right);
            } 
        }
        result += ballsToDestroy;
    }

    int zuma(Node* prevNode, int _data){
        this->insertAfter(prevNode, _data);
        Node* currNode = prevNode->next;
        this->pop(currNode);
        return result;
    }
};

int main(){
   /* _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, pos, color;
    cin >> n;

    List list;
    
    for(int i = 0; i < n; i++){
        cin >> color;
        list.push_back(color);
    }

    Node* it = list.head;
    while(it != nullptr){
        vec.push_back(it);
        it = it->next;
    }

    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> pos >> color;
        int size = list.size;
        if(size == 0){
            cout << "Game Over\n";
        } else{          
            Node* searchedNode = vec[pos];
            list.zuma(searchedNode, color);
            cout << result<< '\n';
            result = 0;
        }
    }
    
    list.print();
    
    return 0;
}

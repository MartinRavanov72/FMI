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
    Node* next = nullptr;
    Node* previous = nullptr;

    Node(int data, Node* next = nullptr, Node* previous = nullptr){
        this->data = data;
        this->next = next;
        this->previous = previous;
    }

    void operator=(Node* other){
        this->data = other->data;
        this->previous = other->previous;
        this->next = other->next;
    }
};


class List{
    public:
    int data;
    int size;
    Node* head, * tail, * mid;

    List(){
        this->head = nullptr;
        this->tail = nullptr;
        this->mid = nullptr;
        this->size = 0;
    }

    ~List(){
        Node* i = this->head;
        while(i != nullptr){
            if(i->next == nullptr){
                delete i;
                break;
            }
            i = i->next;
            delete i->previous;
        }
    }

    void push_back(int number){
        if(this->head == nullptr){
            this->head = new Node(number);
            this->tail = this->head;
            this->mid = this->head;
        } else{
            this->tail->next = new Node(number, nullptr, this->tail);
            this->tail = this->tail->next;
            if(this->size % 2 == 0){
                this->mid = this->mid->next;
            }    
        }
        this->size++;
    }

    void pop_back(){
        if(this->head == this->tail){
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            this->mid = nullptr;
            this->size--;
            return;
        }
        
        Node* temp = this->tail;
        this->tail = this->tail->previous;
        this->tail->next = nullptr;
        delete temp;
        if(this->size % 2 != 0){
            this->mid = this->mid->previous;
        }
        this->size--;
    }

    void print() const{
        Node* i = this->head;
        while(i != nullptr){    
            cout << i->data << " ";
            i = i->next;
        }
    }

     void milen(){
        if(this->size > 1){
            if(this->size % 2 != 0){
                this->mid = this->mid->previous;
            }

            this->tail->next = this->head;
            this->mid->next->previous = nullptr;
            this->head->previous = this->tail;

            this->head = this->mid->next;

            this->mid->next = nullptr;

            Node* temp = this->tail;
            this->tail = this->mid;
            this->mid = temp;
        }     

    }

    
};

int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;
    cin >> n;

    List list;
    string command;

    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == "add"){
            cin >> num;
            list.push_back(num);
        } else if(command == "gun"){
            list.pop_back();
        } else{
            list.milen();
        }
    }

    cout << list.size << endl;
    
    list.print();
    

    return 0;
}
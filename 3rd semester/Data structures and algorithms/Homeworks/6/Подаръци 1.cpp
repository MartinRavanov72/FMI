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
#include <map> 
using namespace std;

int cnt = 0;

class Node{
    public:
    vector<Node*> children;
    int value;
    Node(int value){
        this->children;
        this->value = value;
    }
};

void getNumberOfDescendants(Node* node){
    for(auto child : node->children){
        cnt++;
        getNumberOfDescendants(child);
    }
}


int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num1, num2;
    cin >> n;
    vector<Node*> nodes;
    nodes.push_back(new Node(0));
    while(n > nodes.size()){
        cin >> num1 >> num2;
        Node* newNode = new Node(num2);
        nodes[num1]->children.push_back(newNode);
        nodes.push_back(newNode);
    }

    for(auto node : nodes ){
        getNumberOfDescendants(node);
        cout << cnt << " ";
        cnt = 0;
    }

    return 0;
}

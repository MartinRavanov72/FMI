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
using namespace std;

stack<int> minElStack;

class Stack{
    private:
    stack<int> s;
    
    public:
    void push(int x){
        this->s.push(x);

        if(minElStack.empty() || x <= minElStack.top()){
            minElStack.push(x);
        }
    }

    void pop(){
        if(minElStack.top() == this->s.top()){
            minElStack.pop();
        }
        this->s.pop();
    }

    int peek(){
        return this->s.top();
    }

    int min(){
        return minElStack.top();
    }
};

int main(){
   /* _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;
    string command;

    cin >> n;

    Stack st;
    
    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == "push"){
            cin >> num;
            st.push(num);
        } else if(command == "pop"){
            st.pop();
        } else if(command == "peek"){
            cout << st.peek() << '\n';
        } else{
            cout << st.min() << '\n';
        }
    }
    
    return 0;
}

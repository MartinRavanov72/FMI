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

class Queue{
    public:
    queue<long long> q;
    deque<long long> d;

    void push(long long element){
        if(this->q.size() == 0){
            this->q.push(element);
            this->d.push_back(element);
        } else{
            this->q.push(element);
            while(!this->d.empty() && this->d.back() > element){
                this->d.pop_back();
            }

            this->d.push_back(element);
        }
    }

    void pop(){
        if(this->q.front() == this->d.front()){
            this->d.pop_front();   
        } 

        this->q.pop();
    }

    long long min(){
        return this->d.front();
    }
};


int main(){
   /* _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long sum = 0, num, n, d;
    cin >> n >> d;

    Queue q;

    for(int i = 0; i <= n; i++){
        if(i < d){
            cin >> num;
            q.push(num);
        } else{
            sum += q.min();

            if(i != n){
                q.pop();
                cin >> num;
                q.push(num);
            }     
        }
    }

    cout << sum;
 
    return 0;
}

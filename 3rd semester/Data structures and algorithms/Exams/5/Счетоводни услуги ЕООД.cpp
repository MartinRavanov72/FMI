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


int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, num, sum = 0;
    cin >> n;
    stack<long long> undo;
    stack<long long> redo;
   
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num == -1){
            if(undo.size() != 0){
                redo.push(undo.top());
                sum -= undo.top();
                undo.pop();
            }
        } else if(num == -2){
            if(redo.size() != 0){
                undo.push(redo.top());
                sum += redo.top();
                redo.pop();
            } 
        } else{
            redo = stack<long long>();
            sum += num;
            undo.push(num);
        }
    }

    cout << sum;
 
    return 0;
}

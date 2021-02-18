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
   /* _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long num, n;
    cin >> n;

    stack<int> s;
    stack<int> helper;
    queue<int> result;
    bool write = true;

    for(int i = 0; i < n; i++){
        write = true;
        cin >> num;
        if(num > 0){
            s.push(num);
        } else{
            num = -num;
            if(s.size() == 0){
                result.push(-num);
            } else{
                if(s.top() > num){

                } else if(s.top() == num){
                    s.pop();
                } else{
                    while(s.size() > 0){
                        if(num == s.top()){
                            s.pop();
                            write = false;
                            break;
                        } else if(num < s.top()){
                            break;
                        } else{
                            s.pop();
                        }
                    }

                    if(s.size() == 0 && write){
                        result.push(-num);
                    }
                }
            }
        }
    }

    int size = s.size();

    for(int i = 0; i < size; i++){
        helper.push(s.top());
        s.pop();
    }

    size = helper.size();

    for(int i = 0; i < size; i++){
        result.push(helper.top());
        helper.pop();
    }

    size = result.size();

    for(int i = 0; i < size; i++){
        cout << result.front() << " ";
        result.pop();
    }
 
    return 0;
}

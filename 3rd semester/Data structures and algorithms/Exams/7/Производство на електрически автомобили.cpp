#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <map>
#include <iterator> 
#include <list> 
#include <stack> 
#include <queue> 
#include <deque> 

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;
    cin >> n;

    priority_queue<int> biddings;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num == -1){
            if(!biddings.empty()){
                cout << biddings.top() << " ";
                biddings.pop();
            }
        } else{
            biddings.push(num);
        }
    }
    
    return 0;
}
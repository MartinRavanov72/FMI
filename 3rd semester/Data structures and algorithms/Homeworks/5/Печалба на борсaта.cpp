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
using namespace std;

int main(){
   /* _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long sum = 0, cnt = 0, num, n, k, res = numeric_limits<long long>::max();
    cin >> n >> k;

    queue<long long> q;
    while(cnt < n){
        while(sum < k && cnt < n){
            cin >> num;
            q.push(num);
            sum += num;
            cnt++;
        }
        if(sum >= k && q.size() < res){
            res = q.size();
        }

        while(sum - q.front() >= k && !q.empty()){
            sum -= q.front();
            q.pop();
        }
        
        if(!q.empty() && sum >= k && res > q.size()){
            res = q.size();
        }

        if(sum >= k && !q.empty()){
            sum -= q.front();
            q.pop();
        }
            
    }
    

    if(res == numeric_limits<long long>::max()){
        cout << -1;
    } else{
        cout << res;
    }
    
    
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int k, t, b, n, cnt = 0, num, cnt2 = 0;
    
    cin >> k >> t >> b >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    
    for(int i= 0; i < n; i++){
        cin >> num;
        cnt++;
        pq.push(num);
        
        if(cnt % t == 0 && cnt2 < k*b){
            for(int j= 0; j < k; j++){
                int el = pq.top();
                cout << el << " ";
                pq.pop();
                cnt2++;
            }
        }
        
        
    }
    
    while(!pq.empty() && cnt2 < k*b){
        for(int j= 0; j < k; j++){
            int el = pq.top();
            cout << el << " ";
            pq.pop();
            cnt2++;
        }
    }
    
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<vector<int>> adj;


bool bfs(int start, int end){
    vector<bool> visited;
    
    visited.assign(n, 0);
    
    queue<int> q;
    
    visited[start] = 1;
    
    q.push(start);
    
    while(!q.empty()){
        int t = q.front();
        
        
        
        if(t == end){
            return true;
        }
        
        q.pop();
        
        for(auto item: adj[t]){
            if(!visited[item]){
                visited[item] = true;
                q.push(item);
            }
            
        }
    }
    
    return false;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int m, x, y, k;
    
    cin >> n >> m;
    
    adj.assign(n, vector<int>());
    
    for(int i= 0; i < m; i++){
        cin >> x >> y;
        
        x--;
        y--;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
     
    }
    
    cin >> k;
    
    for(int i= 0; i < k; i++){
        cin >> x >> y;
        
        x--;
        y--;
        
        cout << bfs(x, y) << " ";
    }
    return 0;
}
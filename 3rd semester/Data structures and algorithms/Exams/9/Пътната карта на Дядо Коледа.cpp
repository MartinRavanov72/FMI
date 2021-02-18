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
#include <unordered_map>
#include <iterator> 
#include <list> 
#include <stack> 
#include <queue> 
#include <deque> 

using namespace std;

int m, cnt = 0;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v){
    visited[v] = true;

    for(auto i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[*i]){
            dfs(*i);
        }     
    }     
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, v1, v2;
    
    cin >> m;
    cin >> n;

    adj.assign(m, vector<int>());
    visited.assign(m, false);
    
    for(int i = 0; i < n; i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for(int i = 0; i < m; i++){
        if(!visited[i] && adj[i].size() != 0){
            dfs(i);           
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
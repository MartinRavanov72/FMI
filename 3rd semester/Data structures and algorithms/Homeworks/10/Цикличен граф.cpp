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

vector<bool> visited;
vector<vector<int>> g;

void dfs(int v, bool& hasCycle){
    if(visited[v]){
        hasCycle = true;
        return;
    }

    visited[v] = true;

    for(auto x : g[v]){
        dfs(x, hasCycle);
    }

    visited[v] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, v, e, xi, yi, wi;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v >> e;

        bool hasCycle = false;

        g.assign(v, vector<int>());
        visited.assign(v, false);

        for(int j = 0; j < e; j++){
            cin >> xi >> yi >> wi;
            xi--;
            yi--;
            g[xi].push_back(yi);
        }

        for(int j = 0; j < v; j++){
            dfs(j, hasCycle);
        }

        cout << (hasCycle ? "true " : "false ");
    }

    return 0;
}
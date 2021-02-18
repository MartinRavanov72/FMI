#define _CRT_SECURE_NO_WARNINGS

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

int m, n;
vector<pair<int, int>> edges;
vector<vector<int>> adj;
vector<int> visited;

int dfs(int v){
    int count = 1;

    visited[v] = true;

    for(auto u : adj[v]){
        if(!visited[u]){
            count += dfs(u);
        }
    }

    return count;
}

bool isValid(int h){
    visited.assign(n, false);
    adj.clear();
    adj.resize(n);

    for(int i = 0; i < h; i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    int res = dfs(0);

    return res == n;
}

void binarySearchResult(int l, int r){
    int res = -1;

    while(l <= r){
        int mid = (l + r) / 2;

        if(isValid(mid)){
            res = mid;
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v1, v2;

    cin >> n >> m;

    adj.resize(n);
    visited.assign(n, false);

    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;

        v1--;
        v2--;

        edges.push_back({v1, v2});
    }

    binarySearchResult(0, m);

    return 0;
}
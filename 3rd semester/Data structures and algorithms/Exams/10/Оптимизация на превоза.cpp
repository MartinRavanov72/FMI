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

int k;
unordered_map<int, int> m;
vector<vector<pair<int, int>>> adj;
vector<int> visited;

void dfs(int v, int length = 0, int cost = 0){
    if(length == k){
        m[cost]++;
        return;
    }

    visited[v] = true;

    for(auto i : adj[v]){
        if(!visited[i.first]){
            dfs(i.first, length + 1, cost + i.second);
        }
    }

    visited[v] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, v1, v2, w, cnt = 0, cost = -1;

    cin >> v >> e;

    adj.resize(v);
    visited.assign(v, false);

    for(int i = 0; i < e; i++){
        cin >> v1 >> v2 >> w;

        v1--;
        v2--;

        adj[v1].push_back({v2, w});
    }

    cin >> k;

    for(int i = 0; i < v; i++){
        dfs(i);
    }

    for(auto kvp : m){
        if(cnt < kvp.second || (cost < kvp.first && cnt == kvp.second)){
            cost = kvp.first;
            cnt = kvp.second;
        }
    }

    cout << cost << endl;

    return 0;
}
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
#include <stack> 
#include <queue> 
#include <deque> 

using namespace std;

int m, n;
vector<pair<int, pair<int, int>>> edges;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;

void dfs(int s, int low, int high){
    visited[s] = true;
    
    for(auto i = adj[s].begin(); i != adj[s].end(); i++){
        if(!visited[i->first] && i->second >= edges[low].first && i->second <= edges[high].first){
            dfs(i->first, low, high);
        }
    }
}

bool checkConnected(int low, int high){
    visited.clear();
    visited.assign(n, false);

    dfs(0, low, high);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            return false;
        }
    }

    return true;
}


void searchResult(){
    int high = 0, low = 0, optHigh = 0, optLow = 0, opt = numeric_limits<int>::max();
    bool isConnected = false;

    sort(edges.begin(), edges.end());

    while(high < edges.size() - 1){
        if(!isConnected){
            high++;
        }
        else{
            low++;
        }

        isConnected = checkConnected(low, high);

        if(isConnected){
            if(edges[high].first - edges[low].first < opt){
                opt = edges[high].first - edges[low].first;
                optLow = low;
                optHigh = high;
            }
        }
    }

    cout << edges[optLow].first << " " << edges[optHigh].first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v1, v2, w;

    cin >> n >> m;

    adj.resize(n);

    for(int i = 0; i < m; i++){
        cin >> v1 >> v2 >> w;

        v1--;
        v2--;

        edges.push_back({w, {v1, v2}});
        adj[v1].push_back({v2, w});
        adj[v2].push_back({v1, w});
    }

    searchResult();

    return 0;
}
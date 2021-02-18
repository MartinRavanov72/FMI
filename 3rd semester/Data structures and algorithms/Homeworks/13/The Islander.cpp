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

unordered_map<int, bool> visited;
unordered_map<int, vector<int>> g;
int v;

void dfs(int v){
    visited[v] = true;

    for(auto u : g[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
}

bool isConnected(){
    for(auto kvp : g){
        visited[kvp.first] = false;
    }

    dfs(g.begin()->first);

    for(auto kvp : g){
        if(!visited[kvp.first]){
            return false;
        }
    }

    return true;
}

int checkEulerianPath(){
    if(!isConnected() || g.size() != v){
        return 0;
    }

    int oddVerticesCount = 0;

    for(auto kvp : g){
        if(kvp.second.size() % 2 == 1){
            oddVerticesCount++;
        }
    }

    if(oddVerticesCount > 2){
        return 0;
    } else if(oddVerticesCount == 2){
        return 1;
    } else {
        return 2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, v1, v2;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v >> e;

        for(int j = 0; j < e; j++){
            cin >> v1 >> v2;

            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }

        int result = checkEulerianPath();

        if(result == 0){
            cout << "none" << endl;
        } else if(result == 1){
            cout << "epath" << endl;
        } else{
            cout << "ecycle" << endl;
        }

        visited.clear();
        g.clear();
    }

    return 0;
}
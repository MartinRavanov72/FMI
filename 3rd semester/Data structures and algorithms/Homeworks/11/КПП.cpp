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

vector<vector<pair<int, int>>> adj;
vector<bool> visited;
stack<int> st;

void topologicalSort(int v){
    visited[v] = true;

    for(auto i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[i->first]){
            topologicalSort(i->first);
        }
    }

    st.push(v);
}

 
void findMostWeightedPath(int from, int to){
    vector<int> distances(adj.size(), numeric_limits<int>::min());
    vector<int> sameDistances(adj.size(), 0);

    visited.assign(adj.size(), 0);

    for(int i = 0; i < adj.size(); i++){
        if(!visited[i]){
            topologicalSort(i);
        }
    }

    distances[from] = 0;
    sameDistances[from] = 1;

    while(!st.empty()){
        int v1 = st.top();
        st.pop();

        if(distances[v1] != numeric_limits<int>::min()){
            for(auto i = adj[v1].begin(); i != adj[v1].end(); ++i){
                if(distances[i->first] == distances[v1] + i->second){
                    sameDistances[i->first] += sameDistances[v1];
                }

                if(distances[i->first] < distances[v1] + i->second){
                    distances[i->first] = distances[v1] + i->second;
                    sameDistances[i->first] = sameDistances[v1];
                }
            }
        }
    }

    cout << distances[to] << " " << sameDistances[to] ;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v, w, a, b;

    cin >> n >> m;

    adj.resize(n);

    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    cin >> a >> b;

    findMostWeightedPath(a, b);
}
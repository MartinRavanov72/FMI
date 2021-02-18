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
vector<int> distances;

void findLeastWeighedPaths(int from){
    visited.assign(adj.size(), false);
    distances.assign(adj.size(), numeric_limits<int>::max());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;     
    
    pq.push({0, from});
    distances[from] = 0;

    while(!pq.empty()){
        int v1 = pq.top().second;
        pq.pop();

        if(visited[v1]){
            continue;
        }
        visited[v1] = true;

        for(auto i = adj[v1].begin(); i != adj[v1].end(); i++){
            int v2 = (*i).first;
            int weight = (*i).second;

            if(visited[v2]){
                continue;
            }

            if(distances[v2] > distances[v1] + weight){
                distances[v2] = distances[v1] + weight;
                pq.push({distances[v2], v2});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v1, v2, w, k, tEl, q, searched;

    cin >> n >> m;

    adj.resize(n + 1);

    for(int i = 0; i < m; i++){
        cin >> v1 >> v2 >> w;
        adj[v1].push_back({v2, w});
        adj[v2].push_back({v1, w});
    }

    cin >> k;

    for(int i = 0; i < k; i++){
        cin >> tEl;
        adj[tEl].push_back({n, 0});
        adj[n].push_back({tEl, 0});
    }

    cin >> q;

    findLeastWeighedPaths(n);

    for(int i = 0; i < q; i++){
        cin >> searched;
        cout << distances[searched] << "\n";
    }

    return 0;
}
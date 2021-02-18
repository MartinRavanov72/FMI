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
vector<int> used;

void findLeastWeighedPath(int from){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distances;

    for(int i = 0; i < adj.size(); i++){
        distances.push_back(numeric_limits<int>::max());
    }

    used.assign(adj.size(), false);

    pq.push({0, from});
    distances[from] = 0;

    while(!pq.empty()){
        int v1 = pq.top().second;
        pq.pop();

        if(used[v1]){
            continue;
        }

        used[v1] = true;

        for(auto i = adj[v1].begin(); i != adj[v1].end(); i++){
            int v2 = (*i).first;
            int weight = (*i).second;

            if(distances[v2] > distances[v1] + weight && !used[v2]){
                distances[v2] = distances[v1] + weight;
                pq.push({distances[v2], v2});
            }
        }
    }

    for(int i = 0; i < adj.size(); i++){
        if(i != from){
            cout << (distances[i] == numeric_limits<int>::max() ? -1 : distances[i])<< " ";
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v1, v2, w, s;

    cin >> n >> m;

    adj.resize(n);

    for(int i = 0; i < m; i++){
        cin >> v1 >> v2 >> w;

        adj[v1 - 1].push_back({v2 - 1, w});
        adj[v2 - 1].push_back({v1 - 1, w});
    }

    cin >> s;
    s--;

    findLeastWeighedPath(s); 
}
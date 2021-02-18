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

int findLeastWeighedPath(int from, int to){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distances;

    for(int i = 0; i < adj.size(); i++){
        distances.push_back(numeric_limits<int>::max());
    }

    pq.push({0, from});
    distances[from] = 0;

    while(!pq.empty()){
        int v1 = pq.top().second;
        pq.pop();

        for(auto i = adj[v1].begin(); i != adj[v1].end(); i++){
            int v2 = (*i).first;
            int weight = (*i).second;

            if(distances[v2] > distances[v1] + weight){
                distances[v2] = distances[v1] + weight;
                pq.push({distances[v2], v2});
            }
        }
    }

    if(distances[to] == numeric_limits<int>::max()){
        return -1;
    }

    return distances[to];
}
         

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, v1, v2;

    cin >> n >> m >> k;

    adj.resize(n);

    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;

        adj[v1].push_back({v2, 0});
        adj[v2].push_back({v1, 0});
    }

    for(int i = 0; i < k; i++){
        cin >> v1 >> v2;

        adj[v1].push_back({v2, 1});
        adj[v2].push_back({v1, 1});
    }

    cout << findLeastWeighedPath(0, n - 1) << endl;
}
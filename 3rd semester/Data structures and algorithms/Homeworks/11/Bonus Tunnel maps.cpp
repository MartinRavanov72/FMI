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

class Road{
    public:
    int to, kg, time;

    Road(int to, int kg, int time){
        this->to = to;
        this->kg = kg;
        this->time = time;
    }
};

int k;
vector<vector<Road>> adj;

bool isValid(int weight){
    vector<int> distances(adj.size(), numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    distances[0] = 0;

    while(!pq.empty()){
        int v1 = pq.top().second;
        pq.pop();

        for(auto i = adj[v1].begin(); i != adj[v1].end(); i++){
            if(weight < (*i).kg){
                continue;
            }

            int v2 = (*i).to;
            int time = (*i).time;

            if(distances[v2] > distances[v1] + time){
                distances[v2] = distances[v1] + time;
                pq.push({distances[v2], v2});
            }
        }
    }

    return distances[adj.size() - 1] <= k;
}

int binarySearchResult(int l, int r){
    int res = -1;

    while(l <= r){
        int mid = (l + r) / 2;

        if(isValid(mid)){
            if(res == -1){
                res = mid;
            }

            res = min(res, mid);

            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v, c, t, maxKg = -1;

    cin >> n >> m >> k;

    adj.resize(n);

    for(int i = 0; i < m; i++){
        cin >> u >> v >> c >> t;
        u--;
        v--;

        maxKg = max(maxKg, c);

        adj[u].push_back(Road(v, c, t));
    }

    cout << binarySearchResult(0, maxKg) << endl;

    return 0;
}
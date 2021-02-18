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

void findLeastWeightedPath(int from, int to){
    vector<long long> distances(adj.size(), numeric_limits<long long>::max());
    vector<int> sameDistances(adj.size(), 0);
    set<pair<long long, int>> s;

    distances[from] = 0;
    sameDistances[from] = 1;
    s.insert({0, from});

    while(!s.empty()){
        int v1 = s.begin()->second;
        s.erase(s.begin());

        for(auto i = adj[v1].begin(); i != adj[v1].end(); i++){
            int v2 = (*i).first;
            int weight = (*i).second;

            if(distances[v2] == distances[v1] + weight){
                sameDistances[v2] += sameDistances[v1];
                if(sameDistances[v2] >= 1000000007){
                    sameDistances[v2] -= 1000000007;
                }
            }

            if(distances[v2] > distances[v1] + weight){
                s.erase({distances[v2], v2});
                distances[v2] = distances[v1] + weight;
                sameDistances[v2] = sameDistances[v1];
                s.insert({distances[v2], v2});
            }
        }
    }

    cout << distances[to] << " " << sameDistances[to] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v, w;

    scanf("%d", &n);
    scanf("%d", &m);

    adj.resize(n);

    for(int i = 0; i < m; i++){
        scanf("%d", &u);
        scanf("%d", &v);
        scanf("%d", &w);

        u--;
        v--;

        adj[u].push_back({v, w});
    }

    findLeastWeightedPath(0, n - 1);
}
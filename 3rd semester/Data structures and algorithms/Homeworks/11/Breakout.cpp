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

int n, m;
map<pair<int, int>, vector<tuple<int, int, int>>> adj;
map<pair<int, int>, int> distances;
 
void findLeastWeighedPath(int fromX, int fromY){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for(auto kvp : adj){
        distances[kvp.first] = numeric_limits<int>::max();
    }

    pq.push({0, {fromX, fromY}});
    distances[{fromX, fromY}] = 0;

    while(!pq.empty()){
        pair<int, int> v1 = pq.top().second;
        pq.pop();

        for(auto i = adj[v1].begin(); i != adj[v1].end(); i++){
            pair<int, int> v2 = {get<0>(*i), get<1>(*i)};
            int weight = get<2>(*i);

            if(distances[v2] > distances[v1] + weight){
                distances[v2] = distances[v1] + weight;
                pq.push({distances[v2], v2});
            }
        }
    }
}

bool isValid(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char ch;

    cin >> n >> m;

    vector<vector<int>> grid;
    grid.resize(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ch;

            if(ch == '#'){
                grid[i].push_back(1);
            } else{
                grid[i].push_back(0);
            }
        }
    }

    vector<int> xd{-1, 0, 1, 0}, yd{0, -1, 0, 1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                if(isValid(i + xd[k], j + yd[k])){
                    adj[{i, j}].push_back({i + xd[k], j + yd[k], grid[i][j]});
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                adj[{n, m}].push_back({i, j, 0});
            }
        }
    }

    findLeastWeighedPath(n, m);

    int max = numeric_limits<int>::min();
    int count = 0;

    for(auto kvp : distances){
        if(kvp.second > max && isValid(kvp.first.first, kvp.first.second) && grid[kvp.first.first][kvp.first.second] == 0){
            max = kvp.second;
            count = 1;
        } else if(kvp.second == max && isValid(kvp.first.first, kvp.first.second) && grid[kvp.first.first][kvp.first.second] == 0){
            count++;
        }
    }

    cout << count;
}
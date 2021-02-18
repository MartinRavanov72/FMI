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

map<pair<int, int>, bool> visited;


map<pair<int, int>, vector<tuple<int, int, int>>> adj;
int n, m, result = 0;
pair<int, int> start, endNode;

void hamilton(pair<int, int> startNode, vector<pair<int, int>>& path, int vertices){
    if(path.size() == vertices){ 
        if(path[vertices - 1] == endNode){
            result++;
        } 

        return;
    }

    for(auto w : adj[startNode]){
        if(!visited[{get<0>(w), get<1>(w)}] && get<2>(w) != 1){
            visited[{get<0>(w), get<1>(w)}] = true;
            path.push_back({get<0>(w), get<1>(w)});

            hamilton({get<0>(w), get<1>(w)}, path, vertices);

            visited[{get<0>(w), get<1>(w)}] = false;
            path.pop_back();
        }
    }
}

bool isValid(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<vector<int>> grid;
    grid.resize(n);

    int vertices = n * m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch;
            cin >> ch;

            if(ch == 'x'){
                grid[i].push_back(1);
                vertices--;
            } else if(ch == 's'){
                start = {i, j};
                grid[i].push_back(0);
            } else if(ch == 'e'){
                endNode = {i, j};
                grid[i].push_back(0);
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

    vector<pair<int, int>> path;
    path.push_back(start);

    for(auto kvp : adj){
        visited[kvp.first] = false;
    }

    visited[start] = true;

    hamilton(start, path, vertices);

    cout << result;

    return 0;
}
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

int n;
vector<int> degree;
vector<int> rootsResult;
vector<vector<int>> g;

void rootsMinHeight(){
    queue<int> q;

    for(int i = 0; i < n; i++){
        if(degree[i] == 1){
            q.push(i);
        }
    }

    while(n > 2){
        int size = q.size();
        n -= size;

        for(int i = 0; i < size; i++){
            int v = q.front();
            q.pop();

            for(auto u : g[v]){
                degree[u]--;

                if(degree[u] == 1){
                    q.push(u);
                }
            }
        }
    }
    
    while(!q.empty()){
        rootsResult.push_back(q.front());
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, u;

    cin >> n;

    degree.assign(n, 0);
    g.resize(n);

    for(int i = 0; i < n - 1; i++){
        cin >> v >> u;

        g[v].push_back(u);
        g[u].push_back(v);

        degree[v]++;
        degree[u]++;
    }

    rootsMinHeight();

    sort(rootsResult.begin(), rootsResult.end());

    for(int i = 0; i < rootsResult.size(); i++){
        cout << rootsResult[i] << " ";
    }

    return 0;
}
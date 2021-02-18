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

vector<bool> visited;
vector<vector<int>> g;
int res = 0;

int dfs(int v){
    int cntAll = 0;

    visited[v] = true;

    for(auto child : g[v]){
        if(!visited[child]){
            int cntSub = dfs(child);

            if(cntSub % 2 == 0){
                res++;
            } else{
                cntAll += cntSub;
            }
        }
    }

    return cntAll + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, v1, v2;
   
    cin >> v >> e;

    g.resize(v);
    visited.assign(v, false);

    for(int i = 0; i < e; i++){
        cin >> v1 >> v2;

        v1--;
        v2--;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
 
    dfs(0);
   
    cout << res;
 
    return 0;
}
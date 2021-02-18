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

vector<tuple<int, int, int>> adj;
set<int> nums;
int v;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, l, tests, num, v1, v2, w;
    

    cin >> n >> m;

    vector<vector<int>> g;
    g.assign(n, vector<int>());

    for(int i = 0; i < n; i++){
        g[i].assign(n, 0);
    }

    g.resize(n);

    for(int i = 0; i < m; i++){
        cin >> v1 >> v2 >> w;

        g[v1].push_back(1);
        adj.push_back({v1, v2, w});
    }

    cin >> l;

    for(int i = 0; i < l; i++){
        cin >> num;
        nums.insert(num);
    }

    for(int i = 0; i < m; i++){
        if(nums.count(get<2>(adj[i])) == 0){
            g[get<0>(adj[i])][get<1>(adj[i])] = 1;
        }
    }

    cin >> tests;

    for(int i = 0; i < tests; i++){
        cin >> l;

        bool pass = true;

        vector<int> path(l);

        for(int j = 0; j < l; j++){
            cin >> path[j];
        }

        for(int j = 0; j < l - 1; j++){
            if(g[path[j]][path[j + 1]] == 0){
                pass = false;

                break;
            }
        }

        if(pass){
            cout << '1';
        }
        else{
            cout << '0';
        }
    }

    return 0;
}
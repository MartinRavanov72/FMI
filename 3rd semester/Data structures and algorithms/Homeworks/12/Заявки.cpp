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

int m, n;
vector<pair<int, int>> edges;
vector<int> parent;

int find(int v){
    if(parent[v] == v){
        return v;
    }

    return parent[v] = find(parent[v]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v1, v2, q, type;

    cin >> n >> m;

    parent.resize(n);

    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;

        v1--;
        v2--;

        edges.push_back({v1, v2});
    }

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int rank1 = find(edges[i].first);
        int rank2 = find(edges[i].second);

        if(rank1 != rank2){
            parent[rank2] = rank1;
        }
    }

    cin >> q;

    for(int i = 0; i < q; ++i){
        cin >> type >> v1 >> v2;

        v1--;
        v2--;

        int rank1 = find(v1);
        int rank2 = find(v2);

        if(type == 1){
            cout << (rank1 == rank2);
        }
        else if(rank1 != rank2){          
            parent[rank2] = rank1;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> adj;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n, q, city;

    cin >> m;
    adj.resize(m);

    for(int i = 0; i < m; i++){
        adj[i].resize(m);
    }

    for(int i = 0; i < m; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> city;

            adj[i][city] = 1;
            adj[city][i] = 1;
        }
    }

    vector<int> result;
    bool hasRoad = 1;

    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> n;
        vector<int> cities;

        for(int j = 0; j < n; j++){
            cin >> city;
            cities.push_back(city);
        }

        for(int i = 0; i < n - 1; i++){
            if(!adj[cities[i]][cities[i + 1]]){
                hasRoad = 0;
                break;
            }
        }

        if(hasRoad){
            result.push_back(1);
        }
        else{
            result.push_back(0);
        }

        hasRoad = true;
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}
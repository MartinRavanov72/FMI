#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <iterator> 
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> pairs;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pairs.push_back(make_pair(a, b));
    }

    sort(pairs.begin(), pairs.end());

    vector<pair<int, int>> result;
    result.push_back(pairs[0]);

    int cnt = 0;
    
    for(int i = 0; i < pairs.size(); i++){
        if(result[cnt].second < pairs[i].first){
            result.push_back(pairs[i]);
            cnt++;
        } else {
            if(result[cnt].second >= pairs[i].second){
                continue;
            } 
            result[cnt].second = pairs[i].second; 
        }
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i].first << " " << result[i].second << endl;
    }
    return 0;
}

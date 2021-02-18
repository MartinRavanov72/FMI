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

bool sortMethod(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first == b.first){
        return a.second > b.second;
    } 

    return a.first < b.first;  
}

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> pairs;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pairs.push_back(make_pair(a, b));
    }

    sort(pairs.begin(), pairs.end(), sortMethod);

    vector<pair<int, int>> result;
    result.push_back(pairs[0]);

    int cnt = 0;
    int resultCount = 0;
    
    for(int i = 1; i < pairs.size(); i++){
        if((result[cnt].second >= pairs[i].first) && (result[cnt].second >= pairs[i].second)){
            resultCount++;
        } else{
            result.push_back(pairs[i]);
            cnt++;
        }
    }

    cout << resultCount << endl;

    return 0;
}
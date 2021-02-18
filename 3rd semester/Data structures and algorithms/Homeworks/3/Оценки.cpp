#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <iterator> 
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    vector<long long> points;
    vector<pair<long long, long long>> pairs;

    for(long long i = 0; i < n; i++){
        long long a;
        cin >> a;
        points.push_back(a);
    }

    for(long long i = 0; i < k; i++){
        long long a, b;
        cin >> a >> b;
        pairs.push_back(make_pair(a, b));
    }

    sort(points.begin(), points.end());

    for(long long i = 0; i < k; i++){
        if(pairs[i].first > pairs[i].second){
            cout << "0" << endl;
        } else{
            auto a = lower_bound(points.begin(), points.begin() + n, pairs[i].first);
            auto b = upper_bound(points.begin(), points.begin() + n, pairs[i].second);
            cout << b - a << endl;
        }
    }

    return 0;
}
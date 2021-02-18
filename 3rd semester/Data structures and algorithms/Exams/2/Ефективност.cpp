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

bool sortMethod(const tuple<int, int, int>& a, const tuple<int, int, int>& b){
    double firstNum = ((double)get<1>(a) * get<1>(a)) / (double)get<2>(a);
    double secondNum = ((double)get<1>(b) * get<1>(b)) / (double)get<2>(b);
    if(firstNum == secondNum){
        return get<1>(a) > get<1>(b);
    }

    return firstNum > secondNum;
}

int main(){
    int n;
    cin >> n;

    vector<tuple<int, int, int>> tuples;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        tuples.push_back(make_tuple(i+1, a, b));
    }

    sort(tuples.begin(), tuples.end(), sortMethod);

    for(int i = 0; i < n; i++){
        cout << get<0>(tuples[i]) << " ";
    }

    return 0;
}
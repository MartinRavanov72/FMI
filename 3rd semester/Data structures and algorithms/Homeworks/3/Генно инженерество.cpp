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

long long result = 1;

long long ternarySearch(long long l, long long r, long long index){
    while(l <= r){
        long long mid1 = (2 * l + r) / 3 + 1;
        long long mid2 = (2 * r + l) / 3;

        if(mid1 == mid2){
            if(index == mid1){
                return result;
            } else{
                return result + 1;
            }
        }

        if(index >= mid1 && index <= mid2){
            return result;
        }

        if(index <= mid1){
            r = mid1 - 1;
        } else if(index > mid2){
            l = mid2 + 1;
        }
        result++;
    }

    return result;
}


int main(){
    long long p, n;
    cin >> p >> n;

    vector<long long> indices;

    for(int i = 0; i < n; i++){
        long long index;
        cin >> index;
        indices.push_back(index);
    }

    for(int i = 0; i < n; i++){
        cout << ternarySearch(0, pow(3, p) - 1, indices[i] - 1) << endl;
        result = 1;
    }
    return 0;
}
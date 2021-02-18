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


int n, k, a, q;
map<int, int> hits; 

bool canSearchRight(int pos) { 
    int result = 0, cnt = 0;

    for(int i = 1; i <= n; i++){
        cnt++;

        if(hits[i] > 0 && hits[i] <= pos){
            cnt = 0;
        }

        if(a <= cnt){
            cnt = -1;
            result++;
        }
    } 

    if(result >= k){
        return true;
    }

    return false;
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> a >> q;

    int left = 1, right = q, mid, hit;

    for(int i = 1; i <= q; i++){
        cin >> hit;
        hits[hit] = i;
    }

    while(right >= left){
        mid = (left + right) / 2;

        if(canSearchRight(mid)){
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }

    if(left <= q){
        cout << left;
    } else{
        cout << -1;
    }

    return 0;
}
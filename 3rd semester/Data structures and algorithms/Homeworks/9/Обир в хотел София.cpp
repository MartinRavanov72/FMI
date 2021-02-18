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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, key, result = 0;

    vector<int> keysInRoom;
    vector<int> keysNeeded;
    unordered_map<int, int> keysOwned;

    scanf("%d", &n);   

    for(int i = 0; i < n - 1; i++){
        scanf("%d", &key);
        keysInRoom.push_back(key);
    }

    for(int i = 0; i < n - 1; i++){
        scanf("%d", &key);
        keysNeeded.push_back(key);
    }

    for(int i = 0; i < n - 1; i++){
        if(keysOwned.count(keysInRoom[i]) == 0){
            keysOwned[keysInRoom[i]] = 0;
        }

        keysOwned[keysInRoom[i]]++;

        if(keysOwned[keysNeeded[i]] != 0){
            keysOwned[keysNeeded[i]]--;
        } else{
            result++;
        }
    }

    cout << result << endl;

    return 0;
}
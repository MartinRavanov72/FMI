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

    int n, id, unshippedItems = 0, usersWithUnshippedItems = 0;

    unordered_map<int, int> carts;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> id;

        if(carts.count(id) == 0){
            carts[id] = 0;
        }

        carts[id] ++;

        if(carts[id] == 10){
            carts[id] = 0;
        }
    }

    auto it = carts.begin();

    while(it != carts.end()){
        if(carts[it->first] != 0){
            unshippedItems += carts[it->first];
            usersWithUnshippedItems++;
        }

        it++;
    }

    cout << usersWithUnshippedItems << " " << unshippedItems << endl;

    return 0;
}
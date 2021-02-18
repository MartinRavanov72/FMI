#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <iterator> 
#include <list> 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num, x, y;
    cin >> n >> x >> y;

    list<int> list;

    for(int i = 0; i < n; i++){
        cin >> num;
        list.push_back(num);
    }

    int size = list.size();
    int index = 0;
    auto it = list.begin();

    for(int i = 0;; i++){
        if(index >= size){
            break;
        }
        if(index + x >= size){
            advance(it, y + x);
            reverse(it, next(it, size - index));
            break;
        }
        if(index != 0){
            advance(it, y + x);
        }

        reverse(it, next(it, x));
        index += y + x;
    }

    for(auto const& i : list){
        cout << i << "\n";
    }

    return 0;
}
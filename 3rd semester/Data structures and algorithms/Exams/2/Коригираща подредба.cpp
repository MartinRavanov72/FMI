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

    unordered_set<int> set;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        set.insert(num);
    }

    int size = set.size();
    vector<int> arr;

    for(int i = 0; i < size; i++){
        arr.push_back(0);
    }


    auto iter = set.begin();
   


    for(int i = 0; i < size; i++){
        arr[i] = *iter;
        iter++;
    }

    vector<int> arrHelper;
    for(int i = 0; i < 50000; i++){
        arrHelper.push_back(0);
    }

    for(int i = 0; i < size; i++){
        arrHelper[arr[i]] = arrHelper[arr[i]] + 1;
    }

    for(int i = 0; i < 50000; i++){
        if(arrHelper[i]!=0){
            cout << i << " ";
        }
    }

    return 0;
}
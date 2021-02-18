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
    int n, m;
    cin >> n;

    vector<int> arr1;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr1.push_back(num);
    }


    cin >> m;

    vector<int> arr2;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        arr2.push_back(num);
    }


    vector<int> helper1;
    for(int i = 0; i <= 100000; i++){
        helper1.push_back(0);
    }
    vector<int> helper2;
    for(int i = 0; i <= 100000; i++){
        helper2.push_back(0);
    }


    for(int i = 0; i < n; i++){
        helper1[arr1[i]] = helper1[arr1[i]] + 1;
    }

    for(int i = 0; i < m; i++){
        helper2[arr2[i]] = helper2[arr2[i]] + 1;
    }

    int result = 0;


    for(int i = 0; i <= 100000; i++){
        if((helper1[i] > 0) && (helper2[i] > 0)){
            result += i;
        }
    }


    cout << result;



    return 0;
}
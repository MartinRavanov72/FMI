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
    long long n, k;
    cin >> n >> k;

    vector<int> counters;
    vector<int> printers;
    for(int i = 0; i < k; i++){
        counters.push_back(0);
    }
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        printers.push_back(a);
    }

    long long prints = 0;
    long long i = 0;


    for(i; prints < n; i++){
        for(int j = 0; j < k; j++){
            counters[j]++;
            if(counters[j] == printers[j]){
                prints++;
                counters[j] = 0;
            }
        }
    }

    cout << i;



    return 0;
}
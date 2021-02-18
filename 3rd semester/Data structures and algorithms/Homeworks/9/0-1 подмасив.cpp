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

    int n, num, maxLength = 0, sum = 0;
    vector<int> arr;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num;
        arr.push_back(num);
    }

    unordered_map<int, int> seenBefore;

    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            arr[i] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        sum += arr[i];

        if(sum == 0){
            maxLength = i + 1;
        }

        if(seenBefore.find(sum + n) != seenBefore.end()){
            if(maxLength < i - seenBefore[sum + n]){
                maxLength = i - seenBefore[sum + n];
            }

        } else{
            seenBefore[sum + n] = i;
        }
    }

    cout << maxLength << endl;

    return 0;
}
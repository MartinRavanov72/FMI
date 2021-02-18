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

    vector<int> nums;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        nums.push_back(input);
    }

    make_heap(nums.begin(), nums.end());
    sort_heap(nums.begin(), nums.end());
    int result = 0;
    int previousNum = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            if(nums[i] - previousNum > 1){
                result = previousNum + 1;
                break;
            }
            if(nums[i] - previousNum == 1){
                previousNum = nums[i];
            }
        }     
    }

    if(result == 0){
        result = previousNum + 1;
    }

    cout << result;
    return 0;
}


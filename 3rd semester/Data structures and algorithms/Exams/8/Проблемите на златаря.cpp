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

    int n, num;
    vector<int> nums;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++){
        int l = 0;
        int r = n - 1;

        while(l < r){
            if(nums[i] == nums[l] + nums[r]){
                cout << "true";
                return 0;
            } else if(nums[i] > nums[l] + nums[r]){
                l += 1;
            } else{
                r -= 1;
            }         
        }
    }

    cout << "false";

    return 0;
}
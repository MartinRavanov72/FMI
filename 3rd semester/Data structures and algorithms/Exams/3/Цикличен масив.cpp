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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num, q;
    cin >> n;

    vector<int> nums;

    for(int i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);

    }

    cin >> q;

    int maxEl = numeric_limits<int>::min();
    int index = -1;

    for(int i = 0; i < n; i++){
        if(nums[i] > maxEl){
            maxEl = nums[i];
            index = i;
        }
    }

    if(index < n/2){
        rotate(nums.begin(), nums.begin() + index + 1, nums.end());
    } else{
        rotate(nums.begin(), nums.begin() + index + 1, nums.end());
    }

    //for(int i = 0; i < n; i++){
    //    cout << nums[i] << " ";
    //}

    for(int i = 0; i < q; i++){
        cin >> num;
        int l = 0;
        int r = nums.size();
        int result = -1;
        while(l <= r){
            int m = l + (r - l) / 2;

           
            if(nums[m] == num)
                result =  m;

            
            if(nums[m] < num)
                l = m + 1;

            
            else
                r = m - 1;
        }



        
        if(result == -1){
            cout << result << endl;
        } else{
            if(index + 1 + result > nums.size()){
                cout << (index + 1 + result) - nums.size() << endl;
            } else{
                cout << index + 1 + result << endl;
            }
        }

                 
            
        
    }

    

    return 0;
}
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
    long long n, q, s, p, num;
    cin >> n >> q;

    vector<long long> nums;
    for(long long i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    vector<long long> sums;
    sums.push_back(nums[0]);
    for(int i = 1; i < n; i++){
        sums.push_back(sums[i - 1] + nums[i]);
    }

    for(long long i = 0; i < q; i++){
        cin >> s >> p;

        auto itN = upper_bound(nums.begin(), nums.end(), p);
        itN -= 1;
         
        long long remainder = sums[itN - nums.begin()] - s;
        auto itS = lower_bound(sums.begin(), sums.end(), remainder);

        if(remainder <= 0){
            printf("%ld\n", (itN - nums.begin()) - (itS - sums.begin()) + 1);
        } else{
            printf("%ld\n", (itN - nums.begin()) - (itS - sums.begin()));
        }        
    }

    return 0;
}
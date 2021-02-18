#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x, y, num;
    cin >> x >> y;
    
    vector<int> nums1, nums2;
    
    for(int i= 0; i < x; i++){
        cin >> num;
        
        nums1.push_back(num);
    }
    
    for(int i= 0; i < x; i++){
        cin >> num;
        
        nums2.push_back(num);
    }
    
    sort(nums1.begin(), nums1.end());
    
    for(int item : nums2){
        auto i = lower_bound(nums1.begin(), nums1.end(), item);
        int dist = distance(nums1.begin(), i);
        
        cout << dist << " ";
    }
    
    
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, num;
    
    vector<int> nums;
    
    map<int, int> indices;
    
    cin >> n;
    
    for(int i= 0; i < n; i++){
        cin >> num;
        nums.push_back(num);   
    }
    
    int res = 0;
    int lastIndex = 0;
    
    for(int currIndex = 0; currIndex < n; currIndex++){
        num = nums[currIndex];
        
        lastIndex = max(indices[num], lastIndex);
        
        res = max(res, currIndex - lastIndex + 1);
        
        indices[num] = currIndex + 1;
    }
    
    cout << res;
    
    
    return 0;
}

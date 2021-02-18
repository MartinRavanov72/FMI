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
#include <iterator> 
#include <list> 
#include <stack> 
#include <queue> 
#include <deque> 

using namespace std;


int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;
    cin >> n;

    vector<int> balances;
    for(int i = 0; i < n; i++){
        cin >> num;
        balances.push_back(num);
    }

    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> greater;

    double median = balances[0];
    smaller.push(median);

    printf("%.1f\n", median);

    for(int i = 1; i < n; i++){
        int curr = balances[i];

        if(smaller.size() > greater.size()){
            if(curr < median){
                greater.push(smaller.top());
                smaller.pop();
                smaller.push(curr);
            } else{
                greater.push(curr);
            }
                
            median = ((double)smaller.top() + greater.top()) / 2;
        } else if(smaller.size() < greater.size()){
            if(curr > median){
                smaller.push(greater.top());
                greater.pop();
                greater.push(curr);
            } else{
                smaller.push(curr);
            }
    
            median = ((double)smaller.top() + greater.top()) / 2;
        } else{
            if(curr < median){
                smaller.push(curr);
                median = (double)smaller.top();
            } else{
                greater.push(curr);
                median = (double)greater.top();
            }
        }

        printf("%.1f\n", median);
    }

    return 0;
}

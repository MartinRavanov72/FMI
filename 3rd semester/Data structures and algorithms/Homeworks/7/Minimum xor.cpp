#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
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

    int n, num, result = numeric_limits<int>::max();
    cin >> n;

    set<int> s;
    s.insert(0);

    for(int i = 0; i < n; i++){
        cin >> num;
        s.insert(num);

        auto it = s.lower_bound(num);

        if(it == s.begin()){
            result = min(result, num ^ *(++it));
        } else if(++it == s.end()){
            result = min(result, num ^ *(----it));
        } else{
            int a = num ^ *(it);
            int b = num ^ *(----it);
            int c = min(a, b);
            result = min(result, c);
        }

        cout << result << '\n';
    }

    return 0;
}

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

    int n, num1, num2;
    cin >> n;

    vector<pair<int, int>> intervals;

    for(int i = 0; i < n; i++){
        cin >> num1 >> num2;
        intervals.push_back({num1, num2});
    }

    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> endOfLectures;
    int rooms = 0;

    for(int i = 0; i < intervals.size(); i++){
        pair<int, int> p = intervals[i];

        endOfLectures.push(p.second);

        if(intervals[i].first < endOfLectures.top()){
            rooms++;
        } else{
            endOfLectures.pop();
        }
    }

    cout << rooms << endl;

    return 0;
}

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

class Shift{
    public:
    int hour, endOrStart;

    Shift(int hour, int endOrStart){
        this->hour = hour;
        this->endOrStart = endOrStart;
    }
};

bool compareShifts(const Shift& a, const Shift& b) {
    if(a.hour == b.hour){
        return a.endOrStart > b.endOrStart;
    }
       
    return a.hour < b.hour;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, num1, num2;
    cin >> n >> q;

    vector<Shift> shifts;

    for(int i = 0; i < n; i++){
        cin >> num1 >> num2;
        shifts.push_back({num1, 1});
        shifts.push_back({num2, -1});
    }

    vector<int> queries;

    for(int i = 0; i < q; i++){
        cin >> num1;
        queries.push_back(num1);
        shifts.push_back({num1, 0}); 
    }

    sort(shifts.begin(), shifts.end(), compareShifts);

    map<int, int> m;

    int cnt = 0;

    for(int i = 0; i < shifts.size(); i++){
        cnt += shifts[i].endOrStart;

        if(shifts[i].endOrStart == 0){
            m[shifts[i].hour] = cnt;
        }      
    }

    for(int i = 0; i < queries.size(); i++){
        cout << m[queries[i]] << ' ';
    }

    return 0;
}
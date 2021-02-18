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

class OrderLines{
    public:
    bool operator() (const pair<long long, long long>& a, const pair<long long, long long>& b){
        return a.second > b.second;
    }
};

bool sortSubmissions(const pair<long long, long long>& a, const pair<long long, long long>& b){
    return a.first < b.first;
}


int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, num1, num2;
    cin >> n;

    vector<pair<long long, long long>> submissions;

    for(long long i = 0; i < n; i++){
        cin >> num1 >> num2;
        submissions.push_back({num1, num2});
    }

    sort(submissions.begin(), submissions.end(), sortSubmissions);

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, OrderLines> forCorrection;
    long long currentTime = submissions[0].first;
    long long waitingTime = 0;

    for(long long i = 0; i < n;){
        while(i < n && submissions[i].first <= currentTime){
            forCorrection.push(submissions[i]);
            i++;
        }

        if(!forCorrection.empty()){
            pair<long long, long long> p = forCorrection.top();
            forCorrection.pop();
            currentTime += p.second;
            waitingTime += currentTime - p.first;
        } else{
            currentTime++;
        }
    }

    while(!forCorrection.empty()){
        pair<long long, long long> p = forCorrection.top();
        forCorrection.pop();
        currentTime += p.second;
        waitingTime += currentTime - p.first;      
    }

    cout << waitingTime / n << endl;

    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <iterator> 
#include <list> 
#include <stack> 
#include <queue> 
#include <deque> 
#include <map> 
using namespace std;

int cnt = 0;
vector<vector<int>> relationships;
vector<vector<int>> tree;
vector<int> timeIn;
vector<int> timeOut;


void generateTimesDFS(int current, int parent){
    timeIn[current] = cnt++;

    for(auto child : tree[current]){
        if(child != parent){
            generateTimesDFS(child, current);
        } 
    }

    timeOut[current] = cnt++;
}


string isAncestor(int ancestor, int child){
    return ((timeIn[ancestor] <= timeIn[child] && timeOut[child] <= timeOut[ancestor]) ? "YES\n" : "NO\n");
}


int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, num1, num2;
    cin >> n;

    tree.resize(n + 1);
    timeIn.resize(n + 1);
    timeOut.resize(n + 1);

    vector<int>temp;
    for(int i = 0; i < n - 1; i++){
        cin >> num1 >> num2;
        temp.clear();
        temp.push_back(num1);
        temp.push_back(num2);
        relationships.push_back(temp);
    }

    for(int i = 0; i < relationships.size(); i++){
        tree[relationships[i][0]].push_back(relationships[i][1]);
        tree[relationships[i][1]].push_back(relationships[i][0]);
    }

    generateTimesDFS(0, -1);

    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> num1 >> num2;
        cout << isAncestor(num1, num2);
    }

    return 0;
}

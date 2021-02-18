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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int length1, length2, result = 0;
    string str1, str2;

    cin >> str1 >> str2;

    length1 = str1.length();
    length2 = str2.length();

    vector<vector<int>> m;

    m.resize(length1 + 1);

    for(int i = 0; i <= length1; i++){
        m[i].resize(length2 + 1);
    }

    for(int i = 0; i <= length1; i++){
        for(int j = 0; j <= length2; j++){
            if(i == 0 || j == 0){
                m[i][j] = 0;

            } else if(str1[i - 1] == str2[j - 1]){
                m[i][j] = m[i - 1][j - 1] + 1;
                result = max(result, m[i][j]);

            } else{
                m[i][j] = 0;
            }
        }
    }

    cout << result;

    return 0;
}
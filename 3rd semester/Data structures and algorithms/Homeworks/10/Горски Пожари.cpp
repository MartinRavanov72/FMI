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

vector<vector<int>> grid;
vector<int> xd{-1, 0, 1, 0}, yd{0, -1, 0, 1}, result;
int minX = numeric_limits<int>::max(), minY = numeric_limits<int>::max(), maxX = 0, maxY = 0;

bool valid(int x, int y){
    return x >= 0 && y >= 0 && x < grid.size() && y < grid.size() && grid[x][y] == 1;
}

void dfs(int x, int y){
    if(x < minX){
        minX = x;
    }
    if(x > maxX){
        maxX = x;
    }
    if(y < minY){
        minY = y;
    }
    if(y > maxY){
        maxY = y;
    }

    grid[x][y] = 0;

    for(int i = 0; i < 4; i++){
        if(valid(x + xd[i], y + yd[i])){
            dfs(x + xd[i], y + yd[i]);
        }
    }
}

void printBoundingBox(){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid.size(); j++){
            if(grid[i][j] == 1){
                dfs(i, j);

                result.push_back((maxX - minX + 1) * (maxY - minY + 1));

                maxX = 0;
                minX = numeric_limits<int>::max();
                maxY = 0;
                minY = numeric_limits<int>::max();
            }
        }
    }

    sort(result.begin(), result.end(), greater<int>());

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;

    cin >> n;

    grid.resize(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            grid[i].push_back(num);
        }
    }

    printBoundingBox();

    return 0;
}
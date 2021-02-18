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
using namespace std;

int n, m;
long long sum = 0;
bool** visited;

class Point{
    public:
    int x;
    int y;
    long long value;
};

class Cell{
    public:
    Point point;
    int moves;

    Cell(int x, int y, long long value, int _moves){
        this->point.x = x;
        this->point.value = value;
        this->point.y = y;
        this->moves = _moves;
    }

    Cell(Point _point, int _moves){
        this->point = _point;
        this->moves = _moves;
    }
};

bool isValid(int row, int col){
    return (row >= 0) && (row < n) && (col >= 0) && (col < m);
}

void findMoves(int** matrix, Point start, int moves){
    if(matrix[start.x][start.y] == -1){
        return;
    }

    queue<Cell> q;

    Cell cell(start, 1);
    q.push(cell); 
    visited[start.x][start.y] = true;

    while(!q.empty()){
        Cell cell = q.front();
        Point point = cell.point;

        if(cell.moves == moves){
            sum += point.value;
        }
           
        q.pop();

        int row = point.x + 0;
        int col = point.y + -1;

        if(isValid(row, col) && matrix[row][col] != -1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, point.value, cell.moves + 1);
            q.push(adjacentCell);
        }

        row = point.x + 0;
        col = point.y + 1;

        if(isValid(row, col) && matrix[row][col] != -1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, point.value, cell.moves + 1);
            q.push(adjacentCell);
        }

        row = point.x + 1;
        col = point.y + 0;

        if(isValid(row, col) && matrix[row][col] != -1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, point.value, cell.moves + 1);
            q.push(adjacentCell);
        }

        row = point.x + -1;
        col = point.y + 0;

        if(isValid(row, col) && matrix[row][col] != -1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, point.value, cell.moves + 1);
            q.push(adjacentCell);
        }
    }
    return;
}


int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long c;
    long long x, y, moves;
    cin >> n >> m;

    Point start;
    int** matrix = new int* [n];
    for(int i = 0; i < n; i++){
        matrix[i] = new int[m];
    }

    visited = new bool* [n];
    for(int i = 0; i < n; i++){
        visited[i] = new bool[m];
        for(int j = 0; j < m; j++){
            visited[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c;
            
            matrix[i][j] = c;
            
        }
    }

    cin >> x >> y >> moves;
    x--;
    y--;

    start.x = x;
    start.y = y;
    start.value = matrix[x][y];

    findMoves(matrix, start, moves);
    cout << sum;

    for(int i = 0; i < n; i++){
        delete[] visited[i];
    }

    delete[] visited;

    for(int i = 0; i < n; i++){
        delete[] matrix[i];
    }

    delete[] matrix;
 
    return 0;
}

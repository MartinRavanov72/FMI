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
bool** visited;

class Point{
    public:
    int x;
    int y;
};

class Cell{
    public:
    Point point;
    int moves;

    Cell(int x, int y, int _moves){
        this->point.x = x;
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

int findMoves(int** matrix, Point start, Point end){
    if(matrix[start.x][start.y] == 1 || matrix[end.x][end.y] == 1){
        return -1;
    }

    queue<Cell> q;

    Cell cell(start, 0);
    q.push(cell); 
    visited[start.x][start.y] = true;

    bool noSuchCell = true;

    while(!q.empty()){
        Cell cell = q.front();
        Point point = cell.point;

        if(point.x == end.x && point.y == end.y){
            return cell.moves;
        }
           
        q.pop();

        int row = point.x;
        int col = point.y;
        noSuchCell = true;

        while(true){
            row++;
            if(!isValid(row, col) || matrix[row][col] == 1){
                noSuchCell = false;
                break;
            }
        }

        row--;

        if(!noSuchCell && isValid(row, col) && matrix[row][col] != 1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, cell.moves + 1);
            q.push(adjacentCell);
        }

        row = point.x;
        col = point.y;
        noSuchCell = true;

        while(true){
            row--;
            if(!isValid(row, col) || matrix[row][col] == 1){
                noSuchCell = false;
                break;
            }
        }

        row++;

        if(!noSuchCell && isValid(row, col) && matrix[row][col] != 1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, cell.moves + 1);
            q.push(adjacentCell);
        }

        row = point.x;
        col = point.y;
        noSuchCell = true;

        while(true){
            col++;
            if(!isValid(row, col) || matrix[row][col] == 1){
                noSuchCell = false;
                break;
            }
        }

        col--;

        if(!noSuchCell && isValid(row, col) && matrix[row][col] != 1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, cell.moves + 1);
            q.push(adjacentCell);
        }

        row = point.x;
        col = point.y;
        noSuchCell = true;

        while(true){
            col--;
            if(!isValid(row, col) || matrix[row][col] == 1){
                noSuchCell = false;
                break;
            }
        }

        col++;

        if(!noSuchCell && isValid(row, col) && matrix[row][col] != 1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, cell.moves + 1);
            q.push(adjacentCell);
        }

        row = point.x + 0;
        col = point.y + -1;

        if(isValid(row, col) && matrix[row][col] != 1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, cell.moves + 1);
            q.push(adjacentCell);
        }

        row = point.x + 0;
        col = point.y + 1;

        if(isValid(row, col) && matrix[row][col] != 1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, cell.moves + 1);
            q.push(adjacentCell);
        }

        row = point.x + 1;
        col = point.y + 0;

        if(isValid(row, col) && matrix[row][col] != 1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, cell.moves + 1);
            q.push(adjacentCell);
        }

        row = point.x + -1;
        col = point.y + 0;

        if(isValid(row, col) && matrix[row][col] != 1 && !visited[row][col]){
            visited[row][col] = true;
            Cell adjacentCell(row, col, cell.moves + 1);
            q.push(adjacentCell);
        }
    }
    return -1;
}


int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    cin >> n >> m;

    Point start, end;
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
            if(c == '#'){
                matrix[i][j] = 1;
            } else if(c == 'S'){
                start.x = i;
                start.y = j;
                matrix[i][j] = 0;
            } else if(c == 'F'){
                end.x = i;
                end.y = j;
                matrix[i][j] = 0;
            } else{
                matrix[i][j] = 0;
            }
        }
    }

    cout << findMoves(matrix, start, end);

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

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

class Point{
    public:
    int x, y;

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    Point(){
        this->x = 0;
        this->y = 0;
    }
};

void swap(Point& p1, Point& p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int distanceSquared(Point p1, Point p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

Point nextToTop(stack<Point>& s){
    Point p = s.top();
    s.pop();

    Point res = s.top();
    s.push(p);

    return res;
}

int orientation(Point p1, Point p2, Point p3){
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);

    if(val == 0){
        return 0;
    }

    if(val > 0){
        return 1;
    }

    return 2;
}

double getDistance(int npoints, vector<int>& x, vector<int>& y){
    double distance = 0.0, dx, dy;

    for(int i = 0; i < npoints; ++i){
        dx = x[(i + 1) % npoints] - (double)x[i];
        dy = y[(i + 1) % npoints] - (double)y[i];
        distance += sqrt(dx * dx + dy * dy);
    }

    return distance;
}

Point capitalPoint;

int compare(const void* vp1, const void* vp2){
    Point* p1 = (Point*)vp1;
    Point* p2 = (Point*)vp2;

    int orient = orientation(capitalPoint, *p1, *p2);

    if(orient == 0){
        if(distanceSquared(capitalPoint, *p2) >= distanceSquared(capitalPoint, *p1)){
            return -1;
        } 

        return 1;    
    }  

    if(orient == 2){
        return -1;
    }

    return 1;
}

void findSmallestPerimeter(vector<Point>& points, int n){
    int lowestY = points[0].y;
    int indexOfLowest = 0;

    for(int i = 1; i < n; i++){
        int currY = points[i].y;

        if((currY < lowestY) || (lowestY == currY && points[i].x < points[indexOfLowest].x)){
            lowestY = points[i].y;
            indexOfLowest = i;
        }
    }

    swap(points[0], points[indexOfLowest]);
    capitalPoint = points[0];

    qsort(&points[1], n - 1, sizeof(Point), compare);

    int sizeOfModifiedArr = 1;
    for(int i = 1; i < n; i++){
        while(i < n - 1 && orientation(capitalPoint, points[i], points[i + 1]) == 0){
            i++;
        }

        points[sizeOfModifiedArr] = points[i];
        sizeOfModifiedArr++;
    }

    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    for(int i = 3; i < sizeOfModifiedArr; i++){
        while(orientation(nextToTop(s), s.top(), points[i]) != 2){
            s.pop();
        }
            
        s.push(points[i]);
    }

    vector<int> xValues;
    vector<int> yValues;
    int cnt = 0;

    while(!s.empty()){       
        Point p = s.top();
        s.pop();
        xValues.push_back(p.x);
        yValues.push_back(p.y);
        cnt++;
    }

    double perimeter = getDistance(cnt, xValues, yValues);
    printf("%.2f\n", perimeter);
}

int main(){
    /*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num1, num2;
    cin >> n;

    vector<Point> points;

    for(int i = 0; i < n; i++){
        cin >> num1 >> num2;
        Point point(num1, num2);
        points.push_back(point);
    }

    findSmallestPerimeter(points, n);

    return 0;
}

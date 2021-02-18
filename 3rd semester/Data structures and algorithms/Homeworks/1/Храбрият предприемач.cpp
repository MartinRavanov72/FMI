#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int length;
    cin >> length;

    int* prices = new int[length];
    for(int i = 0; i < length; i++){
        cin >> prices[i];
    }

    int minEl = prices[0];
    int maxEl = minEl;
    int profit = 0;
    for(int i = 0; i < length; i++){
        if(prices[i] < maxEl){

            if(minEl < maxEl){
                profit += maxEl - minEl;
            }
                
            minEl = prices[i];                  
            maxEl = minEl;  
        }

        if(prices[i] > maxEl){
            maxEl = prices[i];
        }

        if(i == length - 1){
            profit += maxEl - minEl;
        }
    }

    cout << profit;

    delete[] prices;

    return 0;
}
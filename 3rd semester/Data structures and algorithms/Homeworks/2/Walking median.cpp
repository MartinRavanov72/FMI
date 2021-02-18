#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <iterator> 
using namespace std;

int main(){
    int n;
    cin >> n;

    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(i == 0){
            arr[0] = num;
        } else{
            int j;
            for(j = i - 1; arr[j] > num && j >= 0; j--){
                arr[j + 1] = arr[j];
            }

            arr[j + 1] = num;
        }
        
        if(i % 2 == 0){
            cout << arr[(i+1) / 2] << endl;
        } else{
            cout << ((double)arr[(i + 1) / 2] + arr[i / 2]) / (double)2 << endl;
        }
    }

    delete[] arr;
    return 0;
}
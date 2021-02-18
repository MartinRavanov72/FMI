#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;


int main(){
    int length;
    cin >> length;

    string queue;
    cin >> queue;

    int bestSpace = -1;


    for(int i = 0; i < length; i++){
        if(queue[i] == '-'){
            int space1 = 0;
            int space2 = 0;
            if(i == 0){
                space1 = 10000;
            }
            if(i == length - 1){
                space2 = 10000;
            }
            for(int j = i - 1; j >= 0; j--){
                if(queue[j] == '-'){
                    space1++;
                } else{
                    break;
                }
                if(j == 0){
                    space1 = 10000;
                }
            }
            for(int j = i + 1; j < length; j++){
                if(queue[j] == '-'){
                    space2++;
                } else{
                    break;
                }

                if(j == length - 1){
                    space2 = 10000;
                }
            }
            if(min(space1, space2) > bestSpace){
                bestSpace = min(space1, space2);
            }
        }
    }

    cout << bestSpace;

    return 0;
}
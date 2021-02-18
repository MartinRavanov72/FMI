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

    vector<long long int> numsA;
    for(int i = 0; i < n; i++){
        long long int input;
        cin >> input;
        numsA.push_back(input);
    }

    //initialize the result array with ones
    vector<long long int> numsB;
    for(int i = 0; i < n; i++){
        numsB.push_back(1);
    }

    long long int product = 1;

    //left side
    //we set each element in numsB as we multiply until we see the i-th element,
    //so all the elements after the i-th element remain, so afterwards each element in b with index i is the product of the numbers 0...i-1 in a
    for(int i = 0; i < n - 1; i++){
        numsB[i+1] = (numsB[i] * numsA[i]) % 1000000007;
    }

    //right side
    //now each element in b is multiplied by the elements after the i-th element
    for(int i = n - 1; i > 0; i--){
        product *= numsA[i];
        product %= 1000000007;
        numsB[i - 1] *= product;
        numsB[i - 1] %= 1000000007;
    }

    for(int i = 0; i < n; i++){
        cout << numsB[i] << " ";
    }
    return 0;
}
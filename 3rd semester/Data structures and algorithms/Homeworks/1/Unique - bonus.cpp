#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <iterator> 
using namespace std;

bool hasReappearingDigits(long long int n){
    set<long long int> digitsSet;
    while(n != 0){
        long long int digit = n % 10;

        if(digitsSet.count(digit)){
            return true;
        }

        digitsSet.insert(digit);
        n /= 10;
    }

    return false;
}

long long int countVariations(long long int n, long long int p){
    long long int variations = 1;

    for(long long int i = 0; i < p; i++){
        variations *= n;
        n--;
    }

    return variations;
}

long long int numbersWithoutReappearingDigitsBefore(long long int n){
    vector<long long int> arr;

    //fill in the vector with the digits of n+1
    for(long long int i = n + 1; i > 0; i /= 10){
        arr.insert(arr.begin(), i % 10);
    }

    long long int result = 0;
    long long int size = arr.size();

    //count all the suitable numbers with size = (size - 1 ... 1)
    for(long long int i = 0; i < size - 1; i++){
        result += 9 * countVariations(9, i);
    }


    //count all the suitable numbers with size = (size)
    set<long long int> seenDigits;
    for(long long int i = 0; i < size; i++){
        //for each digit:
        long long int currentDigit = arr[i];

        long long int nextPossibleDigit;

        //first digit cant be 0
        if(i == 0){
            nextPossibleDigit = 1;
        } else{
            nextPossibleDigit = 0;
        }

        for(nextPossibleDigit; nextPossibleDigit < currentDigit; nextPossibleDigit++){
            //if we have used this digit
            if(seenDigits.count(nextPossibleDigit)){
                continue;
            }
               
            //count the possible variations
            result += countVariations(9 - i, size - i - 1);
        }

        //break if we see the current digit in the set
        if(seenDigits.count(currentDigit)){
            break;
        }
        
        //fill in the set
        seenDigits.insert(currentDigit);
    }
    return result;
}

int main(){
    long long int a, b;
    cin >> a >> b;
    
    long long int numbersWithRepeatingDigitsBeforeB = numbersWithoutReappearingDigitsBefore(b);
    long long int numbersWithRepeatingDigitsBeforeA = numbersWithoutReappearingDigitsBefore(a);
    
    long long int result = numbersWithRepeatingDigitsBeforeB - numbersWithRepeatingDigitsBeforeA;

    bool aHasReappearingDigits = hasReappearingDigits(a);
    if(!aHasReappearingDigits){
        result++;
    }

    cout << result;

    return 0;
}


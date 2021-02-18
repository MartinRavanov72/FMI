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

    vector<string> words;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        words.push_back(word);
    }

    for(int i = 0; i < n; i++){
        vector<char> listOfCharCouples;
        string currentString = words[i];
        for(int j = 0; j < currentString.length(); j++){
            auto positionOfChar = find(listOfCharCouples.begin(), listOfCharCouples.end(), currentString[j]);
            if(positionOfChar == listOfCharCouples.end()){
                listOfCharCouples.push_back(currentString[j]);
            } else{
                listOfCharCouples.erase(positionOfChar);
            }
        }

        if((currentString.length() % 2 == 1 && listOfCharCouples.size() == 1) || (currentString.length() % 2 == 0 && listOfCharCouples.size() == 0)){
            cout << "TRUE" << endl;
        } else{
            cout << "FALSE" << endl;
        }
    }
    return 0;
}
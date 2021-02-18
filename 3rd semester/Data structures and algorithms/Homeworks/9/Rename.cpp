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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string name, prefix;

    scanf("%d", &n);

    set<string> prefixes;
    unordered_map<string, int> names;

    for(int i = 0; i < n; i++){
        char tmp[101];
        scanf("%100s", tmp);
        name = tmp;

        prefix = "";
        bool printed = false;

        for(int j = 0; j < name.size(); j++){
            prefix += name[j];

            if(prefixes.count(prefix) == 0 && !printed){
                printf("%s\n", prefix.c_str());
                printed = true;
            }

            prefixes.insert(prefix);
        }

        if(names.count(name) == 0){
            if(!printed){
                printf("%s\n", name.c_str());
            }

            names[name] = 1;
        } else{
            names[name]++;
            printf("%s %d\n", name.c_str(), names[name]);
        }
    }

    return 0;
}
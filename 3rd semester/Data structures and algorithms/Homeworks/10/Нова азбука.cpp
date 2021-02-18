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

map<char, list<int>> g;

void dfs(char v, map<char, bool>& visited, stack<char>& s){
    visited[v] = true;

    for(auto i : g[v]){
        if(!visited[i]){
            dfs(i, visited, s);
        }
    }

    s.push(v);
}

void sortAlphabet(){
    stack<char> s;
    map<char, bool> visited;

    for(auto kvp : g){
        visited[kvp.first] = false;
    }

    for(auto kvp : g){
        if(!visited[kvp.first]){
            dfs(kvp.first, visited, s);
        }
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

void printAlphabet(vector<string>& words){
    for(int i = 0; i < words.size() - 1; i++){
        string word1 = words[i];
        string word2 = words[i + 1];

        bool firstLonger = false;
        if(word1.length() >= word2.length()){
            firstLonger = true;
        }

        for(int j = 0; j < max(max(word1.length(), word2.length()) - 1, min(word1.length(), word2.length())); j++){
            if(j >= min(word1.length(), word2.length())){
                if(firstLonger){
                    if(g.count(word1[j]) == 0){
                        g[word1[j]] = list<int>();
                    }

                    g[word1[j]].push_back(word1[j+1]);
                    
                    
                } else{
                    if(g.count(word2[j]) == 0){
                        g[word2[j]] = list<int>();
                    }

                    g[word2[j]].push_back(word2[j + 1]);
                   
                }
                
            } else if(word1[j] != word2[j]){
                if(g.count(word1[j]) == 0){
                    g[word1[j]] = list<int>();
                }

                g[word1[j]].push_back(word2[j]);
                break;
            }
        }
    }

    sortAlphabet();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string word;
    vector<string> words;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> word;
        words.push_back(word);
    }

    printAlphabet(words);
    
    return 0;
}
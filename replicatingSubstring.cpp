#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    int solve(int A, string B);
};

int Solution::solve(int A, string B) {
    // the idea is frequency of each substring should be similar
    unordered_map <char, int> mp;
    int n = B.length();
    if(A > n) return -1;
    if(A == 1) return 1;
    
    for(int i=0; i<n; i++) {
        if(mp.find(B[i]) != mp.end()) {
            mp[B[i]]++;
        } else {
            mp[B[i]] = 1;
        }
    }

    bool isFirstElem = false;
    int referThis;
    for(auto i : mp) {
        if(!isFirstElem) {
            isFirstElem = true;
            referThis = i.second/A;
            if(referThis == 0) return -1;
        } else {
            if(i.second/A != referThis) return -1;
        }

    }
    return 1;
}

int main() {
    Solution myObj;

    int A = 7;
    string B = "plssefwmfhaozfyeijzxnwloiucujlpywktarroxzqnavmfexedkdqblldhuoyvmiqmchcbisqjqeowcuzmzqnkdstzgswucmgew";
    cout << myObj.solve(A, B);
    return 0;
}
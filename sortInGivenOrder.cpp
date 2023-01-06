#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
    vector<int> solve(vector<int> &A, vector<int> &B);
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map <int, int> mapAFreq; // SC: O(n)
    unordered_map <int, int> mapB; // SC: O(m) - worst case
    int n = A.size();
    int m = B.size();
    vector<int> a1; // SC: O(n)
    vector<int> a2; // SC: O(m) - worst case

    for(int i=0; i<n; i++) { // TC: O(n)
        if(mapAFreq.find(A[i]) != mapAFreq.end()) {
            mapAFreq[A[i]]++;
        } else {
            mapAFreq[A[i]] = 1;
        }
    }

    for(int i=0, p1=0; i<m; i++) { // TC: O(m)
        if(mapAFreq.find(B[i]) != mapAFreq.end()) {
            mapB.insert({ B[i], p1 });
            if(mapAFreq[B[i]] != 1) {
                p1+=mapAFreq[B[i]];
            } else {                
                p1++; // this ensures mapB does not have anything that is not present in A
            }            
        }        
    }    

    for(int i=0; i<n; i++) {  // O(n)
        if(mapB.find(A[i]) != mapB.end()) {
            a1.push_back(A[i]);
        } else {
            a2.push_back(A[i]);
        }
    }

    for(int i=0; i<a1.size(); i++) {
        // what is the issue now? frequency is 1 and duplicate elements won't be at correct positions - this causes infinite loop
        if(mapB[a1[i]] != i && mapAFreq[a1[i]] == 1) { // incorrect position and does not have dupplicates
            // you will move the element to its correct place
            mapAFreq[a1[i]]--;
            swap(a1[i], a1[mapB[a1[i]]]);
            // address what happens if the element you get at your current position deserves to be here or not
            if((mapB[a1[i]] != i) || (mapB[a1[i]] == i && mapAFreq[a1[i]] > 1)) {
                i--;
            } else {
                mapAFreq[a1[i]]--;
            }
        } else if ( mapB[a1[i]] != i && mapAFreq[a1[i]] > 1) { // incorrect position and does have duplicates
            // you will move the element to its correct place, also handling the duplicates scenario
            int temp = mapAFreq[a1[i]]--;
            swap(a1[i], a1[mapB[a1[i]]+temp-1]);            
            // address what happens if the element you get at your current position deserves to be here or not
            if((mapB[a1[i]] != i) || (mapB[a1[i]] == i && mapAFreq[a1[i]] > 1)) {
                i--;
            } else {
                mapAFreq[a1[i]]--;
            }
        } else if( mapB[a1[i]] == i && mapAFreq[a1[i]] > 1) { // correct position but has duplicates
            // you will move the element to its correct place, also handling the duplicates scenario
            int temp = mapAFreq[a1[i]]--;
            swap(a1[i], a1[mapB[a1[i]]+temp-1]);
            // address what happens if the element you get at your current position deserves to be here or not
            if((mapB[a1[i]] != i) || (mapB[a1[i]] == i && mapAFreq[a1[i]] > 1)) {
                i--;
            } else {
                mapAFreq[a1[i]]--;
            }

        }
    }

    sort(a2.begin(), a2.end());

    a1.insert(a1.end(), a2.begin(), a2.end());

    return a1;
}

int main() {
    Solution myObj;
    vector<int> A = { 16, 17, 20, 4, 3, 3, 16 };
    vector<int> B = { 3, 18, 16, 5, 15, 8, 19, 20, 9, 1 };
    myObj.solve(A, B);
    return 0;
}
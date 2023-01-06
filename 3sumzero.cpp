#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
    vector<vector<int> > threeSum(vector<int> &A);
};

// write your own insertion sort implementation
// still need to handle duplicates

void findOtherTwo(vector<int> &A, int start, int target, vector<vector<int>> &allAns) {

    unordered_map<int, int> myMap; // O(N) space  
    unordered_set<int> mySet;
    int n = A.size();

    for(int i=start; i<n; i++) {
        vector<int> ans; // this contributes towards answer, so not counting it as space
        int localTarget = target - A[i];

        if(myMap.find(localTarget) != myMap.end() && mySet.find(A[i]) == mySet.end()) { // your map has it already - you have the required pair
            mySet.insert(A[i]);
            int p1 = localTarget;
            int p2 = A[i];
            int p3 = A[start-1];
            
            ans.push_back(p1);
            ans.push_back(p2);
            ans.push_back(p3);

            sort(ans.begin(), ans.end()); //O(3log3) - might have to improve here - actually this is constant time so no need to worry about this - this does not scale with input
            allAns.push_back(ans);
        } 
        else if (myMap.find(localTarget) == myMap.end()) {
            if(myMap[A[i]]) {
                myMap[A[i]]++;
            } else {
                myMap[A[i]] = 1;
            }
        }


    }
    
    

}

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end()); // can you skip sorting? - think if sorting can help you with duplicates handling 
    int n = A.size();    

    vector<vector<int>> allAns;
    unordered_set <int> myOuterSet; //O(N) space

    for(int i=0; i<n; i++) { // O(N^2)
        if( myOuterSet.find(A[i]) == myOuterSet.end() ) {
            // update the outer set
            myOuterSet.insert(A[i]);
            int target = 0-A[i];
            findOtherTwo(A, i+1, target, allAns); //allAns is passed by reference and will be modified inside
        }         
    }

    return allAns;


    
}

void printMyVector(vector<vector<int>> &A) {
    int n = A.size();
    int m = 3;
    cout << "[ ";
    for(int i=0; i<n; i++) {
        cout << "[";
        for(int j=0; j<m; j++) {
            cout << A[i][j];
            if(j!=m-1) cout << ", ";
        }
        if(i == n-1) cout << "]";
        else cout << "], ";
    }
    cout << " ]";
}

int main() {
    Solution myObj;

    vector<int> A = { 1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3 };

    vector<vector<int>> ans = myObj.threeSum(A);
    printMyVector(ans);
    return 0;
}
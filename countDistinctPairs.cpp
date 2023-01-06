#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int solve(vector<int> &A, int B);
};

int Solution::solve(vector<int> &A, int B) {

    sort(A.begin(), A.end()); // NlogN
    int n=A.size();

    int p1 = 0;
    int p2 = 1;
    int ans = 0;
    bool goingThroughDuplicates = false;

    if(B == 0) { // any element that has atleast one duplicate adds one to the answer
                
        for(int i=1; i<A.size(); i++) { // O(N)
            if(A[i] == A[i-1]) {
                goingThroughDuplicates = true;
            }
            if(A[i] != A[i-1] && goingThroughDuplicates) {
                goingThroughDuplicates = false;
                ans++;
            }
        }
        if(goingThroughDuplicates) return ans+1;
        return ans;
    }

    bool p2GoingThroughDuplicates = false;
    bool p1GoingThroughDuplicates = false;
    while(p2+1 < n) {

        if(A[p2] == A[p2+1]) {
            p2GoingThroughDuplicates = true;
        } else {
            p2GoingThroughDuplicates = false;
        }

        if(A[p1] == A[p1+1]) {
            p1GoingThroughDuplicates = true;
        } else {
            p1GoingThroughDuplicates = false;
        }

        if (p2GoingThroughDuplicates) {
            p2++;
            continue;
        }
        if (p1GoingThroughDuplicates) {
            p1++;
            continue;
        }
        
        if((A[p2] - A[p1] == B) && !p2GoingThroughDuplicates && !p1GoingThroughDuplicates) {
            ans++;
            p1++;
            p2++;
        } else if ((A[p2] - A[p1] < B) && !p2GoingThroughDuplicates && !p1GoingThroughDuplicates ) {
            p2++;
        } else if ((A[p2] - A[p1] > B) && !p2GoingThroughDuplicates && !p1GoingThroughDuplicates ) {
            p1++;
        }
        
    }

    if((A[p2] - A[p1] == B) && p2GoingThroughDuplicates && p1GoingThroughDuplicates) {
        return ans + 1;
    }
    return ans;

}


int main() {
    Solution myObj;
    vector <int> A = {8, 5, 1, 10, 5, 9, 9, 3, 5, 6, 6, 2, 8, 2, 2, 6, 3, 8, 7, 2, 5, 3, 4, 3, 3, 2, 7, 9, 6, 8, 7, 2, 9, 10, 3, 8, 10, 6, 5, 4, 2, 3};
    int B = 3;
    cout << myObj.solve(A, B);
    return 0;
}
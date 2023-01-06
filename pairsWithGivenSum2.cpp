#include <iostream>
#include <vector>
using namespace std;\

class Solution {
    public:
    int solve(vector<int> &A, int B);
};


int Solution::solve(vector<int> &A, int B) {
    int mod = 1e9+7;
    int p1 = 0;
    int n = A.size();
    int p2=n-1;
    // sorted array - how can you use this information
    // instead of solving it with the appoach of two sum
    // not distinct elements - what problem can this cause
    int ans = 0;
    bool p1GoingThroughDuplicates = A[0] == A[1] ? true : false;
    bool p2GoingThroughDuplicates = A[n-1] == A[n-2] ? true : false;

    while(p1<p2) {
        if(A[p1] + A[p2] == B) {

            if( A[p1] == A[p1+1] || (A[p1] == A[p1-1] && p1 != 0) ) {
                p1GoingThroughDuplicates = true;
            } else {
                p1GoingThroughDuplicates = false;
            }

            if( A[p2] == A[p2-1] || (A[p2] == A[p2+1] && p2 != n-1) ) {
                p2GoingThroughDuplicates = true;
            } else {
                p2GoingThroughDuplicates = false;
            }

            if(p1GoingThroughDuplicates && p2GoingThroughDuplicates) {
                int p1Cnt = 0;
                while(p1GoingThroughDuplicates && p1<p2) {
                    
                    if(A[p1] != A[p1+1]) {
                        p1GoingThroughDuplicates = false;
                    }
                    p1++;
                    p1Cnt++;
                }
                int p2Cnt = 0;
                while(p2GoingThroughDuplicates && p1<=p2) {
                    
                    if(A[p2] != A[p2-1]) {
                        p2GoingThroughDuplicates = false;
                    }
                    p2--;
                    p2Cnt++;
                }
                if(p2Cnt == 1)
                if(p2Cnt!=0) ans = ans + (p1Cnt * p2Cnt);
                else ans = ans + (p1Cnt*(p1Cnt+1))/2;

            } else if(p1GoingThroughDuplicates) {
                ans++;
                p1++;
            } else if(p2GoingThroughDuplicates) {
                ans++;
                p2--;
            } else {
                ans++;
                p1++;
                p2--;
            }

            
        }
        else if(A[p1] + A[p2] < B) {
            p1++;
        } else {
            p2--;
        }
    }

    return ans;
}

int main() {
    Solution myObj;
    vector<int> A = { 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 9, 10 };
    int B = 5;
    cout << myObj.solve(A,B);

}

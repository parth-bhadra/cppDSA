#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    int solve(vector<int> &A, vector<int> &B);
};

int Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map <float, int> freq;
    int n = A.size(); // size of A and B will be same
    if(n == 1) return 1;
    int ans = 2; // given two or more points, atleast two will lie on the same line

    for(int i=0; i<n; i++) { // fix one point
        freq.clear();
        for(int j=0; j<n; j++) { // check all other points
            if(i!=j) {
                float denominator = A[i] - A[j]; // x1 - x2
                float numerator = B[i] - B[j]; // y1 - y2
                float slope;
                if(denominator == 0) {
                    slope = INT_MAX;
                } else {
                    slope = numerator/denominator; // y/x
                }
                if(freq.find(slope) != freq.end()) {
                    freq[slope]++;
                    ans = max(ans, freq[slope]);
                } else {
                    freq[slope] = 2;
                }
            }            
        }
    }

    return ans;
}
int main () {
    Solution myObj;
    vector<int> A = { 48, 45, -3, 7, -25, 38, 2, 13, 13, 18, -44, 34, -27, -46, 48, -39, -41, -32, -16, 17, -6, 44, -28, -44, -6, -43, -16, 30, -3, -27, 32, 38, -26, 20, 4, -44, -37 };
    vector<int> B = { 47, -42, 41, 22, -4, -35, -45, -22, 5, -20, 21, -13, 47, 32, -48, 47, 17, -23, 30, -30, 37, 42, 44, 23, 1, -40, -9, 34, -34, 49, 16, -35, 2, -19, 31, 23, -37 };

    // cout << myObj.solve(A, B);

    return 0;
}
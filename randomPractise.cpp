#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <assert.h>

using namespace std;

class Solution {
    public:
    vector<int> solve(vector<int> &A, vector<vector<int> > &B);
};

vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    vector<int> ans;
    // what is the idea
    // sum of the subarrays, if they are equal you can say that we are good
    // but this is not the case always eg [1 3 1] [0 4 2], both have same sum but are different subarrays when sorted

    unordered_map <int, int> numberRandom;
    for(int i=0; i<A.size(); i++) { // TC: O(N), SC: O(N)
        if(numberRandom.find(A[i]) == numberRandom.end()) {
            numberRandom.insert({A[i], rand()});
        }
    }

    vector<int> prefixSum;
    int mod = 1e9+7;
    int sum = 0;
    for(int i=0; i<A.size(); i++) { // TC: O(N), SC: O(N)
        sum = ((sum%mod) + (numberRandom[A[i]]%mod))%mod;
        prefixSum.push_back(sum);
    }

    for(int i=0; i<B.size(); i++) { // TC: O(M), SC: O(1)
        int l1 = B[i][0];
        int r1 = B[i][1];
        int l2 = B[i][2];
        int r2 = B[i][3];

        long lSum = (l1 == 0) ? prefixSum[r1] : prefixSum[r1]-prefixSum[l1-1];
        long rSum = (l2 == 0) ? prefixSum[r2] : prefixSum[r2]-prefixSum[l2-1];

        if(lSum == rSum) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
    }
    return ans;
}


int main() {
    Solution myObj;
    vector<int> A = { 100000, 100000, 100000, 100000, 100000 };
    vector<vector<int> > B = {{0, 3, 1, 4}, {0, 1, 2, 3}, {4, 4, 1, 1}, {1, 3, 0, 0}, {2, 4, 1, 1}};
    // myObj.solve(A, B);
    int x = 9;
    assert(x==9);
    return 0;
}
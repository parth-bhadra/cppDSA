#include <iostream>
#include <algorithm>


using namespace std;

class Solution {
    public:
    int solve(int A, int B, int C);
};

long long lcm(long long A, long long B) {

    // find hcf first
    long long small = min(A,B);
    long long large = max(A,B);

    while(small) {
        long long temp = small;
        small = large%small;
        large = temp;
    }

    return (A*B)/large;
}

long long countAllMuliples(int A, int B, int Z) {
    long long temp = lcm(A, B);
    return (Z/A) + (Z/B) - (Z/temp);
}

int Solution::solve(int A, int B, int C) {

    // return lcm(565, 29473);
    // return countAllMuliples(33488383, 565, 29473);
    long long mod = 1e9+7;
    long long l = 1;
    long long r = min(B, C) * A;
    long long ans = 1;
    while(l<=r) { // logN
        long long mid = (l+r)/2;
        long long temp_ans = countAllMuliples(B, C, mid);
        if(temp_ans >= A) {
            ans = mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }

    return ans%mod;


}


int main() {

    Solution myObj;

    cout << myObj.solve(33488383, 565, 29473);
    return 0;
}

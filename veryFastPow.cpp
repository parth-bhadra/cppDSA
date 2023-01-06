#include <iostream>

using namespace std;

long long calculateFactorial(long long n, long long p) {
    if(n == 0) {
        return 1;
    }

    long long ans = 1;

    for(long long i=1; i<=n; i++) {
        ans = (ans%p * i%p) % p;
    }

    return ans;
}

long long fastPow(long long a, long long n, long long p) {
    if(a == 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }
    long long ans = 1;
    long long halfPow = fastPow(a, n/2, p);
    ans = ((halfPow % p) * (halfPow % p)) % p; // this multiplication overflows
    
    if(n%2 != 0) {
        ans = (ans * a) % p;
    }

    return ans;
}

class Solution {
    public:
    int solve(int A, int B);
};

int Solution::solve(int A, int B) {
    long long mod = 1e9+7;

    long long factorialAns = calculateFactorial(B, mod); // O(N)
    cout << factorialAns <<endl;

    return fastPow(A, factorialAns, mod);
}

int main() {

    Solution myObj;


    cout << myObj.solve(2, 27) <<endl;
    cout << fastPow(2, 394134213, 1e9+7)<<endl;
    return 0;

    // 666348826
    
}
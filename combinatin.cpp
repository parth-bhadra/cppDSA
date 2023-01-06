#include <iostream>
#include <vector>

using namespace std;


long long fastPow (int a, int n, int p) {
    if(a == 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }

    long long halfPow = fastPow(a, n/2, p);
    long long ans = ((halfPow % p) * (halfPow % p)) % p;
    if( n%2 != 0) {
        ans = ((a%p) * (ans%p)) % p;
    }
    return ans;
}

long long factorial(int a, int p) {
    if(a == 0) return 1;
    if(a == 1) return 1;
    long long ans = 1;
    for(long long i=2; i<=a; i++) {
        ans = ((ans%p) * (i%p)) % p;
    }
    return ans;
}


int main() {

    int A = 51299, B = 25646, C = 3685739;
    long long op1 = factorial(A, C);
    long long op2 = fastPow(factorial(B, C), C-2, C );
    long long op3 = fastPow(factorial(A-B, C), C-2, C );

    long long ans = ((op1%C) * (op2%C)) % C;
    ans = (ans * (op3 % C)) % C;
    return int(ans);

    cout << int(ans);
    return 0;


}

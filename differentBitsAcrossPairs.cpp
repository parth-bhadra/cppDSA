#include<iostream>
#include<vector>

using namespace std;

int main() {
    
    vector <int> A = {1, 3, 5};

    int n = A.size();
    int mod = 1e9 + 7;
    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=0; k<32; k++) {
                // int b1 = (A[i] & (1 << k));
                // int b2 = (A[j] & (1 << k));
                int b1 = (A[i] >> k) & 1;
                int b2 = (A[j] >> k) & 1;
                int temp = b1 ^ b2;
                ans = ((ans % mod) + (temp % mod)) % mod;        
            }
            
        }
    }

    cout << ans;

    return 0;

}



#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;

int main() {
    vector <int> A = {1,2,3,4,5};
    int B = 2;

    
    unordered_map <int, int> freq;
    int ans = 0;
    int mod = 1e9 + 7;
    for(int i=0; i<A.size(); i++) {
        int target = abs(B-A[i]);
        if(!freq[A[i]]) { // nothing found
            freq[A[i]] = 1;
        } else {
            int temp = freq[A[i]];
            ans = ((ans % mod) + (temp % mod)) % mod;
        }
    }
    cout << ans;

    return 0;
}



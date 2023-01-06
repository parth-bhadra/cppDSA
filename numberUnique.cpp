#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main() {
    string A = "101", B="11";
    int n=A.length(), m=B.length();
    if(n > m) {
        int diff = n-m;
        while(diff) {
            B = "0"+B;
            diff--;
        }
    } else if ( n < m) {
        int diff = m - n;
        while(diff) {
            A = "0"+A;
            diff--;
        }
    }

    n=A.length(), m=B.length();

    int sum = 0, carry = 0;
    string ans = "";
    for(int i=n-1; i>=0; i--) {
        sum = int(A[i]) - 48 + int(B[i]) - 48 + carry;
        carry = sum / 2;
        sum = sum % 2;        
        int temp = sum;
        ans = to_string(temp) + ans;
        
    }

    if(carry == 0) {
        cout << ans;
    } else {
        ans = "1"+ans;
        cout << ans;
    }

    return 0;
}
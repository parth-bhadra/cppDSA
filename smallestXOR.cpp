#include <iostream>
using namespace std;

int smallestXOR(int A, int B) {
    int ans = 0;
    int setBitsLeft = B;

    for(int i=31; i>=0; i--) {
        int temp = A>>i & 1; // this checks if ith bit of the given number is set or not
        if(temp == 1) {
            ans = ans + (1<<i);
            setBitsLeft--;
        }

    }

    // return ans;

    for(int i=0; i<32 && setBitsLeft; i++) {
        int temp = (ans>>i) & 1;
        if(temp == 0) {
            ans = ans + (1 << i);
            setBitsLeft--;
        }
    }

    return ans;
}

int main() {


    cout << smallestXOR(4, 6);
    return 0;
}




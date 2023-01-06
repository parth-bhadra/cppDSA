#include<iostream>
#include<vector>
using namespace std;

int main () {

    // given a string
    // figure out the length of consecutive zero subarray length which is maximum
    // i can use carry forward technique for this
    string A = "01010101011001011101010101010101010";
    int cntOfOnes = 0;
    int cntOfZeros = 0;
    int n = A.length();
    bool ffz = false; // found first zero

    int l = -1;
    int r = -1;
    int len = 0;
    int d = 0;
    int pL = -1;
    int pR = -1;
    int pLen = 0;
    int pD = 0;

    // find the first zero

    for(int i=0; i<n; i++) {
        if(A[i] == '0' && ffz == false) {
            l=i;
            r=i;
            len = r-l+1;
            d = 1;
            pL=i;
            pR=i;
            pLen = len;
            pD = 1;
            ffz = true;
            cntOfZeros++;
        } else if(A[i] == '1' && ffz == true) {
            cntOfOnes++;
            
        } else if(A[i] == '0' && ffz == true) {
            cntOfZeros++;
            if((cntOfZeros - cntOfOnes) < 0)  {
                r=i;
                l=i;
                len=r-l+1;
                // ffz = false;
                cntOfOnes = 0;
                cntOfZeros = 1;
            } else {
                r=i;
                len = r-l+1;
                d = (cntOfZeros - cntOfOnes);
                if( d > pD) { // yahan gadbad ho ri hai
                    pD = d;
                    pLen = len;
                    pR = r;
                    pL = l;
                }
            }

        }
    }

    if( pL == -1 && pR == -1) {
        cout << "wow so empty";
    }
    cout << pL+1 << " " <<pR+1;
    return 0;
}
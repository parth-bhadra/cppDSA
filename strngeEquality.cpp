#include <iostream>


using namespace std;

class Solution {
    public:
    int solve(int A);
};


int Solution::solve(int A) {

    int Y = 0;
    int X = 0;

    bool isHSBSet = false;

    for(int i=31; i>=0; i--) {
        if((A>>i & 1) && isHSBSet == false) {
            isHSBSet = true;
            Y = 1 << (i+1);
        }

        if(isHSBSet == true && !(A>>i & 1)) {
            X = 1 << i;
            break;
        }
    }

    return X ^ Y;
}

int main() {
    Solution myObj;
    
    cout << myObj.solve(4);
    return 0;

}
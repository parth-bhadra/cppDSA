#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int divide(int A, int B);
};

int Solution::divide(int A, int B) {

    // this problem will have a lot of edge cases
    int mod = INT_MAX;
    int ans = 0;

    if(A == INT_MIN) {
        A++;
    }

    if(A == 0) {
        return 0;
    }

    // try {
    //     throw "my custom error";
    // } catch (const char* exp) {
    //     cout << A <<endl;
    //     cout << B <<endl;
    // }

    if(((B == 1) && (A > 0)) || ((B == -1) && (A < 0))) {
        return abs(A);
    } else if(((B == 1) && (A < 0)) || ((B == -1) && (A > 0))) {
        return -abs(A);
    }     

    if(A < B) {
        int temp = 0;
        while(temp < B) {
            ans = ans + (1<<temp);
            temp++;
        }
    }

    return ans;

    // use variables to store absolute values for A and B;
    int absA = abs(A);
    int absB = abs(B);
    
    
}

int main() {

    int A = INT_MIN;
    int B = -1;
    Solution myObj;

    cout << myObj.divide(A,B);
    
    return 0;
}
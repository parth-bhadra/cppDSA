#include <iostream>
#include <climits>

using namespace std;

class Solution {
    public:
    unsigned int reverse(unsigned int A);
};

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    unsigned int ans;
    for(int i=0; i<32; i++) {

        int temp = (A >> i) & 1;
        ans = ans + (temp << (31-i));
        // try {
        //     throw "error";
        // } catch (const char* exp) {
        //     unsigned int t2 = (ans >> (31-i)) & 1;
        //     cout << t2;
        // }

    }
    return ans;
}

int main() {
    Solution myObj;

    cout << myObj.reverse(3);
    return 0;

}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> solve(string &A);
    void print(vector<int> &A);
};

vector<int> Solution::solve(string &A) {
    vector<int> z;
    
    z.push_back(-1);
    int n = A.length();
    for(int i=1; i<n; i++) {
        int j=i;
        int k = 0;
        while(j<n) {
            if(A[k] == A[j]) {
                j++;
                k++;
            } else {
                break;
            }
        }
        z.push_back(k);
    }
    return z;
}

void Solution::print(vector<int> &A) {
    for(int i=0; i<A.size(); i++) {
        cout<<A[i]<<" ";
    }
}



int main() {
    string A = "xxyzxxyzwxxyzxxyzx";
    Solution myObj;
    vector<int> ans = myObj.solve(A);
    myObj.print(ans);
    return 0;
}
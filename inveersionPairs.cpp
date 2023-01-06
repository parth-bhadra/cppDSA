#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeTwoSortedArrays (vector<int> A, vector<int> B, long &cnt) {

    vector<int> sortedArray;

    int p1 = 0; int p2 = 0;
    int n = A.size();
    int m = B.size();

    int mod = 1e9 + 7;
    for(int i=n-1, j=m-1; i>=0 && j>=0; ) { //  this counts the  inversion pairs
        if(A[i] > A[j]) {
            cnt = ((cnt)%mod + (j+1)%mod ) % mod;
            i--;
        } else {
            j--;
        }
    }

    while(p1<n && p2<m) {
        if(A[p1] < B[p2]) {
            sortedArray.push_back(A[p1++]);
        } else {
            sortedArray.push_back(B[p2++]);
        }
    }

    while(p1<n) {
        sortedArray.push_back(A[p1++]);
    }
    while(p2<m) {
        sortedArray.push_back(B[p2++]);
    }
    
    return sortedArray;
}

vector<int> mergeSort(vector<int> A, long &cnt) {
    if(A.size() == 1) return A;
    int n = A.size();
    int start = 0;
    int mid = n/2;
    int end = A.size() - 1;

    vector<int> a1;
    for(int i=0; i<mid; i++) {
        a1.push_back(A[i]);
    }

    vector<int> a2;
    for(int i=mid; i<=end; i++) {
        a2.push_back(A[i]);
    }

    vector<int> t1 = mergeSort(a1, cnt);
    vector<int> t2 = mergeSort(a2, cnt);

    return mergeTwoSortedArrays(t1, t2, cnt);
}

void demo(vector<int> arr) {

    try {
        throw "WE ARE ABOUT TO PRINT OUR ARRAY";
    } catch (const char* exp) {
        cout << "Exception caught \n";
        cout << exp << "\n";
        cout << "array size " << arr.size() << "\n";
        for(int i=0; i<arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }        
}    

class Solution {
    public:
    int solve(vector <int> &A);
};

int Solution::solve(vector<int> &A) {
    
    long ans = 0;
    vector<int> resultArray;
    resultArray = mergeSort(A, ans);
    demo(resultArray);
    return int(ans);
    
}

int main() {

    vector<int> A = { 45, 10, 15, 25, 50 };
    Solution myObj;
    cout << myObj.solve(A);
    return 0;
}



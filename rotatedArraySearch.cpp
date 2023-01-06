#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int search(const vector<int> &A, int B);

};

/* int Solution::search(const vector<int> &A, int B) {
    int l = 0;
    int r = A.size()-1;

    while(l <= r) {
        int mid = (l+r)/2;
        bool youCanGoLeft = false;     

        if(A[mid] == B) return mid;
        if(A[l] == B) return l;
        if(A[r] == B) return r;
        bool pivotOnLeft = A[l] > A[mid];
        bool condition1 = B < A[mid] && A[l] <= B; // this means there is no pivot on the left, and you can surely move your search to left
        bool condition2 = B < A[mid] && A[l] > A[mid]; // this means there is pivot on the left, but you can still go left
        bool condition3 = B > A[mid] && B <= A[l] && !pivotOnLeft; // this means that there is no pivot on the left, but you can go on the left


        if ( condition1 || condition2 || condition3 ) {
            youCanGoLeft = true;
        }

        if(youCanGoLeft) {
            r = mid-1;
        } else {
            l = mid+1;
        }

    }

    return -1;
}
 */


int Solution::search(const vector<int> &A, int B) {

    // binary search
    // search space a[0] to a[n-1] - N(array size)
    // the condition that if you can go left or right is going to the most important here

    int l = 0;
    int r = A.size()-1;

    while(l<=r) {
        int mid = (l+r)/2;

        // success scenarios
        if(B == A[l]) return l;
        if(B == A[r]) return r;
        if(B == A[mid]) return mid;
        bool hasPivotOccured = A[l] > A[mid];
        bool condition1 = B < A[mid] && A[l] < B; // you can go left, no pivot has occured
        bool condition2 = B > A[mid] && A[l] > B && !hasPivotOccured; // you can go left, pivot has occured on the right
        bool condition3 = A[l] > B && B < A[mid] && A[l] > A[mid]; // you can go left even though pivot is on the left

        if(condition1 || condition2 || condition3) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }

    }
    return -1;

}

int main() {
    Solution myObj;

    const vector<int>  A = {180, 181, 182, 183, 184, 187, 188, 189, 191, 192, 193, 194, 195, 196, 201, 202, 203, 204, 3, 4, 5, 6, 7, 8, 9, 10, 14, 16, 17, 18, 19, 23, 26, 27, 28, 29, 32, 33, 36, 37, 38, 39, 41, 42, 43, 45, 48, 51, 52, 53, 54, 56, 62, 63, 64, 67, 69, 72, 73, 75, 77, 78, 79, 83, 85, 87, 90, 91, 92, 93, 96, 98, 99, 101, 102, 104, 105, 106, 107, 108, 109, 111, 113, 115, 116, 118, 119, 120, 122, 123, 124, 126, 127, 129, 130, 135, 137, 138, 139, 143, 144, 145, 147, 149, 152, 155, 156, 160, 162, 163, 164, 166, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177};
    int B = 42;

    // const vector<int>  A = {5,1,3};
    // int B = 5;
    // const vector<int>  A = {100, 102, 103, 104, 1, 4, 5, 6, 7, 8, 9};
    // int B = 1;
    
    cout << myObj.search(A, B);
    return 0;
}
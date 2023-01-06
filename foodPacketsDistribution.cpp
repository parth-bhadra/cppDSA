#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
    public:
    int solve(vector<int> &A, int B);
};

int bestPlaceWhereNewOfficeCanBe(vector<int> &A, vector<int> &officePerCity) {
    // nothing can be O(N) inside of this
    int l=1;
    int n=A.size();
    int r=n-1;

    // what is good value to initialise the answer with
    int ans = A[0]/(officePerCity[0]+1); // initialise your answer by assuming that what happens when you add the new office to the city with the least population
    // run binary search to find the which yields the maximum possible population/totalOffices
    
    int ansIndex = 0;

    while(l<=r) {
        int mid = (l+r)/2;
        int temp_ans = A[mid]/(officePerCity[mid]+1);
        if(temp_ans >= ans) {
            ansIndex = mid;
            ans = temp_ans;
            l = mid+1;
        } else {
            r = mid-1;
        }

    }

    swap(A[0], A[ansIndex]);
    swap(officePerCity[0], officePerCity[ansIndex]);
    return 0;
    /* for(int i=1; i<n; i++) {
        int temp_ans = A[i]/(officePerCity[i]+1);
        if(temp_ans > ans) {
            ans = temp_ans;
            ansIndex = i;
        }
    } */

    
}

int Solution::solve(vector<int> &A, int B) {

    // will sorting the original array help? - currently I don't see it causing any problem
    sort(A.begin(), A.end()); // O(NlogN) - not an issue
    int n=A.size();

    // every city has atleast one office - this gives you a starting point
    int officesRemaining = B-n;
    vector<int> officePerCity(n, 1);

    

    while(officesRemaining) { // O(MxN) - quadratic time - need to bring this to MlogN time
        int indexToIncrement = bestPlaceWhereNewOfficeCanBe(A, officePerCity);
        officePerCity[indexToIncrement]++;
        officesRemaining--;
    }

    int ans = A[0]/officePerCity[0];

    for(int i=1; i<n; i++) { // O(N) - not an issue
        int temp_ans = A[i]/officePerCity[i];
        if(temp_ans < ans) {
            ans = temp_ans;
        }
    }

    return ans;



}


int main() {
    // vector<int> A = { 8, 7, 1, 5, 5, 10, 10, 1, 5, 3 };
    // int B = 17;


    vector<int> A = {100, 499, 498, 500, 1000};
    int B = 10;
    Solution myObj;
    cout << myObj.solve(A, B);
    return 0;
}

// implementing merge sort
// you need to know it

// merge sort is broken down into two sub problems
// merging two arrays(which are already sorted)
// a recursive function that helps you convert sorting a given array into two sorted arrays

#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> A, vector<int> B) {
    vector<int> ans; int p1=0, p2=0;
    int n = A.size(); int m = B.size();

    while(p1<n && p2<m) {
        if(A[p1] <= B[p2]) {
            ans.push_back(A[p1]);
            p1++;
        } else {
            ans.push_back(B[p2]);
            p2++;
        }
    }

    while(p1<n) {
        ans.push_back(A[p1]);
        p1++;
    }

    while(p2<m) {
        ans.push_back(B[p2]);
        p2++;
    }

    return ans;
}

void printVector(vector<int> A) {
    for(int i=0; i<A.size(); i++) {
        cout << A[i] << " ";
    }
    return;
}

vector<int> myRecusrsive(vector<int> A) {

    // base case
    if(A.size() == 1) {
        return A;
    }

    // main logic

    int n=A.size();
    int start = 0;
    int end = n-1;
    int mid = n/2;

    vector<int> a1; vector<int> a2;
    for(int i=start; i<mid; i++) {
        a1.push_back(A[i]);
    }

    for(int i=mid; i<=end; i++) {
        a2.push_back(A[i]);
    }

    vector<int> t1 = myRecusrsive(a1);
    vector<int> t2 = myRecusrsive(a2);
    vector<int> sub_ans = mergeSort(t1, t2);
    return sub_ans;

}

int main() {

    vector<int> A = { 2, 6, 17 };
    vector<int> B = { 1, 4, 13 };

    // printVector(mergeSort(A,B));

    vector<int> input = { 2, 51, 27, -1, 0, -1029, 223 };
    printVector(myRecusrsive(input));

    
    return 0;
}

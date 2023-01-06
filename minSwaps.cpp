#include <iostream>
#include <vector>

using namespace std;

int main() {


    // vector<int> A = { 52, 7, 93, 47, 68, 26, 51, 44, 5, 41, 88, 19, 78, 38, 17, 13, 24, 74, 92, 5, 84, 27, 48, 49, 37, 59, 3, 56, 79, 26, 55, 60, 16, 83, 63, 40, 55, 9, 96, 29, 7, 22, 27, 74, 78, 38, 11, 65, 29, 52, 36, 21, 94, 46, 52, 47, 87, 33, 87, 70 };
    // int B = 19;
    // vector<int> A = { 52, 7, 93, 47, 68, 26, 51, 44, 5, 41, 88, 19, 78, 38, 17, 13, 24, 74, 92, 5, 84, 27, 48, 49, 37, 59, 3, 56, 79, 26, 55, 60, 16, 83, 63, 40, 55, 9, 96, 29, 7, 22, 27, 74, 78, 38, 11, 65, 29, 52, 36, 21, 94, 46, 52, 47, 87, 33, 87, 70 };
    // int B = 19;
    vector<int> A = { 1, 12, 10, 3, 14, 10, 5 };
    int B = 8;
    int cnt = 0;
    int n=A.size();
    int cnt_patch = 0;
    int max_cnt_patch = 0;

    // figure out the patch of 11 that has the most number of elements that satisfy your condition
    // the below code is important
    for(int i=0; i<n; i++) {
        if(A[i] <= B) {
            cnt++;
        }
    }

    // make a prefix array for patchCount

    vector<int> prefix_pc;
    int pc_cnt = 0;
    for(int i=0; i<n; i++) {
        if(A[i] <= B) {
            pc_cnt++;
        }
        prefix_pc.push_back(pc_cnt);
    }

    // traverse through this array and find the maximum differnce between the elements
    max_cnt_patch = prefix_pc[cnt-1];
    for(int i=1; i<n && (cnt+i-1) < n; i++) {
        cnt_patch = prefix_pc[cnt+i-1]-prefix_pc[i-1];
        if(cnt_patch > max_cnt_patch) {
            max_cnt_patch = cnt_patch;
        }
    }

    int minSwaps = cnt - max_cnt_patch;
    cout << minSwaps;
    
    return 0;
}
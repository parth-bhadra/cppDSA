#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
    public:
    vector<int> lszero(vector<int> &A);
};
vector<int> Solution::lszero(vector<int> &A) {


    vector<int> ans;
    int max_len = -1;
    unordered_map <int, int> myMap;
    int sum = 0;
    vector<int> pfA;

    int start = -1;
    int end = -1;

    for(int i=0; i<A.size(); i++) {
        sum+=A[i];
        pfA.push_back(sum);
    }

    for(int i=0; i<pfA.size(); i++) { //O(N)
        if(myMap.find(pfA[i]) != myMap.end()) {
            int temp = max_len;
            int diff = i - myMap[pfA[i]];
            max_len = max(max_len, diff);
            if(temp != max_len) {
                end = i;
                start = myMap[pfA[i]]+1;
            }
        } else if(pfA[i] == 0) {
            int temp = max_len;
            max_len = max(max_len, i+1);
            if(temp != max_len) {
                start = 0;
                end = i;
            }
        }   
        else {
            myMap[pfA[i]] = i;  // insert into map
        }
    }

    for(int i=start; i<=end; i++) {
        ans.push_back(A[i]);
    }

    return ans;
}

int main() {
    Solution myObj;
    vector<int> A = {1, 2, -2, 4, -4};
    vector<int> ans = myObj.lszero(A);
    return 0;
}
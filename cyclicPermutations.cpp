#include <iostream>
#include <algorithm>

using namespace std;

void oneCyclicShift(string &B) {    
    reverse(B.begin(), B.end());
    reverse(B.begin(), B.begin() + B.length()-1);    
}

void print(string A) {
    for(int i=0; i<A.length(); i++) {
        cout<<A[i];
    }
}

int main() {
    string A = "0011";
    cout<<"Before: ";
    print(A);
    cout<<endl;
    oneCyclicShift(A);
    cout<<"After: ";
    print(A);
    cout<<endl;    
    return 0;
}
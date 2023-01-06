#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> A = {17, 18, 8, 13, 15, 7, 11, 5, 4, 9, 12, 6, 10, 14, 16, 3};
    int B = 9;
    int cnt = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((A[i] ^ A[j]) == B)
            {
                cnt++;
            }
        }
    }
    return cnt;
    return 0;
}
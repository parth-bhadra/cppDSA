#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int innerSudokuCheck(int a, int B, int C, int D, const vector<string> &A)
{
    unordered_set<char> st;
    int cnt_num = 0;
    int cnt_dot = 0;
    for (int i = a; i < B; i++)
    {
        for (int j = C; j < D; j++)
        {
            if (st.find(A[i][j]) == st.end())
            {
                if (A[i][j] == '.')
                {
                    cnt_dot = 1;
                }
                st.insert(A[i][j]);
                
                if (A[i][j] != '.')
                {
                    cnt_num++;
                }
            }
        }
    }
    if (st.size() != (cnt_dot + cnt_num))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{

    vector<string> A = {"....5..1.", ".4.3.....", ".....3..1", "8......2.", "..2.7....", ".15......", ".....2...", ".2.9.....", "..4......"};

    // go through rows
    for (int i = 0; i < 9; i++)
    {
        unordered_set<char> st;
        for (int j = 0; j < 9; j++)
        {
            int prev_size = st.size();
            if (st.find(A[i][j]) == st.end())
            {
                st.insert(A[i][j]);
            }
            if ((st.size() == prev_size) && A[i][j] != '.')
            {
                return 0;
            }
        }
    }

    // go through columns
    for (int j = 0; j < 9; j++)
    {
        unordered_set<char> st;
        for (int i = 0; i < 9; i++)
        {
            int prev_size = st.size();
            if (st.find(A[i][j]) == st.end())
            {
                st.insert(A[i][j]);
            }
            if ((st.size() == prev_size) && A[i][j] != '.')
            {
                return 0;
            }
        }
    }

    int result;

    result = innerSudokuCheck(0, 3, 0, 3, A);
    if (result == 0)
        return 0;
    result = innerSudokuCheck(0, 3, 3, 6, A);
    // return result;
    if (result == 0)
        return 0;
    result = innerSudokuCheck(0, 3, 6, 9, A);
    if (result == 0)
        return 0;

    result = innerSudokuCheck(3, 6, 0, 3, A);
    if (result == 0)
        return 0;
    result = innerSudokuCheck(3, 6, 3, 6, A);
    if (result == 0)
        return 0;
    result = innerSudokuCheck(3, 6, 6, 9, A);
    if (result == 0)
        return 0;

    result = innerSudokuCheck(6, 9, 0, 3, A);
    if (result == 0)
        return 0;
    result = innerSudokuCheck(6, 9, 3, 6, A);
    if (result == 0)
        return 0;
    result = innerSudokuCheck(6, 9, 6, 9, A);
    if (result == 0)
        return 0;

    return 1;
}
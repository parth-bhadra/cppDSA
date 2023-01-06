#include <vector>
#include <iostream>

using namespace std;

bool checkStrings()
{

    vector<string> word1 = {"a"};
    vector<string> word2 = {"a", "b"};

    int n = word1.size();
    int m = word2.size();
    int p1 = 0, p2 = 0;
    int t1 = 0;
    int t2 = 0;
    for (int i = 0, j = 0; i < n || j < m; /*no direct increments here */)
    {
        // if this for loop does not run you can return false
        if (i < n && j < m)
        {
            for (; p1 < word1[i].length() && p2 < word2[j].length(); p1++, p2++)
            {
                if (word1[i][p1] != word2[j][p2])
                    return false;
            }
        }
        else
        {
            return false;
        }

        if (p1 == word1[i].length())
        {
            t1 += word1[i].length();
            i++;
            p1 = 0;
        }

        if (p2 == word2[j].length())
        {
            t2 += word2[j].length();
            j++;
            p2 = 0;
        }
    }

    if (t1 != t2)
    {
        return false;
    }

    return true;
}

int main()
{

    cout << checkStrings();
    return 0;
}
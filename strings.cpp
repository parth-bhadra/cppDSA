bool checkPalindrome(string A, int left, int right)
{
    int n = right - left + 1;
    int p1 = left;
    int p2 = right;
    while (p1 < p2)
    {
        if (A[p1] != A[p2])
        {
            return false;
        }
        p1++;
        p2--;
    }
    return true;
}

string Solution::longestPalindrome(string A)
{
    int n = A.length();
    int max = 0;
    string result;
    int center = -1;

    for (int i = 0; i < n; i++)
    {
        // write your logic that expands around a center
        int l = i;
        int r = i;

        // this will get you palindromes of odd length
        while (l >= 0 && r < n)
        {
            int proposedMax = r - l + 1;
            if (checkPalindrome(A, l, r))
            {
                if (proposedMax > max)
                {
                    max = proposedMax;
                    result = A.substr(l, proposedMax);
                }
            }
            l--;
            r++;
        }
        // what for even length
        l = i;
        r = i + 1;
        while (l >= 0 && r < n)
        {
            int proposedMax = r - l + 1;
            if (checkPalindrome(A, l, r))
            {
                if (proposedMax > max)
                {
                    max = proposedMax;
                    result = A.substr(l, proposedMax);
                }
            }
            l--;
            r++;
        }
    }
    // return to_string(center);
    return result;
}

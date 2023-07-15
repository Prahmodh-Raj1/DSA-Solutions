//Prob link: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
//TC: O(N) SC: O(1)
int minimumLength(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j && s[i] == s[j]) {
        auto ch = s[i];
        while (i <= j && s[i] == ch)
            ++i;
        while (i < j && s[j] == ch)
            --j;
    }
    return j - i + 1;
}

//problem link: https://leetcode.com/problems/palindrome-pairs/
//TC: O(N*K^2) SC:O(N)
/*Description
You are given a 0-indexed array of unique strings words.

A palindrome pair is a pair of integers (i, j) such that:

0 <= i, j < words.length,
i != j, and
words[i] + words[j] (the concatenation of the two strings) is a 
palindrome
.
Return an array of all the palindrome pairs of words.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]*/
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > result;
        unordered_map<string, int> dict;
        int i, j, size = words.size();
        string left, right, tmp;
        for(i = 0; i < size; i++) {
            tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            dict[tmp] = i;
        }
        
        for(i = 0; i < size; i++) {
            for(j = 0; j < words[i].size(); j++) {
                left = words[i].substr(0, j);
                right = words[i].substr(j);
                if(dict.find(left) != dict.end() && dict[left] != i && isPalindrome(right)) {
                    result.push_back({i, dict[left]});
                    if(left.empty())
                        result.push_back({dict[left], i});
                }
                if(dict.find(right) != dict.end() && dict[right] != i && isPalindrome(left))
                    result.push_back({dict[right], i});
            }
        }
        return result;
    }
    
private:
    bool isPalindrome(string s) {
        int start, end, size = s.size();
        for(start = 0, end = size - 1; start < end; start++, end--) {
            if(s[start] != s[end])
                return false;
        }
        return true;
    }
};

/*Explanation
Steps:

Traverse the array, build map. Key is the reversed string, value is index in array (0 based)

Edge case - check if empty string exists. It's interesting that for given words {"a", ""}, 
  it's expected to return two results [0,1] and [1,0]. Since my main logic can cover [0, 1] concatenate("a", ""), so 
  as to cover the other situation concatenate("", "a"), I need to traverse the words array again, find the palindrome 
word candidate except "" itself, and add pair("", palindrome word) to the final answer.

Main logic part. Partition the word into left and right, and see 1) if there exists a candidate in map equals the left side of
current word, and right side of current word is palindrome, so concatenate(current word, candidate) forms a pair: left | right | candidate.
  2) same for checking the right side of current word: candidate | left | right.*/

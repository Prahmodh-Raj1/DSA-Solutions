/*Q.A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
*/
//Approach-2
//For every balanced parenthesis you just need to avoid boundary '(' and ')' .

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int open = 0;
        
        for(const char& ch : s) {
			//greater than 0 means I skipped boundary '('
            if(ch == '(' && open++ > 0) result.push_back(ch);
			
			//greater than 0 means I skipped boundary ')'
            if(ch == ')' && --open > 0) result.push_back(ch);
        }
        
        return result;
    }
};

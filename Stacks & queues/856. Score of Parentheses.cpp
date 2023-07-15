Q.Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2

Intuition

The final sum will be a sum of powers of 2, as every core (a substring (), with score 1) will have it's score multiplied by 2 for each exterior set of parentheses that contains that core.

Algorithm

Keep track of the balance of the string, as defined in Approach #1. For every ) that immediately follows a (, the answer is 1 << balance, as
 balance is the number of exterior set of parentheses that contains this core.
	
	public int scoreOfParentheses(String S) {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S.charAt(i) == '(') {
                bal++;
            } else {
                bal--;
                if (S.charAt(i-1) == '(')
                    ans += 1 << bal;
            }
        }

        return ans;
    }
}
//Using a stack
int scoreOfParentheses(string s) {
        int score=0;
        stack<int> st;
        for(auto it:s){
            if(it=='('){
                st.push(score);
                score=0;
            }else{
                score = st.top()+max(2*score,1);
                st.pop();
            }
        }
        return score;
    }

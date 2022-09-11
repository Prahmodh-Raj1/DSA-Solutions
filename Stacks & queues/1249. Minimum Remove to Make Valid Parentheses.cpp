#include<bits/stdc++.h>
using namespace std;


/*
Q.Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

INTUITION:
To make the string valid with minimum removals, we need to get rid of all parentheses that do not have a matching pair.

Push char index into the stack when we see '('.

Pop from the stack when we see ')'.

If the stack is empty, then we have ')' without the pair, and it needs to be removed.
In the end, the stack will contain indexes of '(' without the pair, if any. We need to remove all of them too.

Update: check out the new approach 2 that collects indexes of all mismatched parentheses, and removes them right-to-left.

Approach 1: Stack and Placeholder
We mark removed parentheses with '*', and erase all of them in the end.*/

string minRemoveToMakeValid(string s) {
  stack<int> st;
  for (auto i = 0; i < s.size(); ++i) {
    if (s[i] == '(') st.push(i);
    if (s[i] == ')') {
      if (!st.empty()) st.pop();
      else s[i] = '*';
    }
  }
  while (!st.empty()) {
    s[st.top()] = '*';
    st.pop();
  }
  s.erase(remove(s.begin(), s.end(), '*'), s.end());
  return s;
}

/*2ND Approach
Approach 2: Stack with Tracking
Instead of using placeholders, we can track indexes of all mismatched parentheses, and erase them in the end going right-to-left. This idea was inspired by dibdidib.

We can introduce another stack to collect indexes of mismatched ')', or we can use the same stack and mark mismatched ')' somehow. Here, we just negate the index to indicate ')'.

Note that I am adding 1 to make the index 1-based. You cannot tell if zero is negated :)

Java

public String minRemoveToMakeValid(String s) {
  StringBuilder sb = new StringBuilder(s);
  Stack<Integer> st = new Stack();
  for (int i = 0; i < sb.length(); ++i) {
    if (sb.charAt(i) == '(') st.add(i + 1);
    if (sb.charAt(i) == ')') {
      if (!st.empty() && st.peek() >= 0) st.pop();
      else st.add(-(i + 1));
    }
  }
  while (!st.empty())
    sb.deleteCharAt(Math.abs(st.pop()) - 1);
  return sb.toString();
}
If we want to optimize for the worst-case scenario, we should avoid deleteCharAt inside the loop. Instead, we can copy characters that do not appear in the stack into another string builder. Since characters in the stack are naturally sorted, we can use two-pointer technique to do it in the linear time.

Note that for the OJ test cases, the runtime of this solution is a bit worse than for deleteCharAt.

public String minRemoveToMakeValid(String s) {
  StringBuilder sb = new StringBuilder(s), sb1 = new StringBuilder();
  Stack<Integer> st = new Stack();
  for (int i = 0; i < sb.length(); ++i) {
    if (sb.charAt(i) == '(') st.add(i + 1);
    if (sb.charAt(i) == ')') {
      if (!st.empty() && st.peek() >= 0) st.pop();
      else st.add(-(i + 1));
    }
  }
  for(int i = 0, j = 0; i < sb.length(); ++i) {
      if (j >= st.size() || i != Math.abs(st.elementAt(j)) - 1) {
        sb1.append(sb.charAt(i));
      } else ++j;
  }
  return sb1.toString();
}
Complexity Analysis

Time: O(n). We process each character once, or twice for 'single' '('.
Memory: O(n) for the stack.
*/


int main(){
	string s="a)b(c)d";
	string ans=minRemoveToMakeValid(s);
	cout<<"answer is "<<ans<<endl;
	return 0;
	
}

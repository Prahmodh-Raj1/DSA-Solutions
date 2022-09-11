Q.Given two integer arrays pushed and popped each with distinct values,
 return true if this could have been the result of a sequence of push and pop operations
  on an initially empty stack, or false otherwise.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

bool validateStackSequences(vector<int> &push, vector<int> &pop) {
  stack<int> s;
  for (auto i = 0, j = 0; i < push.size(); ++i) {
    s.push(push[i]);
    while (!s.empty() && s.top() == pop[j]) s.pop(), ++j;
  }
  return s.empty();
}

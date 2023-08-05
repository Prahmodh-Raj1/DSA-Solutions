
stack<int> st;
for(int i=0;i<n;i++){  //iterate through all elements of the array
  while(!st.empty() and element represented by st.top() <Operator> arr[i]){
    //The OPERATOR could be any of the four - >, >=, <, <=
    //The OPERATOR inside the while loop condition decides what type of monotonic stack are we creating
      // if the previous condition is satisfied, we pop the top element
      let stackTop = stack.pop();
  
      // do something with stackTop here e.g.
      // nextGreater[stackTop] = i
    }
  
    if (stack.length) {
      // if stack has some elements left
      // do something with stack top here e.g.
      // previousGreater[i] = stack.at(-1)
    }

    // at the ened, we push the current index into the stack
     stack.push(i);
  }
  
  // At all points in time, the stack maintains its monotonic property
}
//For next greater and previous greater elements, we use the monotonic decreasing stack

Next greater indices:  Monotonous non-increasing stack
function findNextGreaterIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize nextGreater array, this array hold the output
  // initialize all the elements are -1 (invalid value)
  let nextGreater = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
    // while loop runs until the stack is not empty AND
    // the element represented by stack top is STRICTLY SMALLER than the current element
    // This means, the stack will always be monotonic non increasing (type 4)
    while (stack.length && arr[stack.top()] < arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
      
      // as given in the condition of the while loop above,
      // nextGreater element of stackTop is the element at index i
      nextGreater[stackTop] = i;
    }
    
    // push the current element
    stack.push(i);
  }
  return nextGreater;
}
//If the question was to find next greater or equal elements, then we would have used a monotonic strictly decreasing stack (type 3)
We use the operator < in while loop condition above - this results in a monotonic non increasing stack (type 4). If we use <= operator, then this becomes a monotonic strictly decreasing stack (type 3)

  Previous Greater indices:
  function findPreviousGreaterIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize previousGreater array, this array hold the output
  // initialize all the elements are -1 (invalid value)
  let previousGreater = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
     // while loop runs until the stack is not empty AND
     // the element represented by stack top is SMALLER OR EQUAL to the current element
     // This means, the stack will always be strictly decreasing (type 3) - because elements are popped when they are equal
     // so equal elements will never stay in the stack (definition of strictly decreasing stack)
    while (stack.length && arr[stack.at(-1)] <= arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
    }
    
    // after the while loop, only the elements which are greater than the current element are left in stack
    // this means we can confidentally decide the previous greater element of the current element i, that's stack top
    if (stack.length) {
      previousGreater[i] = stack.at(-1);
    }
    
    // push the current element
    stack.push(i);
  }
  return previousGreater;
}
//If the question was to find previous greater or equal elements, then we would have used a monotonic non increasing stack (type 4)
We use the operator <= in while loop condition above - this results in a monotonic strictly decreasing stack (type 3). If we use < operator, then this becomes a monotonic non increasing stack (type 4).

  Next greater and previous greater together:


For example, in the array [13, 8, 1, 5, 2, 5, 9, 7, 6, 12]
The next greater element for the first 5 will be 9, the previous greater element for the second 5 will be 5 (not 8)
OR
The next greater element for the first 5 will be 5 (not 9), the previous greater element for the second 5 will be 8.

This solution works if you are okay with one of the two cases above. Let's look at the code now.


function findNextAndPreviousGreaterIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize previousGreater and nextGreater arrays
  let previousGreater = new Array(arr.length).fill(-1);
  let nextGreater = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
     // while loop runs until the stack is not empty AND
     // the element represented by stack top is SMALLER OR EQUAL to the current element
     // This means, the stack will always be strictly decreasing (type 3) - because elements are popped when they are equal
     // so equal elements will never stay in the stack (definition of strictly decreasing stack)
    while (stack.length && arr[stack.at(-1)] <= arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
      
      // This is the only additional line added to the last approach
      // decides the next greater element for the index popped out from stack
      nextGreater[stackTop] = i;
    }
    
    // after the while loop, only the elements which are greater than the current element are left in stack
    // this means we can confidentally decide the previous greater element of the current element i, that's stack top
    if (stack.length) {
      previousGreater[i] = stack.at(-1);
    }
    
    // push the current element
    stack.push(i);
  }
  return [previousGreater, nextGreater];
}
//In the code example given above, the nextGreater array points at next greater or equal element. While previousGreater array points at strictly greater elements in the leftward direction (previous strictly greater).

Next Smaller (strictly smaller):

 
public class NextSmallerElement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int nsmaller[] = new int[n];
        Arrays.fill(nsmaller,-1);
        Stack<Integer> st = new Stack<>();  //monotonic non-decreasing stack
        for(int i=0;i<n;i++) {
            while (!st.isEmpty() && arr[st.peek()] > arr[i]) {
                nsmaller[st.peek()] = i;
                st.pop();
            }

            st.push(i);
        }
        for(int it: nsmaller){
            System.out.print(it+" ");
        }
        System.out.println();
    }
}

Previous smaller: (strictly smaller)
  function findNextSmallerIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize previousSmaller array, this array hold the output
  // initialize all the elements are -1 (invalid value)
  let previousSmaller = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
    // while loop runs until the stack is not empty AND
    // the element represented by stack top is LARGER OR EQUAL to the current element
    // This means, the stack will always be monotonic strictly increasing (type 1)
    while (stack.length && arr[stack.at(-1)] >= arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
    }
    
    // this is the additional bit here
    if (stack.length) {
      // the index at the stack top refers to the previous smaller element for `i`th index
      previousSmaller[i] = stack.at(-1);
    }
    
    // push the current element
    stack.push(i);
  }
  return previousSmaller;
}

Next Smaller and Previous Smaller (merged, one strictly smaller, and the other smaller or equal)

function findNextSmallerIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize previousSmaller array, this array hold the output
  // initialize all the elements are -1 (invalid value)
  let previousSmaller = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
    // while loop runs until the stack is not empty AND
    // the element represented by stack top is LARGER OR EQUAL to the current element
    // This means, the stack will always be monotonic strictly increasing (type 1)
    while (stack.length && arr[stack.at(-1)] >= arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
      
      // as given in the condition of the while loop above,
      // nextSmaller element of stackTop is the element at index i
      nextSmaller[stackTop] = i;
    }
    
    // this is the additional bit here
    if (stack.length) {
      // the index at the stack top refers to the previous smaller element for `i`th index
      previousSmaller[i] = stack.at(-1);
    }
    
    // push the current element
    stack.push(i);
  }
  return [nextSmaller, previousSmaller];
}

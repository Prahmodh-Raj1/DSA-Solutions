//Find the nearest smaller element to the left of the array
//Eg: [4,10,5,8,20,15,3,12]
//ans: -1,4,4,5,8,8,-1,3       if no smaller ele is found, print -1
//Create a stack, for the first ele, no ele would be present in stack, so we print -1 and push the first ele in stack
//for the consequent elements, chk if there's a smaller elemnt in stack's stop, if yes, print the top ele and insert the current ele
//if not,we pop the stack's top and keep chking & continuing the process until 
//stack is not empty and we find a ele smaller than current ele, if stk turns empty, print -1
//TC: O (N)  SC:O(N)
//FInd the nearest greater elment in array
//create a stack, for the first ele, just insert it onto stack, for the consequent ele's,keep chking in stack
//until u find a greater number than the current ele, if found print the number, else keep popping from stack
//and if stk becomes empty, print -1 and push the cur ele onto stck

//Refer for code:https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/

//Q.Find the nearest smaller ele to the right of array
//Eg:[3,10,5,1,15,10,7,6]
//ans:1,5,1,-1,10,7,6,-1
//create a stack, start traversing from the end of array
//Refer for code and intuition: https://www.geeksforgeeks.org/next-greater-element/ 


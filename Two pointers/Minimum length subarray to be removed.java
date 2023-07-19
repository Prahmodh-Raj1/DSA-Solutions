//Problem link: https://www.codingninjas.com/studio/library/find-the-minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted
// TC: O(N) SC: O(1)
static void minUnsorted(int A[], int n)
{
    int S = 0, a= n-1, i, maximum, minimum;  
  
    // Increment S
    for (S = 0; S < n-1; S++)
    {
        if (A[S] > A[S+1])
          break;
    }
  
    //Check if the entire array is sorted
    if (S == n-1)
    {
        System.out.println("The complete array is sorted");
        return;
    }
        // Increment the 'a' pointer till n-1

        for(a = n - 1; a > 0; a--)
    {
        if(A[a] < A[a-1])
          break;
    }
  
    // Find the minimum and maximum element of unsorted array
    maximum = A[S]; minimum = A[S];
    for(i = S + 1; i <= a; i++)
    {
        if(A[i] > maximum){
          maximum = A[i];
        }
        if(A[i] < minimum){
          minimum = A[i];
        }
    }
  
        for( i = 0; i < S; i++)
    {
        if(A[i] > minimum)
        {
          S = i;
          break;
        }    
    }
      
        for( i = n -1; i >= a+1; i--)
    {
        if(A[i] < maximum)
        {
          a = i;
          break;
        }
    }
      
    System.out.println("We need to sort the subarray"+" ("+S+" "+a+")");
    return;
}

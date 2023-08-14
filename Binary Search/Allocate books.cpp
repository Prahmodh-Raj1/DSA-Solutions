//TC: O(Nlog(sum))
int num(int mid, vector<int> &A)
{
        int sum=0,num_student=1;
        for(int i=0;i<A.size();i++)
        {
       
            if(sum+A[i]<=mid)
            {
                sum=sum+A[i];
            }
            else
            {
                num_student++;
                sum=A[i];
            }
        }
        return num_student;
    }
int Solution::books(vector<int> &A, int B)
{
    if(A.size()<B)
    {
        return -1;
    }
    int result=-1;;
    int low=*max_element(A.begin(), A.end());
    int x=0;
    for(int i=0;i<A.size();i++)
    {
        x=x+A[i];
    }
    int high=x;
    while(low<=high)
    {
        int mid = low + (high - low) / 2;
        if(num(mid,A)<=B)
        {
            result=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
       
    }
    return result;

}

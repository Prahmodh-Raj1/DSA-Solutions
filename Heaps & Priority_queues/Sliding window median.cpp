//Problem link : https://leetcode.com/problems/sliding-window-median/
//TC: O(NlogK) SC: O(K)
class Solution{
public:; https://leetcode.com/problems/sliding-window-median/solutions/96392/c-95-ms-single-multiset-o-n-log-n/
//Using multiset
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    int size = nums.size(), median_pos = k - k / 2 - 1;
    vector<double> res(size - k + 1);
    multiset<int> s(nums.begin(), nums.begin() + k);
    auto it = next(s.begin(), median_pos);

    for (auto i = k; i <= size; ++i)
    {
        res[i - k] = ((double)*it + (k % 2 != 0 ? *it : *next(it))) / 2;
        if (i < size)
        {
            // magic numbers (instead of enum) for brevity. INT_MAX means to retrace the iterator from the beginning.
            int repos_it = INT_MAX; 
            if (k > 2)
            {
                // if inserted or removed item equals to the current median, we need to retrace.
                // we do not know which exact element will be removed/inserted, and we cannot compare multiset iterators.
                // otherwise, we can keep or increment/decrement the current median iterator.
                if ((nums[i - k] < *it && nums[i] < *it) || (nums[i - k] > *it && nums[i] > *it)) repos_it = 0;
                else if (nums[i - k] < *it && nums[i] > *it) repos_it = 1; // advance forward.
                else if (nums[i - k] > *it && nums[i] < *it) repos_it = -1; // advance backward.
            }
            s.insert(nums[i]);
            s.erase(s.find(nums[i - k]));

            if (repos_it == INT_MAX) it = next(s.begin(), median_pos);
            else if (repos_it == 1) ++it;
            else if (repos_it == -1) --it;
        }
    }
    return res;
}
};

//Using Priority queue
//TC: O(N*K) SC: O(K)
class Solution {
    
private:
    priority_queue<int,vector<int>,greater<int>> minh;
    priority_queue<int> maxh;
    void add(int num){
        //adding element to the correct heap
        if(maxh.empty() or maxh.top()>num){
            //gotta add to maxh
            maxh.push(num);
        }else{
            //gotta add to minheap
            minh.push(num);
        }
        balance();
    }   
    void balance(){
        if(maxh.size()>minh.size()+1){
            auto it = maxh.top();
            minh.push(it);
            maxh.pop();
        }else if(minh.size()>maxh.size()){
            auto it=minh.top();
            maxh.push(it);
            minh.pop();
        }
    } 
    void remove(int num){
        //removing the element from the correct heap
        if(num<=maxh.top()){
            //remove from maxheap
            maxh.pop();
        }else minh.pop();
        balance();
    }
    double findmedian(){
        if(maxh.size()>minh.size()) return maxh.top();
        if(minh.size()>maxh.size()) return minh.top();
        return (maxh.top() + minh.top())/2.0;
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int left=0;
        int n= nums.size();
        vector<double>  ans(n-k+1);

        for(int right=0;right<n;right++){
            add(nums[right]);
            int sizeofwindow = right-left+1;
            if(sizeofwindow==k){
                ans[left] = findmedian();
                remove(nums[left]);  //remove the  element at the left as we are going to the next window
                left++; //moving to the next window

            }
        }
        return ans;



    }
};

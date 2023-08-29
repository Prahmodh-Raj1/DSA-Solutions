//Prob link: https://leetcode.com/problems/range-sum-query-mutable
//Prob link: https://leetcode.com/problems/range-sum-query-immutable
class SegmentTree{
private:
    vector<int> seg;
public:
    SegmentTree(){

    }
    void resize(int n){
        seg.resize(4*n +1);
    }
    void build(int index,int low,int high,vector<int>& arr){
        if(low==high){
            seg[index] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*index +1,low,mid,arr);
        build(2*index +2,mid+1,high,arr);
        seg[index] = seg[2*index +1] + seg[2*index +2];
    }
    int query(int index,int low,int high,int l,int r){
        if(r<low || high<l) return 0;
        if(low>=l && high<=r) return seg[index];
        int mid = (low + high)/2;
        int left = query(2*index + 1,low,mid,l,r);
        int right  = query(2*index +2,mid+1,high,l,r);
        return left+right;
    }
    void update(int index,int low,int high,int indextoChange,int value){
        if(low==high){
            seg[index]  = value;
            return;
        }
        int mid = (low+high)/2;
        if(indextoChange<=mid){
            update(2*index +1,low,mid,indextoChange,value);
        }else{
            update(2*index +2,mid+1,high,indextoChange,value);
        }
        seg[index] = seg[2*index +1] + seg[2*index +2];
        
    }
};
class NumArray {
public:
    SegmentTree seg;
    int n;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr=nums;
        n = nums.size();
        seg.resize(n);
        seg.build(0,0,n-1,arr);
    }
    
    void update(int index, int val) {
        seg.update(0,0,n-1,index,val);
        arr[index]=val;
    }
    
    int sumRange(int left, int right) {
        int sum1 = seg.query(0,0,n-1,left,right);
        return sum1;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class SegmentTree{
private:
    vector<int> seg;
public:
    SegmentTree(){}
    void resize(int n){
        seg.resize(4*n +1);
    }
    void build(int index,int low,int high,vector<int>& arr){
        if(low==high){
            seg[index]=arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*index +1,low,mid,arr);
        build(2*index +2,mid+1,high,arr);
        seg[index]= seg[2*index +1] + seg[2*index +2]; 
    }
    int query(int index,int low,int high,int l,int r,vector<int>& arr){
        if(r<low || high<l) return 0;
        if(low>=l &&  high<=r) return seg[index];
        int mid = (low+high)/2;
        int left = query(2*index +1,low,mid,l,r,arr);
        int right = query(2*index +2,mid+1,high,l,r,arr);
        return left+right;
    }

};
class NumArray {
public:
    SegmentTree seg;
    int n;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr=nums;
        n = nums.size();
        seg.resize(n);
        seg.build(0,0,n-1,arr);
    }
    
    int sumRange(int left, int right) {
        int sum = seg.query(0,0,n-1,left,right,arr);
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

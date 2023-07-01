//Problem link: https://leetcode.com/problems/find-median-from-data-stream/
//TC: O(LogK) k: size of PQ, SC: O(2*(n/2))
class MedianFinder {
private:
    priority_queue<long long> lower,upper;  //lower contains the smaller n/2 elements, upper contains the larger n/2 elements, upper contains the values in negative sign
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lower.push(num);
        upper.push(-1*lower.top());
        lower.pop();
        if(lower.size()<upper.size()){
            lower.push(-1*upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if(lower.size()>upper.size()){
            return lower.top();
        }
        return (lower.top()-upper.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
/*Explanation: Max-heap small has the smaller half of the numbers.
Min-heap large has the larger half of the numbers.
This gives me direct access to the one or two middle values (they're the tops of the heaps), so getting the median takes O(1) time. And adding a number takes O(log n) time.*/

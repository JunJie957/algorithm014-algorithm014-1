## 使用单调队列处理滑动窗口最大值问题

本周主要的学习内容是哈希、二叉树和堆，其中有一个习题：[239. Sliding Window Maximum](https://leetcode-cn.com/problems/sliding-window-maximum/)，可以使用单调队列来决题目。而单调队列之前并不熟悉，在这里对其定义和使用做一下整理和总结。

### 1、单调队列的定义

    class MonotonicQueue {
    private:
        deque<int> data;	// 数据队列
    public:
    	// 添加新元素
        void push(int n) {
            while (!data.empty() && data.back() < n)
                data.pop_back();
            data.push_back(n);
        }
        
    	// 返回当前队列中元素的最大值
    	int max() { return data.front(); }
    	
    	// 元素出队
    	void pop(int n) {
        if (!data.empty() && data.front() == n)
            data.pop_front();
    	}
    };
（1）**添加新元素**：当需要添加一个新元素时，首先要保证队列中已经存在的元素比新元素都大或都小（单调递增队列、单调递减队列），因此将队列元素的末尾值与新元素进行比较，如果不满足条件，则将末尾元素出队，此处就是保证队列单调的一个重要条件判断。如果队列为空或者队列最后一个元素比新元素大（或小）, 则直接将新元素添加到队列的末尾处。

（2）**返回队列中的最大值/最小值**：直接返回队首元素即可，因为push()操作已经将元素按照单调性的条件进行排序，因此可以保证队首元素始终是最大值或最小值。

（3）**元素出队**：在队列元素不为空的前提下，判断需要出队的元素是否是当前队列的首部元素，如果是，则将元素出队。如果不是，说明队列中不存在此元素，或者在push()操作的时候，已经根据单调队列的条件，对齐进行出队的处理。

### 2、单调队列解决滑动窗口最大值问题

单调队列之所以可以处理滑动窗口问题，是因为在队列中插入或删除元素的过程中，随时可以获取队列中元素的最大值。这也是由于单调队列的性质所决定的。

而队列的大小，取决于滑动窗口的大小，即需要入队的元素个数，另外还有元素之间的大小关系，以及队列的单调性质。

### 3、复杂度分析

（1）push ： O(n)

（2）max():    O(1)

（3）pop():     O(1)

### 4、处理 [239. Sliding Window Maximum](https://leetcode-cn.com/problems/sliding-window-maximum/) 问题的完整代码

    class MonotonicQueue {
    private:
        deque<int> data;
    public:
        void push(int n) {
            while (!data.empty() && data.back() < n) 
                data.pop_back();
            data.push_back(n);
        }
        
    	int max() { return data.front(); }
    
    	void pop(int n) {
        	if (!data.empty() && data.front() == n)
            	data.pop_front();
    	}
    };
    
    class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            MonotonicQueue window;
            vector<int> res;
            for (int i = 0; i < nums.size(); i++) {
                if (i < k - 1) { // 先填满窗口的前 k - 1
                    window.push(nums[i]);
                } else { // 窗口向前滑动
                    window.push(nums[i]);
                    res.push_back(window.max());
                    window.pop(nums[i - k + 1]);
                }
            }
            return res;
        }
    };





































class MyCircularDeque {
public:
    vector<int> v;
    int cap;
    int size;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
        cap = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (cap >= size)  return false;
        v.insert(v.begin(), value);
        ++cap;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (cap >= size) return false;
        v.push_back(value);
        ++cap;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (cap == 0) return false;
        v.erase(v.begin());
        --cap;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (cap == 0) return false;
        v.pop_back();
        --cap;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (cap != 0) return v[0];
        return -1;
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (cap != 0) return v[cap - 1];
        return -1;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cap == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
    	return cap == size; 
    }
};

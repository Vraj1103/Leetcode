class KthLargest {
public:
    priority_queue<int> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto x : nums)
            pq.push(x * (-1));
    }

    int add(int val) {
        pq.push((-1) * val);
        while (pq.size() > K) {
            pq.pop();
        }
        return (-1) * pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
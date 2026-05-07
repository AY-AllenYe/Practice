#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {

            // 移除不在窗口内的索引 （队列不为空、队首不过期）
            if (!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }

            // 保持队列递减
            while (!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            // 窗口形成后记录结果
            if (i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};


int main() {
    Solution solution;
    int n;
    vector<int> nums;
    int k;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        nums.push_back(value);
    }

    cin >> k;

    auto result = solution.maxSlidingWindow(nums, k);
    
    // 输出结果
    cout << "[";
    for(int i = 0; i < result.size(); i++){
        cout << result[i];
        if(i != result.size() - 1){
            cout << ",";
        }
    }
    cout << "]";
    
    return 0;
}
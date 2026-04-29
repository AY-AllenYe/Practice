#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int max_tmp_index = 0;
        vector<int> ans;

        if (nums.size() == 1){
            ans.push_back(nums[0]);
            return ans;
        }
        
        if(k > nums.size()){
            for(int i = 0; i < nums.size(); i++){
                if(nums[max_tmp_index] > nums[i]){
                    max_tmp_index = i;
                }
            }
            ans.push_back(nums[max_tmp_index]);
            return ans;
        }

        for (int i = 0; i < k; i++){
            if(nums[max_tmp_index] <= nums[i]){
                max_tmp_index = i;
            }
        }
        ans.push_back(nums[max_tmp_index]);

        for(int index = 1; index < nums.size() - k + 1; index++){
            if(max_tmp_index >= index){
                if(nums[max_tmp_index] <= nums[index + k - 1]){
                    max_tmp_index = index + k - 1;
                }
            }else{
                max_tmp_index = index;
                for (int i = index; i < k + index; i++){
                    if(nums[max_tmp_index] <= nums[i]){
                        max_tmp_index = i;
                    }
                }
            }
            ans.push_back(nums[max_tmp_index]);
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
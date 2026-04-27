#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        int tmp;
        while (right < nums.size()) {
            if (nums[right]) {
                if(left != right){
                    nums[left] = nums[right];
                    nums[right] = 0;
                }
                left++;
            }
            right++;
        }
        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> result;
    
    int n;
    vector<int> num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        num.push_back(value);
    }

    result = solution.moveZeroes(num);
    
    // 输出结果
    for(int i = 0; i < result.size(); i++){
        cout << result[i];
        if(i != result.size() - 1){
            cout  << ",";
        }
    }
    
    return 0;
}
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int index1 = 0; index1 < nums.size(); index1++) {
            for (int index2 = index1 + 1; index2 < nums.size(); index2++) {
                if (nums[index1] + nums[index2] == target) {
                    return {index1, index2};
                }
            }
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int n, target;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cin >> target;

    vector<int> result = solution.twoSum(nums, target);

    cout << to_string(result[0]) << " " << to_string(result[1]) << endl;
    return 0;
}
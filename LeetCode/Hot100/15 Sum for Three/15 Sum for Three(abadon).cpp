#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int tmp;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                if(nums[i] > nums[j]){
                    tmp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = tmp;
                }
            }
        }

        int left = 1, right = nums.size();
        vector<vector<int>> result;

        if(nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0){
            return {};
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                break;
            }
            left = i + 1;
            right = nums.size() - 1;
            while(nums[i] + nums[left] + nums[right] > 0){
                right--;
            }
            if(left >= right){
                continue;
            }
            while(nums[i] + nums[left] + nums[right] < 0){
                left++;
            }
            if(left >= right){
                continue;
            }
            if(nums[i] + nums[left] + nums[right] == 0){
                result.push_back({nums[i], nums[left], nums[right]});
            }
        }

        // for(int i = 0; i < result.size(); i++){
        //     for(int j = 0; j < 3; j++){
        //         cout << result[i][j];
        //         if(j != 2){
        //             cout  << ",";
        //         }
        //     }
        //     if(i != result.size() - 1){
        //         cout  << ",";
        //     }
        // }
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> result;
    
    int n;
    vector<int> num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        num.push_back(value);
    }

    result = solution.threeSum(num);
    
    // 输出结果
    for(int i = 0; i < result.size(); i++){
        cout << "[";
        for(int j = 0; j < 3; j++){
            cout << result[i][j];
            if(j != 2){
                cout  << ",";
            }
        }
        cout  << "]";
        if(i != result.size() - 1){
            cout  << ",";
        }
    }
    
    return 0;
}
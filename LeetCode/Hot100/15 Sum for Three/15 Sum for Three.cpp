#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        
        if(nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0){
            return {};
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            if(nums[i] > 0){
                break;
            }
            
            int left = i + 1, right = nums.size() - 1;
            
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum > 0){
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                }
            }
        }
        
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
    cout << "[";
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
    cout  << "]";

    return 0;
}
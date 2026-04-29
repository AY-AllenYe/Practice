#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int arr[n];
        for(int i = 0; i < nums.size(); i++){
            arr[i] = nums[i];
        }

        int count = 0;
        for (int start = 0; start < nums.size(); start++){
            int sum = 0;
            // for (int end = start; end >= 0; end--){
            for (int end = start; end < nums.size(); end++){
                sum += arr[end];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};
        

int main() {
    Solution solution;
    vector<string> strs;
    
    int n, k;
    vector<int> num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        num.push_back(value);
    }

    cin >> k;
    auto result = solution.subarraySum(num, k);
    
    // 输出结果
    cout << result;
    
    return 0;
}
#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int index = 0;
        int k_origin = k;
        while(index < nums.size()){
            while(k > 0){
                k -= nums[index++];
                if(index == nums.size()){
                    break;
                }
            }
            if(k == 0){
                ans++;
                index--;
            }
            k = k_origin;
        }
        return ans;
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
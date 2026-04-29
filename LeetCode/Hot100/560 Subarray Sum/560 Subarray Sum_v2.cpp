#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        hashmap[0] = 1;
        int count = 0, pre = 0;
        for(auto x : nums){
            pre += x;
            if(hashmap.find(pre - k) != hashmap.end()){
                count += hashmap[pre - k];
            }
            hashmap[pre]++;
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
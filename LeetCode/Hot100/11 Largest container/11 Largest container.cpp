#include<vector>
#include<string>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxium = 0, cur = 0;
        int left_index = 0, right_index = height.size() - 1;
        while(left_index < right_index){
            cur = min(height[left_index], height[right_index]) * (right_index - left_index);
            maxium = max(cur, maxium);
            if(height[left_index] < height[right_index]){
                left_index++;
            }else{
                right_index--;
            }
        }
        return maxium;
    }
};

int main() {
    Solution solution;
    int result;
    
    int n;
    vector<int> num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        num.push_back(value);
    }

    result = solution.maxArea(num);
    
    cout << result;
    
    return 0;
}
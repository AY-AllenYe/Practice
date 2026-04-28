#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(p.length() > s.length()){
            return {};
        }
        
        vector<int> list_index;
        sort(p.begin(), p.end());

        string s_sub;
        for(int index = 0; index <= s.length() - p.length(); index++){
            s_sub = s.substr(index, p.length());
            sort(s_sub.begin(), s_sub.end());
            if (s_sub == p){
                list_index.push_back(index);
            }
        }
        return list_index;
    }
};

int main() {
    Solution solution;
    string strs;
    string strs_sub;
    
    cin >> strs;
    cin >> strs_sub;

    auto result = solution.findAnagrams(strs, strs_sub);
    
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
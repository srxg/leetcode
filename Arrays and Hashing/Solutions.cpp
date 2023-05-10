#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

// Contains Duplicate
bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_map<int, int> num_map;

    for(int i = 0; i < nums.size(); i++) {
        num_map[nums[i]]++;
    }
    for(auto p : num_map) {
        if(p.second > 1) {
            return true;
        }    
    }
    return false;
}

// Valid Anagram
// a frequency table would be an even better approach, see here:
// bool isAnagram(string s, string t){
//     int freqtable[256]={0};
//     for(int i=0;i<s.size();i++){
//         freqtable[s[i]]++;
//     }
//      for(int i=0;i<t.size();i++){
//         freqtable[t[i]]--;
//     }
//     for(int i=0;i<256;i++){
//         if(freqtable[i]!=0)
//         return false;
//     }
//     return true;
// }
bool isAnagram(std::string s, std::string t) {
    if(s.length() != t.length()) return false;
    std::sort(s.begin(),s.end());
    std::sort(t.begin(), t.end());
    return s==t;
}

// two sum
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numToIndex;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numToIndex.count(complement)) {
            return {numToIndex[complement], i};
        }
        numToIndex[nums[i]] = i;
    }
    return {};
}




int main() {
    std::vector<int> ex_nums = {1,2,2,3};
    std::cout << containsDuplicate(ex_nums) << std::endl;
}
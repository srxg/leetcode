#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <queue>

// Contains Duplicate
bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> nums_set;

    for (int num : nums) {
        if (nums_set.count(num) > 0) {
            return true;
        }
        nums_set.insert(num);
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

/*
 Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
 typically using all the original letters exactly once. 
*/
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> anagrams;
    
    std::unordered_map<std::string, std::vector<std::string>> sortedStringToAnagrams;

    for(int i = 0; i < strs.size(); i++) {
        std::string strCopy = strs[i];
        std::sort(strCopy.begin(),strCopy.end());

        if(!sortedStringToAnagrams.count(strCopy)) {
            sortedStringToAnagrams.emplace(strCopy, std::vector<std::string>{strs[i]});
        } else { // it's an anagram
            sortedStringToAnagrams.at(strCopy).push_back(strs[i]);
        }
    }

    for(auto& i : sortedStringToAnagrams) {
        anagrams.push_back(i.second);
    }

    return anagrams;

}

/**
 * TODO: 
 * ? Something
 * ! Something
 * * Something else
 * 
*/
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::map<int, int> hashmap;
    std::vector<int> ans;

    std::priority_queue<int> maxHeap;

    for(auto& i : nums) {
        hashmap[i]++;
    }
    
    for(auto& i : hashmap) {
        maxHeap.push(i.second);
    }

    while(k > 0) {
        int countFreq = maxHeap.top();
        maxHeap.pop();
        for(auto& it : hashmap) {
            if(countFreq == it.second) {
                ans.push_back(it.first);
                hashmap.erase(it.first);
                --k;
                break;
            }
        }
    }

    return ans;
}

/**
 * Product of Array Except Self
 * Given integer array nums, return array answer
 * such that answer[i] = product of all element of nums
 * apart from nums[i]
*/
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    // given nums
    // get array answer
    // so that answer[i] = product of all elements of nums
    // except nums[i]
    vector<int> answer(nums.size());
    map<int, int> indexToLeftProd;
    // map<int, int[2]> indexToRightProduct;

    int prod = 1;
    // get the left product of each index
    for(int i = 0; i < nums.size(); i++) {
        if(i != 0) prod *= nums[i-1];
        indexToLeftProd[i] = prod;
    }

    prod = 1;

    for(int i = nums.size()-1; i > -1; i--) {
        if(i != nums.size()-1) prod *= nums[i+1];
        answer[i] = indexToLeftProd[i]*prod;
    }

    // for(int i = 0; i < nums.size(); i++) 
    // {
    //     int left = indexToLeftAndRightProduct.at(i)[0];
    //     int right = indexToLeftAndRightProduct.at(i)[1];
    //     std::cout << "For index i = " << std::to_string(i) << ", left product is = " << std::to_string(left) << " and right product is = " << std::to_string(right) << std::endl;
    //     answer[i] = left*right;
    // }
    return answer;
}


int main() {
    std::vector<int> ex_nums = {1,2,2,3};
    std::cout << containsDuplicate(ex_nums) << std::endl;
}
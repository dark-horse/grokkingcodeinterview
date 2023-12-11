#pragma once

using namespace std;

#include<vector>
#include<stack>
#include<unordered_map>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/64beb292777d61d4371e18ae */
/*
** Given two integer arrays nums1 and nums2, return an array answer such that answer[i] is the next greater number for every nums1[i] in nums2.
** The next greater element for an element x is the first element to the right of x that is greater than x.
** If there is no greater number, output -1 for that number.
** The numbers in nums1 are all present in nums2 and nums2 is a permutation of nums1.
***** (Side note = when you say nums2 is a permutation of nums1 that means nums2 does not contain any numbers that nums1 does not contain
***** probably the author meant to say "nums2 contains a permutation of nums1 - as the examples below show)
**
***** Another Side note - the text of the problem does not specify, but the first elements in nums2 are all the elements from nums1.
***** .... and this turns out to be false.... I sort of wished they specified these things...
**
***** Third Side note - the text of the problem does not specify what would happen if nums1 contain duplicates.
***** Let's assume it does not and see if we pass all the tests :)...
**
** Examples
** Input: nums1 = [4,2,6], nums2 = [6,2,4,5,3,7]
** Output: [5,4,7]
** Explanation: The next greater number for 4 is 5, for 2 is 4, and for 6 is 7 in nums2.
**
** Input: nums1 = [9,7,1], nums2 = [1,7,9,5,4,3]
** Output: [-1,9,7]
** Explanation: The next greater number for 9 does not exist, for 7 is 9, and for 1 is 7 in nums2.
**
** Input: nums1 = [5,12,3], nums2 = [12,3,5,4,10,15]
** Output: [10,15,5]
** Explanation: The next greater number for 5 is 10, for 12 is 15, and for 3 is 5 in nums2.
*/

class nextGreater
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans = vector<int>(nums1.size(), -1);
        if (nums1.size() < 1) return ans;

        stack<int> numsStack;
        unordered_map<int, int> valToIndex;
        for (int i = 0; i < nums1.size(); i++) valToIndex[nums1[i]] = i;

        if (valToIndex.find(nums2[0]) != valToIndex.end()) numsStack.push(nums2[0]);
        for (int i = 0; i < nums2.size(); i++)
        {
            while (!numsStack.empty() && numsStack.top() < nums2[i])
            {
                ans[valToIndex[numsStack.top()]] = nums2[i];
                numsStack.pop();
            }

            if (valToIndex.find(nums2[i]) != valToIndex.end()) numsStack.push(nums2[i]);
        }

        return ans;
    }
};
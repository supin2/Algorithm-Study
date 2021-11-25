#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        int size = nums.size();
        for (int j = 0; j < size; j++) {
            if (nums[j] != val) {
                nums[idx] = nums[j];
                idx++;
            }
        }
        return idx;
    }
};
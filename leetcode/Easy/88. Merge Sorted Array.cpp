#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mIdx = m - 1, nIdx = n - 1, totIdx = m + n - 1;
        
        while (mIdx >= 0 && nIdx >= 0) {
            if (nums1[mIdx] >= nums2[nIdx]) {
                nums1[totIdx--] = nums1[mIdx--];
            } else {
                nums1[totIdx--] = nums2[nIdx--];
            }
        }
        while (nIdx >= 0) {
            nums1[totIdx--] = nums2[nIdx--];
        }
    }
};
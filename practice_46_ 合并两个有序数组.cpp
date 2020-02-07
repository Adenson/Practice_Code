给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        nums1.reserve(m+n);
        for(int i = m; i < nums1.size(); ++i)
        {
            nums1[i] = nums2[n-1];
            --n;
        }
        sort(nums1.begin(),nums1.end());
    }
};

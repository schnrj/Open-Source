class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int k = 0;
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merge(m + n);

        while (i < m && j < n) {
            if (nums1[i] < nums2[j])
                merge[k++] = nums1[i++];
            else
                merge[k++] = nums2[j++];
        }

        while (i < m)
            merge[k++] = nums1[i++];

        while (j < n)
            merge[k++] = nums2[j++];

        int total = m + n;
        if (total % 2 != 0)
            return static_cast<double>(merge[(total - 1) / 2]);
        else
            return (static_cast<double>(merge[total / 2 - 1]) + static_cast<double>(merge[total / 2])) / 2.0;
    }
};

class Solution {
public:
    int findFirstOccurrence(vector<int>& nums, int target) {
    int lo = -1, hi = nums.size();
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] >= target) hi = mid;
        else lo = mid;
    }
    if (hi == nums.size() || nums[hi] != target) return -1;
    return hi;
}

int findLastOccurrence(vector<int>& nums, int target) {
    int lo = -1, hi = nums.size();
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] <= target) lo = mid;
        else hi = mid;
    }
    if (lo == -1 || nums[lo] != target) return -1;
    return lo;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int first = findFirstOccurrence(nums, target);
    int last = findLastOccurrence(nums, target);
    return {first, last};
}
};
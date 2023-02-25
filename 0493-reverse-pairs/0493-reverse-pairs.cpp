using lli = long long int;
class Solution {
public:
  int Merge(vector < int > & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > (lli)2 * nums[j]) {
      j++;
    }
    total += (j - (mid + 1));
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
    int mergeSort(int lo,int hi,vector<int>&nums)
    {
        if(lo>=hi)
            return 0;
        int mid = (lo + hi)/2;
        int inv = mergeSort(lo,mid,nums);
        inv += mergeSort(mid+1,hi,nums);
        inv += Merge(nums,lo,mid,hi);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1,nums);
    }
};
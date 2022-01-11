class Solution {
public:
    int search(vector<int>& arr, int target) {
      int i = 0;
      int j = arr.size()-1;
      while(i<=j)
      {
          int mid = j-(j-i)/2;
          if(arr[mid]==target)
              return mid;
          if(arr[mid]>target)
          {
              j = mid -1;
          }
          if(arr[mid]<target)
          {
              i = mid + 1;
          }
      }
      return -1;
    }
};
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(auto i : arr)
            sum += i;
        if(sum%3 != 0)
            return false;
        int cnt = 0,curr = 0;
        for(int i = 0;i<n;i++)
        {
            curr += arr[i];
            if(curr==sum/3){
                cnt++;
                curr = 0;
            }
        }
        return cnt>=3;
        
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt = 0;
        int maxEle = 0;
        for(int i = 0;i<arr.size();i++)
        {
            maxEle = max(arr[i],maxEle);
            if(maxEle == i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
    public: 
    void findCombination(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {

        if(target==0) {
            ans.push_back(ds);
            return;
        }
        for(int  i = idx;i<arr.size();i++)
        {   if(i>idx && arr[i]==arr[i-1]) continue; 
            if(target>=arr[i])
            {
                ds.push_back(arr[i]);
                findCombination(i+1,target-arr[i],arr,ans,ds);
                ds.pop_back();
            }
            else{
                break;
            }
        }
    
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; 
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds); 
        return ans; 
    }
};
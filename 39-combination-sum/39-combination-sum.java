class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>>ans = new ArrayList<>();
        List<Integer>que = new ArrayList<>();
        solve(candidates,target,0,que,ans,0);
        return ans;
    }
    public void solve(int[] arr, int target,int sum ,List<Integer>que,List<List<Integer>>ans,int idx)
    {
       if(idx == arr.length)
       {
           if(target==sum)
           {
               ans.add(new ArrayList(que));
              
           }
           return ;
       }

            if(sum<=target)
            {
                que.add(arr[idx]);
                solve(arr,target,sum+arr[idx],que,ans,idx);
                que.remove(que.size()-1);
            }
             solve(arr,target,sum,que,ans,idx+1);
    
    }
    
}
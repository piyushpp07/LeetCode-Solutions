class Solution {
    public int numPairsDivisibleBy60(int[] time) {
      int count=0;
      int []mp=new int[60];
      for(int i : time)
      {
          if(i%60==0)
              count+=mp[0];
          else
              count+=mp[60-i%60];
             
          mp[i%60]+=1;
      }
        return count;
    }
}
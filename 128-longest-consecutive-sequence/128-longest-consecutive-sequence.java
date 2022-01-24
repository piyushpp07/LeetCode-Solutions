class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer,Boolean>hs=new HashMap<>();
        for(int i : nums)
        {
            hs.put(i,true);
        }
        for(int i : nums)
        {
            if(hs.containsKey(i-1)==true)
                hs.put(i,false);
        }
        int c = 0;  //min size of consequtive sequence
        for(int i:nums)
        {
            if(hs.get(i)==true)
            {
                int ls = 0;
                while(hs.containsKey(ls+i)==true)
                {
                    ls++;
                }
                if(ls>c)
                {
                    c = ls;
                }
            }
        }
        return c;
    }
}
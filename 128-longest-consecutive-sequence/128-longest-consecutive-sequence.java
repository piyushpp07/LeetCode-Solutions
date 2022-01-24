class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer,Boolean>hs=new HashMap<>();
        for(int i : nums)   //fill the hashmap and nums with true to mark all the element as starting point
        {
            hs.put(i,true);
        } 
        for(int i : nums)
        {
            if(hs.containsKey(i-1)==true) //checking if i-1th element is there if it is there i-1 th is starting point
                hs.put(i,false);
        }
        int c = 0;       //min size of consequtive sequence 
        for(int i:nums)        // traversing the array and checking the length of longest consequtive subsequence
        {
            if(hs.get(i)==true)    // used to check if it is starting point of consequtive subsequence
            {
                int ls = 0;        // for checking local count of lcs
                while(hs.containsKey(ls+i)==true)   // we increment ls if the next elements are present in hash map
                {  
                    ls++;  
                }
                if(ls>c)
                {
                    c = ls;   // if local count > global ones globl = local
                }
            }
        }
        return c;
    }
}




//Taking about time complexity it will be O(n) as while loop will run only for conseqtive elements and will run only total of n times 
// like for 123567 loop outer loop will run n time but as hash map will be  (1,2,3,5,6,7) and true for 1 and 5 , so loop will run for first 1 and then 5 for 1 ->2->3 and for 5->6->7 so total will be 6 = length of the array so time complexity will be O(n)
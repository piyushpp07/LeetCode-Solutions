class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer>hs=new HashMap<>();
        for(int i=0;i<nums1.length;i++)
        {
            hs.put(nums1[i],1);
        }
        int q=0;
        for(int i=0;i<nums2.length;i++)
        {
            if(hs.containsKey(nums2[i])==true)
            {
              q++;
              hs.remove(nums2[i]);
            }
        }
        int arr[]=new int[q];
        for(int i=0;i<nums1.length;i++)
        {
            hs.put(nums1[i],1);
        }
        q=0;
        for(int i=0;i<nums2.length;i++)
        {
            if(hs.containsKey(nums2[i])==true)
            {
              arr[q++]=nums2[i];
                hs.remove(nums2[i]);
            }
        }
        return arr;
    }
}
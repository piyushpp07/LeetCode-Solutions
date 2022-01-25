class Solution {
    public boolean validMountainArray(int[] arr) {
        if(arr.length<3)
            return false;
        int idx=0;
        int  max = arr[0];
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]>max)
            {
                max = arr[i];
             
                idx=i;
            }
  
        }
        boolean dec = false;
        for(int i=idx+1;i<arr.length;i++)
        {
            if(arr[i]>=arr[i-1])
                return false;
            else dec = true;
        }
        boolean inc =false;
        for(int i=1;i<idx+1;i++)
        {
            if(arr[i]<=arr[i-1])
                  return false;
            else inc = true;
        }
        if(inc&&dec)
            return true;
        return false;
    }
}
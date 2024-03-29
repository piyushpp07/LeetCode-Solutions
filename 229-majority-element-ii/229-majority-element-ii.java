class Solution {
        public static boolean isGreaterThanNb3(int[] arr, int val) {
        int count = 0;
        
        for(int ele : arr) {
            if(ele == val)
                count++;
        }
        
        return count > arr.length / 3;
    }
    public List<Integer> majorityElement(int[] arr) {
       if(arr.length == 0) return new ArrayList<>();
        int count1 = 1;
        int val1 = arr[0];
        
        int count2 = 0;
        int val2 = arr[0];
        
        int i = 1;
        while(i < arr.length) {
            if(arr[i] == val1) {
                count1++;
            } else if(arr[i] == val2) {
                count2++;
            } else {
                if(count1 == 0) {
                    val1 = arr[i];
                    count1 = 1;
                } else if(count2 == 0) {
                    val2 = arr[i];
                    count2 = 1;
                } else {
                    count1--;
                    count2--;
                }
            }
            i++;
        }
        ArrayList<Integer> res = new ArrayList<>();
        if(isGreaterThanNb3(arr, val1) == true)
            res.add(val1);
        
        if(val1 != val2 && isGreaterThanNb3(arr, val2) == true)
            res.add(val2);
        
        return res;        
    }
}
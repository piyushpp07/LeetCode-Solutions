class Solution {
    public int firstUniqChar(String s) {
       int n = s.length();
        if(n==1)
            return 0;
       for(int i = 0;i<n;i++)
       {
           char ch = s.charAt(i);
           boolean sol = true;
           for(int j = 0;j<n;j++)
           {  if(j!=i){
                 if(ch == s.charAt(j)){
                   sol = false;
                   break;
               }
               
              }

           }
           if(sol == true)
               return i;
       }
        return -1;

    }
}
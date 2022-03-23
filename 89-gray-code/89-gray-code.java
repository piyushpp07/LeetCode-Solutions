class Solution {
    public List<String> solve(int n){
            if(n==0)
      {
       List<String>res = new ArrayList<String>();   
        res.add("0");
        return res;
      }
      if(n==1)
      {
           List<String>res = new ArrayList<String>();   
            res.add("0");
            res.add("1");
            return res; 
      }
List<String> getfrom = solve(n-1);
List<String> myres = new ArrayList<String>();
      for(int i = 0;i<getfrom.size();i++)
      {
        String  rstr = getfrom.get(i);
        myres.add("0"+rstr);
      }
      for(int i = getfrom.size()-1;i>=0;i--)
      {
        String  rstr = getfrom.get(i);
        myres.add("1"+rstr);
      }
      return myres;
    }
    public List<Integer> grayCode(int n) {
         List<String> ans=solve(n);

         List<Integer>sol   = new ArrayList<Integer>();
         for(String s : ans)
         {
          int decimal=Integer.parseInt(s,2);  
          sol.add(decimal);
         }
   
      return sol;
    }
}
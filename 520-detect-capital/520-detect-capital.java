class Solution {
    public boolean detectCapitalUse(String word) {
        int n = word.length();
        boolean first = false;
        int count = 0;
        for(int i=0;i<n;i++){
            char ch = word.charAt(i);
            if(ch>='A'&&ch<='Z')
            {
                if(i==0)
                    first = true;
                count++;
            }
        }
        if(count==n||(first==true&&count==1)||count==0)
            return true;
        else 
            return false;
        
    }
}
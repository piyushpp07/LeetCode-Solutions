class Solution {
public:
    int myAtoi(string s) {
      int n=s.length();
      int i = 0;
      int sign = 1;
      while(s[i]==' '&&i<n)
          i++;
      if(s[i]=='-'){
            sign = 0;
            i++;
        }
     else if(s[i]=='+')
            i++;
      long int res = 0;
      while(s[i]>='0'&&s[i]<='9')
      {
          res = res * 10;
          if(res>=INT_MAX||res<=INT_MIN)
         break;
          res = res + (s[i]-'0');
          i++;
      }
        if(sign == 0){
            res = -1 * res;
        }
                if(res <= INT_MIN)
            return INT_MIN;
        
        if(res >= INT_MAX)
            return INT_MAX;
        return (int)res;
        
     
    }
};
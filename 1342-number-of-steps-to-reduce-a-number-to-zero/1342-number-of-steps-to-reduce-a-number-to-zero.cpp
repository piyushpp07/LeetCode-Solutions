class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0)
                return 0;
         else 
         {      int n =  num;
                n =  n%2 == 0 ? n/2 : n-1;
                return 1+numberOfSteps(n);
                
         }
    }
};
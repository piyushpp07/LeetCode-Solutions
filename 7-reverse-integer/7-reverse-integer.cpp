class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x<0){
            sign = 0;
        }
        else sign = 1;
        int y = 0;
        while(x)
        {   if(y < INT_MIN/10 )
                return 0;
            else if (y  > INT_MAX/10)
                return 0;
            y = x%10 + y*10;
            x = x/10;
        }
        return y;
        
    }
};
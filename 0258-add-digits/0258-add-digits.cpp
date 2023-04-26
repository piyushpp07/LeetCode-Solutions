class Solution {
public:
    int addDigits(int num) {
        if(num < 10)
            return num;
        int newnum = 0;
        while(num)
        {
            newnum =newnum   + num%10;
            num = num / 10;
        }
        return addDigits(newnum);
    }
};
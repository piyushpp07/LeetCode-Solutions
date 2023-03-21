class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 1;
        for(int i =0;i<digits.size();i++)
        {
            
            if(carry && carry + digits[i]>=10)
            {
                carry = 1;
                digits[i]  = 0;
            }
            else if(carry == 1) {
                carry = 0;
                digits[i]+=1;
            }
            else {
                carry = 0;
            }
        }
        if(carry)
            digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
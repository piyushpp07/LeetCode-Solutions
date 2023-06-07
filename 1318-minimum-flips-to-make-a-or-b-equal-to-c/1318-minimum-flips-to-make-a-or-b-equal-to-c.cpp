class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for(int i = 0;i<32;i++)
        {
            bool aa = a & (1 << i);
            bool bb = b & (1 << i);
            bool cc = c & (1 << i);
            if(cc==false)
            {
                if(aa==true&bb==true)
                    res+=2;
                else if(aa==true||bb==true)
                    res++;
            }
            else
            {
                if(aa==false&&bb==false)
                    res+=1;
            }
        }
        return res ;
    }
};
//a ^ a | b =a ^ c 
// 100
// 010 
// 111
// 1000
// 0011

// 0101
// 111
// 111

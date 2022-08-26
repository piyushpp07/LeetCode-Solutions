class Solution {
public:
    int countDigits(int number){
    int result = 0;
    while (number){
        result += pow(10, number % 10);
        number /= 10;
    }
    return result;
}
    bool reorderedPowerOf2(int n) {
        int count = countDigits(n),i;
        for(i = 0;i<32;i++)
        {
            if((countDigits((long)1<<i))==count)
                return true;
        }
        return false;
    }
};
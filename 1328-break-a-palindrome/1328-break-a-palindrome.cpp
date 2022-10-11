class Solution {
public:
    bool isPal(string palindrome){
        int i=0, j=palindrome.size();
        while(i<j){
            if(palindrome[i++]!=palindrome[j--]) return false;
        }
        return true;
    }
    
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        int flag = 1;
        if(n==1) return "";
        for(int i=0; i<n/2; i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                flag=0;
                break;
            }
        }
        if(flag) palindrome[n-1]='b';
        return palindrome;
    }
};
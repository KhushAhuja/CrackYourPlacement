class Solution {
public:
    bool PalindromeChecker(string str, int left,int right){

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        int mis=0;
        int i=-1,j=-1;
        while(l<=r){
            if(s[l]!=s[r] and mis>0) return false;
            else if(s[l]!=s[r] and mis==0){
                if(s[l]!=s[r-1] and s[r]!=s[l+1]) return false;
                if(s[l]==s[r-1] and s[r]==s[l+1]){
                    i=l, j=r;
                    break;
                }
                else if(s[l]==s[r-1]) r--;
                else l++;
                mis++;
            }
            else l++,r--;
        }
        if(i!=-1 and j!=-1){
            return (PalindromeChecker(s,i,j-1) or PalindromeChecker(s,i+1,j));
        }
        return true;
    }
};
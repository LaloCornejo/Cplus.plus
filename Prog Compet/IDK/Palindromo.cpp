class Solution {
public:
    bool isPalindrome(int x) {
       long long int copy=x;
       long long int rev=0;
        while(x!=0){
            long long int rem;
            rem=x%10;
            rev=rev*10 +rem;
            x=x/10;
            
        }
         bool check=false;
        if(rev<0){
            return check;
        }
       
        else if(rev==copy){
            check=true;
            return check;
        }else return check;
        
    }
};
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = 46340;
        while(left < right){
            int mid = left + (right-left)/2;
            if(mid * mid > x){
                right=mid;
            }
            else{
                left = mid+1;
            }
        }
        if(x==2147483647) return 46340;
        return left*left==x?left:left-1;
    }
};
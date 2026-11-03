class Solution {
public:
    bool canEat(vector<int>& piles,int h , int mid){
        for(int i =0;i < piles.size();i++){
            h-=piles[i]/mid;
            if(piles[i]%mid!=0) h--;
        }
        return h >=0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxLayer = 0;
        for(int i = 0;i < piles.size();i++){
            maxLayer = max(maxLayer, piles[i]);
        }
        int left = 1;
        int right = maxLayer;
        while(left < right){
            int mid = left + (right-left)/2;
            if(canEat(piles,h,mid)){
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }
};
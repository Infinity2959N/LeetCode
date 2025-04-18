class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        for(int bill: bills){
            if(bill==5){
                five++;
            }
            else if(bill==10){
                ten++;
                five--;
                if(five< 0)    return false;
            }
            else{ //bill==20
                if(five>0 && ten>0){
                    five--;
                    ten--;
                }else{  // If we don't have atleast a 10, we gotta pauy with 3 5s. 2 tens won't work.
                    five-=3;
                }
                if(five< 0)    return false;
            }
        }
        return true;
    }
};
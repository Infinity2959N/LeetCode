/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int beg=1, end=n;
        while(beg <= end){
            int num =beg+ (end-beg)/2;
            int res= guess(num);
            if(res== -1){
                end=num-1;
            }else if(res== 1){
                beg=num+1;
            }else{
                return num;
            }
        }
        return -1;
    }
};
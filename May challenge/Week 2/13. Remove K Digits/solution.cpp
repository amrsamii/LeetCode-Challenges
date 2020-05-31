class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k--){
            for(int i = 0,sz = num.length(); i < sz ; i++){
		// if reached final digit without removing any digit, remove the last ont
		// ex: 12345 , k = 1 => 1234
                if(i == sz-1){
                    num.erase(i,1);
                
		// if the current digit is larger than the next digit, we have increased then decreased, so remove the peak
		// ex: 1234321 , k = 1 => 123321    
                }else if(num[i] > num[i+1]){
                    num.erase(i,1);
                    break;
                }
            }
        }
        num.erase(0,min(num.find_first_not_of('0'),num.length()-1));
        if(num.length() == 0)
            return "0";
        return num;
    }
};

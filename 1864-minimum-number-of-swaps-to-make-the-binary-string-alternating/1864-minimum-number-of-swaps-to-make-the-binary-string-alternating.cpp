class Solution {
public:
    int minSwaps(string s) {
        int cnt0=0, cnt1=0, miss0=0, miss1=0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '0'){
                cnt0++;
            }else{
                cnt1++;
            }
        }

        if(abs(cnt1-cnt0) > 1){
            return -1;
        }

        for(int i=0; i<s.length(); i+=2){
           if(s[i] != '0'){
             miss0++;
           }else{
            miss1++;
           }
        }

        return cnt0 == cnt1 ? min(miss0 , miss1) : cnt0 > cnt1 ? miss0 : miss1;
    }
};
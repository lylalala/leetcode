class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> num(10,0);
        vector<int> res(2,0);
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                res[0]++;
            else
                num[secret[i]-'0']++;
        }
        for(int i=0;i<secret.size();i++){
            if(secret[i]!=guess[i]&&num[guess[i]-'0']>0){
                num[guess[i]-'0']--;
                res[1]++;
            }
        }
        return to_string(res[0])+"A"+to_string(res[1])+"B";
    }
};

class Solution {
public:
    bool isPunishNum = false;
    void isValid(string &dig,int &n,int i,int sum){
        if(sum==n and i>=dig.size()){
            isPunishNum = true;
            return;
        }
        
        for(int k=i;k<dig.length();++k){
            string subs = dig.substr(i, k-i+1);
            int num = stoi(subs);
            isValid(dig,n,k+1,sum+num);
        }
    }
    bool check(int sq,int n){
        string digit = "";
        while(sq){
            int dig = sq%10;
            digit.push_back(dig+'0');
            sq/=10;
        }
        reverse(digit.begin(),digit.end());

        isPunishNum = false;
        isValid(digit,n,0,0);
        if(isPunishNum) return true;
        return false;
    }

    int punishmentNumber(int n) 
    {
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            if(check(i*i,i))
                sum+=i*i;
        }
        
        return sum;
    }
};

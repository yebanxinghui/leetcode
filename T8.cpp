class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        int sum=0;
        int flag=1;
        while(str[i]==' ') i++;
        if(str[i]=='-'){
            flag=-1;
            i++;
        }
        else if(str[i]=='+'){
            flag=1;
            i++;
        }
        else if(str[i]<'0' || str[i]>'9') return 0;
        while(str[i]>='0' && str[i]<='9')
        {
            int temp = str[i]-'0';
            if(flag == 1 && (sum>INT_MAX/10 || (sum == INT_MAX/10 && temp>7))) return INT_MAX;
            else if(sum<INT_MIN/10 || (sum == INT_MIN/10 && temp>8)) return INT_MIN;
            sum = sum*10 + temp*flag;
            i++;
        }
        return sum;
    }
};
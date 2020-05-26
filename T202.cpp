class Solution {
public:
    int bitSum(int n)
    {
        int sum = 0;
        while(n>0)
        {
            int tmp = n % 10;
            sum += tmp*tmp;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow(n),fast(n);
        do{
            slow = bitSum(slow);
            fast = bitSum(fast);
            fast = bitSum(fast);
        }while(slow!=fast);

        return slow == 1;
    }
};
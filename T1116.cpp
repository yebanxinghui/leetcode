class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cond;
    bool zero_flag = true;
    bool odd_flag = true;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;++i)
        {
            unique_lock<mutex> lk(m);
            cond.wait(lk,[this]{return zero_flag;});
            printNumber(0);
            zero_flag = false;
            cond.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2;i<=n;i+=2)
        {
            unique_lock<mutex> lk(m);
            cond.wait(lk,[this]{return !zero_flag && !odd_flag;});
            printNumber(i);
            zero_flag = true;
            odd_flag = true;
            cond.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1;i<=n;i+=2)
        {
            unique_lock<mutex> lk(m);
            cond.wait(lk,[this]{return !zero_flag && odd_flag;});
            printNumber(i);
            zero_flag = true;
            odd_flag = false;
            cond.notify_all();
        }
    }
};
class Foo {
private:
    int counter = 1;
    condition_variable cv1;
    condition_variable cv2;
    // 使用lock和unlock手动加锁
    mutex g_mutex;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<std::mutex> lk(g_mutex);
        printFirst();
        counter++;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<std::mutex> lk(g_mutex);
        cv1.wait(lk, [this]{return counter == 2;});
        printSecond();
        counter++;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(g_mutex);
        cv2.wait(lk, [this]{return counter == 3;});
        printThird();
    }
};
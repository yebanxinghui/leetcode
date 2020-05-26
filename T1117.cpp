class H2O {
public:
    int countOxygen;
    pthread_mutex_t lockHy;
    pthread_mutex_t lockOx;

    H2O() {
        pthread_mutex_init(&lockHy,NULL);
        pthread_mutex_init(&lockOx,NULL);
        pthread_mutex_lock(&lockOx);
        this->countOxygen = 2;    
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        pthread_mutex_lock(&lockHy);
        releaseHydrogen();
        this->countOxygen--;
        if(this->countOxygen>0)
            pthread_mutex_unlock(&lockHy);
        else pthread_mutex_unlock(&lockOx);
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        pthread_mutex_lock(&lockOx);
        releaseOxygen();
        this->countOxygen = 2;
        pthread_mutex_unlock(&lockHy);
    }
};
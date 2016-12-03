class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers):n(maxNumbers) {
        numbers = new int[n];
        available = new bool[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = i;
            available[i] = true;
        }
    }
    
    ~PhoneDirectory() {
        delete[] numbers;
        delete[] available;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (!n) return -1;
        int number = numbers[--n];
        available[number] = false;
        return number;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return available[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (!available[number]) {
            available[number] = true;
            numbers[n++] = number;
        }
    }

private:
    int* numbers, n;
    bool* available;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

#ifndef LONG_INT
#define LONG_INT
#include <iostream>

// Example class
class LongInt {
    private: 
        long data;
    public:
        LongInt() {
            data = 0;
        }
        LongInt(int dt) {
            data = static_cast<long> (dt); 
        }
        LongInt(float dt) {
            data = static_cast<long> (dt); 
        }
        LongInt(double dt) {
            data = static_cast<long> (dt); 
        }
        bool operator < (const LongInt& other) {
            return data < other.data;
        }
        bool operator > (const LongInt& other) {
            return data > other.data;
        }
        bool operator == (const LongInt& other) {
            return other.data == data;
        }

        friend std::ostream& operator<<(std::ostream& out, LongInt longInt) {
            out << longInt.data;
            return out;
        }
};

#endif //LONG_INT
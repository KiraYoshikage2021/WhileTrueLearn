#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

class BigInt {
private:
    bool isZero;
    size_t len;
    size_t size;
    char * s;

    void ensureCapacity(size_t minCapacity) {
        if (size >= minCapacity) {
            return;
        }

        size_t newSize = (size == 0) ? 16 : size;
        
        while (newSize < minCapacity) {
            newSize *= 2;
        }

        char * newS = new char[newSize];
        std::memset(newS, 0, newSize);

        if (s != nullptr) {
            std::memcpy(newS, s, len);
            delete [] s;
        }

        s = newS;
        size = newSize;
    }

    void updateState() {
        while (len > 1 && s[len-1] == 0) {
            len--;
        }

        if (len == 1 && s[0] == 0) {
            isZero = true;
            
        } else {
            isZero = false;
        }
    }

public:

    BigInt(size_t val) {
        size = 16;
        s = new char[size];
        std::memset(s, 0, size);
        len = 0;

        if (val == 0) {
            s[0] = 0;
            len = 1;
            isZero = true;
            
        } else {
            isZero = false;
            while (val > 0) {
                ensureCapacity(len + 1);
                s[len++] = val % 10;
                val /= 10;
            }
        }
    }

    BigInt(const char * str) {
        size_t inputLen = std::strlen(str);
        if (inputLen == 0) {
            size = 16;
            s = new char[size];
            std::memset(s, 0, size);
            s[0] = 0;
            len = 1;
            isZero = true;
            return;
        }

        size = inputLen < 16 ? 16 : inputLen;
        s = new char[size];
        std::memset(s, 0, size);
        len = 0;

        for (int i = inputLen - 1; i >= 0; --i) {
            if (isdigit(str[i])) {
                s[len++] = str[i] - '0';
            }
        }

        if (len == 0) {
            len = 1;
            s[0] = 0;
        }

        updateState();
    }

    BigInt(const BigInt& other) {
        size = other.size;
        len = other.len;
        isZero = other.isZero;
        s = new char[size];
        std::memcpy(s, other.s, size);
    }

    ~BigInt() {
        delete[] s;
    }

    BigInt& operator=(const BigInt& other) {
        if (this == &other) return *this;

        delete[] s;

        size = other.size;
        len = other.len;
        isZero = other.isZero;
        s = new char[size];
        std::memcpy(s, other.s, size);

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInt& bi) {
        if (bi.isZero) {
            os << '0';
            return os;
        }
        for (int i = bi.len - 1; i >= 0; --i) {
            os << (int)bi.s[i];
        }
        return os;
    }

    bool operator==(const BigInt& other) const {
        if (isZero && other.isZero) return true;
        if (len != other.len) return false;
        for (size_t i = 0; i < len; ++i) {
            if (s[i] != other.s[i]) return false;
        }
        return true;
    }

    bool operator != (const BigInt& other) const {
        return !(*this == other);
      
    }

    bool operator<(const BigInt& other) const {
        if (isZero && !other.isZero) return true;
        if (!isZero && other.isZero) return false;
        if (len != other.len) return len < other.len;

        for (int i = len - 1; i >= 0; --i) {
            if (s[i] != other.s[i]) return s[i] < other.s[i];
        }
        return false;
    }

    bool operator>(const BigInt& other) const {
        return other < *this;
    }

    bool operator<=(const BigInt& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInt& other) const {
        return !(*this < other);
    }


    BigInt& operator+=(const BigInt& other) {
        size_t maxLen = std::max(len, other.len);
        ensureCapacity(maxLen + 2);

        int carry = 0;
        for (size_t i = 0; i < maxLen || carry; ++i) {
            int sum = carry;
            if (i < len) sum += s[i];
            if (i < other.len) sum += other.s[i];

            if (i >= len) len++;

            s[i] = sum % 10;
            carry = sum / 10;
        }
        updateState();
        return *this;
    }

    BigInt operator+(const BigInt& other) const {
        BigInt temp(*this);
        temp += other;
        return temp;
    }

    BigInt& operator*=(const BigInt& other) {
        if (this->isZero || other.isZero){
            *this = BigInt(static_cast<size_t>(0));
            return *this;
        }

        size_t resultLen = len + other.len;
        char* resultS = new char[resultLen];
        std::memset(resultS, 0, resultLen);

        for (size_t i = 0; i < len; ++i) {
            for (size_t j = 0; j < other.len; ++j) {
                int product = s[i] * other.s[j];
                size_t pos = i + j;

                int sum = product + resultS[pos];
                resultS[pos] = sum % 10;
                int carry = sum / 10;

                size_t k = pos + 1;
                while (carry > 0) {
                    int nextSum = resultS[k] + carry;
                    resultS[k] = nextSum % 10;
                    carry = nextSum / 10;
                    k++;
                }
            }
        }

        delete [] s;
        s = resultS;
        size = resultLen;
        len = resultLen;

        updateState();
        return *this;
    }

    BigInt operator*(const BigInt& other) const {
        BigInt temp(*this);
        temp *= other;
        return temp;
    }
};


int main() {
    std::cout << "--- BigInt Project Tests ---" << std::endl;

    // 1. Constructor tests
    BigInt a(12345);
    BigInt b("9876543210987654321"); // Large number check
    BigInt c(a); // Copy constructor
    BigInt zero(static_cast<size_t>(0));

    std::cout << "a (size_t): " << a << std::endl;
    std::cout << "b (char*): " << b << std::endl;
    std::cout << "c (copy of a): " << c << std::endl;
    std::cout << "zero: " << zero << std::endl;

    // 2. Comparison tests
    std::cout << "\n--- Comparisons ---" << std::endl;
    std::cout << "a == c: " << (a == c ? "True" : "False") << " (Expected: True)" << std::endl;
    std::cout << "a != b: " << (a != b ? "True" : "False") << " (Expected: True)" << std::endl;
    std::cout << "a < b:  " << (a < b ? "True" : "False") <<  " (Expected: True)" << std::endl;
    std::cout << "b > a:  " << (b > a ? "True" : "False") <<  " (Expected: True)" << std::endl;
    std::cout << "a <= c: " << (a <= c ? "True" : "False") << " (Expected: True)" << std::endl;

    // 3. Math tests
    std::cout << "\n--- Addition ---" << std::endl;
    BigInt sum = a + b;
    std::cout << "a + b = " << sum << std::endl;
    
    c += BigInt(5);
    std::cout << "c (which was 12345) += 5: " << c << " (Expected: 12350)" << std::endl;

    std::cout << "\n--- Multiplication ---" << std::endl;
    BigInt small(10);
    BigInt large("1000000000000000");
    BigInt prod = small * large;
    std::cout << "10 * 10^15 = " << prod << " (Expected: 10000000000000000)" << std::endl;

    BigInt mulTest(5);
    mulTest *= BigInt(5);
    std::cout << "5 *= 5: " << mulTest << " (Expected: 25)" << std::endl;
    
    mulTest *= BigInt(static_cast<size_t>(0));
    std::cout << "25 *= 0: " << mulTest << " (Expected: 0)" << std::endl;

    // 4. Edge cases
    std::cout << "\n--- Edge Cases ---" << std::endl;
    BigInt bigSum("99");
    bigSum += BigInt(1);
    std::cout << "99 + 1 = " << bigSum << " (Expected: 100)" << std::endl;

    std::cout << "\nAll tests completed." << std::endl;

    return 0;
}

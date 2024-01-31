#include <iostream>

namespace std {
    template<typename T>
    class unique_ptr1 {
        T* ptr = new T;
    public:
        unique_ptr1(const unique_ptr1<T>& ptr1) = delete;
        unique_ptr1(T* ptr_) : ptr(ptr_) {}
        unique_ptr1<T> operator= (const unique_ptr1<T>& ptr1) = delete;
        T operator* () {
            return *ptr;
        }
       
        T* operator-> () {
            return ptr;
        }
        ~unique_ptr1() {
            delete ptr;
            std::cout << "destructor" << std::endl;
        }
        T* get() const {
            return ptr;
        }
       
        T* release() {
            T* ptr1 = ptr;
            ptr = nullptr;
            return ptr1;

        }

    };
}

class Int {
public:
    int k = 0;
};

class Int2 {
public:
    int k = 1;
};

int main() {
    std::unique_ptr1<int> pi(new int(10));
    std::unique_ptr1<Int> I(new Int);
    std::unique_ptr1<Int2> I2(new Int2);
    int* in = nullptr;
    std::cout << I->k << std::endl;
    std::cout << I2->k << std::endl;
    std::cout << in << ' ' << pi.get() << ' ' << std::endl;
    in = pi.release();
    *in = 20;
    std::cout << in << ' ' << *in << ' ' << std::endl;
     std::cout << pi.get() << ' ' << std::endl;
    *in = 134;
    std::cout << *in << std::endl;
    delete in;
    return 0;
}
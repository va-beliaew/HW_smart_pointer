#include <iostream>

namespace std {
    template<typename T>
    class unique_ptr1 {
        T* ptr = new T;
    public:
        unique_ptr1(const unique_ptr1<T>& ptr1) = delete;
        unique_ptr1(T*&& ptr_) : ptr(ptr_) {}
        unique_ptr1<T> operator= (const unique_ptr1<T>& ptr1) = delete;
        T& operator* () {
            return *ptr;
        }
        T& operator-> () {
            return ptr;
        }
        ~unique_ptr1() {
            delete ptr;
            std::cout << "destructor" << std::endl;
        }
        T* get() const {
            return ptr;
        }
        T get_value() const {
            if (!ptr) {
                return 0;
            }
            else {
                return *ptr;
            }
        }
        void release(T*& ptrr) {
            ptrr = ptr;
            ptr = nullptr;

        }

    };

}

int main() {
    std::unique_ptr1<int> pi(new int(10));
    int* in = nullptr;
    std::cout << in << ' ' << pi.get() << ' ' << pi.get_value() << std::endl;
    pi.release(in);
    *in = 20;
    std::cout << in << ' ' << *in << ' ';
     std::cout << pi.get() << ' ' << pi.get_value() << std::endl;
    *in = 134;
    std::cout << *in << std::endl;
    delete in;
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

// Your class SimpleBuffer
template <class T>
class SimpleBuffer {
private:
    T data_;

public:
    // Implement your public members
    explicit SimpleBuffer<T>(T data) : data_(data) {};
    ~SimpleBuffer() = default;

    friend istream& operator>>(istream& istream, SimpleBuffer<T>& buf){
        T input_data;

        istream >> input_data;
        buf.data_ += input_data;

        return istream;
    }

    friend ostream& operator<<(ostream& ostream, const SimpleBuffer<T>& buf) {
        ostream << "Current data: " << buf.data_;

        return ostream;
    }

};

template <class T>
ostream& operator<<(ostream& ostream, const SimpleBuffer<T>& buf) {
    ostream << "Current data: " << buf.data_; // Output the 'data_' member
    return ostream;
}


// main() of your program for test
int main() {
    SimpleBuffer<string> buf_str("");

    for(int k = 0; k < 3; k++){
        cin >> buf_str;
        cout << buf_str << endl;
    }

    SimpleBuffer<int> buf_int(0);

    for(int k = 0; k < 5; k++){
        cin >> buf_int;
        cout << buf_int << endl;
    }

    return 0;
}
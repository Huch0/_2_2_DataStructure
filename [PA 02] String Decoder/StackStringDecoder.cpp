#include <iostream>
#include <string>

using namespace std;

class StringDecoder {
private:
    string data_;

    // Implement your class here
public:
    StringDecoder() {};
    ~StringDecoder() {};

    string getData() const {
        return data_;
    }

    void setData(const string& newString) {
        data_ = newString;
    }

    string decodeData() const;

    static bool isValidCharacter(char c) {
        // Valid characters for 'text'
        return isalnum(c) || c == '.' || c == ',' || c == '!' || c == '?' ||
               c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*';
    }

    static int hexToInt(const char c) {
        if (c >= '0' && c <= '9') {
            return c - '0'; // Convert '0'-'9' to 0-9
        } else if (c >= 'A' && c <= 'F') {
            return 10 + (c - 'A'); // Convert 'A'-'F' to 10-15
        } else {
            return -1;
        }
    }
};

// Implement your class here
#include <stack>
#define INVALID_INPUT "ERROR: Invalid input"
string StringDecoder::decodeData() const {
   stack<string> subTextStack;
   stack<int> repeatTimeStack;

   size_t index = 0;
   string subText;

   while (data_[index] != '\0') {
       char currentChar = data_[index];

       if (currentChar == '{') {
           const int repeatTime = hexToInt(data_[index - 1]);

           if (index == 0 || repeatTime == -1)
               return INVALID_INPUT;

           repeatTimeStack.push(repeatTime);
           // Remove n from subText
           subText.pop_back();
           // Store current subText to stack
           subTextStack.push(subText);
           subText.clear();
       } else if (currentChar == '}') {
           // Brace is not opened
           if (repeatTimeStack.empty())
               return INVALID_INPUT;

           string repeatedText = subTextStack.top();
           const int repeatTime = repeatTimeStack.top();
           subTextStack.pop();
           repeatTimeStack.pop();

           for (int i = 0; i < repeatTime; i++) {
               repeatedText += subText;
           }

           subText = repeatedText;
       } else {
           if (!isValidCharacter(currentChar))
               return INVALID_INPUT;

           subText += currentChar;
       }
       index++;
   }
   return subText;
}



istream& operator >> (istream& istream, StringDecoder& sd) {
    string inputString;
    istream >> inputString;

    sd.setData(inputString);

    sd.setData(sd.decodeData());

    return istream;
}

ostream& operator << (ostream& ostream, StringDecoder& sd) {
    ostream << sd.getData();

    return ostream;
}

int main() {
    StringDecoder sd;

    // Note:
    // encoded input strings are read from an input file using operator>>
    // your class may store a decoded string in data_ to print it using operator<<
    while (cin >> sd) {
        cout << sd << endl;
    }

    return 0;
}

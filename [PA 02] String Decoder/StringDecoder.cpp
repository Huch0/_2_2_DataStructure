#include <iostream>
#include <string>

using namespace std;

class StringDecoder {
private:
    string data_;

    // Implement your class here
public:
    #define INVALID_INPUT "ERROR: Invalid input"

    StringDecoder() {};
    ~StringDecoder() {};

    string getData() const {
        return data_;
    }

    void setData(const string& newString) {
        data_ = newString;
    }

    pair<string, int> decodeData(int i, int isOpen) const;

    static bool isValidCharacter(char c) {
        // Valid characters for 'text'
        return isalnum(c) || c == '.' || c == ',' || c == '!' || c == '?' ||
               c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&';
    }

    static bool isValidHexDigit(char c) {
        // Valid hexadecimal digits for 'hex'
        return isxdigit(c);
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

pair<string, int> StringDecoder::decodeData(int i, int isOpen) const {
    string resultText;

    while (data_[i] != '\0') {
        const char currentChar = data_[i];

        if (currentChar == '{') {
            if (i == 0)
                return make_pair(INVALID_INPUT, i);

            const int repeatTime = hexToInt(data_[i - 1]);

            if (repeatTime == -1)
                return make_pair(INVALID_INPUT, i); // Return the error and the current index

            // Remove n from resultText
            resultText.pop_back();

            // Handle zero repetitions
            if (repeatTime == 0) {
                // Skip to the next '}' and continue
                while (data_[i] != '\0' && data_[i] != '}') {
                    i++;
                }
                i++; // Move past the '}'
                continue;
            }

            i++;
            pair<string, int> subTextInfo = decodeData(i, 1);
            string subText = subTextInfo.first;

            if (subText == INVALID_INPUT)
                return make_pair(INVALID_INPUT, i);

            for (int j = 0; j < repeatTime; j++) {
                resultText += subText;
            }

            // Update index based on subTextInfo
            i = subTextInfo.second;
        } else if (currentChar == '}') {
            // Closed unopened brace
            if (!isOpen)
                return make_pair(INVALID_INPUT, i);
            i++;

            // Return the decoded string and the updated index
            return make_pair(resultText, i);
        } else {
            // Invalid char
            if (!isValidCharacter(currentChar))
                return make_pair(INVALID_INPUT, i);
            resultText += currentChar;
            i++;
        }
    }
    // Unclosed open brace
    if (isOpen)
        return make_pair(INVALID_INPUT, i);

    return make_pair(resultText, i); // Return the decoded string and the updated index
}




istream& operator >> (istream& istream, StringDecoder& sd) {
    string inputString;
    istream >> inputString;

    sd.setData(inputString);

    sd.setData(sd.decodeData(0, 0).first);

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

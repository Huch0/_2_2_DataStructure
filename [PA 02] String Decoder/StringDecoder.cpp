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

    pair<string, int> decodeData(int i, int openBraces) const;

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

pair<string, int> StringDecoder::decodeData(int i, int openBraces) const {
    string resultText;

    while (data_[i] != '\0') {
        const char currentChar = data_[i];

        if (currentChar == '{') {
            const int repeatTime = hexToInt(data_[i - 1]);
            openBrace

            if (i == 0 || repeatTime == -1)
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

            pair<string, int> subTextInfo = decodeData(i + 1, openBraces);
            string subText = subTextInfo.first;
            // Update index based on subTextInfo
            i = subTextInfo.second;

            if (subText == INVALID_INPUT)
                return make_pair(INVALID_INPUT, i);

            for (int j = 0; j < repeatTime; j++) {
                resultText += subText;
            }
        } else if (currentChar == '}') {
            openBraces--;

            // Close unopened brace
            if (openBraces < 0 || resultText.empty())
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
    if (openBraces > 0)
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

{
data_.clear();

size_t idx = 0; //현재위치
stack<int> s;
stack <string> stackString;
string temp; // 현재 해독중인 문자열을 저장하는 임시변수

if (str.empty()) {  //문자열이 비어있는경우
    data_ = "ERROR: Invalid input";
    return false;
}

while (idx<str.length()) {
    if (str[idx] == '{') { //문자열 돌다가 { 를 만날때
        if (idx == 0 || !hexDigit(str[idx - 1])) {
            //이전문자가 16진수가 아닌경우
            data_ = "ERROR: Invalid input";
            return false;
        }
        //이전문자가 16진수라면
        s.push(hexToInt(str[idx - 1])); //
        //문자가 나왔을때 그 문자를 16진수로 변환하여 스택 s에 저장
        temp.pop_back(); // 중복을 피하기위해 pop
        stackString.push(temp); // 현재까지의 문자열 조각을 stackstring stack에 저장
        temp.clear(); // 새로운 문자열 조각을 만들 준비
    } else if (str[idx] == '}') { //}를 만나는 경우
        if (s.empty()) {
            data_ = "ERROR: Invalid input";
            return false;
        }

        string result = stackString.top();
        stackString.pop();

        for (int i = 0; i<s.top();++i) {
            result += temp;
        }
        s.pop();

        temp = result;
    } else {
        if (!isValid(str[idx])) {
            data_ = "ERROR: Invalid input";
            return false;
        }
        temp += str[idx];
    }
    idx++;
}
data_ = temp;
return true;
}


#include <iostream>
#include <string>
#include <list>
#include <vector>

int main() {
    int a;
    double MIN_LOAD_FACTOR, MAX_LOAD_FACTOR;
    int NUMBER_OF_THE_FOLLOWING_LINES;

    std::cin >> a >> MIN_LOAD_FACTOR >> MAX_LOAD_FACTOR >> NUMBER_OF_THE_FOLLOWING_LINES;
    std::cout << a << " " << MIN_LOAD_FACTOR << " " << MAX_LOAD_FACTOR << " " << NUMBER_OF_THE_FOLLOWING_LINES << std::endl;

    for (int i = 0; i < NUMBER_OF_THE_FOLLOWING_LINES; i++) {
        char COMMAND_N;
        std::string KEY_N;
        std::string VALUE_N;

        std::cin >> COMMAND_N >> KEY_N >> VALUE_N;

        std::cout << i << std::endl;

    }
    std::cout << a << " " << MIN_LOAD_FACTOR << " " << MAX_LOAD_FACTOR << " " << NUMBER_OF_THE_FOLLOWING_LINES << std::endl;

    return 0;
}
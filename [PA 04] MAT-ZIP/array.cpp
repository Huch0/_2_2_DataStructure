// Add any additional header files freely
#include <iostream>
#include <string>

using namespace std;

// Returns menu serving time of each menu
int getMenuTime(char menu){
    switch(menu){
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'D': return 4;
        case 'E': return 5;
        case 'F': return 7;
        case 'G': return 10;
        case 'H': return 12;
        case 'I': return 14;
        case 'J': return 15;
    }
}

// Your program here
int main () {
    int customers;
    cin >> customers;

    int tableSchedule[200] = {0};

    int startTime;
    char menu;
    int menuTime;

    for (int i = 0; i < customers; i++) {
        cin >> startTime >> menu;

        menuTime = getMenuTime(menu);

        for (int j = startTime; j < startTime + menuTime; j++) {
            tableSchedule[j] += 1;
        }
    }

    int maxTables = 0;
    for (int i = 0; i < 200; i++) {
        if (tableSchedule[i] > maxTables) {
            maxTables = tableSchedule[i];
        }
    }

    cout << maxTables;

    return 0;
}
#include <iostream>
#include "Decision.hpp"

using namespace std;

int main() {
    const int MAX_ENTRIES = 20;
    int weatherLog[MAX_ENTRIES];
    int decisionLog[MAX_ENTRIES];
    int count = 0;
    int inputWeather;

    cout << "--- Weather Decision System ---" << endl;
    cout << "1: sunny and humid" << endl;
    cout << "2: sunny and not humid" << endl;
    cout << "3: raining and windy" << endl;
    cout << "4: raining and not windy" << endl;
    cout << "5: overcast" << endl;
    cout << "Enter -1 to stop." << endl;

    while (count < MAX_ENTRIES) {
        cout << "Enter weather (-1 to quit): ";
        cin >> inputWeather;

        if (inputWeather == -1) {
            break;
        }

        if (inputWeather < 1 || inputWeather > 5) {
            cout << "Invalid input. Please enter 1-5." << endl;
            continue;
        }

        int decision = MakeDecision(inputWeather);

        weatherLog[count] = inputWeather;
        decisionLog[count] = decision;
        count++;
    }

    PrintResults(weatherLog, decisionLog, count);

    PrintPlayPercentage(decisionLog, count);

    return 0;
}

#include "Decision.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string getWeatherDescription(int w) {
    switch(w) {
        case 1: return "sunny and humid";
        case 2: return "sunny and not humid";
        case 3: return "raining and windy";
        case 4: return "raining and not windy";
        case 5: return "overcast";
        default: return "unknown";
    }
}

string getDecisionDescription(int d) {
    return (d == 1) ? "play" : "not play";
}

int MakeDecision(int weather) {
    // Âß¼­£º
    // 1 (Sunny+Humid) -> Don't Play (0)
    // 2 (Sunny+!Humid) -> Play (1)
    // 3 (Rain+Windy) -> Don't Play (0)
    // 4 (Rain+!Windy) -> Play (1)
    // 5 (Overcast) -> Play (1)
    
    if (weather == 2 || weather == 4 || weather == 5) {
        return 1;
    } else {
        return 0;
    }
}

void PrintResults(int* weatherArr, int* decisionArr, int count) {
    cout << endl << "--- Results ---" << endl;
    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ". Weather: " << getWeatherDescription(weatherArr[i]) << endl;
        cout << "   Decision: " << getDecisionDescription(decisionArr[i]) << endl;
    }
}

void PrintPlayPercentage(int* decisionArr, int count) {
    if (count == 0) {
        cout << "No data to calculate percentage." << endl;
        return;
    }

    int playCount = 0;
    for (int i = 0; i < count; i++) {
        if (decisionArr[i] == 1) {
            playCount++;
        }
    }

    double percentage = (double)playCount / count * 100.0;
    cout << "Play Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;
}

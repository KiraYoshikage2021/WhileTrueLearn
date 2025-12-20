#include "Computing.hpp"
#include <cstdlib> // rand
#include <cmath>   // sqrt, pow

double getRandomDouble() {
    return (double)rand() / (double)RAND_MAX;
}

int MakeDecision(int weather, double p) {
    // p 对应决策树图中的变量 x
    double threshold = 0.0;
    
    // 根据 Project 2 定义的天气代码映射决策树逻辑：
    // 1: Sunny + Humid (>70)     -> Tree: Play prob = x
    // 2: Sunny + Not Humid (<=70)-> Tree: Play prob = 1 - x/2
    // 3: Rain + Windy (True)     -> Tree: Play prob = x
    // 4: Rain + Not Windy (False)-> Tree: Play prob = 1 - x/2
    // 5: Overcast                -> Tree: Play prob = 1
    
    switch (weather) {
        case 1: // Sunny + Humid
            threshold = p;
            break;
        case 2: // Sunny + Not Humid
            threshold = 1.0 - (p / 2.0);
            break;
        case 3: // Rain + Windy
            threshold = p;
            break;
        case 4: // Rain + Not Windy
            threshold = 1.0 - (p / 2.0);
            break;
        case 5: // Overcast
            return 1; // Always Play
        default:
            return 0; // 异常输入默认不玩
    }


    if (getRandomDouble() < threshold) {
        return 1; // Play
    } else {
        return 0; // Not Play
    }
}

double CompPlayPercentage(int* D, int count) {
    if (count == 0) return 0.0;
    
    int playCount = 0;
    for (int i = 0; i < count; i++) {
        if (D[i] == 1) {
            playCount++;
        }
    }
    return (double)playCount / count;
}

void CompStatistics(double* percentages, int count, double& ave, double& std) {
    if (count == 0) {
        ave = 0.0;
        std = 0.0;
        return;
    }


    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += percentages[i];
    }
    ave = sum / count;



    double varianceSum = 0.0;
    for (int i = 0; i < count; i++) {
        varianceSum += std::pow(percentages[i] - ave, 2);
    }
    std = std::sqrt(varianceSum / count);
}

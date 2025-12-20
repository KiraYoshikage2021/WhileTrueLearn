#include "Experiment.hpp"
#include "Computing.hpp"
#include <cstdlib> // rand
#include <iostream>
#include <iomanip> // setprecision

using namespace std;

double SingleTest(int p, int count) {
    // 1. 创建数组 D
    int* D = new int[count];
    
    // 将整数 p (2-9) 转换为 double (0.2-0.9)
    double probX = (double)p / 10.0;
    
    // 2. 模拟 count 天
    for (int j = 0; j < count; j++) {
        // 随机生成天气 1-5
        // rand() % 5 得到 0-4，+1 得到 1-5
        int weather = (rand() % 5) + 1;
        
        // 调用 MakeDecision 并保存
        D[j] = MakeDecision(weather, probX);
    }
    
    // 3. 计算并返回百分比
    double result = CompPlayPercentage(D, count);
    
    // 清理内存
    delete[] D;
    return result;
}

void MultipleTest(double* percentageArray, int p, int count) {
    // 运行 count 次 SingleTest
    for (int i = 0; i < count; i++) {
        percentageArray[i] = SingleTest(p, count);
    }
}

void DoExperiment(int count) {
    // 1. 创建 2D 数组 M (8 行 x count 列)
    double** M = new double*[8];
    for (int i = 0; i < 8; i++) {
        M[i] = new double[count];
    }

    // 2. 创建 P 数组 (2, 3, ... 9)
    int P[8] = {2, 3, 4, 5, 6, 7, 8, 9};

    cout << fixed << setprecision(6);
    cout << "Running Experiment with count = " << count << endl;
    cout << "------------------------------------------------------" << endl;

    // 3. 针对每个 P[i] 进行测试
    for (int i = 0; i < 8; i++) {
        // 调用 MultipleTest 填充 M[i]
        MultipleTest(M[i], P[i], count);
        
        // 计算统计数据
        double ave = 0.0;
        double std = 0.0;
        CompStatistics(M[i], count, ave, std);
        
        // 输出结果
        cout << "P = " << P[i] << " (x=" << (P[i]/10.0) << ")"
             << " | Average = " << ave 
             << " | StdDev = " << std << endl;
    }

    // 4. 清理内存
    for (int i = 0; i < 8; i++) {
        delete[] M[i];
    }
    delete[] M;
}

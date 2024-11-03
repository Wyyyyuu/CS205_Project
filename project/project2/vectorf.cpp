#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    srand(time(NULL)); // 设置随机数种子

    int n;
    cout << "请输入向量的长度：";
    cin >> n;
    // 动态分配内存
    float* vec1 = new float[n]; 
    float* vec2 = new float[n];

    for (int i = 0; i < n; i++) {
        vec1[i] = static_cast<float>(rand()) / RAND_MAX; // 生成0-1之间的随机浮点数
    }

    for (int i = 0; i < n; i++) {
        vec2[i] = static_cast<float>(rand()) / RAND_MAX; // 生成0-1之间的随机浮点数
    }

    double result = 0.0;

    // 获取当前时间
    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++){
        result += vec1[i] * vec2[i];
    }

    // 获取程序结束时间点
    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "点乘结果为: " << result << endl;

    // 计算程序运行时间
    auto elapsed_ns = duration_cast<nanoseconds>(end_time - start_time);
    cout << "程序运行时间为：" << elapsed_ns.count() << "ns" << endl;

    delete[] vec1,vec2; // 释放动态分配的内存 
    
    return 0;
}
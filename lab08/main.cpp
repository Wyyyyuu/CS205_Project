#include <iostream>
#include <cstdlib>
#include <chrono>
#include "matoperation.hpp"

using namespace std;

#define TIME_START start=std::chrono::steady_clock::now();
#define TIME_END(NAME) end=std::chrono::steady_clock::now(); \
             duration=std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();\
             cout<<(NAME)<<": result="<<result \
             <<", duration = "<<duration<<"ms"<<endl;



int main(int argc, char ** argv)
{
    size_t nSize = 200000000;
    //float * p1 = new float[nSize](); //the memory is not aligned
    //float * p2 = new float[nSize](); //the memory is not aligned

    //256bits aligned, C++17 standard
    float * p1 = static_cast<float*>(aligned_alloc(256, nSize*sizeof(float))); 
    float * p2 = static_cast<float*>(aligned_alloc(256, nSize*sizeof(float)));
    float result = 0.0f;

    //初始化p1,p2
    for (size_t i = 0; i < nSize; i++) {
        p1[i] = 0.f;
        p2[i] = 1.f;
    }

    // p1[2] = 2.3f;
    // p2[2] = 3.0f;
    // p1[nSize-1] = 2.0f;
    // p2[nSize-1] = 1.1f;

    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto duration = 0L;

    result = add(p1, p2, nSize);
    result = add(p1, p2, nSize);

    TIME_START
    result = add(p1, p2, nSize);
    TIME_END("normal")

    TIME_START
    result = add_unloop(p1, p2, nSize);
    TIME_END("unloop")

    TIME_START
    result = add_avx2(p1, p2, nSize);
    TIME_END("SIMD")

    TIME_START
    result = add_avx2_omp(p1, p2, nSize);
    TIME_END("SIMD+OpenMP")

    delete []p1;
    delete []p2;

    return 0;
}
//#pragma GCC optimize(3)
#include <benchmark/benchmark.h>
#include <iostream>
#include <vector>
#include "multiplication.h"
#include <fstream>

using namespace std;

static void mine(benchmark::State& state) {
    double* C = new double[state.range(0)*state.range(0)];
    double* random1 = new double[state.range(0)*state.range(0)];
    random_matrix(state.range(0), state.range(0), random1);
    double* random2 = new double[state.range(0)*state.range(0)];
    random_matrix(state.range(0), state.range(0), random2);
    for (auto _ : state)
        origin_GEMM(colOrder, noTrans, trans, state.range(0), state.range(0), state.range(0), 
                    1, random1, state.range(0), random2, state.range(0), 1, C, state.range(0));
    state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(state.range(0)));

    delete[] C;
    delete[] random1;
    delete[] random2;
}

int main(int argc, char** argv) {
    // Initialize the benchmark
    ::benchmark::Initialize(&argc, argv);

    // Run the benchmark for different data sizes
    ::benchmark::RegisterBenchmark("mine", mine)
        ->Arg(4)  // Add the data sizes you want to test
        ->Arg(16)
        ->Arg(32)
        ->Arg(64)
        ->Arg(128)
        ->Arg(256)
        ->Arg(512)
        ->Arg(800)
        ->Arg(1024)
        ->Arg(2048)
        // ->Arg(8192)
        
        ->Unit(benchmark::kMillisecond);

    // Plot the results
    ::benchmark::RunSpecifiedBenchmarks();
    
    return 0;
}

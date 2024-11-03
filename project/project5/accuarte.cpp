//#pragma GCC optimize(3)
#include <iostream>
#include <cmath>
#include <cstring>
#include <cblas.h>
#include "multiplication.h"
using namespace std;

int main() {
    double* C1 = new double[1024*1024];
    double* C2 = new double[1024*1024];
    double* random1 = new double[1024*1024];
    random_matrix(1024, 1024, random1);
    double* random2 = new double[1024*1024];
    random_matrix(1024, 1024, random2);

    origin_GEMM(colOrder, noTrans, trans, 1024, 1024, 1024, 1, random1, 1024, random2, 1024, 1, C1, 1024);

    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans, 1024, 1024, 1024, 1, random1, 1024, random2, 1024, 1, C2, 1024);
 
    double error = 0.0;
    for(int i = 0; i < 16; i++){
        error += fabs(C1[i] - C2[i]);
    }

    cout << error << endl;

    delete[] C1;
    delete[] C2;
    delete[] random1;
    delete[] random2;
}


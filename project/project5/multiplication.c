#pragma GCC optimize(3)
#include <stdio.h>
#include <stdlib.h>
#include "sys/time.h"
#include <math.h>
#include "multiplication.h"
#include <immintrin.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
// // 按行储存or按列储存
// enum order{rowOrder=0, colOrder=1};
// // 是否转置
// enum transpose{noTrans=0, trans=1};

// 生成随机矩阵
void random_matrix(size_t row, size_t col, double *A)
{
  // 检查空指针
  if (A == NULL)
  {
    printf("A是空指针!");
  }
  else
  {
    double minValue = 0.0;  // 随机数范围的最小值
    double maxValue = 10.0; // 随机数范围的最大值

    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned int seed = (unsigned int)tv.tv_usec;
    srand(seed);

    for (int i = 0; i < row * col; ++i)
    {
      double randomNum = minValue + ((double)rand() / RAND_MAX) * (maxValue - minValue);
      A[i] = randomNum;
    }
  }
}

// 初始矩阵乘法
void origin_GEMM(enum order order, enum transpose TransA, enum transpose TransB, size_t M, size_t N, size_t K, 
                    double alpha, double* A, size_t lda, double* B, size_t ldb, double beta, double*C, size_t ldc)
{
  // 对传入指针进行检查
  if (C == NULL)
  {
    printf("C是空指针!");
  }
  else if (A == NULL)
  {
    printf("A是空指针!");
  }
  else if (B == NULL)
  {
    printf("B是空指针!");
  }
  else
  {

    // i,j,k顺序
    // 按行储存时
    if (order == 0)
    {
    #pragma omp parallel for schedule(dynamic)
      for (int i = 0; i < M * N; i++)
      {
          C[i] = beta * C[i];
      }
    #pragma omp parallel for schedule(dynamic)
      for (int ii = 0; ii < M; ii += 4)
      {
          for (int jj = 0; jj < N; jj += 4)
          {
              for (int kk = 0; kk < K; kk += 4)
              {
                  for (int i = ii; i < min(ii + 4, M); i++)
                  {
                      for (int j = jj; j < min(jj + 4, N); j++)
                      {
                          double sum = 0.0;
                          for (int k = kk; k < min(kk + 4, K); k++)
                          {
                              double a = (TransA == noTrans) ? A[i * lda + k] : A[k * lda + i];
                              double b = (TransB == noTrans) ? B[k * ldb + j] : B[j * ldb + k];
                              sum += a * b;
                          }
                          C[i * ldc + j] += alpha * sum;
                      }
                  }
              }
          }
      }
    }
    // 按列储存时
    if (order == 1)
    {
    #pragma omp parallel for schedule(dynamic)
      for (int i = 0; i < M * N; i++)
      {
          C[i] = beta * C[i];
      }
    #pragma omp parallel for schedule(dynamic)
      for (int jj = 0; jj < N; jj += 4)
      {
          for (int kk = 0; kk < K; kk += 4)
          {
              for (int j = jj; j < min(jj + 4, N); j++)
              {
                  for (int k = kk; k < min(kk + 4, K); k++)
                  {
                      double b = (TransB == noTrans) ? B[j * ldb + k] : B[k * ldb + j];
                      for (int i = 0; i < M; i++)
                      {
                          double a = (TransA == noTrans) ? A[k * lda + i] : A[i * lda + k];
                          C[j * ldc + i] += alpha * a * b;
                      }
                  }
              }
          }
      }
    }

    // // i,j,k顺序
    // // 按行储存时
    // if (order == 0)
    // {
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     for (int i = 0; i < M; i++)
    //     {
    //         for (int j = 0; j < N; j++)
    //         {
    //             double sum = 0.0;
    //             for (int k = 0; k < K; k++)
    //             {
    //                 double a = (TransA == noTrans) ? A[i * lda + k] : A[k * lda + i];
    //                 double b = (TransB == noTrans) ? B[k * ldb + j] : B[j * ldb + k];
    //                 sum += a * b;
    //             }
    //             C[i * ldc + j] = alpha * sum + beta * C[i * ldc + j];
    //         }
    //     }

    // }

    // // 按列储存时
    // if (order == 1)
    // {
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     for (int i = 0; i < M; i++)
    //     {
    //         for (int j = 0; j < N; j++)
    //         {
    //             double sum = 0.0;
    //             for (int k = 0; k < K; k++)
    //             {
    //                 double a = (TransA == noTrans) ? A[k * lda + i] : A[i * lda + k];
    //                 double b = (TransB == noTrans) ? B[j * ldb + k] : B[k * ldb + j];
    //                 sum += a * b;
    //             }
    //             C[j * ldc + i] = alpha * sum + beta * C[j * ldc + i];
    //         }
    //     }

    // }

    // // j,i,k顺序
    // // 按行储存时
    // if (order == 0)
    // {
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     for (int j = 0; j < N; j++)
    //     {
    //         for (int i = 0; i < M; i++)
    //         {
    //             double sum = 0.0;
    //             for (int k = 0; k < K; k++)
    //             {
    //                 double a = (TransA == noTrans) ? A[i * lda + k] : A[k * lda + i];
    //                 double b = (TransB == noTrans) ? B[k * ldb + j] : B[j * ldb + k];
    //                 sum += a * b;
    //             }
    //             C[i * ldc + j] = alpha * sum + beta * C[i * ldc + j];
    //         }
    //     }

    // }

    // // 按列储存时
    // if (order == 1)
    // {
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     for (int j = 0; j < N; j++)
    //     {
    //         for (int i = 0; i < M; i++)
    //         {
    //             double sum = 0.0;
    //             for (int k = 0; k < K; k++)
    //             {
    //                 double a = (TransA == noTrans) ? A[k * lda + i] : A[i * lda + k];
    //                 double b = (TransB == noTrans) ? B[j * ldb + k] : B[k * ldb + j];
    //                 sum += a * b;
    //             }
    //             C[j * ldc + i] = alpha * sum + beta * C[j * ldc + i];
    //         }
    //     }

    // }

    // // j,k,i顺序
    // // 按行储存时
    // if (order == 0)
    // {
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     for (int j = 0; j < N; j++)
    //     {
    //         for (int k = 0; k < K; k++)
    //         {
    //             double b = (TransB == noTrans) ? B[k * ldb + j] : B[j * ldb + k];
    //             for (int i = 0; i < M; i++)
    //             {
    //                 double a = (TransA == noTrans) ? A[i * lda + k] : A[k * lda + i];
    //                 C[i * ldc + j] += alpha * a * b;
    //             }
    //         }
    //     }

    // }

    // // 按列储存时
    // if (order == 1)
    // {
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     for (int j = 0; j < N; j++)
    //     {
    //         for (int k = 0; k < K; k++)
    //         {
    //             double b = (TransB == noTrans) ? B[j * ldb + k] : B[k * ldb + j];
    //             for (int i = 0; i < M; i++)
    //             {
    //                 double a = (TransA == noTrans) ? A[k * lda + i] : A[i * lda + k];
    //                 C[j * ldc + i] += alpha * a * b;
    //             }
    //         }
    //     }
        
    // }

    // // k,j,i顺序
    // // 按行储存时
    // if (order == 0)
    // {
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     for (int k = 0; k < K; k++)
    //     {
    //         for (int j = 0; j < N; j++)
    //         {
    //             double b = (TransB == noTrans) ? B[k * ldb + j] : B[j * ldb + k];
    //             for (int i = 0; i < M; i++)
    //             {
    //                 double a = (TransA == noTrans) ? A[i * lda + k] : A[k * lda + i];
    //                 C[i * ldc + j] += alpha * a * b;
    //             }
    //         }
    //     }

    // }

    // // 按列储存时
    // if (order == 1)
    // {
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     for (int k = 0; k < K; k++)
    //     {
    //         for (int j = 0; j < N; j++)
    //         {
    //             double b = (TransB == noTrans) ? B[j * ldb + k] : B[k * ldb + j];
    //             for (int i = 0; i < M; i++)
    //             {
    //                 double a = (TransA == noTrans) ? A[k * lda + i] : A[i * lda + k];
    //                 C[j * ldc + i] += alpha * a * b;
    //             }
    //         }
    //     }
        
    // }

    // // k,i,j顺序
    // // 按行储存时
    // if (order == 0)
    // {
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     for (int k = 0; k < K; k++)
    //     {
    //         for (int i = 0; i < M; i++)
    //         {
    //             for (int j = 0; j < N; j++)
    //             {
    //                 double a = (TransA == noTrans) ? A[i * lda + k] : A[k * lda + i];
    //                 double b = (TransB == noTrans) ? B[k * ldb + j] : B[j * ldb + k];
    //                 C[i * ldc + j] += alpha * a * b;
    //             }
    //         }
    //     }

    // }

    // // 按列储存时
    // if (order == 1)
    // {
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     for (int k = 0; k < K; k++)
    //     {
    //         for (int i = 0; i < M; i++)
    //         {
    //             for (int j = 0; j < N; j++)
    //             {
    //                 double a = (TransA == noTrans) ? A[k * lda + i] : A[i * lda + k];
    //                 double b = (TransB == noTrans) ? B[j * ldb + k] : B[k * ldb + j];
    //                 C[j * ldc + i] += alpha * a * b;
    //             }
    //         }
    //     }
        
    // }

    // // i,k,j顺序
    // // 按行储存时
    // if (order == 0)
    // {   
    //     //#pragma omp parallel for
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }
    //     //#pragma omp parallel for collapse(2)
    //     for (int i = 0; i < M; i++)
    //     {
    //         for (int k = 0; k < K; k++)
    //         {
    //             double a = (TransA == noTrans) ? A[i * lda + k] : A[k * lda + i];
    //             for (int j = 0; j < N; j++)
    //             {
    //                 double b = (TransB == noTrans) ? B[k * ldb + j] : B[j * ldb + k];
    //                 C[i * ldc + j] += alpha * a * b;
    //             }
    //         }
    //     }

    // }

    // // 按列储存时
    // if (order == 1)
    // {
    //     //#pragma omp parallel for
    //     for(int i = 0; i < M * N ; i++){
    //         C[i] = beta * C[i];
    //     }

    //     //#pragma omp parallel for collapse(2)
    //     for (int i = 0; i < M; i++)
    //     {
    //         for (int k = 0; k < K; k++)
    //         {
    //             double a = (TransA == noTrans) ? A[k * lda + i] : A[i * lda + k];
    //             for (int j = 0; j < N; j++)
    //             {
    //                 double b = (TransB == noTrans) ? B[j * ldb + k] : B[k * ldb + j];
    //                 C[j * ldc + i] += alpha * (a * b);
    //             }
    //         }
    //     }
        
    // }
  }
}

// int main(){
//     // 创建随机数组
//     int c = 256;
//     double *C = (double*)calloc(c, sizeof(double));
//     // 创建随机数组
//     double *random1 = (double*)malloc(c * sizeof(double));
//     random_matrix(16, 16, random1);
//     double *random2 = (double*)malloc(c * sizeof(double));
//     random_matrix(16, 16, random2);

//     long timeuse = __LONG_MAX__;
//     struct timeval start, end;
//     gettimeofday(&start, NULL);

//     origin_GEMM(colOrder, noTrans, trans, 16, 16, 16, 1, random1, 16, random2, 16, 1, C, 4);

//     gettimeofday(&end, NULL);
//     timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
//     printf("Time: %.ld ns\n", timeuse * 1000);

//     // for (int i = 0; i < 16; i++){
//     //     printf("%lf ", C[i]);
//     // }
//     // printf("\n");

//     free(C);
//     free(random1);
//     free(random2);

//     return 0;
// }
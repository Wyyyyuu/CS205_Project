#include <cblas.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys/time.h"

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

int main()
{
  // 创建随机数组
  int c = 1600;
  double *C = calloc(c, sizeof(double));
  double *random1 = malloc(c * sizeof(double));
  random_matrix(40,40,random1);
  double *random2 = malloc(c * sizeof(double));
  random_matrix(40,40,random2);

  long timeuse = __LONG_MAX__;
  struct timeval start, end;
  gettimeofday(&start, NULL);

  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans, 40, 40, 40, 1, random1, 40, random2, 40, 1, C, 40);

  gettimeofday(&end, NULL);
  timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
  printf("Time: %.ld ns\n", timeuse * 1000);

  // for(int i=0; i<16; i++){
  //   printf("%lf ", C[i]);
  // }
  // printf("\n");

  free(C);
  free(random1);
  free(random2);

  return 0;
}
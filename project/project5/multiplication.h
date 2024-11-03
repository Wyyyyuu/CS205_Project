#include <stddef.h>
// 按行储存or按列储存
enum order{rowOrder=0, colOrder=1};
// 是否转置
enum transpose{noTrans=0, trans=1};
void random_matrix(size_t row, size_t col, double *A);
void origin_GEMM(enum order order, enum transpose TransA, enum transpose TransB, size_t M, size_t N, size_t K, 
                    double alpha, double* A, size_t lda, double* B, size_t ldb, double beta, double*C, size_t ldc);


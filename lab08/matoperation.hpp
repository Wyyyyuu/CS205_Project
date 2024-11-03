#pragma once


float add(const float *p1, const float * p2, size_t n);
float add_unloop(const float *p1, const float * p2, size_t n);
float add_avx2(const float *p1, const float * p2, size_t n);
float add_avx2_omp(const float *p1, const float * p2, size_t n);
// float add_neon(const float *p1, const float * p2, size_t n);
// float add_neon_omp(const float *p1, const float * p2, size_t n);
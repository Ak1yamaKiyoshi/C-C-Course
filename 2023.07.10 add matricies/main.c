#include <emmintrin.h>
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <time.h>

float *add(float *vector0, float *vector1) {
  float *resultVector = (float *)calloc(sizeof(float), 4);
  for (int i = 0; i < 3; i++)
    resultVector[i] = vector0[i] + vector1[i];
  return resultVector;
}

float *substract(float *vector0, float *vector1) {
  float *resultVector = (float *)calloc(sizeof(float), 4);
  for (int i = 0; i < 3; i++)
    resultVector[i] = vector0[i] - vector1[i];
  return resultVector;
}

float *multiply(float *vector0, float *vector1) {
  float *resultVector = (float *)calloc(sizeof(float), 4);
  for (int i = 0; i < 3; i++)
    resultVector[i] = vector0[i] * vector1[i];
  return resultVector;
}

float *divide(float *vector0, float *vector1) {
  float *resultVector = (float *)calloc(sizeof(float), 4);
  for (int i = 0; i < 3; i++)
    resultVector[i] = vector0[i] / vector1[i];
  return resultVector;
}

unsigned long int time_diff(struct timespec start, struct timespec end) {
  return (unsigned long int)((end.tv_sec - start.tv_sec) * 1000000000 +
                             (end.tv_nsec - start.tv_nsec));
}

float *randVector(int *vec) {
  for (int i = 0; i < 3; i++)
    vec[i] = rand();
  return vec;
}

struct test {
  size_t usual_sum;
  size_t faster_sum;
};

void test() {}

int main(void) {
  struct test add_test;
  add_test.faster_sum = 0;
  add_test.usual_sum = 0;
  struct test sub_test;
  sub_test.faster_sum = 0;
  sub_test.usual_sum = 0;
  struct test mul_test;
  mul_test.faster_sum = 0;
  mul_test.usual_sum = 0;
  struct test div_test;
  div_test.faster_sum = 0;
  div_test.usual_sum = 0;

  struct timespec start;
  struct timespec end;
  srand(time(NULL));

  float vec0[] = {50, 50, 50, 50};
  float vec1[] = {50, 50, 50, 50};

  __m128 vec2;
  vec2 = _mm_set_ps(50, 50, 50, 50);
  __m128 vec3;
  vec3 = _mm_set_ps(50, 50, 50, 50);

  float *rvec_f;
  __m128 *rvec_m128;

  for (float i = 0; i < 10000000; i++) {
    timespec_get(&start, TIME_UTC);
    /* operation */
    rvec_f = add(vec0, vec1);
    /* operation */
    timespec_get(&end, TIME_UTC);
    add_test.usual_sum += time_diff(start, end);
    free(rvec_f);

    /**********************************/
    rvec_m128 = (__m128 *)malloc(sizeof(__m128));
    timespec_get(&start, TIME_UTC);
    ///* operation */
    *rvec_m128 = _mm_add_ps(vec2, vec3);
    ///* operation */
    timespec_get(&end, TIME_UTC);
    add_test.faster_sum += time_diff(start, end);
    // free(rvec_m128);
  }
  printf(" usual: %5ld ns", add_test.usual_sum / 10000000);
  printf("\n fast : %5ld ns", add_test.faster_sum / 10000000);
  return 0;
}
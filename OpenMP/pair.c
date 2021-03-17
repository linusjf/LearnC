#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int a, b;
  omp_nest_lock_t lck;
} pair;

void incr_a(pair *p, int a) {
  // Called only from incr_pair, no need to lock.
  p->a += a;
}

void incr_b(pair *p, int b) {
  // Called both from incr_pair and elsewhere,
  // so need a nestable lock.

  omp_set_nest_lock(&p->lck);
  p->b += b;
  omp_unset_nest_lock(&p->lck);
}

void incr_pair(pair *p, int a, int b) {
  omp_set_nest_lock(&p->lck);
  incr_a(p, a);
  incr_b(p, b);
  omp_unset_nest_lock(&p->lck);
}

int work1() {
 return rand() % 10 + 1;
}

int work2() {
 return rand() % 10 + 1;
}

int work3() {
 return rand() % 10 + 1;
}

void f(pair *p) {
#pragma omp parallel sections
  {
#pragma omp section
    incr_pair(p, work1(), work2());
#pragma omp section
    incr_b(p, work3());
  }
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  pair*  val = malloc(sizeof(pair));
  val->a = val->b = 0;
  omp_init_nest_lock(&val->lck);
  f(val);
  printf("a = %d, b = %d\n", val->a, val->b);
  omp_destroy_nest_lock(&val->lck);
}

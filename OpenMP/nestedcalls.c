#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  omp_set_max_active_levels(5);
  omp_set_dynamic(0);
#pragma omp parallel num_threads(2)
  {
    if (omp_get_thread_num() == 0)
      /* line A */
      omp_set_num_threads(4);
    else
      /* line B */
      omp_set_num_threads(6);
    /* The following statement will print out
     *
     * 0: 2 4
     * 1: 2 6
     *
     * omp_get_num_threads() returns the number
     * of the threads in the team, so it is
     * the same for the two threads in the team.
     */
    printf("%d: %d %d\n", omp_get_thread_num(), omp_get_num_threads(),
           omp_get_max_threads());
/* Two inner parallel regions will be created
 * one with a team of 4 threads, and the other
 * with a team of 6 threads.
 */
#pragma omp parallel
    {
#pragma omp master
      {
        /* The following statement will print out
         *
         * Inner: 4
         * Inner: 6
         */
        printf("Inner: %d\n", omp_get_num_threads());
      }
      omp_set_num_threads(7); /* line C */
    }
/* Again two inner parallel regions will be created,
 * one with a team of 4 threads, and the other
 * with a team of 6 threads.
 *
 * The omp_set_num_threads(7) call at line C
 * has no effect here, since it affects only
 * parallel regions at the same or inner nesting
 * level as line C.
 */
#pragma omp parallel
    { printf("count me.\n"); }
  }
  return (0);
}

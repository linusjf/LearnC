#include <stdio.h>
#include <time.h>

int main()
{
    time_t daylight, standard;
    struct tm timestr;
    double diff;

    timestr.tm_year = 2012 - 1900;
    timestr.tm_mon = 11 - 1;
    timestr.tm_mday = 4;
    timestr.tm_hour = 1;
    timestr.tm_min = 30;
    timestr.tm_sec = 0;

    /* first with standard time */
    timestr.tm_isdst = 0;
    standard = mktime(&timestr);

    /* now with daylight time */
    timestr.tm_isdst = 1;
    daylight = mktime(&timestr);

    diff = difftime(standard, daylight);

    printf("Difference is %f hour(s)\n", diff/60.0/60.0);

    return 0;
}


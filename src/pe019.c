/*
 * How many Sundays fell on the first of the month during the twentieth century
 * (1 Jan 1901 to 31 Dec 2000)?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_leap(int year)
{
        return (year % 4 == 0);
}

int main()
{
        int num_sundays = 0;
        int day, month, year, wday;
        day = 1, month = 1, year = 1901;
        wday = 2; // From wikipedia, found that 1901 started on a Tuesday.

        while(year < 2001) {
                if (wday ==  0 && day == 1)
                        ++num_sundays;

                ++day;
                ++wday;

                /* parse new weekday */
                if (wday == 7)
                        wday = 0;

                /* parse new month */
                if (month == 2) {
                        if ((!is_leap(year) && day == 29) || (is_leap(year) && day == 30)) {
                                ++month;
                                day = 1;
                        }
                }
                if (month == 9 || month == 4 || month == 6 || month == 11) {
                        if (day == 31) {
                                ++month;
                                day = 1;
                        }
                }
                if (day == 32) {
                        ++month;
                        day = 1;
                }

                /* parse new year */
                if (month == 13) {
                        ++year;
                        month = 1;
                }
        }

        printf("%d\n", num_sundays);
        return 0;
}

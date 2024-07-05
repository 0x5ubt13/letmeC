//
// Created by 0x5ubt13 during a flight on 05/07/2024.
//

#include <stdio.h>
#include <string.h>
#define LINES 100               /* max lines to be sorted */

main()                          /* sort input lines */
{
    char *lineptr[LINES];       /* pointers to text lines */
    int nlines;                 /* number of input lines read */

    if ((nlines = readlines(lineptr, LINES)) >= 0) {
        sort(lineptr, nlines);
        writelines(lineptr, nlines);
    }
    else
        printf("input too big to sort\n");
}

#define MAXLEN 1000

readlines(lineptr, maxlines)    /* read input lines */
char *lineptr[];                /* for sorting */
int maxlines;
{
    int len, nlines;
    char *p, *alloc(), line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines)
            return(-1);
        else if ((p = alloc(len)) == NULL)
            return(-1);
        else {
            line[len-1] = '\0'; /* zap newline */
            strcpy_s(p, line);
            lineptr[nlines++] = p;
        }
    return (nlines);
}

/* The newline at the end of each line is deleted so it will
 * not affect the order in which the lines are sorted. */

void writelines(lineptr, nlines) /* write output lines */
char *lineptr[];
int nlines;
{
    //    int i;
    //
    //    for (i = 0; i < nlines; i++)
    //        printf("%s\n", lineptr[i]);

    /* Since lineptr is itself an array which is passed to writelines,
     * it can be treated as a pointer in exactly the same manner as
     * the following */

    while (--nlines > 0)
        printf("%s\n", *lineptr++);

    /* *lineptr points initially to the first line; each increment
     * advances it to the next line while nlines is counted down */
}

sort(v, n)                      /* sort strings v[0] v[n-1] into increasing order */
char *v[];                      /* aka lineptr */
int n;
{
    int gap, i, j;
    char *temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i-gap; j >= 0; j -= gap) {
                if (strcmp(v[j], v[j+gap]) <= 0)
                    break;
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}
#ifndef CHEST_MSD_IO_H
#include <stdio.h>
#include <stdlib.h>
#define CHEST_MSD_IO_H

#define MSD_IO_LINE_MAX 1024

char* msd_io_getline();

char* msd_io_getstr();

#endif //CHEST_MSD_IO_H

#ifdef MSD_IO_IMPLEMENTATION

/* returns 0 if the line is longer than MSD_IO_LINE_MAX */
char* msd_io_getline() {
    char* line = malloc(MSD_IO_LINE_MAX);

    int line_l = 0;
    while ( (line[line_l] = getchar()) != '\n' && line_l++ < MSD_IO_LINE_MAX );

    return line_l < MSD_IO_LINE_MAX ? line : 0;
}

/* same as msd_io_getline but removes the newline at the end */
char* msd_io_getstr() {
    char* line = malloc(MSD_IO_LINE_MAX);

    int line_l = 0;
    while ( (line[line_l] = getchar()) != '\n' && line_l++ < MSD_IO_LINE_MAX );
    line[line_l] = '\0';

    return line_l < MSD_IO_LINE_MAX ? line : 0;
}

#endif // MSD_IO_IMPLEMENTATION

#ifndef CHEST_MSD_RND_H
#include <stdlib.h>
#include <time.h>
#define CHEST_MSD_RND_H

char msd_rnd_det_getletter() { // returns a random lowercase letter (same random letter during the duration of the program - det - deterministic)
    srand( time(0) );

    return 97 + rand() % 26;
}

#endif //CHEST_MSD_RND_H

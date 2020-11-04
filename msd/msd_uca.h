#ifndef CHEST_MSD_UCA_H
#include <stdio.h>
#include <stdlib.h>
#define CHEST_MSD_UCA_H

char* msd_uca_to_str_new(const unsigned char* uca, unsigned long long int uca_l);

char* msd_uca_to_str_loc(unsigned char* uca, unsigned long long int uca_l);

void msd_uca_printallchars(unsigned char const* uca, unsigned long long int const uca_l);

#endif //CHEST_MSD_UCA_H

#ifdef MSD_UCA_IMPLEMENTATION
char* msd_uca_to_str_new(const unsigned char* uca, unsigned long long int uca_l) {
    char* str = (char*) malloc(uca_l + 1);
    int i;
    for(i = 0; i < uca_l; i++) str[i] = (char) uca[i];
    str[uca_l + 1] = '\0';
    return str;
}

char* msd_uca_to_str_loc(unsigned char* uca, unsigned long long int uca_l) {
    char* str = (char*) realloc(uca, uca_l + 1);
    str[uca_l + 1] = '\0';
    return str;
}

void msd_uca_printallchars(unsigned char const* uca, unsigned long long int const uca_l) {
    int i;
    for (i = 0; i < uca_l; i++) {
        printf("'%c' ", uca[i]);
    }
    putchar('\n');
}
#endif // MSD_UCA_IMPLEMENTATION

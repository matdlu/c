#ifndef CHEST_MSD_STR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHEST_MSD_STR_H

int msd_str_isspace(char c);

int msd_str_isblank(const char* str);

/* msd_str_cat - appends s1 to s2 and returns a pointer to the end of the concatenated string */
char* msd_str_cat(char* s1, const char* s2);

unsigned long long int msd_str_len(const char* str);

char* msd_str_cat_new(const char* s1, const char* s2);

void msd_str_printchars(const char* str);

int msd_str_cmp(const char* s1, const char* s2);

int msd_str_cnt_spaces(char* str);

struct msd_str_Split_out {
    unsigned long long int sa_l;
    char** sa;
} typedef msd_str_Split_out;

msd_str_Split_out msd_str_split(char* str);

#endif //CHEST_MSD_STR_H

#ifdef MSD_STR_IMPLEMENTATION

int msd_str_isspace(char c) {
    return c==' '||c=='\n'||c=='\t'||c=='\v'||c=='\f'||c=='\r';
}

int msd_str_isblank(const char* str) {
    while( *str ) {
        if( ! msd_str_isspace(*str) ) return 0;
        str++;
    }

    return 1;
}

/* msd_str_cat - appends s1 to s2 and returns a pointer to the end of the concatenated string */
char* msd_str_cat(char* s1, const char* s2) {
    while( *s1 ) s1++;
    while( *s1++ = *s2++ );
    return --s1;
}

unsigned long long int msd_str_len(const char* str) {
    if ( str ) {
        unsigned long long int str_l = 0;
        while (str[str_l]) str_l++;
        return str_l--;
    } else {
        return 0;
    }
}

char* msd_str_cat_new(const char* s1, const char* s2) {
    unsigned long long int s1_l = msd_str_len(s1);
    unsigned long long int s2_l = msd_str_len(s2);

    char* str = (char*) malloc(s1_l + s2_l + 1); // +1 for \0 in the end

    int i;
    for(i = 0; i < s1_l; i++) str[i] = s1[i];

    for(i = 0; i < s2_l; i++) str[s1_l + i] = s2[i];

    str[s1_l+s2_l+1] = '\0';

    return str;
}

void msd_str_printchars(const char* str) {
    unsigned long long int str_l = msd_str_len(str);
    int i;
    for(i = 0; i < str_l + 1; i++) {  // +1 to include '\0'
        printf("'%c' ", str[i]);
    }
    putchar('\n');
}

int msd_str_cmp(const char* s1, const char* s2) {
    if ( s1 && s2 ) {
        int r = 0;

        unsigned long long int s1_l = 0;
        unsigned long long int s2_l = 0;

        while( *(s1 + s1_l) && *(s2 + s2_l) ) {
            r = *(s1 + s1_l++) == *(s2 + s2_l++);
            if ( ! r ) return 0;
        }

        if ( *(s1 + s1_l) ^ *(s2 + s2_l) ) return 0;

        return r;
    } else {
        return 0;
    }
}

int msd_str_cnt_spaces(char* str) {
    int l = 0;
    char not_space = 0;
    int i;
    for(i = 0; str[i]; i++) {
        if ( msd_str_isspace( str[i+1] ) || str[i+1] == 0 ) {
            if ( not_space ) l++;
            not_space = 0;
        } else {
            not_space = 1;
        }
    }

    return l;
}

msd_str_Split_out msd_str_split(char* str) {
    msd_str_Split_out out;

    unsigned long long int str_l = 0;
    unsigned long long int not_space = 0;
    while( str[str_l] ) {
        if ( msd_str_isspace( str[str_l+1] ) || str[str_l+1] == 0 ) {
            if ( not_space ) out.sa_l++;
            not_space = 0;
        } else {
            not_space = 1;
        }
        str_l++;
    }

    out.sa = (char**) malloc( out.sa_l * sizeof out.sa);

    out.sa_l = 0;
    not_space = 0;
    int i;
    for(i = 0; i < str_l + 1; i++) {
        if ( msd_str_isspace( str[i] ) || str[i] == '\0' ) {
            if ( not_space ) {
                out.sa[out.sa_l] = (char*) malloc(not_space * sizeof(char*));
                memcpy(out.sa[out.sa_l], str + i - not_space, not_space);
                out.sa[out.sa_l][not_space] = '\0';
                out.sa_l++;
            }
            not_space = 0;
        } else {
            not_space++;
        }
    }

    return out;
}

//todo: make a splitting function based on overwriting the input placing \0 at the end of words and making a pointer array to begginings of these words

#endif // MSD_STR_IMPLEMENTATION

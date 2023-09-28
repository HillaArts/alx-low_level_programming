#ifndef _MAIN_H
#define _MAIN_H

#include <stddef.h>
#include <stdio.h>

void print_binary(unsigned long int n);
unsigned int binary_to_uint(const char *b);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);

#endif /* _MAIN_H */

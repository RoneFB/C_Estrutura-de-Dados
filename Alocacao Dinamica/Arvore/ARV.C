#include<stdio.h>
#include<stdlib.h>

struct cel{
    int valor;
    struct cel *esq, *dir;
};typedef struct cel no;



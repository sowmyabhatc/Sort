#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<stdint.h>
#include "appconst.h"

void bubble_sort(int32_t list[],uint32_t size);
void selection_sort(int32_t list[],uint32_t size);
void insertion_sort(int32_t list[],uint32_t size);


void quick_sort(int32_t list[],int32_t start,int32_t end);
void merge_sort(int32_t list[],int32_t low,int32_t high);
#endif // SORT_H_INCLUDED

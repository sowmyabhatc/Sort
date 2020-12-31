#include<stdint.h>
#include"sort.h"
#include "appconst.h"
#include<stdio.h>
static void _swap_(int32_t *num1,int32_t  *num2){
int32_t temp;
temp=*num1;
*num1=*num2;
*num2=temp;
}

void bubble_sort(int32_t list[],uint32_t size){
int32_t pass, index;
for (pass=0; pass<size-1;++pass){

    for(index =size-1; index>pass ;--index){
        if(list[index]<list[index-1]){
            _swap_(&list[index],&list[index-1]);
        }
    }
}
}


void selection_sort(int32_t list[],uint32_t size){
int32_t pass,min_pos,index;
for (pass=0; pass<size-1;++pass){
    min_pos=pass;
    for(index=pass+1; index<size; ++index){
        if(list[index]<list[min_pos]){
            min_pos=index;
        }
    }
    _swap_(&list[pass],&list[min_pos]);
}
}


void insertion_sort(int32_t list[],uint32_t size){
int32_t pass,key,index;
for (pass=1;pass<size;++pass){
    key=list[pass];
    index=pass-1;
    while(index>=0  && list[index]>key){
        list[index+1]=list[index];
        --index;

    }
    list[index+1]=key;
}
}

static uint32_t  _partition_(int32_t list[],int32_t start,int32_t end){
uint32_t up =start,down=end;
int32_t pivot=list[start];

do{
   while(list[up]<=pivot  && up<=down){++up;}
   while(list[down]>pivot  && up<=down){--down;}

   if(up<=down){
    _swap_(&list[up],&list[down]);
   }
}while(up<=down);
_swap_(&list[down],&list[start]);

return down;
}

void quick_sort(int32_t list[],int32_t start,int32_t end){
int32_t mid;
if (start < end){
    mid = _partition_(list,start,end);  //Here mid=down
    quick_sort(list,start,mid-1);
    quick_sort(list,mid+1,end);
}
}


static void   _merge_(int32_t list[],int32_t low,int32_t mid,int32_t high){
int32_t temparray[ARRAY_SIZE];
int32_t f_index=low,s_index=mid+1,t_index=low; //t_index indx for temp aray

while(f_index<=mid  &&  s_index<=high){
    if(list[f_index]<list[s_index]){
        temparray[t_index++]=list[f_index++];
    }else{
    temparray[t_index++]=list[s_index++];
    }
}
if(f_index > mid){
    while(s_index<=high){
        temparray[t_index++]=list[s_index++];
    }
}
else{
    while(f_index<=mid){
        temparray[t_index++]=list[f_index++];
    }
}
for (int32_t k=low;k<high;++k){
        list[k]=temparray[k]; //copy back sorted element from temparray to actual list

}
}

void merge_sort(int32_t list[],int32_t low,int32_t high){
int32_t mid;
if(low<high){
    mid=(low+high)/2;
    merge_sort(list,low,mid);
    merge_sort(list,mid+1,high);
    _merge_(list,low,mid,high);
}
}

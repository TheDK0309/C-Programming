#include "array_operations.hh"
#include <iostream>
int greatest_v1(int* itemptr, int size){
    int max = *itemptr;

    for (int i = 1; i < size; i++)
        if (*(itemptr+i) > max)
            max = *(itemptr+i);

    return max;
}
int greatest_v2(int* itemptr, int* endptr){
    int size= endptr - itemptr;
    int max= *itemptr;
    for (int i = 1; i < size; i++)
        if (*(itemptr+i) > max)
            max = *(itemptr+i);
    return max;
}
void copy(int* itemptr, int* endptr, int* targetptr){
    int size= endptr - itemptr;
        for(int i=0;i<size;i++){
            *(targetptr+i)=*(itemptr+i);
        }
}
void reverse(int* leftptr, int* rightptr){
    int j=rightptr- leftptr-1;
    int i=0;
    while(i<j){
        int temp= *(leftptr+i);
        *(leftptr+i)=*(leftptr+j);
        *(leftptr+j)=temp;
        i++;
        j--;
    }
}


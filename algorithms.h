#ifndef LABA3_1_ALGORITHMS_H
#define LABA3_1_ALGORITHMS_H
#include <iostream>
#include "ArraySequence.h"
template <typename T>
void BubbleSort(Sequence<T>* arr, bool (*cmp)(T,T), int first, int last){
    for (int i=first; i < last; i++){
        for (int j=first; j < last-i;j++){
            if(cmp(arr->Get(j),arr->Get(j+1))){
                swap(arr,j,j+1);
            }
        }
    }
}
template <typename T>
void QuickSort(Sequence<T>* arr,bool (*cmp)(T,T), int first, int last)
{
    int Lbord=first;
    int Rbord=last;
    T pivot=arr->Get((Lbord+Rbord)/2);
    do{
        while (cmp(pivot,arr->Get(Lbord))) Lbord++;
        while (cmp(arr->Get(Rbord),pivot)) Rbord--;
        if (Lbord<=Rbord){
            swap(arr,Lbord,Rbord);
            Lbord++;
            Rbord--;
        }
    } while (Lbord<Rbord);
    if (first<Rbord) QuickSort(arr, cmp, first, Rbord);
    if (Lbord<last) QuickSort(arr, cmp, Lbord, last);
}

template <typename T>
void InsertionSort(Sequence<T>* arr,bool (*cmp)(T,T), int first, int last){
    for (int i=first+1; i<last+1;i++){
        for(int j=i; j>0 && cmp(arr->Get(j-1),arr->Get(j));j--){
            swap(arr,j-1,j);
        }
    }
}
template <typename T>
void swap(Sequence<T>* arr, int index1, int index2){
    T temp = arr->Get(index1);
    arr->Set(index1, arr->Get(index2));
    arr->Set(index2, temp);
}

bool cmp(int a, int b){
    if (a > b) {
        return true;
    } else {
        return false;
    }
}

bool cmp(float a, float b){
    if (a > b) {
        return true;
    } else {
        return false;
    }
}
#endif //LABA3_1_ALGORITHMS_H

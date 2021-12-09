#ifndef LABA3_1_SORTINFO_H
#define LABA3_1_SORTINFO_H
#pragma once
#include <iostream>
#include "ArraySequence.h"
#include "ListSequence.h"
#include "algorithms.h"
#include <ctime>
#include <chrono>
#include <functional>
template <typename T>
class SortInformation{
public:
    void (*Sort)(Sequence<T>*,bool(*cmp)(T,T),int,int);
    Sequence<T>* arr;
    unsigned long int Time=0;

    SortInformation(Sequence<T>* array, void (*Sort1)(Sequence<T>*,bool (*cmp)(T,T),int,int), bool (*cmp)(T,T)){
        arr=array;
        Sort=Sort1;
        SortTime();
    }

    SortInformation(){
        arr=nullptr;
        Sort=nullptr;
        Time=0;
    }

    void SortTime(){

        auto start = std::chrono::high_resolution_clock::now();
        Sort(arr,cmp,0,arr->GetLength()-1);
        auto end = std::chrono::high_resolution_clock::now();
        Time = std::chrono::duration_cast<std::chrono::duration<unsigned long int , std::ratio<1>>>((end - start)*1000000).count();
    }
    void AverageSortTimeOn10attempts(int countElements){
        auto begin = std::chrono::high_resolution_clock::now();
        for (int i=0; i<10;i++){
            ArraySequence<T>* arr_temp= new ArraySequence<T>(countElements);
            EnterTheRandomNumbers(arr_temp);
            Sort(arr_temp,cmp,0,arr_temp->GetLength()-1);
        }
        auto finish = std::chrono::high_resolution_clock::now();
        Time=chrono::duration_cast<std::chrono::duration<unsigned long int , std::ratio<1>>>((finish - begin)*1000000).count();
        Time=Time/10;
    }

    void AverageSortTimeOn10attempts2(int countElements){
        auto begin = std::chrono::high_resolution_clock::now();
        for (int i=0; i<10;i++){
            ListSequence<T>* list_temp= new ListSequence<T>(countElements);
            EnterTheRandomNumbers(list_temp);
            Sort(list_temp,cmp,0,list_temp->GetLength()-1);
        }
        auto finish = std::chrono::high_resolution_clock::now();
        Time=chrono::duration_cast<std::chrono::duration<unsigned long int , std::ratio<1>>>((finish - begin)*1000000).count();
        Time=Time/10;
    }
    void EnterTheRandomNumbers(Sequence<T>* buffer){
        int number;
        srand(static_cast<unsigned int>(time(0)));
        for (int i=0; i<buffer->GetLength();i++){
            number=rand();
            buffer->Set(i,number);
        }
    }
    void PrintTime(){
        cout<<"Time of Sort: "<<Time<<" mks!"<<endl;
    }
};
#endif //LABA3_1_SORTINFO_H

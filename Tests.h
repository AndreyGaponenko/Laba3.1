#ifndef LABA3_1_TESTS_H
#define LABA3_1_TESTS_H
#include "ListSequence.h"
#include "ArraySequence.h"
#include "SortInfo.h"
#include "algorithms.h"
//#include "Menu.h"
void StraightArray_QuickSort(){
    int num;
    cout<<"Here we are sorting by Quick Sort already sorted array, which has numbers from 1 to n."<<endl;
    cout<<"Enter a quantity of numbers in Array: ";
    cin>>num;
    ArraySequence<int>* arr = new ArraySequence<int>(num);
    for (int i=0; i<num; i++){
        arr->Set(i,i+1);
    }
    SortInformation<int>* result = new SortInformation<int>(arr,QuickSort,cmp);
    result->PrintTime();
}
void BackArray_QuickSort(){
    int num;
    cout<<"Here we are sorting by Quick Sort already back sorted array, which has numbers from n down to 1."<<endl;
    cout<<"Enter a quantity of numbers in Array: ";
    cin>>num;
    ArraySequence<int>* arr = new ArraySequence<int>(num);
    for (int i=0; i<num; i++){
        arr->Set(i,num-i);
    }
    SortInformation<int>* result = new SortInformation<int>(arr,QuickSort,cmp);
    result->PrintTime();
}
void RandomArray_QuickSort(){
    int num;
    int number;
    cout<<"Here we are sorting by Quick Sort array, which has random numbers"<<endl;
    cout<<"Enter a quantity of numbers in Array: ";
    cin>>num;
    ArraySequence<int>* arr = new ArraySequence<int>(num);
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<num;i++){
        number=rand();
        arr->Set(i,number);
    }
    SortInformation<int>* result = new SortInformation<int>(arr,QuickSort,cmp);
    result->PrintTime();
}

void StraightArray_BubbleSort(){
    int num;
    cout<<"Here we are sorting by Bubble Sort already sorted array, which has numbers from 1 to n."<<endl;
    cout<<"Enter a quantity of numbers in Array: ";
    cin>>num;
    ArraySequence<int>* arr = new ArraySequence<int>(num);
    for (int i=0; i<num; i++){
        arr->Set(i,i+1);
    }
    SortInformation<int>* result = new SortInformation<int>(arr,BubbleSort,cmp);
    result->PrintTime();
}
void BackArray_BubbleSort(){
    int num;
    cout<<"Here we are sorting by Bubble Sort already back sorted array, which has numbers from n down to 1."<<endl;
    cout<<"Enter a quantity of numbers in Array: ";
    cin>>num;
    ArraySequence<int>* arr = new ArraySequence<int>(num);
    for (int i=0; i<num; i++){
        arr->Set(i,num-i);
    }
    SortInformation<int>* result = new SortInformation<int>(arr,BubbleSort,cmp);
    result->PrintTime();
}
void RandomArray_BubbleSort(){
    int num;
    int number;
    cout<<"Here we are sorting by Bubble Sort array, which has random numbers"<<endl;
    cout<<"Enter a quantity of numbers in Array: ";
    cin>>num;
    ArraySequence<int>* arr = new ArraySequence<int>(num);
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<num;i++){
        number=rand();
        arr->Set(i,number);
    }
    SortInformation<int>* result = new SortInformation<int>(arr,BubbleSort,cmp);
    result->PrintTime();
}

void StraightArray_InsertionSort(){
    int num;
    cout<<"Here we are sorting by Insertion Sort already sorted array, which has numbers from 1 to n."<<endl;
    cout<<"Enter a quantity of numbers in Array: ";
    cin>>num;
    ArraySequence<int>* arr = new ArraySequence<int>(num);
    for (int i=0; i<num; i++){
        arr->Set(i,i+1);
    }
    SortInformation<int>* result = new SortInformation<int>(arr,InsertionSort,cmp);
    result->PrintTime();
}
void BackArray_InsertionSort(){
    int num;
    cout<<"Here we are sorting by Insertion Sort already back sorted array, which has numbers from n down to 1."<<endl;
    cout<<"Enter a quantity of numbers in Array: ";
    cin>>num;
    ArraySequence<int>* arr = new ArraySequence<int>(num);
    for (int i=0; i<num; i++){
        arr->Set(i,num-i);
    }
    SortInformation<int>* result = new SortInformation<int>(arr,InsertionSort,cmp);
    result->PrintTime();
}
void RandomArray_InsertionSort(){
    int num;
    int number;
    cout<<"Here we are sorting by Insertion Sortnarray, which has random numbers"<<endl;
    cout<<"Enter a quantity of numbers in Array: ";
    cin>>num;
    ArraySequence<int>* arr = new ArraySequence<int>(num);
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<num;i++){
        number=rand();
        arr->Set(i,number);
    }
    SortInformation<int>* result = new SortInformation<int>(arr,InsertionSort,cmp);
    result->PrintTime();
}

void StraightList_QuickSort(){
    int num;
    cout<<"Here we are sorting by Quick Sort already sorted list, which has numbers from 1 to n."<<endl;
    cout<<"Enter a quantity of numbers in List: ";
    cin>>num;
    ListSequence<int>* List = new ListSequence<int>(num);
    for (int i=0; i<num; i++){
        List->Set(i,i+1);
    }
    SortInformation<int>* result = new SortInformation<int>(List,QuickSort,cmp);
    result->PrintTime();
}
void BackList_QuickSort(){
    int num;
    cout<<"Here we are sorting by Quick Sort already back sorted List, which has numbers from n down to 1."<<endl;
    cout<<"Enter a quantity of numbers in List: ";
    cin>>num;
    ListSequence<int>* List = new ListSequence<int>(num);
    for (int i=0; i<num; i++){
        List->Set(i,num-i);
    }
    SortInformation<int>* result = new SortInformation<int>(List,QuickSort,cmp);
    result->PrintTime();
}
void RandomList_QuickSort(){
    int num;
    int number;
    cout<<"Here we are sorting by Quick Sort List, which has random numbers"<<endl;
    cout<<"Enter a quantity of numbers in List: ";
    cin>>num;
    ListSequence<int>* List = new ListSequence<int>(num);
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<num;i++){
        number=rand();
        List->Set(i,number);
    }
    SortInformation<int>* result = new SortInformation<int>(List,QuickSort,cmp);
    result->PrintTime();
}

void StraightList_BubbleSort(){
    int num;
    cout<<"Here we are sorting by Bubble Sort already sorted list, which has numbers from 1 to n."<<endl;
    cout<<"Enter a quantity of numbers in List: ";
    cin>>num;
    ListSequence<int>* List = new ListSequence<int>(num);
    for (int i=0; i<num; i++){
        List->Set(i,i+1);
    }
    SortInformation<int>* result = new SortInformation<int>(List,BubbleSort,cmp);
    result->PrintTime();
}
void BackList_BubbleSort(){
    int num;
    cout<<"Here we are sorting by Bubble Sort already back sorted List, which has numbers from n down to 1."<<endl;
    cout<<"Enter a quantity of numbers in List: ";
    cin>>num;
    ListSequence<int>* List = new ListSequence<int>(num);
    for (int i=0; i<num; i++){
        List->Set(i,num-i);
    }
    SortInformation<int>* result = new SortInformation<int>(List,BubbleSort,cmp);
    result->PrintTime();
}
void RandomList_BubbleSort(){
    int num;
    int number;
    cout<<"Here we are sorting by Bubble Sort List, which has random numbers"<<endl;
    cout<<"Enter a quantity of numbers in List: ";
    cin>>num;
    ListSequence<int>* List = new ListSequence<int>(num);
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<num;i++){
        number=rand();
        List->Set(i,number);
    }
    SortInformation<int>* result = new SortInformation<int>(List,BubbleSort,cmp);
    result->PrintTime();
}

void StraightList_InsertionSort(){
    int num;
    cout<<"Here we are sorting by Insertion Sort already sorted list, which has numbers from 1 to n."<<endl;
    cout<<"Enter a quantity of numbers in List: ";
    cin>>num;
    ListSequence<int>* List = new ListSequence<int>(num);
    for (int i=0; i<num; i++){
        List->Set(i,i+1);
    }
    SortInformation<int>* result = new SortInformation<int>(List,InsertionSort,cmp);
    result->PrintTime();
}
void BackList_InsertionSort(){
    int num;
    cout<<"Here we are sorting by Insertion Sort already back sorted List, which has numbers from n down to 1."<<endl;
    cout<<"Enter a quantity of numbers in List: ";
    cin>>num;
    ListSequence<int>* List = new ListSequence<int>(num);
    for (int i=0; i<num; i++){
        List->Set(i,num-i);
    }
    SortInformation<int>* result = new SortInformation<int>(List,InsertionSort,cmp);
    result->PrintTime();
}
void RandomList_InsertionSort(){
    int num;
    int number;
    cout<<"Here we are sorting by Insertion Sort List, which has random numbers"<<endl;
    cout<<"Enter a quantity of numbers in List: ";
    cin>>num;
    ListSequence<int>* List = new ListSequence<int>(num);
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<num;i++){
        number=rand();
        List->Set(i,number);
    }
    SortInformation<int>* result = new SortInformation<int>(List,InsertionSort,cmp);
    result->PrintTime();
}
#endif //LABA3_1_TESTS_H

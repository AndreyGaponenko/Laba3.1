#include <iostream>
//#include "Vector.h"
#include "ArraySequence.h"
#include "algorithms.h"
#include "SortInfo.h"
#include "Menu.h"
#include "ListSequence.h"
#include "Tests.h"
int main() {
    /*Vector<int>* vector = new Vector<int>(10);
    vector->Print_Vector();
    vector->Set(14,2);
    vector->Print_Vector();
    cout<<vector->Get(2)<<endl;
    vector->Print_Vector();*/
    //ArraySequence<int>* arr = new ArraySequence<int>(10000);
    //arr->EnterRandomNumbers();
    //arr->Print_Array();
    //SortInformation<int>* Info = new SortInformation<int>(arr,BubbleSort);
    //Info->AverageSortTimeOn10attempts(10000);
    //arr->Print_Array();
    //Info->PrintTime();
    //clock_t t=clock();
    //QuickSort(arr,0,arr->GetLength()-1);
    //BubbleSort(arr);
    //InsertionSort(arr,0,arr->GetLength()-1);
    //arr->Print_Array();
    //t=clock()-t;
    //double time = (double) t/CLOCKS_PER_SEC;
    //printf("Quick sort took %.8lf seconds\n",time);
    //arr->Print_Array();
    //ListSequence<int>* data = new ListSequence<int>();
    //general->ChooseSort();
    /*ArraySequence<int>* arr = new ArraySequence<int>(1);
    arr->Print_Array();
    arr->Insert(0,15);
    arr->Print_Array();
    arr->Insert(0,15);
    arr->Print_Array();
    arr->Insert(0,5);
    arr->Print_Array();
    arr->Prepend(155);
    arr->Print_Array();
    arr->Prepend(160);
    arr->Print_Array();*/
    /*ListSequence<int>* list = new ListSequence<int>(10);
    cout<<list->GetLength()<<endl;
    list->Set(2,122);
    list->Insert(3,221);
    list->Append(15);
    list->Append(20);
    list->Prepend(-15);
    list->Append(-65);
    InsertionSort(list,0,list->GetLength()-1);
    cout<<list->GetF()<<" "<<list->GetL()<<" "<<list->Get(5)<<" "<<list->GetLength()<<endl;
    //cout<<list->GetLength();
    list->Print_List();*/
    Menu<int>* general = new Menu<int>();
    general->GenMenu();
    //BackArray_QuickSort();
    //BackList_QuickSort();
    //BackList_BubbleSort();
    //BackList_InsertionSort();
}

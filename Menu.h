#ifndef LABA3_1_MENU_H
#define LABA3_1_MENU_H
#include <iostream>
#include "SortInfo.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "algorithms.h"
#endif //LABA3_1_MENU_H
template <class T>
class Menu {
public:
    Sequence<T>* data;

    Menu() {
        data = nullptr;
    }
    Menu(Sequence<T>* arr){
        data = arr;
    }

    void Print_Data(){
        cout << "Data: " << endl;
        cout <<"(";
        for (int i=0; i<data->GetLength(); i++){
            cout<< data->Get(i);
            if (i!=data->GetLength()-1) cout<<"; ";
        }
        cout <<")"<< endl;
    }

    void EnterElements(){
        cout<<"Enter a numbers:"<<endl;
        int number;
        for (int i=0; i<data->GetLength();i++){
            cin>>number;
            data->Set(i,number);
        }
    }

    void EnterRandomNumbers(){
        int number;
        srand(static_cast<unsigned int>(time(0)));
        for (int i=0; i<data->GetLength();i++){
            number=rand();
            data->Set(i,number);
        }
    }

    void ActionsWithData() {
        int index;
        do{
            std::cout << "1 - to append element" << std::endl
                      << "2 - to prepend element" << std::endl
                      << "3 - to insert element" << std::endl
                      << "4 - to print data" << std::endl
                      << "5 - to choose a type of sort"<<std::endl
                      << "0 - to exit in menu" << std::endl;
            T number;
            cin >> index;
            if (index == 1) {
                cout << "Element to append: ";
                cin >> number;
                data->Append(number);
                cout << endl;
            }
            if (index == 2) {
                cout << "Element to prepend: ";
                cin >> number;
                data->Prepend(number);
                cout << endl;
            }
            if (index == 3) {
                int indexIns;
                cout << "Index of element to insert: ";
                cin >> indexIns;
                cout << "Element to insert: ";
                cin >> number;
                data->Insert(indexIns, number);
                cout << endl;
            }
            if (index == 4) {
                Print_Data();
            }
            if(index==5){
                ChooseSort();
            }
        }while (index != 0);
    }

    void textSort(){
        std::cout <<"Choose a type of Sort:"<<std::endl;
        std::cout << "1 - Quick Sort:" << std::endl
                  << "2 - Bubble Sort:" << std::endl
                  << "3 - Insertion Sort: " << std::endl;
    }
    void ChooseSort(){
        int sortNum;
            textSort();
            do {
                cout<<"Your choice:";
                cin>>sortNum;
            }while(sortNum>3 || sortNum<1);
            SortInformation<T>* info;
            if (sortNum == 1) {
                info=new SortInformation<T>(data, QuickSort, cmp);
                cout<<"Data after Quick Sort:"<<endl;
                Print_Data();
            }
            if (sortNum == 2) {
                info=new SortInformation<T>(data, BubbleSort, cmp);
                cout<<"Data after Bubble Sort:"<<endl;
                Print_Data();
            }
            if (sortNum == 3) {
                info=new SortInformation<T>(data, InsertionSort, cmp);
                cout<<"Data after Bubble Sort:"<<endl;
                Print_Data();
            }
    }

    void ChooseTypeElandEnter(){
        int quantity;
        cout << "Enter a way to enter a elements and type of their collection:" << endl;
        int way;
        std::cout << "1 - By yourself in array" << std::endl
                  << "2 - Random in array" << std::endl
                  << "3 - By yourself in list" << std::endl
                  << "4 - Random in list" << std::endl;
        do {
            cin >> way;
            if (way == 1) {
                cout << "Enter a quantity of elements:" << endl;
                cin >> quantity;
                data = new ArraySequence<T>(quantity);
                EnterElements();
                Print_Data();
                ActionsWithData();
            }
            if (way == 2) {
                cout << "Enter a quantity of elements:" << endl;
                cin >> quantity;
                data = new ArraySequence<T>(quantity);
                EnterRandomNumbers();
                Print_Data();
                ActionsWithData();
            }
            if (way == 3) {
                cout << "Enter a quantity of elements:" << endl;
                cin >> quantity;
                data = new ListSequence<T>(quantity);
                EnterElements();
                Print_Data();
                ActionsWithData();
            }
            if (way == 4) {
                cout << "Enter a quantity of elements:" << endl;
                cin >> quantity;
                data = new ListSequence<T>(quantity);
                EnterRandomNumbers();
                Print_Data();
                ActionsWithData();
            }
        }while(way<1 || way>4);
    }

    void SpecialOptions(){
        cout<<"Here you can see a average time of sorting random numbers in all ways. Choose what you want:"<<endl;
        int choice;
        int choice2;
        int quantity;
        std::cout << "1 - Use Array" << std::endl
                  << "2 - Use List" << std::endl;
        do{
            cin>>choice;
            if(choice==1){
                ArraySequence<T>* buffer = new ArraySequence<T>(1);
                SortInformation<T>* TimeTest;
                textSort();
                do{
                    cin>>choice2;
                    if (choice2==1){
                        TimeTest = new SortInformation<T>(buffer, QuickSort,cmp);
                        cout << "Enter a quantity of elements:" << endl;
                        cin>>quantity;
                        TimeTest->AverageSortTimeOn10attempts(quantity);
                        TimeTest->PrintTime();
                    }else
                    if (choice2==2){
                        TimeTest = new SortInformation<T>(buffer, BubbleSort,cmp);
                        cout << "Enter a quantity of elements:" << endl;
                        cin>>quantity;
                        TimeTest->AverageSortTimeOn10attempts(quantity);
                        TimeTest->PrintTime();
                    }else
                    if (choice2==3){
                        TimeTest = new SortInformation<T>(buffer, InsertionSort,cmp);
                        cout << "Enter a quantity of elements:" << endl;
                        cin>>quantity;
                        TimeTest->AverageSortTimeOn10attempts(quantity);
                        TimeTest->PrintTime();
                    }
                }while(choice2<1 || choice2>3);
            }
            if(choice==2){
                ListSequence<T>* buffer = new ListSequence<T>(1);
                SortInformation<T>* TimeTest;
                textSort();
                do{
                    cin>>choice2;
                    if (choice2==1){
                        TimeTest = new SortInformation<T>(buffer, QuickSort,cmp);
                        cout << "Enter a quantity of elements:" << endl;
                        cin>>quantity;
                        TimeTest->AverageSortTimeOn10attempts2(quantity);
                        TimeTest->PrintTime();
                    }else
                    if (choice2==2){
                        TimeTest = new SortInformation<T>(buffer, BubbleSort,cmp);
                        cout << "Enter a quantity of elements:" << endl;
                        cin>>quantity;
                        TimeTest->AverageSortTimeOn10attempts2(quantity);
                        TimeTest->PrintTime();
                    }else
                    if (choice2==3){
                        TimeTest = new SortInformation<T>(buffer, InsertionSort,cmp);
                        cout << "Enter a quantity of elements:" << endl;
                        cin>>quantity;
                        TimeTest->AverageSortTimeOn10attempts2(quantity);
                        TimeTest->PrintTime();
                    }
                }while(choice2<1 || choice2>3);
            }
        }while(choice<1 || choice>2);
    }

    void GenMenu(){
        int select;
        do {
            std::cout << "1 - Make new data" << std::endl
                      << "2 - Special options with counting of time"<<std::endl
                      << "0 - Finish program." << std::endl;
            cin>>select;
            if (select==1) {
                ChooseTypeElandEnter();
            }
            if (select==2){
                SpecialOptions();
            }
        }while(select!=0);
    }

};
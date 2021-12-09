#ifndef LABA3_1_LISTSEQUENCE_H
#define LABA3_1_LISTSEQUENCE_H
#include "Sequence.h"
#include "LinkedList.h"
#pragma once
template <typename T> class ListSequence: public Sequence<T>{
private:
    LinkedList<T>* listSequence;
public:
    ListSequence(){
        listSequence = new LinkedList<T>();
    }
    ListSequence(int size){
        listSequence = new LinkedList<T>(size);
    }
    ListSequence(T* elements, int count){
        listSequence= new LinkedList<T>(elements, count);
    }
    ListSequence(LinkedList<T>& list){
        listSequence = LinkedList<T>(list);
    }
    ListSequence(LinkedList<T>* list){
        listSequence=list;
    }
    ListSequence(ListSequence<T>* list){
        listSequence=list->listSequence;
    }
    ListSequence(ListSequence<T>& list){
        listSequence=list.listSequence;
    }

    void DeleteListSequence(){
        listSequence->DeleteLinkedList();
    }

    T GetF(){
        return listSequence->GetF();
    }
    T GetL(){
        return listSequence->GetL();
    }
    T Get(int index){
        return listSequence->Get(index);
    }

    ListSequence<T>* GetSubSequence(int FirstIndex, int LastIndex){
        ListSequence<T>* NewList;
        NewList->GetSubSequence(FirstIndex,LastIndex);
        auto* listSequence = new ListSequence<T>(NewList);
        return listSequence;
    }

    int GetLength(){
        return listSequence->GetLength();
    }

    void Append(T elem){
        listSequence->Append(elem);
    }
    void Prepend(T elem){
        listSequence->Prepend(elem);
    }
    void Set(int index, T elem){
        listSequence->Set(index,elem);
    }
    void Insert(int index, T elem){
        listSequence->Insert(index, elem);
    }

    ListSequence<T>* Concat(Sequence<T>* list){
        auto* NewLinkedList = new ListSequence<T>(listSequence);
        for(int i=0; i<list->GetLength();i++){
            NewLinkedList->Append(list->Get(i));
        }
        return NewLinkedList;
    }

    T operator[] (int index){
        return listSequence->Get(index);
    }

    void Print_List(){
        cout<<"(";
        for (int i=0; i<listSequence->GetLength(); i++){
            cout<< listSequence->Get(i);
            if (i!=listSequence->GetLength()-1) cout<<"; ";
        }
        cout <<")"<< endl;
    }
};
#endif //LABA3_1_LISTSEQUENCE_H

#ifndef LABA3_1_ARRAYSEQUENCE_H
#define LABA3_1_ARRAYSEQUENCE_H
#include "Sequence.h"
#include "DynamicArray.h"
#include <ctime>
#pragma once

template <typename T> class ArraySequence: public Sequence<T> {
private:
    DynArray<T>* dynArray;
public:
    ArraySequence(){
        dynArray=new DynArray<T>(0);
    }
    ArraySequence(int size){
        dynArray=new DynArray<T>(size);
    }
    ArraySequence(T* elements, int count){
        dynArray=new DynArray<T>(elements,count);
    }
    ArraySequence(ArraySequence<T>* arraySequence){
        this->dynArray=arraySequence->dynArray;
    }
    ArraySequence(ArraySequence<T>& arraySequence){
        this->dynArray=arraySequence.dynArray;
    }
    ArraySequence(DynArray<T>& dynarr){
        dynArray=new DynArray<T>(dynarr);
    }
    ArraySequence(DynArray<T>* dynarr){
        dynArray=dynarr;
    }

    void DeleteArraySequence(){
        dynArray->DeleteDynArray();
    }

    T GetF() override{
        if (this->GetLength()==0){
            throw out_of_range(NO_INDEX1);
        }
        return dynArray->Get(0);
    }

    T GetL() override{
        if (this->GetLength()==0) {
            throw out_of_range(NO_INDEX1);
        }
        return dynArray->Get(dynArray->GetLength()-1);
    }

    T Get(int index) override{
        if(index<0 || index>=this->GetLength()) {
            throw out_of_range(NO_INDEX1);
        }
        return dynArray->Get(index);
    }

    ArraySequence<T>* GetSubSequence(int FirstIndex, int LastIndex) override {
        if (FirstIndex<0 || FirstIndex>=this->GetLength() || LastIndex<0 || LastIndex>=this->GetLength()){
            throw out_of_range(NO_INDEX1);
        }
        ArraySequence<T>* temp = new ArraySequence<T>();
        for (int i=FirstIndex; i<LastIndex; i++){
            temp->Append(this->Get(i));
        }
        return temp;
    }

    int GetLength() override{
        return dynArray->GetLength();
    }

    void Append(T item) override{
        dynArray->Resize(dynArray->GetLength()+1);
        this->Set(dynArray->GetLength()-1,item);
    }

    void Prepend(T item) override{
        dynArray->Resize(dynArray->GetLength()+1);
        DynArray<T>* NewArray = new DynArray<T>(dynArray->GetLength());
        NewArray->Set(0,item);
        for (int i=1; i<dynArray->GetLength();i++){
            NewArray->Set(i, dynArray->Get(i-1));
        }
        dynArray=NewArray;
    }

    void Set(int index,T item){
        if(index<0 || index>dynArray->GetLength()){
            throw out_of_range(NO_INDEX1);
        }
        return dynArray->Set(index,item);
    }

    void Insert(int index, T item) override{
        if(index<0 || index>=dynArray->GetLength()){
            throw out_of_range(NO_INDEX1);
        }
        DynArray<T>* NewArray = new DynArray<T>(dynArray->GetLength()+1);
        for (int i=0; i<index;i++){
            NewArray->Set(i,dynArray->Get(i));
        }
        NewArray->Set(index, item);
        for (int i=index+1; i<=dynArray->GetLength();i++){
            NewArray->Set(i,dynArray->Get(i-1));
        }
        dynArray=NewArray;
    }

    ArraySequence<T>* Concat (Sequence <T>* list) override{
        ArraySequence<T>* NewSequence = new ArraySequence<T>();
        for (int i=0; i<dynArray->GetLength();i++){
            NewSequence->Append(dynArray->Get(i));
        }
        for (int i=0; list->GetLength();i++){
            NewSequence->Append(list->Get(i));
        }
        return NewSequence;
    }

    T operator [] (int index) override{
        return dynArray->Get(index);
    }

};
#endif //LABA3_1_ARRAYSEQUENCE_H

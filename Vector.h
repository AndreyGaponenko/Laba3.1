#ifndef LABA3_1_VECTOR_H
#define LABA3_1_VECTOR_H
#include <iostream>
#include <iomanip>
#include "ArraySequence.h"
#include <stdexcept>
#include <complex>
#pragma once
const string DIFFERENTV="Vectors have different dimensions! ";
template <class T> class Vector{
private:
    ArraySequence<T>* vector;
    int dimension=0;
public:
    Vector(){
        ArraySequence<T>* new_vector;
        vector=new_vector;
        dimension=0;
    }

    Vector(int dim){
        vector=new ArraySequence<T>(dim);
        for (int i=0; i<dim;i++){
            vector->Set(i,0);
        }
        dimension=dim;
    }

    Vector(T* elements, int dim){
        for (int i=0; i<dim; i++){
            vector->Set(i,elements[i]);
        }
        dimension=dim;
    }

    T Get(int index){
        return vector->Get(index);
    }

    int GetDim(){
        return dimension;
    }

    void Set( T elem,int index){
        vector->Set(index, elem);
    }

    void Append(T elem){
        vector->Append(elem);
    }

    void Prepend(T elem){
        vector->Prepend(elem);
    }

    void Delete_Vector(){
        vector->DeleteArraySequence();
    }

    void Print_Vector(){
        cout << "Vector: " << endl;
        cout <<"(";
        for (int i=0; i<dimension; i++){
            cout<< vector->Get(i);
            if (i!=dimension-1) cout<<"; ";
        }
        cout <<")"<< endl;
    }
};
#endif //LABA3_1_VECTOR_H

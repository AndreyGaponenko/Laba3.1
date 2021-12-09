#ifndef LABA3_1_DYNAMICARRAY_H
#define LABA3_1_DYNAMICARRAY_H
#include <string>
#include <sstream>
#pragma once
using namespace std;
const string NO_INDEX1="Such index doesn't exist!";
const string NO_SIZE1="The size can't be less than 0!";

template <typename T>
class DynArray{
private:
    T* data = nullptr;
    int length;
public:
    DynArray(){
        length=0;
    };
    DynArray(int size){
        if (size<0){
            throw length_error(NO_SIZE1);
        }
        data = new T[size];
        this->length=size;
        for (int i=0; i<this->length; i++){
            data[i]=0;
        }
    };
    DynArray(T* elements, int count){
        if (count<0){
            throw length_error(NO_SIZE1);
        };
        data = new T[count];
        length=count;
        for (int i=0; i<count; i++){
            data[i]=elements[i];
        };
    };
    DynArray(DynArray<T> &dynarr){
        length=dynarr.length;
        for (int i=0; i<this->GetLength(); i++){
            data[i]=dynarr.data[i];
        };
    };
    DynArray(DynArray<T>* dynarr){
        length=dynarr->length;
        data=dynarr->data;
    }

    void DeleteDynArray(){
        delete [] data;
        length=0;
    };

    string InterpString(int value){
        ostringstream os;
        os << value;
        return os.str();
    }

    T Get(int index){
        if ((index<0)||(index>=length)){
            string message = NO_INDEX1 + " You want to get " + InterpString(index)+" element, but there are only "+InterpString(length);
            throw out_of_range(message);
        }
        return data[index];
    }

    int GetLength(){
        return length;
    }

    void Set(int index, T value){
        if ((index<0)||(index>=length)){
            string message = NO_INDEX1 + " You want to get " + InterpString(index)+" element, but there are only "+InterpString(length);
            throw out_of_range(message);
        }
        data[index]=value;
    }

    void Resize(int NewSize){
        if (NewSize<0){
            throw out_of_range(NO_INDEX1);
        }
        if (NewSize==0){
            delete [] data;
            length=0;
            return;
        }
        if (NewSize<this->GetLength()){
            T* data2 = new T[NewSize];
            for (int i=0; i<NewSize; i++){
                data2[i]=data[i];
            }
            delete[] data;
            data=data2;
            this->length=NewSize;
            return;
        }else if(NewSize>this->GetLength()){
            T* data2 = new T[NewSize];
            for (int i=0; i<this->GetLength(); i++){
                data2[i]=data[i];
            }
            for (int i=this->GetLength();i<NewSize;i++){
                data2[i]=0;
            }
            delete[] data;
            data=data2;
            length=NewSize;
            return;
        }
    }
    T operator[] (int index){
        if (index<0 || index >= this->length){
            throw out_of_range(NO_INDEX1);
        }
        return this->Get(index);
    }
    T* GetDataFrom(int IndexElemF){
        T* datatemp=new T[this->GetLength()-IndexElemF];
        datatemp=*(data+IndexElemF);
        return datatemp;
    }

    /*void AppendWith0F(T item) {
        this->Resize(this->GetLength()+1);
        *(data+1)=*data;
        this->data[0]=item;
    }

    void Prepend(T item){
        this->Resize(this->GetLength()+1);
        this->data[this->GetLength()-1]=item;
    }

    void Print_DynArray(){
        cout << "Array: " << endl;
        cout <<"(";
        for (int i=0; i<this->GetLength(); i++){
            cout<< this->Get(i);
            if (i!=this->GetLength()-1) cout<<"; ";
        }
        cout <<")"<< endl;
    }*/
};
#endif //LABA3_1_DYNAMICARRAY_H

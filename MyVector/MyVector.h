//
// Created by 邱天 on 2021/10/20.
//

#ifndef MYVECTOR_MYVECTOR_H
#define MYVECTOR_MYVECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class MyVector {
private:
    T *data;        // 数据
    int Size;       // 实际个数
    int Capacity;   // 现有容量
    int id;
    int count = 0;
public:
    MyVector<T>();
    ~MyVector<T>();

    int size();
    int capacity();

    void setId(int num);
    int getId();
    void setCount(int num);
    int getCount();
    T *getData();

    void clear();
    bool empty();
    //void swap(MyVector<T> &v);
    T at(int index);
    void push_back(T v);
    void pop_back();

    void expand();

    T *begin();
    T *end();
    //T front();

    T *erase(T *pos);
    T *insert(T *pos, T val);
    void insert(T *pos, int count, T val);

    void show();
    void showWithoutId();
};

template <typename T>
MyVector<T>::MyVector() {
    Size = 0;
    Capacity = 10;
    data = new T[Capacity];
}

template <typename T>
MyVector<T>::~MyVector() {

}

template <typename T>
int MyVector<T>::size() {
    return Size;
}

template <typename T>
int MyVector<T>::capacity() {
    return Capacity;
}

template <typename T>
void MyVector<T>::setId(int num) {
    id = num;
}

template <typename T>
int MyVector<T>::getId() {
    return id;
}

template <typename T>
void MyVector<T>::setCount(int num) {
    count = num;
}

template <typename T>
int MyVector<T>::getCount() {
    return count;
}

template <typename T>
T * MyVector<T>::getData() {
    return data;
}

template <typename T>
bool MyVector<T>::empty() {
    return (Size == 0);
}

template <typename T>
void MyVector<T>::clear() {
    while(!empty()) {
        pop_back();
    }
}

template <typename T>
T MyVector<T>::at(int index) {
    if(empty() || index > Capacity) {
        return (T)NULL;
    }

    return data[index];
}

template <typename T>
void MyVector<T>::push_back(T v) {
    if(Size >= Capacity) {
        expand();
    }
    data[Size++] = v;
}

template <typename T>
void MyVector<T>::pop_back() {
    if(empty()) {
        return;
    }
    data[Size-1] = (T)NULL;
    --Size;
}

template <typename T>
void MyVector<T>::expand() {
    if(Size > Capacity) {
        Capacity *= 2;
        T *old = this->data;
        data = new T[Capacity];
        for(int i=0; i<Size; i++) {
            data[i] = old[i];
        }
        delete [] old;
    }
}

template <typename T>
T * MyVector<T>::begin() {
    if(!empty()) {
        return data;
    } else {
        return (T*)NULL;
    }
}

template <typename T>
T * MyVector<T>::end() {
    if(!empty()) {
        return data + Size;
    } else {
        return (T*)NULL;
    }
}

template <typename T>
void MyVector<T>::show() {
    cout << id << ". (";
    for(int i=0; i<Size; i++) {
        if(i == Size -1) {
            cout << at(i);
        } else {
            cout << at(i) << ", ";
        }
    }
    cout << ")" << endl;
}

template <typename T>
void MyVector<T>::showWithoutId() {
    cout << "(";
    for(int i=0; i<Size; i++) {
        if(i == Size -1) {
            cout << at(i);
        } else {
            cout << at(i) << ", ";
        }
    }
    cout << ")";
}


#endif //MYVECTOR_MYVECTOR_H

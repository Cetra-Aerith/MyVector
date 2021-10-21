//
// Created by 邱天 on 2021/10/21.
//

#ifndef MYVECTOR_TEST_H
#define MYVECTOR_TEST_H

#include "MyVector.h"

template <typename T>
void createVector(MyVector<MyVector<T>> & VectorPool) {
    MyVector<T> temp;
    temp.setId(VectorPool.getCount() + 1);

    T n;
    while(cin >> n) {
        temp.push_back(n);
        if(cin.get() == '\n') break;
    }

    VectorPool.push_back(temp);
    VectorPool.setCount(VectorPool.size());
}

template <typename T>
void ShowAllVectors(MyVector<MyVector<T>> VectorPool) {
    MyVector<T> *myVector = VectorPool.begin();
    for(int i=0; i<VectorPool.size(); i++,myVector++) {
        myVector->show();
    }
}

template <typename T>
MyVector<T> *SelectVectorById(MyVector<MyVector<T>> VectorPool, int id) {
    MyVector<T> *myVector = VectorPool.begin();
    MyVector<T> *temp;
    for(int i=0; i<VectorPool.size(); i++,myVector++) {
        if(myVector->getId() == id) {
            temp = myVector;
        }
    }
    return temp;
}

template <typename T>
void AddVector(MyVector<MyVector<T>> VectorPool, int num1, int num2) {
    MyVector<T> *temp_1, *temp_2, Vector_Sum;

    temp_1 = SelectVectorById(VectorPool, num1);
    temp_2 = SelectVectorById(VectorPool, num2);

    if(temp_1->size() == temp_2->size()) {
        for(int i=0; i<temp_1->size(); i++) {
            T sum = temp_1->at(i) + temp_2->at(i);
            Vector_Sum.push_back(sum);
        }
    } else {
        cout << "异常需处理" << endl;
    }

    temp_1->showWithoutId();
    cout << " + ";
    temp_2->showWithoutId();
    cout << " = ";
    Vector_Sum.showWithoutId();
    cout << endl;
}

template <typename T>
void ExpandVector(MyVector<T> *myVector) {
    T n;
    while(cin >> n) {
        myVector->push_back(n);
        if(cin.get() == '\n') break;
    }
}

template <typename T>
void ShrinkVector(MyVector<T> *myVector, int dim) {
    for(int i=0; i<dim; i++) {
        myVector->pop_back();
    }
}

#endif //MYVECTOR_TEST_H

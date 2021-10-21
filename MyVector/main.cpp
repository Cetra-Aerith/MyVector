#include "MyVector.h"
#include "Test.h"

int main() {
    cout << "请输入向量的数据类型：" << endl;
    cout << "a. 整型     b. 浮点型" << endl;

    char choice_1;
    cin >> choice_1;

    switch (choice_1) {
        case 'a': {
            MyVector<MyVector<int>> VectorPool;

            while(true) {
                cout << "0. 返回上一级" << endl;
                cout << "1. 添加向量" << endl;
                cout << "2. 显示向量" << endl;
                cout << "3. 修改向量" << endl;
                cout << "4. 删除向量" << endl;
                cout << "5. 向量相加" << endl;
                cout << "6. 向量相减" << endl;
                cout << "7. 向量点乘" << endl;

                int choice_2 = 0;
                cin >> choice_2;
                switch (choice_2) {
                    case 1:{
                        cout << "向量：";
                        createVector(VectorPool);
                        break;
                    }
                    case 2:{
                        ShowAllVectors(VectorPool);
                        break;
                    }
                    case 3:{
                        ShowAllVectors(VectorPool);
                        cout << "请输入要修改向量的序号：";
                        int num;
                        cin >> num;

                        MyVector<int> *myVector = SelectVectorById(VectorPool, num);

                        cout << "a. 扩展维度" << endl;
                        cout << "b. 缩小维度" << endl;
                        cout << "输入您想要执行的操作：";
                        char choice_3;
                        cin >> choice_3;
                        switch (choice_3) {
                            case 'a':{
                                cout << "需要扩展维度的值：";
                                ExpandVector(myVector);
                                cout << "已扩展向量：";
                                myVector->show();
                                cout << endl;
                                break;
                            }
                            case 'b':{
                                cout << "该向量现维度为 " << myVector->size() << " 维" << endl;
                                cout << "需要缩小几个维度: ";
                                int dim;
                                cin >> dim;
                                ShrinkVector(myVector, dim);
                                cout << "已缩小向量：";
                                myVector->show();
                                cout << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case 4:{
                        ShowAllVectors(VectorPool);
                        cout << "请输入想要 删除的向量的序号：" << endl;
                        int num=0;
                        /*while(cin>>num){
                            if(cin.get() =='\n') break;
                            VectorPool.erase(SelectVectorById(VectorPool,num));
                        }*/
                        cin >> num;
                        VectorPool.erase(SelectVectorById(VectorPool, num));
                        break;
                    }
                    case 5:{
                        ShowAllVectors(VectorPool);

                        cout << "请输入相加的两个向量序号：" << endl;
                        int num1, num2;
                        cout << "第一个向量序号：";
                        cin >> num1;
                        cout << "第二个向量序号：";
                        cin >> num2;
                        //维数不同时的异常处理
                        //AddVector(VectorPool, num1, num2);
                        SelectVectorById(VectorPool, num1)->showWithoutId();
                        cout << " + ";
                        SelectVectorById(VectorPool, num2)->showWithoutId();
                        cout << " = ";
                        (*SelectVectorById(VectorPool,num1)+*SelectVectorById(VectorPool,num2)).showWithoutId();
                        cout << endl;
                        break;
                    }
                    case 6:{
                        ShowAllVectors(VectorPool);

                        cout << "请输入相减的两个向量序号：" << endl;
                        int num1, num2;
                        cout << "第一个向量序号：";
                        cin >> num1;
                        cout << "第二个向量序号：";
                        cin >> num2;
                        //维数不同时的异常处理
                        //AddVector(VectorPool, num1, num2);
                        SelectVectorById(VectorPool, num1)->showWithoutId();
                        cout << " - ";
                        SelectVectorById(VectorPool, num2)->showWithoutId();
                        cout << " = ";
                        (*SelectVectorById(VectorPool,num1)-*SelectVectorById(VectorPool,num2)).showWithoutId();
                        cout << endl;
                        break;
                    }
                    case 7:{
                        ShowAllVectors(VectorPool);

                        cout << "请输入点乘的两个向量序号：" << endl;
                        int num1, num2;
                        cout << "第一个向量序号：";
                        cin >> num1;
                        cout << "第二个向量序号：";
                        cin >> num2;
                        //维数不同时的异常处理
                        //AddVector(VectorPool, num1, num2);
                        SelectVectorById(VectorPool, num1)->showWithoutId();
                        cout << " * ";
                        SelectVectorById(VectorPool, num2)->showWithoutId();
                        cout << " = ";
                        *SelectVectorById(VectorPool,num1)**SelectVectorById(VectorPool,num2);
                        cout << endl;
                        break;
                    }
                    case 0:return 0;
                }
               /* if(choice_2 == 1) {
                    cout << "向量：";
                    createVector(VectorPool);
                } else if(choice_2 == 2) {
                    ShowAllVectors(VectorPool);
                } else if(choice_2 == 3) {
                    ShowAllVectors(VectorPool);
                    cout << "请输入要修改向量的序号：";
                    int num;
                    cin >> num;

                    MyVector<int> *myVector = SelectVectorById(VectorPool, num);

                    cout << "a. 扩展维度" << endl;
                    cout << "b. 缩小维度" << endl;
                    cout << "输入您想要执行的操作：";
                    char choice_3;
                    cin >> choice_3;

                    if(choice_3 == 'a') {
                        cout << "需要扩展维度的值：";
                        ExpandVector(myVector);
                        cout << "已扩展向量：";
                        myVector->show();
                        cout << endl;
                    } else if(choice_3 == 'b') {
                        cout << "该向量现维度为 " << myVector->size() << " 维" << endl;
                        cout << "需要缩小几个维度: ";
                        int dim;
                        cin >> dim;
                        ShrinkVector(myVector, dim);
                        cout << "已缩小向量：";
                        myVector->show();
                        cout << endl;
                    }
                } else if(choice_2 == 4) {
                    ShowAllVectors(VectorPool);

                    cout << "请输入相加的两个向量序号：" << endl;
                    int num1, num2;
                    cout << "第一个向量序号：";
                    cin >> num1;
                    cout << "第二个向量序号：";
                    cin >> num2;

                    //AddVector(VectorPool, num1, num2);
                    SelectVectorById(VectorPool, num1)->showWithoutId();
                    cout << " + ";
                    SelectVectorById(VectorPool, num2)->showWithoutId();
                    cout << " = ";
                    (*SelectVectorById(VectorPool,num1)+*SelectVectorById(VectorPool,num2)).showWithoutId();
                    cout << endl;
                }
                else {
                    return 0;
                }*/
            }
        }
        case 'b': {
            cout << "case b" << endl;
        }
    }

    return 0;
}

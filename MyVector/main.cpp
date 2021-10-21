#include "MyVector.h"
#include "Test.h"

int main() {
    cout << "�������������������ͣ�" << endl;
    cout << "a. ����     b. ������" << endl;

    char choice_1;
    cin >> choice_1;

    switch (choice_1) {
        case 'a': {
            MyVector<MyVector<int>> VectorPool;

            while(true) {
                cout << "0. ������һ��" << endl;
                cout << "1. �������" << endl;
                cout << "2. ��ʾ����" << endl;
                cout << "3. �޸�����" << endl;
                cout << "4. ɾ������" << endl;
                cout << "5. �������" << endl;
                cout << "6. �������" << endl;
                cout << "7. �������" << endl;

                int choice_2 = 0;
                cin >> choice_2;
                switch (choice_2) {
                    case 1:{
                        cout << "������";
                        createVector(VectorPool);
                        break;
                    }
                    case 2:{
                        ShowAllVectors(VectorPool);
                        break;
                    }
                    case 3:{
                        ShowAllVectors(VectorPool);
                        cout << "������Ҫ�޸���������ţ�";
                        int num;
                        cin >> num;

                        MyVector<int> *myVector = SelectVectorById(VectorPool, num);

                        cout << "a. ��չά��" << endl;
                        cout << "b. ��Сά��" << endl;
                        cout << "��������Ҫִ�еĲ�����";
                        char choice_3;
                        cin >> choice_3;
                        switch (choice_3) {
                            case 'a':{
                                cout << "��Ҫ��չά�ȵ�ֵ��";
                                ExpandVector(myVector);
                                cout << "����չ������";
                                myVector->show();
                                cout << endl;
                                break;
                            }
                            case 'b':{
                                cout << "��������ά��Ϊ " << myVector->size() << " ά" << endl;
                                cout << "��Ҫ��С����ά��: ";
                                int dim;
                                cin >> dim;
                                ShrinkVector(myVector, dim);
                                cout << "����С������";
                                myVector->show();
                                cout << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case 4:{
                        ShowAllVectors(VectorPool);
                        cout << "��������Ҫ ɾ������������ţ�" << endl;
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

                        cout << "��������ӵ�����������ţ�" << endl;
                        int num1, num2;
                        cout << "��һ��������ţ�";
                        cin >> num1;
                        cout << "�ڶ���������ţ�";
                        cin >> num2;
                        //ά����ͬʱ���쳣����
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

                        cout << "���������������������ţ�" << endl;
                        int num1, num2;
                        cout << "��һ��������ţ�";
                        cin >> num1;
                        cout << "�ڶ���������ţ�";
                        cin >> num2;
                        //ά����ͬʱ���쳣����
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

                        cout << "�������˵�����������ţ�" << endl;
                        int num1, num2;
                        cout << "��һ��������ţ�";
                        cin >> num1;
                        cout << "�ڶ���������ţ�";
                        cin >> num2;
                        //ά����ͬʱ���쳣����
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
                    cout << "������";
                    createVector(VectorPool);
                } else if(choice_2 == 2) {
                    ShowAllVectors(VectorPool);
                } else if(choice_2 == 3) {
                    ShowAllVectors(VectorPool);
                    cout << "������Ҫ�޸���������ţ�";
                    int num;
                    cin >> num;

                    MyVector<int> *myVector = SelectVectorById(VectorPool, num);

                    cout << "a. ��չά��" << endl;
                    cout << "b. ��Сά��" << endl;
                    cout << "��������Ҫִ�еĲ�����";
                    char choice_3;
                    cin >> choice_3;

                    if(choice_3 == 'a') {
                        cout << "��Ҫ��չά�ȵ�ֵ��";
                        ExpandVector(myVector);
                        cout << "����չ������";
                        myVector->show();
                        cout << endl;
                    } else if(choice_3 == 'b') {
                        cout << "��������ά��Ϊ " << myVector->size() << " ά" << endl;
                        cout << "��Ҫ��С����ά��: ";
                        int dim;
                        cin >> dim;
                        ShrinkVector(myVector, dim);
                        cout << "����С������";
                        myVector->show();
                        cout << endl;
                    }
                } else if(choice_2 == 4) {
                    ShowAllVectors(VectorPool);

                    cout << "��������ӵ�����������ţ�" << endl;
                    int num1, num2;
                    cout << "��һ��������ţ�";
                    cin >> num1;
                    cout << "�ڶ���������ţ�";
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

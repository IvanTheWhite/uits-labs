
#include <iostream>
#include <cstdlib>

using namespace std;

//1. ��������� �� ���������

int main()
{
    int a = 5;
    int* p = &a; //��������� �� "a"
    int** pp = &p; //��������� �� "p", ��������� �� ���������

    cout << **pp << endl; //������� 5;

    int b = 8;

    *pp = &b;
    // �������� �������� �����, ���������� � ��������� "p"
    // �� ����� ���������� "b";

    cout << *p << endl; //������� 8;

    return 0;
}


//2. ��������� ������ ��� ������ ����������

int main()
{
    unsigned const int height = 2;
    unsigned const int width = 3;

    int A[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            A[i][j] = rand() % 10;
        }
    }


    //����� ����� ���������    
    for (int i = 0; i < height; i++)
    {
        // ��� ��� A[i] �������� ����������
        // �� ������ ���������� �������,
        // ����� ������������ ���������
        for (int* p = A[i]; p < A[i] + width; p++)
        {
            cout << *p << "\t";
        }

        cout << endl;
    }
    cout << endl;

    //����� ��� ������������� ���������� ������
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // ������, ��� // *(ptr+i) � ptr[i] - ������������
            // A[i][j],
            // ��� ��� A[i] - ��������� �� ������, �����������
            // �� �������� ������:
            // *(A[i]+j)
            // ��� ��� A - ��������� �� ������ �����,
            // ����������� �� �������� �������:
            // *(*(A+i)+j)

            cout << *(*(A + i) + j) << "\t";
        }
        cout << endl;
    }
    return 0;
}

//3. ������������� ����������� ������� ��� ����������

int main()
{

    unsigned const int size = 12;
    unsigned const int height = 3;

    if (size % height != 0)
    {
        cout << "incompatible size and height" << endl;
        return 1;
    }

    int width = size / height;
    int A[size];

    for (int i = 0; i < size; i++)
    {
        A[i] = i+1;
        cout << A[i] << " ";
    }
    cout << endl;

    int* D[height];
    // �� ������ ��������� ������,
    // � ���������� ������ ����������.
    // ������� � int D[height][width] � ���,
    // ��� �� ����������� ������ ��� ������ -
    // ���������, ���������� � ������� ��������� � ������

    for(int i=0; i <height; i++)
    {
        // ��������� ������ A �� height ������ �� width
        // ��������� � ������ � ��������� ������ ���� ������
        // � ������� D
        D[i] = &A[i*width];
    }

    cout << endl;

    //������ ��������� ������ D �������� ��� �������� A
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout<<D[i][j]<<"\t";
        }

        cout << endl;
    }

    cout << endl;

    D[0][1] = -8; // ��������� � D �������� A

    for (int i = 0; i < size; i++)
    {        
        cout << A[i] << " ";
    }

    cout<<endl;

}


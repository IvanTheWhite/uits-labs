#include <iostream>
#include <cstdlib>

using namespace std;

// ���������� ���������� ��������������� ������ �������
const int height = 6;
const int width = 2;

// �������, ����������� ��� �������� ��������� ������
// � ����������� ����� ��� ���������
float sum(float A[height][width])
{
    float sum = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sum+=A[i][j];
        }
    }

    return sum;
}

int main()
{

    // ���������� � ����������� 
    float A[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            A[i][j] = rand()%100/10.;
            cout<<A[i][j]<<" ";
        }

        cout<<endl;
    }

    // ����� ������� � �������� � �� �������, ������ �������
    // ������� ����� �� ���������� ����������
    cout<<sum(A)<<endl;

    system("pause");

    return 0;
}



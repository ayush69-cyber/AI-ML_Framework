#include<iostream>
#include<cmath>
using namespace std;
class matrix
{
    const int row, column;
    int **data;
    public:
    matrix(int r,int c) :row(r),column(c)
    {
        data = new int*[row];
        for(int i = 0 ; i<row ; i++)
        {
            data[i] = new int[column];
        }
    }
    int det()
    {
        if(row == 1 && column == 1)
            return (data[0][0]);
        else if(row == 2 && column == 2)
            return ((data[0][0] * data[1][1]) - (data[1][0]*data[0][1]));
        else if(row == column)
        {
            matrix m(row-1,column-1);
            int result = 0;
            for(int i = 0; i<column ; i++)
            {
                for(int j = 0; j<row-1 ; j++)
                {
                    int c = 0;
                    for(int k = 0 ; k < column ; k++)
                    {
                        if(k!=i)
                        {
                            m.data[j][c] = data[j+1][k];
                            c++;
                        }
                    }
                }
                m.print();
                result += (data[0][i] * m.det() * pow(-1,i));
                cout << "Result" << i << ":" << result << endl;
            }
            return result;
        }
        else
        {
            cout << "Garbage Value Dimension error:" << endl;
            return -1;
        }
    }
    void getinfo()
    {
        cout << "Enter the datas " << endl;
        for(int i = 0 ; i< row ; i++)
        {
            for(int j = 0 ; j< column ; j++)
            {
                cin >> data[i][j];
            }
        }
    }
    void print()
    {
        for(int i = 0 ; i< row ; i++)
        {
            for(int j = 0 ; j< column ; j++)
            {
                cout  << data[i][j] << '\t';
            }
            cout << '\n';
        }
    }

};
int main()
{
    matrix m1(4,4);
    m1.getinfo();
    m1.print();
    cout << m1.det();
    return 0;
}
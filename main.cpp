#include <iostream>

using namespace std;
void rotar90(int matriz[5][5]);
void rotar180(int matriz[5][5]);
void rotar270(int matriz[5][5]);
void punto14();
void crearmatriz(int nums[], int n);
int main()
{
    int n;
    cout<<"ingrese cuantas matrices desea implementar en la cerradura"<<endl;
    cin>>n;
    int cant[n], matriz[n];
    for (int j=0; j<n; j++)
    {
        int num=2;
        while(num%2!=1)
        {
            cout<<"ingrese el tamano del que desea la matriz numero "<<j+1<<": ";
            cin>>num;
        }
        cant[j]=num;
    }
    int* matrices[n];

}

void crearmatriz(int nums[], int n)
{
    int num,num1,val=1;
    num=nums[n];
    num1=num/2;
    int matriz[num][num];
    for(int j=0; j<num; j++)
    {
        for(int i=0; i<num; i++)
        {
            if(j==num1 && i==num1)
            {
                matriz[j][i]=0;
            }
            if(j!=num1 || i!=num1)
            {
                matriz[j][i]=val;
                val+=1;
            }
        }
    }
}

//funciones traidas de la practica de laboratorio 2
void rotar90(int matriz[5][5])
{
    int matrot[5][5];
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            matrot[j][5-1-i]=matriz[i][j];
        }
    }
    cout<<"Matriz rotada 90 grados:"<<endl;
}

void rotar180(int matriz[5][5])
{
    int matrot[5][5];
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            matrot[5-1-i][5-1-j]=matriz[i][j];
        }
    }

    cout<<"Matriz rotada 180 grados:"<<endl;
}

void rotar270(int matriz[5][5])
{
    int matrot[5][5];
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            matrot[5-1-j][i]=matriz[i][j];
        }
    }

    cout<<"Matriz rotada 270 grados:"<<endl;
}

void punto14()
{
    int matriz[5][5];
    int cont=1;
    for (int i=0; i<5; i++)
    {
        for (int j = 0; j<5; j++)
        {
            matriz[i][j]=cont++;
        }
    }
    cout<<"Matriz original:"<<endl;

    rotar90(matriz);

    rotar180(matriz);

    rotar270(matriz);
}

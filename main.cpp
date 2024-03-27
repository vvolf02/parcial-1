#include <iostream>

using namespace std;
void rotar90(int matriz[n][n]);
void rotar180(int matriz[n][n]);
void rotar270(int matriz[n][n]);
void punto14();
int** crearmatriz(int n);
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
    int*** matrices=new int**[n];
    for(int j=0; j<n; j++)
    {
        matrices[j]=crearmatriz(cant, j);
    }
}

int** crearmatriz(int n)
{
    int num,num1,val=1;
    num=n
    num1=num/2;
    int **matriz=new int*[num];
    for(int i=0; i<num; i++)
    {
        matriz[i]=new int[num];
    }
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
    return matriz;
}

//funciones traidas de la practica de laboratorio 2
void rotar90(int matriz[n][n])
{
    int matrot[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            matrot[j][n-1-i]=matriz[i][j];
        }
    }
    cout<<"Matriz rotada 90 grados:"<<endl;
}

void rotar180(int matriz[n][n])
{
    int matrot[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            matrot[n-1-i][n-1-j]=matriz[i][j];
        }
    }

    cout<<"Matriz rotada 180 grados:"<<endl;
}

void rotar270(int matriz[n][n])
{
    int matrot[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            matrot[n-1-j][i]=matriz[i][j];
        }
    }

    cout<<"Matriz rotada 270 grados:"<<endl;
}

void punto14()
{
    int matriz[n][n];
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

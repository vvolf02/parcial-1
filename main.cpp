#include <iostream>

using namespace std;
void rotar90(int **matriz, int n);
int** crearmatriz(int n);
int main()
{
    int n, val=2, num1;
    cout<<"cuantas matrices desea que contenga la cerradura?"<<endl;
    cin>>n;
    int reglas[n+1];
    cout<<"a continuacion, ingrese las reglas para la cerradura"<<endl;
    cout<<"ingrese la fila de la celda de referencia"<<endl;
    cin>>reglas[0];
    num1=reglas[0];
    cout<<"ingrese la columna de la celda de referencia"<<endl;
    cin>>reglas[1];
    if(reglas[1]>reglas[0])
    {
        num1=reglas[1];
    }
    if(num1%2==0)
    {
        num1+=1;
    }
    int p=1;
    for(int i=2; i<=n; i++)
    {
        if(i<=n)
        {
            val=2;
        }
        while (val<-1 || val>1)
        {
            cout<<"ingrese la condicion numero "<<p<<" (-1 para >, 0 para = y 1 para <)"<<endl;
            cin>>val;
        }
        reglas[i]=val;
        p+=1;
    }
    int*** matrices=new int**[n];
    for(int j=0; j<n; j++)
    {
        matrices[j]=crearmatriz(num1);
    }
}

int** crearmatriz(int n)
{
    int num,num1,val=1;
    num=n;
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

void rotar90(int** matriz, int n)
{
    int** matrot=crearmatriz(n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            matrot[j][n-1-i]=matriz[i][j];
        }
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            matriz[i][j]=matrot[i][j];
        }
    }
    for (int i=0; i<n; i++)
    {
        delete[] matrot[i];
    }
    delete[] matrot;
}

/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
void rotar90(int **matriz, int n);
int** crearmatriz(int n);
void casos(int* reglas, int*** matrices, int n, int num1, int fila);

int main()
{
    int n, val=2, num1;
    cout<<"cuantas matrices desea que contenga la cerradura?"<<endl;
    cin>>n;
    int reglas[n+1];

    cout<<"a continuacion, ingrese las reglas para la cerradura."<<endl;
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

    casos(reglas,matrices,0,num1,0);

    val=matrices[0][reglas[0]][reglas[1]];
    int val2=0;
    int fila=reglas[0];
    int columna=reglas[1];

    for(int i=2; i<=n+1;i++ ) //n=son las matrices en total
    {
        int cond=reglas[i]; //Las condiciones 1,-1 ó 0 que aparecenel la relga

        int contador=0, x=0, tamaño=0;
        bool verificador=true, verificador2=true;
        casos(reglas,matrices,i-1,num1-tamaño,fila+x);

        while(verificador = true)//&& verificador2=true)
        {
            if (cond=0)
            {
                matrices[i-1]=matrices[i-2];  //Copiar y pegar, la opción felíz
                verificador=false;
            }

            val2=matrices[i-1][fila+x][columna+x]; // X:disminuye

            if(cond=1 && contador<3)
            {
                if(val>val2)
                {
                    val=val2;
                    verificador=false;
                }

                if(val<val2)
                {
                    rotar90(matrices[i-1], num1+tamaño);
                    contador++;
                }
                if(contador=3)
                {
                    matrices[i-1]=crearmatriz(num1-2);
                    x= x-1;
                    tamaño= tamaño-2;
                    casos(reglas,matrices,i-1,num1-tamaño,fila+x);

                    if(fila+x>num1-2 || columna+x>num1-2 ||num1+tamaño==0)
                    {
                        verificador2=false;
                    }
                    fila=fila+x;
                    columna=columna+x;
                    num1=num1+tamaño;
                }
            }

            if(cond=-1 && contador<3)
            {
                if(val<val2)
                {
                    val=val2;
                    verificador=false;
                }

                if(val>val2)
                {
                    rotar90(matrices[i-1], num1+tamaño);
                    contador++;
                }
                if(contador=3)
                {
                    matrices[i-1]=crearmatriz(num1+2);
                    x= x+1;
                    tamaño= tamaño+2;
                    casos(reglas,matrices,i-1,num1-tamaño,fila+x);

                    if(fila+x>num1+2 || columna+x>num1+2 ||num1+tamaño==0)
                    {
                        verificador2=false;
                    }
                    fila=fila+x;
                    columna=columna+x;
                    num1=num1+tamaño;
                }
            }


        }
        if (verificador2==false)
        {
            i=n+1;
            "La regla no tiene solución";
        }

    }
    //Acá iria la comentacion de que si cumplio todo




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

void casos(int* reglas, int*** matrices, int n, int num1,int fila)
{
    if(reglas[n+1]=1)
    {
        if(fila<=num1/2)
        {
            rotar90(matrices[n], num1);
            rotar90(matrices[n], num1);
        }
    }
    if(reglas[n+1]=-1)
    {
        if(fila>(num1/2)+1)
        {
            rotar90(matrices[n], num1);
            rotar90(matrices[n], num1);
        }
    }
}


void ubicar(int** matriz) {
    cout << "Primera posición de la matriz: " << matriz[0][0] <<endl;
}

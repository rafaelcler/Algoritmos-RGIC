#include <iostream>
#include <stdlib.h>
using namespace std;

class matriz
{

protected:

    int m;
    int n;
    int **mb;

public:
    void CriaMatriz(int m, int n)
    {
        this->m=m;
        this->n=n;
        this->mb=(int**)malloc(m*sizeof(int));

        if(mb==NULL)
        {
            cout<<"Memoria Insuficiente"<<endl;
            exit(1);
        }
        else
        {
            for (int i=0; i<m; i++)
            {
                mb[i]=(int*)malloc(n*sizeof(int));

                if(mb[i]==NULL)
                {
                    cout<<"Memoria Insuficiente"<<endl;
                    exit(1);
                }

            }

            for(int k=0; k<m; k++)
            {
                for(int l=0; l<n; l++)
                {
                    cout<<"\nEntre com o valor= ";
                    cin>>mb[k][l];
                }
            }

        }

    }

void ImprimeMatriz(){

for (int k=0; k<m; k++)
            {
                for(int l=0; l<n; l++)
                {
                    cout<<"\nMatriz= "<<this->mb[k][l]<<endl;
                }
            }
}

};
int main()
{
    matriz t;
    t.CriaMatriz(2,2);
    t.ImprimeMatriz();
    return 0;
}

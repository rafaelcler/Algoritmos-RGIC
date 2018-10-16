#include "Matriz.h"
#include<iostream>

using namespace std;

void matriz::CriaMatriz(int m, int n)
{
    /*Extrutura matriz*/

    this->m=m;
    this->n=n;


    /*Alocando memoria......No trabalho do Rafael a memória erá alocada com malloc que não é do C++,
     portanto, vamos modificar para o New*/
    this->mb=new int*[m];

    for (int k=0; k<m; k++)
    {

        mb[k]=new int[n];
    }

}

void matriz::PreencheMatriz()
{
    /*Preenchendo a Matriz - O preenchimento foi separado da criação da matriz*/
    cout<<"\n**********MATRIZ***********"<<endl;

    for (int k=0; k<m; k++)
    {
        for (int l=0; l<n; l++)
        {
            cout<<"\nEntre com o Valor do elemento=";
            cin>>mb[k][l];
        }
    }


}

void matriz::ImprimeMatriz(){
cout<<"********MATRIZ********"<<endl;
for (int k=0; k<m; k++){
    for (int l=0; l<n; l++){
        cout<<mb[k][l]<<"\t ";
    }
    cout<<endl;
}
}

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    double num;
    struct Node * post;
    struct Node * ant;
};
typedef struct Node node;

class CircularList
{

private:

struct Node * position;


public:

    void CriaCabecalista(){

    node * cabeca = (node*)malloc(sizeof(node));
        if(cabeca==NULL)
        {
            cout<<"\nMemoria insuficiente"<<endl;
            exit(1);
        }
        else
        {
            cabeca->post=cabeca;
            cabeca->ant=cabeca;
            position=cabeca;
    }
    }

    void AdicaodeElLista()
    {

        node * novo=(node*)malloc(sizeof(node));
        if(novo==NULL)
        {
            cout<<"\nMemoria insuficiente"<<endl;
            exit(1);
        }
        else
        {
            node * posterior=position->post;
            novo->post=posterior;
            novo->ant=position;
            posterior->ant=novo;
            position->post=novo;
            position=novo;
        }
        cout<<"\nEntre com o valor do elemento = ";
        cin>>novo->num;

    }

    double PegaValPos()
    {

        return position->num;


    }

    void RemoveNode()
    {
        node * anterior=position->ant;
        node * posterior=position->post;

        cout<<"\nElemento que esta sendo removido = "<<position->num<<endl;

        anterior->post=posterior;
        posterior->ant=anterior;
        node * eleremov=position;
        position=posterior;
        free(eleremov);

    }

    void ApontaPositionProx()
    {
        position=position->post;
    }

    void ApontaPositionAnt()
    {
        position=position->ant;
    }

    void teste(){
    int quantidade;
    double valores;
    cout<<"\nEntre com a quantidade de elementos que se deseja adicionar na lista = ";
    cin>>quantidade;

    while (quantidade!=0){
        AdicaodeElLista();
        quantidade--;

    }
    valores=PegaValPos();
    cout<<"\nO valor do elemento apontado por position = "<<valores<<endl;

    ApontaPositionAnt();
    valores=PegaValPos();
    cout<<"\nO valor do elemento apontado por position = "<<valores<<endl;
    ApontaPositionAnt();
    valores=PegaValPos();
    cout<<"\nO valor do elemento apontado por position = "<<valores<<endl;

    RemoveNode();
    valores=PegaValPos();
    cout<<"\nO valor do elemento apontado por position = "<<valores<<endl;

    ApontaPositionProx();
    valores=PegaValPos();
    cout<<"\nO valor do elemento apontado por position = "<<valores<<endl;
    }

};

int main()
{
CircularList A;
A.CriaCabecalista();
A.teste();


    return 0;
}

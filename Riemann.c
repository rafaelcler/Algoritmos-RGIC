#include<stdlib.h>
#include<math.h>
#include<stdio.h>

struct funcao
{

    int quantidade;
    double* vetgrau;
    double* vetconstante;


};
typedef struct funcao Func;

Func* Criaf()
{
    Func* R = (Func*)malloc(sizeof(Func));
    if(R==NULL)
    {
        printf("A memoria é Insuficiente");
        exit(1);
    }
    printf("\nEntre com a quantidade de elementos que tem a funcao = ");
    scanf("%d",&R->quantidade);
    int cont=R->quantidade;

    R->vetgrau=(double*)malloc(cont*sizeof(double));
    R->vetconstante=(double*)malloc(cont*sizeof(double));

    int i;
    printf("\nA cada elemento da funcao entre primeior com o grau do elemento e depois com a constante que o multiplica");
    for (i=0; i<cont; i++)
    {
        printf("\nGrau = ");
        scanf("%lf",&R->vetgrau[i]);
        printf("\nConstante = ");
        scanf("%lf",&R->vetconstante[i]);
    }

    return R;
}

void Riemann(Func*f,double a, double b, int n)
{
    int i,j;
    double aux;
    double vetx[n+1];
    double vety[n+1];
    /*Calculando o passo*/
    double delta=(b-a)/n;
    /*Formando o vetor de elementos*/
    vetx[0]=a;
    aux=vetx[0];
    for (i=1; i<=n; i++)
    {
        vetx[i]=aux+delta;
        aux=vetx[i];
    }

    /*Aplicando a função no vetor de elementos*/
    for(i=0; i<=n; i++)
    {
        double soma=0.00;
        int cont=f->quantidade;
        for (j=0; j<cont; j++)
        {
            double num=vetx[i];
            double poten=f->vetgrau[j];
            double constante=f->vetconstante[j];
            soma=soma+(pow(num,poten)*constante);
        }
        vety[i]=soma;
    }

    /*Calculando a integral pela direita*/
    double area=0.00;
    for (i=1; i<=n; i++)
    {
        area=area+(delta*vety[i]);
    }
    printf("\nIntegral = %f",area);
}

void main()
{
    Func* F;
    double a,b;
    int n;
    printf("\nEntre com o menor valor do intervalo da integracao = ");
    scanf("%lf",&a);
    printf("\nEntre com o maior valor do intervalo da integracao = ");
    scanf("%lf",&b);
    printf("\nEntre com o numero de particoes = ");
    scanf("%d",&n);

    F=Criaf();
    Riemann(F,a,b,n);

}

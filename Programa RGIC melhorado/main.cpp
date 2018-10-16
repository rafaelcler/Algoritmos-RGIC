#include <iostream>
#include "Matriz.h"
using namespace std;

int main()
{
    matriz M;
    M.CriaMatriz(2,2);
    M.PreencheMatriz();
    M.ImprimeMatriz();
    return 0;
}

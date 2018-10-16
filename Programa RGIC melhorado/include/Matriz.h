#ifndef MATRIZ_H
#define MATRIZ_H


class matriz
{
   private:
    int m;
    int n;
    int **mb;

    public:
        void CriaMatriz(int m, int n);
        void PreencheMatriz();
        void ImprimeMatriz();

};

#endif // MATRIZ_H

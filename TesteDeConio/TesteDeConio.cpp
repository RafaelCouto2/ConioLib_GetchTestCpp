#include <iostream>
#include <conio.h>
#include <stdlib.h>

void mostrar(short **ptr);

int main()
{
    bool retorno = false;
    short trash = 0;
    short** t = new short* [5];

    for (int i = 0; i < 5; i++) {
        t[i] = new short[5];
    }
    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {
            t[l][c] = 0;
        }
    }

    //std::cout << (int) 's' << std::endl;

    t[0][0] = 1;
    short* m = &t[0][0];

    mostrar(t);

    int g = 100;

    while (g != 101) {
        
        g = _getch(); //Retorna, em inteiro e decimal, a tecla precionada.
        
        switch (g) {
        //ESQUERDA PARA A DIREITA
        case 100:
            system("cls");
            for (int l = 0; l < 5; l++) {
                for (int c = 0; c < 5; c++) { 
                    if (&(t[l][c]) == m) {
                        if (t[4][4] == 1) {
                            *m = 0;
                            m = &(t[0][0]);
                            *m = 1;
                        } else if (c == 4 && t[l][c] == 1) {
                            *m = 0;
                            m = &(t[++l][0]);
                            *m = 1;
                        }
                        else {
                            t[l][c + 1] = *m;
                            t[l][c] = trash;
                            m = &(t[l][++c]);
                        }
                    }
                }
            }
            mostrar(t);
            //std::cout << m;
            break;
        case 97:
            //DIREITA PARA A ESQUERDA
            system("cls");
            for (int l = 0; l < 5; l++) {
                for (int c = 0; c < 5; c++) {
                    if (&(t[l][c]) == m) {
                        if (t[0][0] == 1) {
                            retorno = true;
                            *m = 0;
                            m = &(t[4][4]);
                            *m = 1;
                        }
                        else if (c == 0 && t[l][c] == 1) {
                            *m = 0;
                            m = &(t[--l][4]);
                            *m = 1;
                        }
                        else {
                            if (!retorno) {
                                t[l][c - 1] = *m;
                                t[l][c] = trash;
                                m = &(t[l][--c]);
                            }
                        }
                    }
                }
            }
            retorno = false;
            mostrar(t);
            break;

        case 119:
            //BAIXO PARA CIMA
            system("cls");
            for (int l = 0; l < 5; l++) {
                for (int c = 0; c < 5; c++) {
                    if (&(t[l][c]) == m) {
                        if (t[0][c] == 1) {
                            retorno = true;
                            *m = 0;
                            m = &(t[4][c]);
                            *m = 1;
                        }
                        //else if (l == 4 && t[l][c] == 1) {
                        //    *m = 0;
                        //    m = &(t[++l][0]);
                        //    *m = 1;
                        //} //POSSÍVEL ADIÇÃO A DIAGONAL
                        else {
                            if (!retorno) {
                                t[l - 1][c] = *m;
                                t[l][c] = trash;
                                m = &(t[--l][c]);
                            }
                        }
                    }
                }
            }
            retorno = false;
            mostrar(t);
            break;
        case 115:
            //CIMA PARA BAIXO
            system("cls");
            for (int l = 0; l < 5; l++) {
                for (int c = 0; c < 5; c++) {
                    if (&(t[l][c]) == m) {
                        if (t[4][c] == 1) {
                            retorno = true;
                            *m = 0;
                            m = &(t[0][c]);
                            *m = 1;
                        }
                        //else if (c == 4 && t[l][c] == 1) {
                        //    *m = 0;
                        //    m = &(t[++l][0]);
                        //    *m = 1;
                        //} //POSSÍVEL ADIÇÃO A DIAGONAL
                        else {
                            if (!retorno) {
                                t[l + 1][c] = *m;
                                t[l][c] = trash;
                                m = &(t[++l][c]);
                            }
                        }
                    }
                }
            }
            retorno = false;
            mostrar(t);
            break;
        }


        //FIM WHILE
    }

    for (int i = 0; i < 5; i++) {
        delete [] t[i];
    }
    delete [] t;

    return 0;
}

void mostrar(short **ptr) {
    std::cout << "|W - CIMA  |A - ESQUERDA | " << "\n" <<
        "|S - BAIXO |D - DIREITA  |" << std::endl;
    for (int l = 0; l < 5; l++) {
        std::cout << "      |";
        for (int c = 0; c < 5; c++) {
            std::cout << ptr[l][c];
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl; 
}

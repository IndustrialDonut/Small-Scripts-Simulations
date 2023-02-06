
#include <iostream>
#include <random>
#include <cmath>
#include <Windows.h>

#define SIZE 15

double TU = 1.5;

int s[SIZE][SIZE];

void init()
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (distribution(generator) < 0.5)
                s[i][j] = 1;
            else
                s[i][j] = -1;
        }
    }
}

double deltaU(int i, int j)
{
    int top, bottom, left, right;

    if (i == 0)
        top = s[SIZE - 1][j];
    else
        top = s[i - 1][j];

    if (i == SIZE - 1)
        bottom = s[0][j];
    else
        bottom = s[i + 1][j];

    if (j == 0)
        left = s[i][SIZE - 1];
    else
        left = s[i][j - 1];

    if (j == SIZE - 1)
        right = s[i][0];
    else
        right = s[i][j + 1];

    return (s[i][j] * 2 * (top + bottom + right + left));
}

void gotoxy(short x, short y) {
#ifdef _WIN32
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("%c[%d;%df", 0x1B, y, x);
#endif
}

void colorsquares()
{
    /*
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (s[i][j] > 0)
                std::cout << char(24);
            else
                std::cout << char(25);
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;
    */
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (s[i][j] > 0)
                std::cout << char(24);
            else
                std::cout << char(254);
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    init();
    std::cout << "-- INITIAL STATE --" << std::endl;
    colorsquares();


    std::default_random_engine generator;
    std::uniform_int_distribution<int> int_distribution(0 , 9);
    std::uniform_real_distribution<double> real_distribution(0.0, 1.0);

    for (int c = 0; c < 100 * SIZE * SIZE; c++) // main loop
    {
        int i = int_distribution(generator);
        int j = int_distribution(generator);

        double DU = deltaU(i, j);

        if (DU <= 0.0)
            s[i][j] = -s[i][j];       
        else if (real_distribution(generator) < std::exp(-DU / TU))
            s[i][j] = -s[i][j];
    }

    std::cout << "-- FINAL STATE --" << std::endl;
    colorsquares();


    // printing to confirm random generators are uniform, not gaussian
    std::cout << std::endl;
    std::cout << std::endl;
    double avg = 0;
    for (int i = 0; i < 1000; i++)
    {
        avg += int_distribution(generator);
    }
    avg /= 1000;
    //std::cout << avg;
    avg = 0;

    std::cout << std::endl;
    
    for (int i = 0; i < 1000; i++)
    {
        avg += real_distribution(generator);
    }
    avg /= 1000;
    //std::cout << avg;
    std::cin.get();
}


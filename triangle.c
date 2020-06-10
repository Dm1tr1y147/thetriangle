#include <stdio.h>

void drawLine(int freeSpace, int length, char symbol);

int main()
{
    int height;
    scanf("%d\n", &height);
    char symbol1, symbol2;
    scanf("%c %c", &symbol1, &symbol2);

    for (int i = 0; i < height; i++)
    {
        char curSymbol;
        if ((i + 1) % 2 == 1) {
            curSymbol = symbol1;
        } else {
            curSymbol = symbol2;
        }
        drawLine(height - i - 1, i * 2 + 1, curSymbol);
    }

    return 0;
}

void drawLine(int freeSpace, int length, char symbol)
{
    for (int i = 0; i < freeSpace; i++)
    {
        putchar(' ');
    }
    for (int i = 0; i < length; i++)
    {
        putchar(symbol);
    }
    putchar('\n');
}
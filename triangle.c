#include <stdio.h>

void drawLine(int freeSpace, int length, char symbol);

int main()
{
    int height;
    scanf("%d\n", &height);
    char symbol;
    scanf("%c", &symbol);

    for (int i = 0; i < height; i++)
    {
        drawLine(height - i - 1, i * 2 + 1, symbol);
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
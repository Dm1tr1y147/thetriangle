#include <stdio.h>
#include <string.h>

void clrscr();
void drawTriangle(char *type, int height, char symbol1, char symbol2);
void drawLine(int freeSpace, int length, char symbol);

int main()
{
    while (1)
    {
        clrscr();
        printf("\n\n");
        printf("  *   Welcom to The Triangle programm.\n");
        printf(" ***  It would help you to draw some simple, but beautiful triangles.\n");
        printf("***** Hope you'll enjoy using it!\n");
        printf("\n\n");

        sleep(2);

        clrscr();
        printf("\n\n");
        printf("Select what mode do you want to work with:\n");

        drawTriangle("so", 5, '*', '0');
        printf("(so)lid\n");

        drawTriangle("st", 5, '*', '+');
        printf("(st)ripped\n");

        char type[2];
        fgets(type, 2, stdin);
    }

    return 0;
}

void clrscr()
{
    printf("\e[1;1H\e[2J");
}

void drawTriangle(char *type, int height, char symbol1, char symbol2)
{
    if (!(strncmp(type, "so", 2)))
    {
        symbol2 = symbol1;
    }
    else if (!(strncmp(type, "st", 2)))
    {
    }
    else
    {
        printf("Wrong input, try angain");
    }

    for (int i = 0; i < height; i++)
    {
        char curSymbol;
        if ((i + 1) % 2 == 1)
        {
            curSymbol = symbol1;
        }
        else
        {
            curSymbol = symbol2;
        }
        drawLine(height - i - 1, i * 2 + 1, curSymbol);
    }
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
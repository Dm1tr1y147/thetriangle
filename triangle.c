#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void clrscr();
bool strcomp(char *a, char *b);
void swap(char *a, char *b);
void drawTriangle(char type[3], int height, char symbol1, char symbol2);
void drawRomb(char type[3], int height, char symbol1, char symbol2);
void drawLine(int freeSpace, int length, char symbol);
void getTriangleOptions(char *type);

int main()
{
    /*
        Header
    */
    clrscr();
    printf("\n\n");
    printf("  *   Welcom to The Triangle programm.\n");
    printf(" ***  It would help you to draw some simple, but beautiful triangles.\n");
    printf("***** Hope you'll enjoy using it!\n");
    printf("\n\n");

    sleep(2);

    clrscr();

    /*
        Preview
    */
    drawTriangle("so", 5, '*', '\0');
    printf("(so)lid\n");

    drawTriangle("st", 5, '*', '+');
    printf("(st)ripped\n");

    /*
        Configuration
    */
    printf("Select what mode do you want to work with: ");

    // Type
    char type[3];
    fgets(type, 3, stdin);

    printf("%s. Great choise!\n", (strcomp(type, "so") ? "Solid" : "Stripped"));

    // Height
    int height;
    printf("Height of triangle: ");
    scanf("%d", &height);
    getchar();

    // Primary symbol
    char symbol1;
    printf("Primary symbol: ");
    symbol1 = getchar();
    getchar();

    // Secondary symbol
    char symbol2;
    if (strcomp(type, "st"))
    {
        printf("Secondary symbol: ");
        symbol2 = getchar();
        getchar();
    }

    // Romb
    bool romb;
    printf("Make a romb? (y/n): ");
    romb = getchar() == 'y';

    /*
        Drawing
    */
    if (romb)
    {
        drawRomb(type, height, symbol1, symbol2);
    }
    else
    {
        drawTriangle(type, height, symbol1, symbol2);
    }

    return 0;
}

void clrscr()
{
    printf("\e[1;1H\e[2J");
}

bool strcomp(char *a, char *b)
{
    int i = 0;
    while (a[i] != '\0' && a[i] != '\n')
    {
        if (a[i] != b[i])
            return false;
        i++;
    }
    if (a[i] != '\0' || b[i] != '\0')
        return false;
    return true;
}

void swap(char *a, char *b)
{
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void drawTriangle(char type[3], int height, char symbol1, char symbol2)
{
    if (strcomp(type, "so"))
    {
        symbol2 = symbol1;
    }
    else if (strcomp(type, "st"))
    {
    }
    else
    {
        printf("Wrong input, try angain\n");
        return;
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

void drawRomb(char type[3], int height, char symbol1, char symbol2)
{
    if (strcomp(type, "so"))
    {
        symbol2 = symbol1;
    }
    else if (strcomp(type, "st"))
    {
    }
    else
    {
        printf("Wrong input, try angain\n");
        return;
    }

    for (int i = 0; i < height / 2; i++)
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
        drawLine(height / 2 - i, i * 2 + 1, curSymbol);
    }

    if (height % 2 == 0)
        swap(&symbol1, &symbol2);

    for (int i = height - (height / 2 + 1); i >= 0; i--)
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
        drawLine(height / 2 - i, i * 2 + 1, curSymbol);
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

void getTriangleOptions(char *type)
{
    printf("");
}
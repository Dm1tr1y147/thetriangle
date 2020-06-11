#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct
{
    char type[3];
    unsigned height;
    char symbol1, symbol2;
    bool romb;
} triangle;

void clrscr();
bool strcomp(char *a, char *b);
void swap(char *a, char *b);
void drawTriangle(triangle tr);
void drawRomb(triangle tr);
void drawLine(int freeSpace, int length, char symbol);
triangle getTriangleOptions(triangle tr);

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

    // sleep(2); disabled while development

    clrscr();

    /*
        Preview
    */
    triangle solid;
    strcpy(solid.type, "so");
    solid.height = 5;
    solid.symbol1 = '*';
    drawTriangle(solid);
    printf("(so)lid\n");

    triangle stripped;
    strcpy(stripped.type, "st");
    stripped.height = 5;
    stripped.symbol1 = '*';
    stripped.symbol2 = '+';
    drawTriangle(stripped);
    printf("(st)ripped\n");

    /*
        Configuration
    */
    printf("Select what mode do you want to work with: ");

    triangle tr;

    // Type
    fgets(tr.type, 3, stdin);

    printf("%s. Great choise!\n", (strcomp(tr.type, "so") ? "Solid" : "Stripped"));

    /*
        Drawing
    */
    if (tr.romb)
    {
        drawRomb(tr);
    }
    else
    {
        drawTriangle(tr);
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

void drawTriangle(triangle tr)
{
    if (strcomp(tr.type, "so"))
    {
        tr.symbol2 = tr.symbol1;
    }
    else if (strcomp(tr.type, "st"))
    {
    }
    else
    {
        printf("Wrong input, try angain\n");
        return;
    }

    for (int i = 0; i < tr.height; i++)
    {
        char curSymbol;
        if ((i + 1) % 2 == 1)
        {
            curSymbol = tr.symbol1;
        }
        else
        {
            curSymbol = tr.symbol2;
        }
        drawLine(tr.height - i - 1, i * 2 + 1, curSymbol);
    }
}

void drawRomb(triangle tr)
{
    if (strcomp(tr.type, "so"))
    {
        tr.symbol2 = tr.symbol1;
    }
    else if (strcomp(tr.type, "st"))
    {
    }
    else
    {
        printf("Wrong input, try angain\n");
        return;
    }

    for (int i = 0; i < tr.height / 2; i++)
    {
        char curSymbol;
        if ((i + 1) % 2 == 1)
        {
            curSymbol = tr.symbol1;
        }
        else
        {
            curSymbol = tr.symbol2;
        }
        drawLine(tr.height / 2 - i, i * 2 + 1, curSymbol);
    }

    if (tr.height % 2 == 0)
        swap(&tr.symbol1, &tr.symbol2);

    for (int i = tr.height - (tr.height / 2 + 1); i >= 0; i--)
    {
        char curSymbol;
        if ((i + 1) % 2 == 1)
        {
            curSymbol = tr.symbol1;
        }
        else
        {
            curSymbol = tr.symbol2;
        }
        drawLine(tr.height / 2 - i, i * 2 + 1, curSymbol);
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

triangle getTriangleOptions(triangle tr)
{
    // Height
    printf("Height of triangle: ");
    scanf("%d", &tr.height);
    getchar();

    // Primary symbol
    printf("Primary symbol: ");
    tr.symbol1 = getchar();
    getchar();

    // Secondary symbol
    if (strcomp(tr.type, "st"))
    {
        printf("Secondary symbol: ");
        tr.symbol2 = getchar();
        getchar();
    }

    // Romb
    printf("Make a romb? (y/n): ");
    tr.romb = getchar() == 'y';

    return tr;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct
{
    char type[3];
    int height;
    char symbol1, symbol2;
    bool romb;
} triangle;

void clrscr();
bool strcomp(char *a, char *b);
void swap(char *a, char *b);
void drawTriangle(triangle tr);
void drawFlippedTriangle(triangle tr);
char curSymbol(char symbol1, char symbol2, int i);
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
    triangle solid = {
        .type = "so",
        .height = 5,
        .symbol1 = '*',
        .romb = false};
    drawTriangle(solid);
    printf("(so)lid\n");

    triangle stripped = {
        .type = "st",
        .height = 5,
        .symbol1 = '*',
        .symbol2 = '+',
        .romb = false};
    drawTriangle(stripped);
    printf("(st)ripped\n");

    /*
        Configuration
    */
    triangle tr;

    tr = getTriangleOptions(tr);

    /*
        Drawing
    */
    drawTriangle(tr);

    if (tr.romb)
        drawFlippedTriangle(tr);

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
        tr.symbol2 = tr.symbol1;

    if (tr.romb)
    {
        tr.height /= 2;
        tr.height++;
    }

    for (int i = 0; i < tr.height; i++)
        drawLine(tr.height - i - 1, i * 2 + 1, curSymbol(tr.symbol1, tr.symbol2, i));
}

void drawFlippedTriangle(triangle tr)
{
    if (strcomp(tr.type, "so"))
        tr.symbol2 = tr.symbol1;

    for (int i = tr.height - (tr.height / 2 + 1); i >= 0; i--)
        drawLine(tr.height / 2 - i, i * 2 + 1, curSymbol(tr.symbol1, tr.symbol2, i));
}

char curSymbol(char symbol1, char symbol2, int i)
{
    if ((i + 1) % 2 == 1)
        return symbol1;
    else
        return symbol2;
}

void drawLine(int freeSpace, int length, char symbol)
{
    for (int i = 0; i < freeSpace; i++)
        putchar(' ');

    for (int i = 0; i < length; i++)
        putchar(symbol);

    putchar('\n');
}

triangle getTriangleOptions(triangle tr)
{
    // Type
    printf("Select what mode do you want to work with: ");
    fgets(tr.type, 3, stdin);
    printf("%s. Great choise!\n", (strcomp(tr.type, "so") ? "Solid" : "Stripped"));

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
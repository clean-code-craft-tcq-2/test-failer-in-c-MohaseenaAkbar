#include <stdio.h>
#include <assert.h>

int Format_Colour(const char**,const char**);
void Print_Colour(int,int,const char** ,const char** );
void Print_Colour_Test(int,int,const char** ,const char** );

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int ColorMapArray_size = Format_Colour(majorColor,minorColor);
    return ColorMapArray_size;
 }
int Format_Colour(const char** majorColor,const char** minorColor)
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
        Print_Colour(i,j,majorColor,minorColor);
        }
    }
    return i * j;
}

int PairNumber;
void Print_Colour(int i,int j,const char** majorColor,const char** minorColor)
{
    PairNumber= i * 5 + j;
    printf("%d | %s | %s\n",PairNumber, majorColor[i], minorColor[i]);
}
 
void Print_Colour_Test(int i,int j,const char** majorColor,const char** minorColor)
{
    printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(PairNumber==25);
    printf("All is well (maybe!)\n");
    return 0;
}

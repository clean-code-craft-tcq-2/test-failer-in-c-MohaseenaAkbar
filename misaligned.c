#include <stdio.h>
#include <assert.h>

int Format_Colour(const char*,const char*);
void Print_Colour(int,const char* ,const char* );
int PairNumber;

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int ColorMapArray_size = Format_Colour(*majorColor,*minorColor);
    return ColorMapArray_size;
 }
int Format_Colour(const char* majorColor,const char* minorColor)
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
        PairNumber= i * 5 + j;
        Print_Colour(PairNumber,majorColor,minorColor);
        }
    }
    return i * j;
}

void Print_Colour(int PairNumber,const char* majorColor,const char* minorColor)
{
    printf("%d | %s | %s\n",PairNumber, majorColor, minorColor);
} 

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(PairNumber==25);
    printf("All is well (maybe!)\n");
    return 0;
}

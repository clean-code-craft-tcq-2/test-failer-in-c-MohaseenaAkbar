#include <stdio.h>
#include <assert.h>

int Format_Colour(const char**,const char**,void (*P)(int,const char*,const char*));
void Print_Colour(int,const char* ,const char* );
int PairNumber;

int printColorMap(int (*Format_Colour_Test)(const char**,const char**,void (*p)(int,const char*,const char*)),void (*Print_Colour_Test)(int,const char*,const char*)) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int ColorMapArray_size = (*Format_Colour_Test)(majorColor,minorColor,Print_Colour_Test);
    return ColorMapArray_size;
 }
int Format_Colour(const char** majorColor,const char** minorColor,void (*Print_Colour_Test)(int,const char*,const char*))
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
        PairNumber= i * 5 + j + 1;
        Print_Colour(PairNumber,majorColor[i],minorColor[j]);
        }
    }
    return i * j;
}

void Print_Colour(int PairNumber,const char* majorColor,const char* minorColor)
{
    printf("%d | %s | %s\n",PairNumber, majorColor, minorColor);
} 

int main() {
    int (*Format_Colour_Test)(const char**,const char**,void (*p)(int,const char*,const char*))=Format_Colour;
    void (*Print_Colour_Test)(int,const char*,const char*)=Print_Colour;
    int result = printColorMap(Format_Colour_Test,Print_Colour_Test);
    assert(result == 25);
    assert(PairNumber==25);
    printf("All is well (maybe!)\n");
    return 0;
}

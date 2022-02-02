#include <stdio.h>
#include <assert.h>

int FormatColourMap(const char**,const char**);
void PrintColourMap(int,int,const char** ,const char** )
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int ColorMapArray_size = FormatColourMap(majorColor,minorColor);
    return ColorMapArray_size;
 }
int FormatColourMap(const char** majorColor,const char** minorColor)
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
        PrintColourMap(i,j,majorColor,minorColor);
        }
    }
    return i * j;
}

void PrintColourMap(int i,int j,const char** majorColor,const char** minorColor)
{
    printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
}
    
int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

unsigned int my_rand()
{
    static unsigned int seed = 1;

    seed = (48271 * (long long int)seed) % 0x7fffffff;
    return seed;
}

int main(int argc, char *argv[]) 
{
    char str[255];
    fgets(str, sizeof(str), stdin);
    int n = atoi(str);

    int c = 0;
    for(int i = 0; i < n; i++){
        unsigned int ix = my_rand() & 0x3fffffff | 0x3f800000;
        unsigned int iy = my_rand() & 0x3fffffff | 0x3f800000;
        float x = *(float*)&ix;
        float y = *(float*)&iy;
        x = 2.0f * x - 3.0f;
        y = 2.0f * y - 3.0f;
        float dist = x * x + y * y;
        if(dist < 1.0f) c++;
    }
    
    printf("%f\n", (float)(4*c)/(float)n);

    return 0;
}

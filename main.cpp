#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {

    uint32_t x, y;
    uint32_t hx, hy;
    uint32_t plus;

    FILE* f1;
    FILE* f2;

    f1 = fopen(argv[1], "rb");
    f2 = fopen(argv[2], "rb");

    fread(&x, sizeof(uint32_t), 1, f1);
    fread(&y, sizeof(uint32_t), 1, f2);

    hx = ntohl(x);
    hy = ntohl(y);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", hx, hx, hy, hy, hx+hy, hx+hy);

    fclose(f1);
    fclose(f2);
}
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

int getFileSize(FILE* file)
{
    int currentPosition = ftell(file);
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, currentPosition, SEEK_SET);
    return fileSize;
}
int main(int argc, char* argv[]) {

    uint32_t x, y;
    uint32_t hx, hy;

    FILE* f1;
    FILE* f2;

    f1 = fopen(argv[1], "rb");
    f2 = fopen(argv[2], "rb");

    if(f1==NULL || f2==NULL){
        fprintf(stderr,"file open errer ocurred!");
        return 0;
    }
    int size1 = getFileSize(f1), size2 = getFileSize(f2);
    if(size1<4 || size2<4){
        fprintf(stderr,"file size below 4 bytes!");
        return 0;
    }

    fread(&x, sizeof(uint32_t), 1, f1);
    fread(&y, sizeof(uint32_t), 1, f2);

    hx = ntohl(x);
    hy = ntohl(y);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", hx, hx, hy, hy, hx+hy, hx+hy);

    fclose(f1);
    fclose(f2);

    return 0;
}
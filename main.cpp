#include<stdio.h> // for printf
#include<stdint.h> // for uint32_t
#include <netinet/in.h> // for ntohl

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("usage: ./add-nbo <file1> <file2>\n");
        return 1;
    }

    FILE *f1, *f2;
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");
    if (f1 == NULL || f2 == NULL) {
        printf("failed to open file\n");
        return 1;
    }

    // add 32bit number
    uint32_t num1, num2;
    fread(&num1, sizeof(uint32_t), 1, f1);
    fread(&num2, sizeof(uint32_t), 1, f2);

    num1 = ntohl(num1);
    num2 = ntohl(num2);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", 
            num1, num1, num2, num2, num1 + num2, num1 + num2);

    fclose(f1);
    fclose(f2);

    return 0;
}


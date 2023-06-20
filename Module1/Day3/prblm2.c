#include <stdio.h>

void printBits(unsigned int num) {
    int i;
    unsigned int mask = 1 << 31; // Start with the leftmost bit

    for (i = 0; i < 32; i++) {
        // Print current bit (0 or 1)
        printf("%d", (num & mask) ? 1 : 0);

        // Shift the mask to the right
        mask >>= 1;
    }
}

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);
    printf("Bits: ");
    printBits(num);
    printf("\n");
    return 0;
}

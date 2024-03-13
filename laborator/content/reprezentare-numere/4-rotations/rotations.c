#include <stdio.h>

void printBits(unsigned int num) {
    // Size of unsigned int in bits
    int size = sizeof(unsigned int) * 8;
    
    // Iterate over each bit from left to right
    for (int i = size - 1; i >= 0; i--) {
        // Bitwise shift to check each bit
        int bit = (num >> i) & 1;
        // Print the bit
        printf("%d", bit);
        
        // Add space for better readability
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}
void rotate_left(unsigned int *number, int bits)
{
	unsigned int bit_mask = -1;
    printBits(bit_mask);
	bit_mask <<= (sizeof(*number) * 8 - bits);
    printBits(bit_mask);
	bit_mask &= (*number);
    printBits(bit_mask);
	bit_mask >>= (sizeof(*number) * 8 - bits);
    printBits(bit_mask);
    printf("\n");
    printBits(*number);
	(*number) <<= bits;
    printBits(*number);
	(*number) |= bit_mask;
    printBits(*number);
}

void rotate_right(unsigned int *number, int bits)
{
    /* TODO */
    (void)number;
    (void)bits;
}

int main(void)
{
    /* TODO: Test functions */
    unsigned int number = 604;
    rotate_left(&number, 30);
    printf("%u\n",number);
    return 0;
}


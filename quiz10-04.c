/** quiz10-04.c
* ===========================================================
*    Name: 
* Section:
* Purpose: Quiz 10
* ===========================================================
*/

#include <stdio.h>
#include <stdint.h>

/** ----------------------------------------------------------
 * @fn void print_bits(void* ptr, int num_bytes)
 * @brief prints char representation of any variables individual bits
 * @param ptr is a pointer to the variable being printed
 * @param num_bytes is the number of bytes in the variable
 * @return void, prints each bit as a character, ends with a new line
 * ----------------------------------------------------------
 */
void print_bits(void* ptr, int num_bytes) {
    // Cast the pointer as an unsigned byte
    uint8_t* byte = ptr;

    // For each byte, (bytes are little endian ordered)
    for (int i = num_bytes - 1; i >= 0; --i) {

        // For each bit, (inside the byte, bits are big endian ordered)
        for (int j = 7; j >= 0; --j) {

            // Print a character 1 or 0, given the bit value
            printf("%c", (byte[i] >> j) & 1 ? '1' : '0');
        }
        
        // Separate bytes
        printf(" ");
    }

    // End with a new line
    printf("\n");
}

// YOUR FUNCTION WILL GO HERE


int main(void){

    int result = 0;
    int testValue = 17;
    int bitToChange = 1;
    int newBitValue = 1;

    result = setBit(testValue, bitToChange, newBitValue);
    printf("You called setBit(%d, %d, %d)\n", testValue, bitToChange, newBitValue);
    printf("Original Value in Bits:  ");
    print_bits(&testValue, 4);
    printf("New Value in Bits:       ");
    print_bits(&result, 4);

    return 0;

}
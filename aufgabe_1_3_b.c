#include <stdio.h>
// Call with: ./aufgabe_1_3_a | ./aufgabe_1_3_b
int main(void) {
    int count_A = 0;
    int count_B = 0;
    int count_C = 0;
    while (1) {
        if ((count_A + count_B + count_C) % 100000 == 0) {
            fprintf(stdout, "As: %i, Bs: %i, Cs: %i \n", count_A, count_B, count_C);
            fflush(stdout);
        }
        char val = getchar();
        switch (val) {
            case 'A':
                count_A++;
                break;
            case 'B':
                count_B++;
                break;
            case 'C':
                count_C++;
                break;
            default:
                break;
        }
    }
}
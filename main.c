#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Allocate space for exactly two doubles on the heap
    double *register_ptr = (double *)malloc(2 * sizeof(double));

    if (register_ptr == NULL) return 1;

    // Initialize both slots to 0.0
    *(register_ptr + 0) = 0.0; // The Older value
    *(register_ptr + 1) = 0.0; // The Newer value

    char input[32];
    double temp_val;

    printf("2-Slot RPN (Type a number or +, -, *, /)\n");

    while (scanf("%s", input) == 1) {
        // Check if input is an operator
        if (isdigit(input[0]) || (input[0] == '-' && isdigit(input[1]))){
            *(register_ptr + 0) = *(register_ptr + 1);
            *(register_ptr + 1) = atof(input);
        }

        else {
            // Make a case for each of the 4 possible operators
            switch (input[0]) {
                case '+':
                    temp_val = *(register_ptr + 0) + *(register_ptr + 1);
                    break;
                case '-':
                    temp_val = *(register_ptr + 0) - *(register_ptr + 1);
                    break;
                case '*':
                    if (*(register_ptr + 1) == -0.0) {
                        *(register_ptr + 1) = 0.0;
                    }
                    temp_val = *(register_ptr + 0) * *(register_ptr + 1);
                    break;
                case '/':
                    if (*(register_ptr + 1) == 0) {
                        printf("ERR: DIV BY 0\n");
                        continue;
                    }
                    temp_val = *(register_ptr + 0) / *(register_ptr + 1);
                    break;
            }

            // Memmove: Destination -> Source, check size of next chunk
            memmove(&register_ptr[0], &register_ptr[1], (1) * sizeof(register_ptr[0]));
            register_ptr[1] = temp_val;
        }

        // Print the last input.
        // This will display the most recent number like a normal calculator would.
        printf("%.2f\n", register_ptr[1]);
        printf("Current State: [%.2f, %.2f]\n", register_ptr[0], register_ptr[1]);
    }

    // Clean up
    free(register_ptr);
    register_ptr = NULL;

    return 0;
}

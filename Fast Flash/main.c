#include "fastflash.h"

int main() {
    // Seed random number generator for dice_roll, coin_toss, and random_range
    srand((unsigned int)time(NULL));

    char input[512];

    printf("====================================================\n");
    printf("        FAST FLASH LANG (Compiler / REPL)           \n");
    printf("        Instant Task Execution Engine (100 Funcs)   \n");
    printf("====================================================\n");
    printf("Type commands directly (e.g., 'add 200, 50', 'c2f 37', 'bmi 70, 1.75')\n");
    printf("Type 'help' to view all 100 functions | Type 'exit' to quit.\n\n");

    while (1) {
        printf("Flash> ");
        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        // Check for quit/exit command
        char check[16];
        if (sscanf(input, "%15s", check) == 1) {
            if (strcmp(check, "exit") == 0 || strcmp(check, "quit") == 0) {
                printf("Terminating Fast Flash Lang. Goodbye!\n");
                break;
            }
        }

        // Execute command instantly
        ff_execute(input);
    }

    return 0;
}

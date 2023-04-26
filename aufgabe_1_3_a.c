#include <stdio.h>
#include <unistd.h>

void child_A_proc() {
    while (1) {
        fprintf(stdout, "%s", "A");
        fflush(stdout);
    }
}
void child_C_proc() {
    while (1) {
        fprintf(stdout, "%s", "C");
        fflush(stdout);
    }
}
void parent_proc() {
    while (1) {
        fprintf(stdout, "%s", "B");
        fflush(stdout);
    }
}

int main(void) {
    int child_A;
    int child_C;
    child_A = fork();   /* neuen Prozess starten                          */
    if (child_A == 0)   /* Bin ich der Sohnprozess?                       */
        child_A_proc(); /* ... dann child-Funktion ausfuehren             */
    else {
        child_C = fork();
        if (child_C == 0) {
            child_C_proc();
        } else
            parent_proc(); /* ... sonst parent-Funktion ausfuehren           */
    }

    return 0;
}

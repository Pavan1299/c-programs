#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ep[30], stack[30], arr[30], temp[30];
int i, k = 0, j, l, r, s;

void push(char ep[]) {
    arr[i] = ep[k];
    i++;
}

void dispinp() {
    printf("\t\t\t");
    for (k = 0; k < strlen(ep); k++)
        printf("%c", ep[k]);
    printf("$");
}

void dispstk() {
    printf("\n");
    for (k = 0; k < strlen(stack); k++)
        printf("%c", stack[k]);
}

void assign() {
    stack[++j] = arr[i];
    ep[i] = ' ';
    dispstk();
    dispinp();
}

int main(void) {
    printf("SHIFT REDUCE PARSER\n");
    printf("The Production is: E->E+E/E*E/E-E/i\n");
    printf("Enter the string to be parsed:\n");
    gets(ep);
    printf("\nSTACK\t\t\tINPUT\t\t\tACTION\n");
    printf("\n$");
    dispinp();
    printf("\t\t\tShift");
    for (k = 0; k < strlen(ep); k++)
        push(ep);
    l = strlen(ep);
    stack[0] = '$';
    for (i = 0; i < l; i++) {
        switch (arr[i]) {
            case 'i':
                assign();
                printf("\t\t\tReduce by E->i");
                stack[j] = 'E';
                dispstk();
                dispinp();
                if (arr[i + 1] != '\0')
                    printf("\t\t\tShift");
                break;
            case '+':
                assign();
                printf("\t\t\tShift");
                break;
            case '*':
                assign();
                printf("\t\t\tShift");
                break;
            case '-':
                assign();
                printf("\t\t\tShift");
                break;
            default:
                printf("\nError: String not accepted");
                goto label;
        }
    }
    l = strlen(stack);
    while (l > 2) {
        r = 0;
        for (i = l - 1; i >= l - 3; i--) {
            temp[r] = stack[i];
            r++;
        }
        temp[r] = '\0';
        if ((strcmp(temp, "E+E") == 0) || (strcmp(temp, "E*E") == 0) || (strcmp(temp, "E-E") == 0)) {
            for (i = l; i > l - 3; i--)
                stack[i] = ' ';
            stack[l - 3] = 'E';
            printf("\t\t\tReduce by E->");
            for (i = 0; i < strlen(temp); i++)
                printf("%c", temp[i]);
            dispstk();
            dispinp();
            l = l - 2;
        } else {
            printf("\nError: String not accepted");
            goto label;
        }
    }
    printf("\t\t\tAccept");
    printf("\n\nString accepted");
    label:
    return 0;
}
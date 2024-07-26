#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

int pow(int base, int exp) {
    int res = base;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

int mod(int a, int b) {
    return a % b;
}

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int calculator() {
    char input[20];
    double a, b;
    char op;
    fgets(input, sizeof(input), stdin);
    if (sscanf(input,"%lf %c %lf", &a, &op, &b) == 3) {
        switch (op) {
            case '+':
                printf("%d\n", add(a, b));
                break;
            case '-':
                printf("%d\n", sub(a, b));
                break;
            case '*':
                printf("%d\n", mul(a, b));
                break;
            case '/':
                printf("%d\n", div(a, b));
                break;
            case '^':
                printf("%d\n", pow(a, b));
                break;
            case '%':
                printf("%d\n", mod(a, b));
                break;
            default:
                printf("Invalid operator\n");
        }
    } else if (sscanf(input,"%lf%c", &a, &op) == 2) {
        switch (op) {
            case '!':
                printf("%d\n", factorial(a));
                break;
            default:
                printf("Invalid operator\n");
        }
    }
    return 0;
}




#include <stdio.h>

int main() {
    int max_width, value_to_print;
    max_width = 4;
    value_to_print = 100;
    printf("%*d\ttext\n", max_width, value_to_print);
    value_to_print = 1000;
    printf("%*d\ttext\n", max_width, value_to_print);
}
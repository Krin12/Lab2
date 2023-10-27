#include <stdio.h>
#include "calc.h"
#include <dlfcn.h>

int main() {
    void *handle = dlopen("./libcalc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    int (*add_ptr)(int, int) = dlsym(handle, "add");
    int (*subtract_ptr)(int, int) = dlsym(handle, "subtract");
    int (*multiply_ptr)(int, int) = dlsym(handle, "multiply");
    int (*divide_ptr)(int, int) = dlsym(handle, "divide");

    int a = 10, b = 5;
    printf("Addition: %d\n", add_ptr(a, b));
    printf("Subtraction: %d\n", subtract_ptr(a, b));
    printf("Multiplication: %d\n", multiply_ptr(a, b));
    printf("Division: %d\n", divide_ptr(a, b));

    dlclose(handle);
    return 0;
}

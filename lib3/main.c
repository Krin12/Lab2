#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle = dlopen("./libcalc.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    int (*add_func)(int, int) = dlsym(handle, "add");
    int (*subtract_func)(int, int) = dlsym(handle, "subtract");
    int (*multiply_func)(int, int) = dlsym(handle, "multiply");
    int (*divide_func)(int, int) = dlsym(handle, "divide");

    int a = 10, b = 5;
    printf("Add: %d\n", add_func(a, b));
    printf("Subtract: %d\n", subtract_func(a, b));
    printf("Multiply: %d\n", multiply_func(a, b));
    printf("Divide: %d\n", divide_func(a, b));

    dlclose(handle);
    return 0;
}

#include <stdio.h>
#include <math.h>

// Функція для обчислення y для заданих x, a та b.
double calculate_y(double x, double a, double b) {
    return (pow(tan(a * x), 2) + log(x)) / exp(-b * x);
}

// Функція обчислення середнього арифметичного.
double calculate_average(double sum, int count) {
    return (count == 0) ? 0 : sum / count;  // Уникайте ділення
}

int main() {
    double a = 1.3, b = 0.56;  // Константи
    double x_start = 1.3, x_end = 6.1, h = 0.6;  // діапазон x і розмір кроку
    double sum = 0;  // Сума значень y > 1
    int count = 0;  // Кількість значень y > 1
    printf("x\t\ty\n");
    for (double x = x_start; x <= x_end; x += h) {
        double y = calculate_y(x, a, b);
        printf("%.2f\t\t%.5f\n", x, y);
        
        if (y > 1) {
            sum += y;
            count++;
        }
    }

    double average = calculate_average(sum, count);
    printf("Average of y > 1: %.5f\n", average);

    return 0;
}

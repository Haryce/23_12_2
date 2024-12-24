#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x * x; //f(x) = x^2
}
double LeftInt(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n; 
    double integral = 0.0;
    for (int i = 0; i < n; i++) {
        integral += func(a + i * h); 
    }
    integral *= h;
    return integral;
}
int main() {
    setlocale(LC_ALL, "Russian");
    double b; //верхний предел интегрирования
    int n; //количество прямоугольников
    cout << "Введите верхний предел интегрирования (больше 2): ";
    cin >> b;
    if (b <= 2) {
        cout << "Ошибка: верхний предел должен быть больше 2." << endl;
        return 1;
    }
    cout << "Введите количество прямоугольников: ";
    cin >> n;
    //проверка на допустимое количество прямоугольников
    if (n <= 0) {
        cout << "Ошибка: количество прямоугольников должно быть положительным." << endl;
        return 1;
    }
    double result = LeftInt(f, 2, b, n);
    cout << "Определённый интеграл от 2 до " << b << " равен " << result << endl;
    return 0;
}
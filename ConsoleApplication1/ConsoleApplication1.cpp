#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double F(double t, double v) {
    return 1 / t;
}

int main(int argc, char** argv)
{
    double a = 1; double b = 5;
    double n = 10;
    double h = (b - a) / n;
    std::unique_ptr<double[]> T(new double[(int)n]);
    std::unique_ptr<double[]> V(new double[(int)n]);

    T[0] = a; V[0] = 0;

    //метод Эйлера
    for (int i = 1; i <= n - 1; i++) {
        T[i] = a + i * h;
        V[i] = V[i - 1] + h * F(T[i - 1], V[i - 1]);
    }

    std::ofstream output;
    output.open("Ex1_Euler.txt");
    for (int i = 0; i <= n - 1; i++) {
        output << T[i] << '\t' << V[i] << std::endl;
    }


    // std::unique_ptr<double[]> T(new double[(int)n]);
    //std::unique_ptr<double[]> V(new double[(int)n]);
    std::unique_ptr<double[]> V1(new double[(int)n]);
    std::unique_ptr<double[]> V2(new double[(int)n]);
    std::unique_ptr<double[]> V3(new double[(int)n]);
    std::unique_ptr<double[]> V4(new double[(int)n]);

    //метод Рунге-Кутта
    for (int i = 1; i <= n - 1; i++) {
        T[i] = a + i * h;
        V1[i] = h * F(T[i - 1], V[i - 1]);
        V2[i] = h * F(T[i - 1] + h / 2.0, V[i - 1] + V1[i] / 2.0);
        V3[i] = h * F(T[i - 1] + h / 2, V[i - 1] + V2[i] / 2);
        V4[i] = h * F(T[i - 1] + h, V[i - 1] + V3[i]);
        V[i] = V[i - 1] + (V1[i] + 2 * V2[i] + 2 * V3[i] + V4[i]) / 6;
    }


    std::ofstream otput_2;
    otput_2.open("Ex1_Runge–Kutta.txt");
    for (int i = 0; i <= n - 1; i++) {
        otput_2 << T[i] << '\t' << V[i] << std::endl;
    }

    return 0;
}

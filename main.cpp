#include <iostream>
#include <cmath>
#include "math_func.h"

double Equation(double x) {
    double f = (pow(x, 3)) - (3 * pow(x, 2)) + (9*x) - 8;
    return f;
}
double Chord_formula(double start, double end) {            // getting initial approximation
    return end - (Equation(end) * (end - start)) / (Equation(end) - Equation(start));
}

void Localization();
double Dichotomy_Method(double start, double end);
double Chord_method(double start, double end);

double x = 0, y = -1;
double start = -10, end = 10, step = 10, eps = 0.001;
double midPoint;

int main() {
    std::cout << "LOCALIZATION:\n" << std::endl;
    Localization();

    std::cout << "DICHOTOMY METHOD: " << std::endl;
    std::cout << "X = " << Dichotomy_Method(start, end) << std::endl;

    std::cout << "CHORD METHOD: " << std::endl;
    std::cout << "X = " << Chord_method(start, end) << std::endl;

    return 0;
}

void Localization() {       // tabulate math function until x changes sign, update value of start and end
    step *= 0.1;
    std::cout << "x\ty" << std::endl;
    double prev_y = start;                      // for comparing y
    double start_t = start, end_t = start;      // for updating start and end
    y = -1;

    for (x = start; x <= end && (copysign(prev_y, y) == prev_y) ; x += step) {
        prev_y = y;
        y = Equation(x);
        start_t = x - step;
        end_t = x;
        std::cout << x << "\t" << y << std::endl;
    }
    std::cout << std::endl;
    start = start_t;        // 1
    end = end_t;            // 2

}

double Dichotomy_Method(double start, double end) {
    if((SubtractByModule(end, start) >= eps) && start != end) {
        midPoint = (start + end) / 2;

        if (std::signbit(Equation(start) * Equation(midPoint)) == 1)
            return Dichotomy_Method(start, midPoint);

        else if(std::signbit(Equation(midPoint) * Equation(end)) == 1)
            return Dichotomy_Method(midPoint, end);
    }
    return midPoint;
}

double Chord_method(double start, double end) {
    double c = MAX_SIZE;
    while(abs(c) >= eps) {
        c = start - end;
        if(Chord_formula(start, end) * Equation(start) < 0)           // calculate the next interval
            end = Chord_formula(start, end);            // a = c
        else
            start = Chord_formula(start, end);          // b = c
    }
    return Chord_formula(start, end);
}


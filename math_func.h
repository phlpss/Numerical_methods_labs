//
// Created by phili on 3/4/2023.
//

#ifndef LAB_NM_CPP_MATH_FUNC_H
#define LAB_NM_CPP_MATH_FUNC_H
#define MAX_SIZE 1000

int SubtractByModule(int a, int b) {
    return fabs(a) - fabs(b);
}
float SubtractByModule(float a, float b) {
    return fabs(a) - fabs(b);
}
double SubtractByModule(double a, double b) {
    return fabs(a) - fabs(b);
}

int AddByModule(int a, int b) {
    return fabs(a) + fabs(b);
}
float AddByModule(float a, float b) {
    return fabs(a) + fabs(b);
}
double AddByModule(double a, double b) {
    return fabs(a) + fabs(b);
}







#endif //LAB_NM_CPP_MATH_FUNC_H

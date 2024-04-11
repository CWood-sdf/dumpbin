#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
void populate(double x[], double y[]) {
    // do yeet stuff
    ifstream file = ifstream();
    file.open("lin_reg.txt");
    if (!file.is_open()) {
        cout << "sdfsd" << endl;
        return;
    }
    string val = "";
    int xIndex = 0;
    while (val[0] != 'Y') {
        file >> val;
        if (val[0] == 'X') {
            continue;
        }
        if (val[0] == 'Y') {
            break;
        }
        double v = atof(val.data());
        x[xIndex] = v;
        xIndex++;
    }
    int yIndex = 0;
    while (val[0] != 'x') {
        file >> val;
        if (val.size() == 0) {
            break;
        }
        double v = atof(val.data());
        y[yIndex] = v;
        yIndex++;
        if (yIndex == xIndex) {
            break;
        }
    }
}
void multiply(double x[], double y[], double out[], int size) {
    for (int i = 0; i < size; i++) {
        out[i] = x[i] * y[i];
    }
}

void square(double arr[], double out[], int size) {
    for (int i = 0; i < size; i++) {
        out[i] = arr[i] * arr[i];
    }
}
double slope(double x[], double y[], int size) {
    double xMean = 0;
    double yMean = 0;
    for (int i = 0; i < size; i++) {
        xMean += x[i];
        yMean += y[i];
    }
    xMean /= size;
    yMean /= size;
    for (int i = 0; i < size; i++) {
        x[i] -= xMean;
        y[i] -= yMean;
    }
    double mult[1000] = {};
    multiply(x, y, mult, size);
    double squ[1000] = {};
    square(x, squ, size);
    // return the arrays to normal
    for (int i = 0; i < size; i++) {
        x[i] += xMean;
        y[i] += yMean;
    }
    double squSum = 0;
    double multSum = 0;
    for (int i = 0; i < size; i++) {
        squSum += squ[i];
        multSum += mult[i];
    }
    return multSum / squSum;
}
double yInt(double x[], double y[], int size) {
    double b = slope(x, y, size);
    double xMean = 0;
    double yMean = 0;
    for (int i = 0; i < size; i++) {
        xMean += x[i];
        yMean += y[i];
    }
    xMean /= size;
    yMean /= size;
    return yMean - b * xMean;
}

int main() {
    double x[1000] = {};
    double y[1000] = {};
    for (int i = 0; i < 1000; i++) {
        x[i] = 10;
        y[i] = -10;
    }

    populate(x, y);
    int size = 0;
    while (x[size] < 5) {
        size++;
    }
    double m = slope(x, y, size);
    double b = yInt(x, y, size);
    cout << "y = " << m << "x + " << b << endl;

    return 0;
}

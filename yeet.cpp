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
void multiply(double x[], double y[], double out[]) {
}

void square(double arr[], double out[]) {
}
double slope(double x[], double y[]) {
    return 0.0;
}
double yInt(double x[], double y[]) {
    return 0.0;
}

int main() {
    double x[1000] = {};
    double y[1000] = {};
    for (int i = 0; i < 1000; i++) {
        x[i] = 10;
        y[i] = -10;
    }

    populate(x, y);

    for (int i = 0; x[i] < 5; i++) {
        cout << "[" << x[i] << ", " << y[i] << "], ";
    }
    cout << endl;

    return 0;
}

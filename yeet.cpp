#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
class LinearRegression {
public:
    double x[1000];
    double y[1000];
    LinearRegression() {
        for (int i = 0; i < 1000; i++) {
            // populate with impossible values so we know when the actual
            // inputted values end
            x[i] = 10;
            y[i] = -10;
        }
    }
    void populate() {
        // do yeet stuff
        ifstream file = ifstream();
        file.open("lin_reg.txt");
        if (!file.is_open()) {
            cout << "sdfsd" << endl;
            return;
        }
        string val = "";
        int xIndex = 0;
        while (true) {
            file >> val;
            if (val[0] == 'X') {
                continue;
            }
            // if we're on the line for ys, then exit the loop and goto y loop
            if (val[0] == 'Y') {
                break;
            }
            double v = atof(val.data());
            x[xIndex] = v;
            xIndex++;
        }
        int yIndex = 0;
        while (true) {
            file >> val;
            if (val.size() == 0) {
                break;
            }
            double v = atof(val.data());
            y[yIndex] = v;
            yIndex++;
            // if the x and y arrays are the same size, we have read all data
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
    double slope(int size) {
        /// Sum((x[i] - mean(x))*(y[i] - mean(y)))
        /// -------------------------------------
        ///     Sum((x[i] - mean(x) ^ 2)

        // find mean(x) and mean(y)
        double xMean = 0;
        double yMean = 0;
        for (int i = 0; i < size; i++) {
            xMean += x[i];
            yMean += y[i];
        }
        xMean /= size;
        yMean /= size;

        // find (x[i] - mean(x)) and (y[i] - mean(y))
        for (int i = 0; i < size; i++) {
            x[i] -= xMean;
            y[i] -= yMean;
        }

        // do the (x[i] - mean(x))*(y[i] - mean(y))
        double mult[1000] = {};
        multiply(x, y, mult, size);
        // do the x[i] - mean(x) ^ 2
        double squ[1000] = {};
        square(x, squ, size);

        // return x and y arrays to normal
        for (int i = 0; i < size; i++) {
            x[i] += xMean;
            y[i] += yMean;
        }

        // do the Sum() parts
        double squSum = 0;
        double multSum = 0;
        for (int i = 0; i < size; i++) {
            squSum += squ[i];
            multSum += mult[i];
        }

        // Do the division
        return multSum / squSum;
    }
    double yInt(int size) {
        /// mean(y) - slope * mean(x)

        // get slope
        double b = slope(size);

        // get mean(y) and mean(x)
        double xMean = 0;
        double yMean = 0;
        for (int i = 0; i < size; i++) {
            xMean += x[i];
            yMean += y[i];
        }
        xMean /= size;
        yMean /= size;

        // do equation
        return yMean - b * xMean;
    }
};

int main() {
    LinearRegression linReg = LinearRegression();

    // populate array
    linReg.populate();

    // get the size of the array
    int size = 0;
    while (linReg.x[size] < 5) {
        size++;
    }

    // Get the slope and y intercept
    double m = linReg.slope(size);
    double b = linReg.yInt(size);

    // print
    cout << "y = " << m << "x + " << b << endl;

    return 0;
}

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double frequency = 0.0;
    double stages = 0.0;

    cout << "Enter the frequency (in Hz): ";
    cin >> frequency;
    cout << "Enter the number of stages: ";
    cin >> stages;

    double gain =
        pow(275 / sqrt(23 * 23 + 0.5 * frequency * frequency), stages);

    // Force 2 decimal places
    gain = gain * 100;
    gain = round(gain);
    gain = gain / 100;

    cout << "The voltage gain is " << gain << ", at a frequency of "
         << frequency << " (Hz)." << endl;
}

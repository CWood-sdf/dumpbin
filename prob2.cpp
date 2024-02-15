#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    bool wantsContinue;
    cout << "This program calulates impact speed from a given height. Enter a "
            "height:"
         << endl;

    std::vector<double> heights = {};
    do {
        double height;
        cin >> height;
        heights.push_back(height);

        cout << "Do you want to enter another height? (y/n) ";
        char response;
        cin >> response;
        wantsContinue = response == 'y';
    } while (wantsContinue);

    ofstream file("impact_table.txt", ios::app);
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }
    int heightColWidth = 20;
    int speedColWidth = 25;
    file << std::right << std::setw(heightColWidth) << "Height (ft)";
    file << std::right << std::setw(speedColWidth) << "Impact Speed (ft/s)";
    file << endl;
    for (int i = 0; i < heights.size(); i++) {
        file << endl;
        double height = heights[i];
        file << std::right << std::setw(heightColWidth) << fixed
             << setprecision((int)log10(height)) << heights[i];
        double speed = sqrt(2 * 32.2 * height);
        file << std::right << std::setw(speedColWidth) << fixed
             << setprecision((int)log10(speed)) << speed;
    }
    file << endl;
    file.close();
}

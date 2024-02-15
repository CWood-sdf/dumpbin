#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> resistances = {};
    ifstream file("resistors.txt");
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }
    char line[100];
    file.getline(line, 100);
    file.close();

    string currentNumber = "";
    for (int i = 0; i < sizeof(line); i++) {
        if (line[i] == ' ' || line[i] == '\0') {
            for (int j = 0; j < currentNumber.length(); j++) {
                if (currentNumber[j] < '0' || currentNumber[j] > '9') {
                    currentNumber = "";
                    break;
                }
            }
            if (currentNumber.length() == 0) {
                continue;
            }
            resistances.push_back(stoi(currentNumber));
            currentNumber = "";
        } else {
            currentNumber += line[i];
        }
        // Break at end of line
        if (line[i] == '\0') {
            break;
        }
    }

    int res = 0;
    for (int i = 0; i < resistances.size(); i++) {
        res += resistances[i];
    }

    cout << "The total equivalent resistance is ";
    cout << setprecision(1) << res;
    cout << " (ohms) if resistors are connected in series." << endl;

    return 0;
}

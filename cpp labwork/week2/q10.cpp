#include <iostream>
using namespace std;

double bmi (double weight, double height) {
    double bmi = weight/(height * height);
    return bmi;
}

string bmiResult(double bmi) {
    cout << "Your bmi is: " << bmi << endl;
    if (bmi <= 18.5) {
         return "You are under-weight!";
    }
    else if (bmi >= 24.5) {
        return "You are over-weight!";
    }
    else {
        return "You have ideal weight according to your height!";
    }
}
int main() {
    cout << "Enter your weight (kg): ";
    double weight;
    cin >> weight;

    cout << "Enter your height (m): ";
    double height;
    cin >> height;

    double ans = bmi(weight, height);
    cout << bmiResult(ans) << endl;
}
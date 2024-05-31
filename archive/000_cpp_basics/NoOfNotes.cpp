#include <iostream>
using namespace std;


int main() {
    int amt;
    int n100 = 0, n20 = 0,n50 = 0, n1 = 0, note = 100;
    cout << "Enter amount: ";
    cin >> amt;

    switch (note) {
        case (100):
            n100 = amt/100;
            amt = amt % 100;
        case 50:
            n50 = amt/50;
            amt = amt%50;
        case 20:
            n20 = amt/20;
            amt = amt%20;
        case 1:
            n1 = amt;
    }
    cout << amt << " = " << n100 << " 100ruppes notes, " << n50 << " 50 ruppes notes, "<< n20 << " 20 ruppes notes, " << n1 << " 1 ruppe notes." << endl;
}
#include <iostream>
#include <map>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<int, map<int, bool>> booked;
    map<int, int> seats;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "BOOK") {
            int x, y;
            cin >> x >> y;

            if (seats[y] == 0 && seats.count(y)) {
                cout << "false\n";
            }
            else if (booked[y][x] == true) {
                cout << "false\n";
            }
            else {
                if (!seats.count(y)) seats[y] = 100;
                booked[y][x] = true;
                seats[y]--;
                cout << "true\n";
            }
        }

        else if (op == "CANCEL") {
            int x, y;
            cin >> x >> y;

            if (booked[y][x] == true) {
                booked[y][x] = false;
                seats[y]++;
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        }

        else if (op == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;

            if (booked[y][x] == true) cout << "true\n";
            else cout << "false\n";
        }

        else if (op == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;

            if (!seats.count(y)) cout << 100 << "\n";
            else cout << seats[y] << "\n";
        }
    }
}
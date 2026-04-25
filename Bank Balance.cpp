#include <iostream>
#include <map>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<int, int> money;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "CREATE") {
            int x, y;
            cin >> x >> y;

            if (money.count(x) == 0) {
                money[x] = y;
                cout << "true\n";
            } else {
                money[x] += y;
                cout << "false\n";
            }
        }

        else if (op == "DEBIT") {
            int x, y;
            cin >> x >> y;

            if (money.count(x) && money[x] >= y) {
                money[x] -= y;
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        }

        else if (op == "CREDIT") {
            int x, y;
            cin >> x >> y;

            if (money.count(x)) {
                money[x] += y;
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        }

        else if (op == "BALANCE") {
            int x;
            cin >> x;

            if (money.count(x)) cout << money[x] << "\n";
            else cout << -1 << "\n";
        }
    }
}
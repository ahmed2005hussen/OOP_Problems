
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

class universe {
protected:
    vector<vector<string>> grid;

public:
    universe() : grid(30, vector<string>(30, " ")) {}

    void setgrid() {
        int n = 0;
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                grid[i][j] = to_string(n++);
            }
        }
    }
    void reset() {
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                if (grid[i][j] != "*")
                    grid[i][j] = " ";
            }
        }
    }

    void printgrid() {
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                cout<<setw(4) << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    void initialize(string n) {
        int value = stoi(n);
        if (value >= 0 && value < 900) {
            int i = value / 30;
            int j = value % 30;
            grid[i][j] = "*";
        }
        else {
            cout << "Invalid inputd " << endl;
        }
    }

    int count_neighbors(int i, int j) {
        int count = 0;

        if (i == 0 && j == 0) {
            if (grid[i + 1][j] == "*") count++;
            if (grid[i][j + 1] == "*") count++;
            if (grid[i + 1][j + 1] == "*") count++;
        }

        else if (i == 29 && j == 0) {
            if (grid[i - 1][j] == "*") count++;
            if (grid[i][j + 1] == "*") count++;
            if (grid[i - 1][j + 1] == "*") count++;
        }

        else if (i == 0 && j == 29) {
            if (grid[i][j - 1] == "*") count++;
            if (grid[i + 1][j] == "*") count++;
            if (grid[i + 1][j - 1] == "*") count++;
        }

        else if (i == 29 && j == 29) {
            if (grid[i - 1][j] == "*") count++;
            if (grid[i][j - 1] == "*") count++;
            if (grid[i - 1][j - 1] == "*") count++;
        }

        else if (i == 0) {
            if (grid[i][j - 1] == "*") count++;
            if (grid[i][j + 1] == "*") count++;
            if (grid[i + 1][j] == "*") count++;
            if (grid[i + 1][j - 1] == "*") count++;
            if (grid[i + 1][j + 1] == "*") count++;
        }

        else if (i == 29) {
            if (grid[i][j - 1] == "*") count++;
            if (grid[i][j + 1] == "*") count++;
            if (grid[i - 1][j] == "*") count++;
            if (grid[i - 1][j - 1] == "*") count++;
            if (grid[i - 1][j + 1] == "*") count++;
        }

        else if (j == 0) {
            if (grid[i - 1][j] == "*") count++;
            if (grid[i + 1][j] == "*") count++;
            if (grid[i][j + 1] == "*") count++;
            if (grid[i - 1][j + 1] == "*") count++;
            if (grid[i + 1][j + 1] == "*") count++;
        }

        else if (j == 29) {
            if (grid[i - 1][j] == "*") count++;
            if (grid[i + 1][j] == "*") count++;
            if (grid[i][j - 1] == "*") count++;
            if (grid[i - 1][j - 1] == "*") count++;
            if (grid[i + 1][j - 1] == "*") count++;
        }

        else {
            if (grid[i - 1][j] == "*") count++;
            if (grid[i + 1][j] == "*") count++;
            if (grid[i][j - 1] == "*") count++;
            if (grid[i][j + 1] == "*") count++;
            if (grid[i - 1][j - 1] == "*") count++;
            if (grid[i - 1][j + 1] == "*") count++;
            if (grid[i + 1][j - 1] == "*") count++;
            if (grid[i + 1][j + 1] == "*") count++;
        }

        return count;
    }


    void next_generation() {
        vector<vector<string>> temp = grid;

        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                int neighbors = count_neighbors(i, j);

                if (grid[i][j] == "*" && (neighbors < 2 || neighbors > 3)) {
                    temp[i][j] = " ";
                }
                else if (grid[i][j] == " " && neighbors == 3) {
                    temp[i][j] = "*";
                }
            }
        }

        grid = temp;
    }

    void run() {
        reset();
        while(true) {
            system("cls");
            next_generation();
            printgrid();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
};

int main() {
    cout << "Welcome to the Game of Life!" << endl;
    universe a;
    a.setgrid();
    a.printgrid();

    while (true) {
        string n;
        cout << "Enter a cell to activate (0-899) or -1 to quit: ";
        cin >> n;

        if (n == "-1") {
            break;
        }

        a.initialize(n);
        system("cls");
        a.printgrid();
    }

    cout << "Starting simulation..." << endl;
    a.run();
    return 0;
}

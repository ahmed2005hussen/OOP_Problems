#include <bits/stdc++.h>

using namespace std;

class labelGenerator {
protected:
    static int counter;
    string label;
public:
    labelGenerator(string s, int n) {
        counter = n;
        label = s;
    }

    virtual string count_sequence() {
        return string(label) + " " + to_string(counter++);
    }

    virtual string count_incre(int n) {
        string result = string(label) + " " + to_string(counter);
        counter += n;
        return result;
    }
};

int labelGenerator::counter = 0;

class FileLabelGenerator : public labelGenerator {
private:
    string name;
    fstream file;
public:
    FileLabelGenerator(string s, int n, string fi) : labelGenerator(s, n) {
        name = fi;
        file.open(name + ".txt", ios::in);
        if (!file.is_open()) {
            cout << "Error: Unable to open the file " << name + ".txt" << endl;
        }
    }

    string count_sequence() override {
        if (file.is_open()) {
            string line;
            getline(file, line);
            return label + " " + to_string(counter++) + " " + line;

        } else {
            return "Error: File is not open.";
        }
    }

    string count_incre(int n) override {
        if (file.is_open()) {
            string line;
            getline(file, line);
            string result = string(label) + " " + to_string(counter) + ' ' + line;
            counter += n;
            return result;

        } else {
            return "Error: File is not open.";
        }
    }

    int countLine() {
        int lineCount = 0;
        string line;
        while (getline(file, line)) {
            ++lineCount;
        }
        file.clear();
        file.seekg(0, ios::beg);
        return lineCount;
    }

    ~FileLabelGenerator() {
        if (file.is_open()) {
            file.close();
        }
    }
};

void solve_file() {
    cout << "Enter name the file " << endl;
    string name;
    cin >> name;

    cout << "enter the name for your label " << endl;
    string s;
    cin >> s;

    cout << "enter the initial number " << endl;
    int initial;
    cin >> initial;

    FileLabelGenerator label1(s, initial, name);

    cout << "Enter number of operation do you want " << endl;
    cout << "1- sequence pattern , like : 1 , 2 , 3 , 4 ,.. " << endl;
    cout << "2- increase by number " << endl;
    int op;
    cin >> op;

    int end = label1.countLine();

    if (op == 1) {
        for (int i = 0; i < end; i++) {
            cout << label1.count_sequence() << endl;
        }
        cout << endl;

    } else if (op == 2) {
        cout << "enter the increase number " << endl;
        int incre;
        cin >> incre;
        for (int i = 0; i < end; i++) {
            cout << label1.count_incre(incre) << endl;
        }
    }
}

void solve_tarminal() {
    cout << "Enter the name for your label : " << endl;
    cin.ignore();
    string s;
    getline(cin, s);
    cout << "Enter the initial number" << endl;
    int initial = 0;
    cin >> initial;


    cout << "Enter the number to stop " << endl;
    int end = 0;
    cin >> end;


    cout << "Enter number of operation do you want " << endl;
    cout << "1- sequence pattern , like : 1 , 2 , 3 , 4 ,.. " << endl;
    cout << "2- increase by number " << endl;
    int op;
    cin >> op;


    labelGenerator a(s, initial);
    switch (op) {
        case 1 :
            for (int i = 0; i <= end - initial; i++) {
                cout << a.count_sequence() << endl;
            }
            cout << endl;
            break;
        case 2:
            cout << "enter the increase number " << endl;
            int incre;
            cin >> incre;
            for (int i = initial; i <= end; i += incre) {
                cout << a.count_incre(incre) << endl;
            }
            break;

    }
}


int main() {
    cout << "Welcome to you " << endl;
    cout << "enter choice do you want " << endl;
    cout << "1- terminal " << endl;
    cout << "2- file " << endl;
    cout << "3- exit " << endl;

    char n;
    cin >> n;

    if (n == '1') {
        solve_tarminal();
    } else if (n == '2') {
        solve_file();
    } else if (n == '3') {
        return 0;
    } else {
        cout << "wrong number  " << endl;
    }
    main();
}



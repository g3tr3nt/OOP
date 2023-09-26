#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct student {
    string name;
    string surname;
    int group;
    int number;
    int course;
    string adress;
}object;

    string name;
    string surname;
    int Chemistry;
    int Math;
    int English;
    int OOP;

void RW(string filename, bool isDatFile = false) {
    ofstream Q(filename, ios::app);
    if (!Q) {
        cout << "Не вдалося відкрити файл для запису.\n";
        return;
    }

    if (isDatFile) {
        cin >> object.name;
        cin >> object.surname;
        cin >> object.group;
        cin >> object.number;
        cin >> object.course;
        cin >> object.adress;

        Q << object.name << " ";
        Q << object.surname << " ";
        Q << object.group << " ";
        Q << object.number << " ";
        Q << object.course << " ";
        Q << object.adress << " " << endl;
    }
    else {
        cin >> name;
        cin >> surname;
        cin >> Chemistry;
        cin >> Math;
        cin >> English;
        cin >> OOP;

        Q << name << " ";
        Q << surname << " ";
        Q << Chemistry << " ";
        Q << Math << " ";
        Q << English << " ";
        Q << OOP << " ";
    }
    Q.close();
}

void RD(string filename, bool isDatFile = false) {
    ifstream Q(filename);
    if (isDatFile) {
        while (Q >> object.name >> object.surname >> object.group >> object.number >> object.course >> object.adress)
        {
            if (object.number == 0)
            {
                cout << "Прізвище: " << object.surname << endl;
                cout << "Адреса: " << object.adress << endl;
            }
        }
    }
    else {
        double Chemistry[100], Math[100], English[100], OOP[100];
        string name[100], surname[100];
        int i = 0;

        while (Q >> name[i] >> surname[i] >> Chemistry[i] >> Math[i] >> English[i] >> OOP[i])
        {
            i++;
        }

        Q.close();

        for (int j = 0; j < i - 1; j++) {
            for (int k = 0; k < i - j - 1; k++) {
                if (Chemistry[k] < Chemistry[k + 1]) {
                    swap(Chemistry[k], Chemistry[k + 1]);
                    swap(name[k], name[k + 1]);
                    swap(surname[k], surname[k + 1]);
                }
                if (Math[k] < Math[k + 1]) {
                    swap(Math[k], Math[k + 1]);
                    swap(name[k], name[k + 1]);
                    swap(surname[k], surname[k + 1]);
                }
                if (English[k] < English[k + 1]) {
                    swap(English[k], English[k + 1]);
                    swap(name[k], name[k + 1]);
                    swap(surname[k], surname[k + 1]);
                }
                if (OOP[k] < OOP[k + 1]) {
                    swap(OOP[k], OOP[k + 1]);
                    swap(name[k], name[k + 1]);
                    swap(surname[k], surname[k + 1]);
                }
            }
        }

        cout << "Хімія: ";
        for (int j = 0; j < i; j++) {
            cout << Chemistry[j] << " ";
        }
        cout << endl;

        cout << "Математика: ";
        for (int j = 0; j < i; j++) {
            cout << Math[j] << " ";
        }
        cout << endl;

        cout << "Англійська: ";
        for (int j = 0; j < i; j++) {
            cout << English[j] << " ";
        }
        cout << endl;

        cout << "ООП: ";
        for (int j = 0; j < i; j++) {
            cout << OOP[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ukr");
    cout << "Введіть що ви хочите зробити та який тип файлу вам потрібен (DAT/TXT)" << endl;
    string a, fileType;
    cin >> a >> fileType;

    if (a == "Edit") {
        
        if (fileType == "DAT") {
            RW("INFO.DAT", true);
        }
        else if (fileType == "TXT") {
            RW("INFO.TXT");
        }
    }
    else if (a == "Show") {

        if (fileType == "DAT") {
            RD("INFO.DAT", true);
        }
        else if (fileType == "TXT") {
            RD("INFO.TXT");
        }
    }
}


//Room Allotment and booking system using advance DSA Concepts and Multiple parameters In C++
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

static int p = 0;

class Room {
    char roomn[5], host[10], start[5], send[5], from[10], to[10], chair[8][4][10];

public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
};

Room room[10];

void vline(char ch) {
    for (int i = 80; i > 0; i--)
        cout << ch;
}

void Room::install() {
    cout << "Enter Room no: ";
    cin >> room[p].roomn;
    cout << "\nEnter Host's name: ";
    cin >> room[p].host;
    cout << "\nStart time: ";
    cin >> room[p].start;
    cout << "\nSession Ends at: ";
    cin >> room[p].send;
    cout << "\nFrom: \t\t\t";
    cin >> room[p].from;
    cout << "\nTo: \t\t\t";
    cin >> room[p].to;
    room[p].empty();
    p++;
}

void Room::allotment() {
    int chair;
    char number[5];
    top:
    cout << "Room no: ";
    cin >> number;
    int n;
    for (n = 0; n < p; n++) {
        if (strcmp(room[n].roomn, number) == 0)
            break;
    }
    while (n < p) {
        cout << "\nChair Number: ";
        cin >> chair;
        if (chair > 32) {
            cout << "\nThere are only 32 chairs available in this Room.";
        } else {
            if (strcmp(room[n].chair[chair / 4][(chair % 4) - 1], "Empty") == 0) {
                cout << "Enter passenger's name: ";
                cin >> room[n].chair[chair / 4][(chair % 4) - 1];
                break;
            } else {
                cout << "The Chair no. is already reserved.\n";
            }
        }
        if (n >= p) {
            cout << "Enter correct Room no.\n";
            goto top;
        }
    }
}

void Room::empty() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(room[p].chair[i][j], "Empty");
        }
    }
}

void Room::show() {
    int n;
    char number[5];
    cout << "Enter Room no.: ";
    cin >> number;
    for (n = 0; n < p; n++) {
        if (strcmp(room[n].roomn, number) == 0)
            break;
    }
    if (n < p) {
        vline('*');
        cout << "\nRoom no: \t" << room[n].roomn << "\nHost: \t" << room[n].host << "\nFrom: \t\t" << room[n].from
             << "\t\tTo: \t\t" << room[n].to << "\n";
        vline('*');
        room[n].position(n);
        int a = 1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 4; j++) {
                a++;
                if (strcmp(room[n].chair[i][j], "Empty") != 0) {
                    cout << "\nThe chair no " << (a - 1) << " is reserved for " << room[n].chair[i][j] << ".";
                }
            }
        }
    } else {
        cout << "Enter correct Room no.";
    }
}

void Room::position(int l) {
    int s = 0, p = 0;
    for (int i = 0; i < 8; i++) {
        cout << "\n";
        for (int j = 0; j < 4; j++) {
            s++;
            if (strcmp(room[l].chair[i][j], "Empty") == 0) {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
                p++;
            } else {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
            }
        }
    }
    cout << "\n\nThere are " << p << " chairs empty in Room No: " << room[l].roomn;
}

void Room::avail() {
    for (int n = 0; n < p; n++) {
        vline('*');
        cout << "\nRoom no: \t" << room[n].roomn << "\nHost: \t" << room[n].host << "\t\tStart time: \t"
             << room[n].start << "\tEnd Time: \t" << room[n].send << "\nFrom: \t\t" << room[n].from
             << "\t\tTo: \t\t" << room[n].to << "\n";
        vline('*');
        vline('_');
    }
}

int main() {
    int w;
    while (1) {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t1. Install\n\t\t\t" << "2. Reservation\n\t\t\t"
             << "3. Show\n\t\t\t" << "4. Rooms Available\n\t\t\t" << "5. Exit";
        cout << "\n\t\t\tEnter your choice:-> ";
        cin >> w;
        switch (w) {
            case 1:
                room[p].install();
                break;
            case 2:
                room[p].allotment();
                break;
            case 3:
                room[0].show();
                break;
            case 4:
                room[0].avail();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}

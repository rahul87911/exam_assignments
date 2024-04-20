#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class Sports
class Sports {
protected:
    string sports_name;
    double fees;
public:
    Sports(string _sports_name, double _fees) : sports_name(_sports_name), fees(_fees) {}
    string getSportsName() const { return sports_name; }
    double getFees() const { return fees; }
};

// Class Person
class Person {
protected:
    string name;
    int age;
public:
    Person(string _name, int _age) : name(_name), age(_age) {}
    string getName() const { return name; }
    int getAge() const { return age; }
};

// Class Player
class Player : public Person {
protected:
    int id;
    string mobile;
    vector<string> sportsEnrolled;
public:
    Player(string _name, int _age, int _id, string _mobile) : Person(_name, _age), id(_id), mobile(_mobile) {}

    void enrollSport(string sportName) {
        sportsEnrolled.push_back(sportName);
    }

    void displaySportsList() {
        cout << "Sports enrolled by " << name << ":\n";
        for (const string& sport : sportsEnrolled) {
            cout << "- " << sport << endl;
        }
    }

    string getMobile() const { return mobile; }
};

int main() {
    vector<Sports> sportsList;
    vector<Player> players;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add new player\n";
        cout << "2. Add new sport\n";
        cout << "3. Enroll player into sport\n";
        cout << "4. Take player name from user and display his/her sports list\n";
        cout << "5. Display all players and their sports registered\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, mobile;
                int age, id;
                cout << "Enter player name: ";
                cin >> name;
                cout << "Enter player age: ";
                cin >> age;
                cout << "Enter player id: ";
                cin >> id;
                cout << "Enter player mobile: ";
                cin >> mobile;
                players.push_back(Player(name, age, id, mobile));
                cout << "New player added successfully.\n";
                break;
            }
            case 2: {
                string name;
                double fees;
                cout << "Enter sport name: ";
                cin >> name;
                cout << "Enter sport fees: ";
                cin >> fees;
                sportsList.push_back(Sports(name, fees));
                cout << "New sport added successfully.\n";
                break;
            }
            case 3: {
                if (players.empty() || sportsList.empty()) {
                    cout << "No players or sports available.\n";
                } else {
                    int playerIndex, sportIndex;
                    cout << "Enter player index: ";
                    cin >> playerIndex;
                    cout << "Enter sport index: ";
                    cin >> sportIndex;
                    players[playerIndex].enrollSport(sportsList[sportIndex].getSportsName());
                    cout << "Player enrolled into sport successfully.\n";
                }
                break;
            }
            case 4: {
                if (players.empty()) {
                    cout << "No players available.\n";
                } else {
                    string playerName;
                    cout << "Enter player name: ";
                    cin >> playerName;
                    bool found = false;
                    for (Player& player : players) {
                        if (player.getName() == playerName) {
                            player.displaySportsList();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Player not found.\n";
                    }
                }
                break;
            }
            case 5: {
                if (players.empty()) {
                    cout << "No players available.\n";
                } else {
                    cout << "All players and their sports registered:\n";
                    for (Player& player : players) {
                        cout << "Player: " << player.getName() << ", Mobile: " << player.getMobile() << endl;
                        player.displaySportsList();
                        cout << endl;
                    }
                }
                break;
            }
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

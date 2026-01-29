#include <iostream>
using namespace std;

#define MAX 6

class SocialNetwork {
    int graph[MAX][MAX];

public:
    SocialNetwork() {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                graph[i][j] = 0;
            }
        }
    }

    void addFriend(int u, int v) {
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    void recommendFriends(int user) {
        int mutual[MAX] = {0};

        for (int i = 0; i < MAX; i++) {
            if (graph[user][i] == 1) {
                for (int j = 0; j < MAX; j++) {
                    if (graph[i][j] == 1 &&
                        graph[user][j] == 0 &&
                        j != user) {
                        mutual[j]++;
                    }
                }
            }
        }

        cout << "\nFriend Recommendations for User " << user << ":\n";
        bool found = false;

        for (int i = 0; i < MAX; i++) {
            if (mutual[i] > 0) {
                cout << "User " << i
                     << " (Mutual Friends: " << mutual[i] << ")\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No recommendations available.\n";
        }
    }
};

int main() {
    SocialNetwork sn;
    sn.addFriend(0, 1);
    sn.addFriend(0, 2);
    sn.addFriend(1, 3);
    sn.addFriend(2, 3);
    sn.addFriend(3, 4);
    sn.addFriend(4, 5);

    int user;
    cout << "Enter user ID (0-5): ";
    cin >> user;

    sn.recommendFriends(user);

    return 0;
}


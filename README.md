Final project explanation
Submitted by: Rizwan ULLAH 
Cu-id: CU-5498-2024 
BS SOFTWARE engineering 3rd semister 
----------------------------------------------------------------
Social Media Friend Recommendation System (Using Graphs in C++)
Project Overview

This project is a Social Media Friend Recommendation System developed in C++ using the concept of Graphs.
The system suggests new friends to a user based on the number of mutual friends, which is similar to how real social media platforms work (e.g., Facebook, Instagram, LinkedIn).

Each user in the system is represented as a node, and each friendship is represented as an edge between two nodes.
 Objective of the Project

The main goal of this project is to:

Understand graph representation using an adjacency matrix

Implement mutual friend logic

Recommend friends who are not directly connected but share common friends
 Concept Used
Graph Data Structure

Users → Vertices (nodes)
Friendships → Edges

Graph Type → Undirected graph
Representation → Adjacency Matrix
 How the Graph Works

If graph[i][j] = 1 → User i and User j are friends

If graph[i][j] = 0 → No direct friendship
 Program Structure Explanation
 Header Files
#include <iostream>
using namespace std;

Used for input and output operations
 Constant Definition
#define MAX 6

Represents total number of users (User IDs: 0 to 5)
SocialNetwork Class

This class manages the entire social network.
a) Adjacency Matrix
int graph[MAX][MAX];

Stores friendship relationships between users

b) Constructor
SocialNetwork() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            graph[i][j] = 0;
}
Initializes the graph
Initially, no user is connected to anyone

c) addFriend Function

void addFriend(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}
Creates a two-way (bidirectional) friendship
Because friendships are mutual

d) recommendFriends Function

This is the core logic of the project.
void recommendFriends(int user)

Steps:

Create an array to count mutual friends
Loop through user’s direct friends

Check friends-of-friends
Ignore:
The user themself
Already connected friends
Count mutual friends
Display recommendations

if (graph[i][j] == 1 &&
    graph[user][j] == 0 &&
    j != user)

Recommendation Rule:
Recommend users who are not already friends but share one or more mutual friends

Main Function
int main()


Tasks:

Create SocialNetwork object

Add predefined friendships

Take user input

Show recommendations

Example Execution
Existing Friendships
0 ↔ 1
0 ↔ 2
1 ↔ 3
2 ↔ 3
3 ↔ 4
4 ↔ 5

User Input
Enter user ID (0–5): 0

Output
Friend Recommendations for User 0:
User 3 (Mutual Friends: 2)
Explanation:

User 0 shares two mutual friends (1 and 2) with User 3

Hence, User 3 is recommended
Time & Space Complexity
Time Complexity: O(N³)

Space Complexity: O(N²)
(Due to adjacency matrix)
Conclusion

This project successfully demonstrates how graph data structures can be used to build a friend recommendation system.
It provides a strong foundation for understanding real-world applications of graphs in social networking platforms.



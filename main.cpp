/*
    Chapter: Chapter 6 Excersise 16

    Programmer: Vincent Epefanio

    Date: 11/29/2024

    Requirements: For this programming problem, download the following files from the book’s companion website:
    • Teams.txt—This file contains a list of several Major League baseball teams in alphabetical order. Each team listed in the file has won the World Series at least once.
    • WorldSeriesWinners.txt—This file contains a chronological list of the World Series’ winning teams from 1903 to 2012. (The first line in the file is the name of the team that won in 1903, and the last line is the name of the team that won in 2012. Note the World Series was not played in 1904 or 1994.)
    Write a program that displays the contents of the Teams.txt file on the screen and prompts the user to enter the name of one of the teams. The program should then display the number of times that team has won the World Series in the time period from 1903 to 2012.
    TIP: Read the contents of the WorldSeriesWinners.txt file into an array or vector. When the user enters the name of a team, the program should step through the array or vector counting the number of times the selected team appears.

*/



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


vector<string> readTeamsFile(const string &filename) {
    vector<string> teams;
    ifstream file(filename);
    string team;

    if (file.is_open()) {
        while (getline(file, team)) {
            teams.push_back(team);
        }
        file.close();
    } else {
        cout << "Error opening file: " << filename << endl;
    }

    return teams;
}


vector<string> readWorldSeriesWinnersFile(const string &filename) {
    vector<string> winners;
    ifstream file(filename);
    string winner;

    if (file.is_open()) {
        while (getline(file, winner)) {
            winners.push_back(winner);
        }
        file.close();
    } else {
        cout << "Error opening file: " << filename << endl;
    }

    return winners;
}


int countTeamWins(const string &team, const vector<string> &winners) {
    return count(winners.begin(), winners.end(), team);
}

int main() {
    
    string teamsFile = "Teams.txt";
    string winnersFile = "WorldSeriesWinners.txt";

    
    vector<string> teams = readTeamsFile(teamsFile);
    vector<string> winners = readWorldSeriesWinnersFile(winnersFile);

    
    cout << "Teams that have won the World Series at least once:" << endl;
    for (const string &team : teams) {
        cout << team << endl;
    }

    
    string userTeam;
    cout << "\nEnter the name of a team from the list above: ";
    getline(cin, userTeam);


    if (find(teams.begin(), teams.end(), userTeam) != teams.end()) {
    
        int wins = countTeamWins(userTeam, winners);
        cout << userTeam << " has won the World Series " << wins << " times between 1903 and 2012." << endl;
    } else {
        cout << "The team you entered is not in the list of teams." << endl;
    }

    return 0;
}



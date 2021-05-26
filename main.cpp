/******************************************************************************
Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/
#include <iostream>
#include <vector>
#include <unistd.h>
#include <fstream>
using namespace std;
void Intro(){
/***
* Prints the information required to play the game.
***/
cout <<"Welcome to Rock, Paper, Scissors, Lizard, Spock \n" << endl;
cout <<"*Rules are as follows: " << endl;
cout <<" \tScissors cuts Paper which covers Rock which crushes Lizard whom
poisons Spock whom smashes" << endl;
cout <<" \tScissors which decapitates Lizard whom eats Paper which disproves
Spock whom vaporizes Rock which crushes" << endl;
cout <<" \tScissors \n" << endl;
}
int NumberOfPlayers(){
/***
* It puts the user or users to choose their game mode.
***/
int PlayerNumber;
cout<<"How many players will be joining us today(Please choose 1 or 2)? ";
cin>>PlayerNumber;
cout<<endl;
return PlayerNumber;
}
4
string WhatIsThePlayerChoise(int pChoice){
/***
* Converts the numerical options chosen by the player into their respective words. 1 ->
Rock
***/
int playerChoice = pChoice;
wrongNaming:
if(playerChoice == 1){
return "Rock";
}
else if(playerChoice == 2){
return "Paper";
}
else if(playerChoice == 3){
return "Scissors";
}
else if(playerChoice == 4){
return "Lizard";
}
else if(playerChoice == 5){
return "Spock";
}
else{
cout << "That's not an option"<< endl;
cout << "Make sure to Choose a number between 1 and 5"<<endl;
cin >> playerChoice;
goto wrongNaming;
}
} //Takes the player in-game option(1 - 6) and tells if it's Rock, Paper or etc.
int WhichPlayerWin(int player1, int player2){
/***
* It obtains the numerical information chosen by the players and uses conditional
statements
* to go through the rules of the game and provide a winner.
***/
if ((player1 == 1 && player2 == 3) || (player1 == 1 && player2 == 4)){
//Rock(1)->Scissors(3), Lizard(4)
return 1;
}
5
else if((player1 == 2 && player2 == 1) || (player1 == 2 && player2 == 5)){
//Paper(2)->Rock(1), Spock(5)
return 1;
}
else if((player1 == 3 && player2 == 2) || (player1 == 3 && player2 == 4)){
//Scissors(3)->Paper(2), Lizard(4)
return 1;
}
else if((player1 == 4 && player2 == 2) || (player1 == 4 && player2 == 5)){
//Lizard(4)->Paper(2),Spock(5)
return 1;
}
else if((player1 == 5 && player2 == 1) || (player1 == 5 && player2 == 3)){
//Spock(5)->Rock(1), Scissors(3)
return 1;
}
else if(player1 == player2){
//Players have the same number
return 3;
}
else{
//Player2 wins
return 2;
}
} //Tells which player wins
void AccessAndEdditFiles(bool Computer, string player1Name, string player2Name,
vector<int> gameScore){
/***
* Create and write to a text file to create the leaderboard.
***/
ofstream MyFile;
MyFile.open("leaderboard.txt", ofstream::app);
if(Computer== false){
MyFile<< "Game Score -->"<<player1Name<<" vs "<<player2Name<<",
"<<gameScore.at(0)<<":"<<gameScore.at(1)<<endl;
}
else{
MyFile <<"Game Score -->"<<player1Name<<" vs "<<"Computer,
"<<gameScore.at(0)<<":"<<gameScore.at(1)<<endl;
}
}
6
int main()
{
srand(time(0));
//Variables
vector<int> gameScore = {0,0};
int player1 = 0;
int player2 = 0;
int computerChoice = 0;
int PlayerNumber = 0;
int scoreToIncrease = 0;
string player1Name = "";
string player2Name = "";
bool Computer = false;
int dialogChoice;
//Dialogs
vector <string> if_player_1_wins_over_player_2 = {
"Congratulations, Player one you have won! ",
"Wow, that's unfortunate Player two, Player 1 wins! ",
"Your score is great, you won Player One! Player two is at your mercy...",
};
vector <string> if_player_2_wins_over_player_1 = {
"Congratulations, Player two you have won! ",
"Wow, that's unfortunate Player one, Player 2 wins! ",
"Your score is great, you won Player Two! Player one is at your mercy...",
};
vector <string> if_player_1_wins_over_computer = {
"Congratulations, Player one you have won! ",
"Your score is great, you won Player One! Computers are at your mercy...",
"Wow, that's unfortunate Computer, Player 1 wins! ",
};
vector <string> if_computer_wins_over_player_1 = {
"You failed to score a point against the supermachine in this round. Try again
please!",
"Well um... that's awkward- Computer bamboozled the Player! It happens... but there
is nothing bad about trying again!",
"Wow, that's unfortunate Player 1, Computer wins! ",
};
7
vector <string> if_its_a_tie = {
"It's a TIE! ",
"It's a tie?? No, lets try that again ",
"You tied... I don't know if I can count that as leaderboard worthy"
};
//Intro
Intro();
//Deciding Number of players
wrongPlayerNumber:
PlayerNumber = NumberOfPlayers();
if (PlayerNumber == 1 or PlayerNumber == 2){
}
else{ cout<< "That's not an option"<<endl;
goto wrongPlayerNumber;}
if (PlayerNumber == 1){
//Player 2 is a Computer
Computer = true;
}
while(true){
cout <<"Please choose a number(1-6)\t\t1 => Rock, 2 => Paper, 3 => Scissors, 4 =>
Lizard, 5 => Spock, 6 => End Game" << endl;
cout <<"Player 1: ";
cin >> player1;
if(Computer == false){
cout <<"Player 2: ";
cin >> player2;
cout <<endl;
}
//Exit the game with number 6
if(player1 == 6 || player2 == 6){
break;
}
cout <<"Player 1 chooses "<< WhatIsThePlayerChoise(player1) << endl;
8
if(Computer == false){
cout <<"Player 2 chooses "<< WhatIsThePlayerChoise(player2) << endl;
}
else{
player2 = rand() % 5 + 1;
usleep(300000);
cout <<"Computer chooses "<< WhatIsThePlayerChoise(player2) << endl;
}
usleep(1000000);
//Who wins
scoreToIncrease = WhichPlayerWin(player1, player2);
dialogChoice = rand() % 3;
if (scoreToIncrease == 1){
if(Computer == false){
cout << if_player_1_wins_over_player_2.at(dialogChoice)<<endl;}
else{
cout << if_player_1_wins_over_computer.at(dialogChoice)<<endl;}\
gameScore.at(0)++;
}
else if(scoreToIncrease == 2){
if(Computer == false){
cout << if_player_2_wins_over_player_1.at(dialogChoice)<<endl;
gameScore.at(1)++;}
else{
cout << if_computer_wins_over_player_1.at(dialogChoice)<<endl;
gameScore.at(1)++;
}
}
else{
//It's a TIE #No score will be increase
cout << if_its_a_tie.at(dialogChoice)<<endl;
}
cout << endl;
}
cout << endl;
cout <<"Player 1 enter your name: ";
cin.ignore();
getline (cin,player1Name);
//cin >> player1Name;
if(Computer == false){
9
cout <<"Player 2 enter your name: ";
getline (cin,player2Name);
}
cout<<endl;
//leaderboard
AccessAndEdditFiles(Computer, player1Name, player2Name, gameScore);
cout << endl << "GAME ENDED! Go check your score on the leaderboard.";
return 0;
}

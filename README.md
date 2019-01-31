# Introduction

Program in C++, which provide support to follow the score of a Tennis match.

## Tennis Score Rules

visit https://en.wikipedia.org/wiki/Tennis_scoring_system

## How to use

To build and launch the unit tests : ./runTests  
(Executable : TennisScoringSystemTest)

To build and launch the interface in terminal to test the program with user values : ./run
(Executable : TennisMatchTest)

## Classes

The classes are separated in : 
- TennisScoringSystem : manages a whole match
- TennisSetScoringSystem : manages a set
- TennisGameScoringSystem : manages a game
  - TennisGameAdvantageScoringSystem : inherits from TennisGameScoringSystem , the game has specific display and winning condition 
  - TennisGameTieBreakScoringSystem : inherits from TennisGameScoringSystem , the game has specific display and winning condition 

The file src/main.cpp contains the interface to test the program in terminal.
The files in tests/ are the unit tests.

## Functionalities

A match contains multiple sets, and these sets contains multiple games.
- A match can be played in Best-Of-Three or Best-Of-Five modes (the majority of 3 or 5 sets must be won to win the match)
- A match can be played in 1 VS 1 or 2 VS 2
- When a set has a score 6-6, a tie break game is played instead of a advantage game
- The server is announced, and the score of the server is displayed first
- The winner is announced with the final score
- 3 display modes are available for the same score :
  - english : Fifteen-Love
  - numeric : 15-0
  - standard : 1-0
  


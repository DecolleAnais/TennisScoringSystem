# Introduction

Write production-grade implementation focusing on simplicity, readability and efficiency. 
The code should be also fully covered by unit tests.

# Instructions and deliverables

1. Before starting to code, initialize a git repository.
2. Perform regular commits during your coding session.
3. When the exercise is done, prepare an archive containing everything (including .git folder) except build output folder.
4. Send this archive by email.

# Problem Statement

Create a program in C++, which provide support to follow the score of a Tennis match.


## Tennis Score Rules

visit https://en.wikipedia.org/wiki/Tennis_scoring_system


The tennis scoring system is a way to keep track of tennis matches.
[...]
A tennis match is composed of points, games, and sets. A set consists of a number of games (a minimum of six), which in turn each consist of points. A set is won by the first side to win 6 games, with a margin of at least 2 games over the other side (e.g. 6–3 or 7–5). There is usually a tie-break if the set is tied at six games per player. A match is won when a player or a doubles team has won the majority of the prescribed number of sets. Matches employ either a best-of-three (first to two sets wins) or best-of-five (first to three sets wins) set format. The best-of-five set format is usually only used in the men's singles or doubles matches at Grand Slam and Davis Cup matches.


## Suggested Test Cases

- when match begins, serving player is Player1

In first set:
- When Player1 wins first point score is 15-0
- When Player 1 wins first point and second point score is 30-0

In first set:
- When player2 wins first point score is 0-15 => 
- When player2 wins first point and second point score is 0-30 => Love-Thirteen

In first set:
- When both players have won 2 points each score is 30-30 => Thirteen-O

etc...



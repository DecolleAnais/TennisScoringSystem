#include "TennisGameScoringSystem.h"

#include <iostream>

void TennisGameScoringSystem::pointWonBy(int player)
{
	try
	{
		gameScore[player]++;	
	}
	catch(std::exception& e)
	{
		std::cout << "Error accessing gameScore of player" << player << " " << e.what() << std::endl;
	}
}

void TennisGameScoringSystem::pointsWonBy(int player, const int nbPointsWon)
{
	try
	{
		gameScore[player] += nbPointsWon;
	}	
	catch(std::exception& e)
	{
		std::cout << "Error accessing gameScore of player" << player << " " << e.what() << std::endl;
	}
}

std::array<int,2> TennisGameScoringSystem::getGameScore(const bool reverseOrder) const
{
	if(reverseOrder)
	{
		std::array<int,2> gameScoreReversed = {gameScore[1], gameScore[0]};
		return gameScoreReversed;
	}

	return gameScore;
}

int TennisGameScoringSystem::getScoreOf(int player) const
{
	try
	{
		return gameScore[player];
	}
	catch(std::exception& e)
	{
		std::cout << "Error accessing gameScore of player" << player << " " << e.what() << std::endl;
	}

	return -1;
}

int TennisGameScoringSystem::getWinner() const
{
	if(gameScore[0] == gameScore[1])
		return -1;

	return (gameScore[0] > gameScore[1]) ? 0 : 1;
}

int TennisGameScoringSystem::currentPoint() const
{
	return gameScore[0] + gameScore[1];
}
#include "TennisGameScoringSystem.h"

#include <assert.h>
#include <algorithm>
#include <iostream>
#include <math.h>

void TennisGameScoringSystem::pointWonBy(int player)
{
	assert(player < gameScore.size() && player >= 0);
	
	gameScore[player]++;	
}

void TennisGameScoringSystem::pointsWonBy(int player, const int nbPointsWon)
{
	assert(player < gameScore.size() && player >= 0);
	
	gameScore[player] += nbPointsWon;	
}

std::array<int,2> TennisGameScoringSystem::getGameScore() const
{
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
		std::cout << "Error accessing gameScore of player" << player << e.what() << std::endl;
	}

	return -1;
}

int TennisGameScoringSystem::getWinner() const
{
	if(gameScore[0] == gameScore[1])
		return -1;

	return (gameScore[0] > gameScore[1]) ? 0 : 1;
}
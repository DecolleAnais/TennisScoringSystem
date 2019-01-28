#include "TennisGameScoringSystem.h"

#include <assert.h>
#include <algorithm>
#include <iostream>
#include <math.h>

TennisGameScoringSystem::TennisGameScoringSystem()
{

}

void TennisGameScoringSystem::pointWonBy(int player)
{
	assert(player < gameScore.size() && player >= 0);
	
	gameScore[player]++;	
}

void TennisGameScoringSystem::pointsWonBy(int player, int nbPointsWon)
{
	assert(player < gameScore.size() && player >= 0);
	
	gameScore[player] += nbPointsWon;	
}

std::string TennisGameScoringSystem::plainEnglishScore() const
{	
	std::string score = "";

	if(gameScore[0] == gameScore[1])
	{
		if(gameScore[0] >= 3)
		{
			score = "Deuce";
		}
		else
		{
			score = mapOfPlainEnglishScores.at(gameScore[0]) + "-All";
		}
	}
	else
	{
		int maxScore = std::max(gameScore[0], gameScore[1]);

		if(maxScore >= 4)
		{
			int playerWithMaxScore = getWinner();

			if(std::abs(gameScore[0] - gameScore[1]) >= 2)
			{	
				score = "Game won by Player" + std::to_string(playerWithMaxScore + 1);
			}
			else
			{
				score = "Advantage Player" + std::to_string(playerWithMaxScore + 1);
			}
		}
		else
		{
			score = mapOfPlainEnglishScores.at(gameScore[0]) + "-" + mapOfPlainEnglishScores.at(gameScore[1]);
		}
	}	
	return score;
}

std::string TennisGameScoringSystem::plainNumericalScore() const
{
	std::string score = "";

	int maxScore = std::max(gameScore[0], gameScore[1]);

	if(maxScore >= 4)
	{
		if(gameScore[0] == gameScore[1])
		{
			score = "40-40";
		}
		else if(std::abs(gameScore[0] - gameScore[1]) >= 2)
		{				
			int playerWithMaxScore = getWinner();
			score = "Game won by Player" + std::to_string(playerWithMaxScore + 1);
		}
		else if(gameScore[0] > gameScore[1])
		{
			score = "40A-40";
		}
		else
		{
			score = "40-40A";
		}
	}
	else
	{
		score = mapOfPlainNumericalScores.at(gameScore[0]) + "-" + mapOfPlainNumericalScores.at(gameScore[1]);
	}

	return score;
}

std::array<int,2> TennisGameScoringSystem::getScore() const
{
	return gameScore;
}

int TennisGameScoringSystem::getWinner() const
{
	return (gameScore[0] > gameScore[1]) ? 0 : 1;
}

bool TennisGameScoringSystem::isEnded()
{
	return true;
}
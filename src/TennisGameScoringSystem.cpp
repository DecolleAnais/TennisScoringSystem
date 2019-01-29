#include "TennisGameScoringSystem.h"

#include <assert.h>
#include <algorithm>
#include <iostream>
#include <math.h>

TennisGameScoringSystem::TennisGameScoringSystem()
{
	maxPossibleScore = (--mapOfPlainNumericalScores.end())->first;
}

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

std::string TennisGameScoringSystem::plainEnglishScore() const
{	
	std::string score = "";

	if(isEnded())
	{
		score = "Game won by Player" + std::to_string(getWinner() + 1);
	}
	else if(gameScore[0] == gameScore[1])
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

		if(maxScore > maxPossibleScore)
		{
				score = "Advantage Player" + std::to_string(getWinner() + 1);
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

	int currentMaxScore = std::max(gameScore[0], gameScore[1]);

	int maxPossibleScore = (--mapOfPlainNumericalScores.end())->first;

	std::string advantageScore1 = "";
	std::string advantageScore2 = "";

	if(isEnded())
	{
		return "Game won by Player" + std::to_string(getWinner() + 1);
	}
	else if(currentMaxScore > maxPossibleScore)
	{
		gameScore[0] > gameScore[1] ? advantageScore1 = "A" : advantageScore2 = "A";
	}

	std::string score1 = mapOfPlainNumericalScores.at( std::min(gameScore[0], maxPossibleScore) ) + advantageScore1;
	std::string score2 = mapOfPlainNumericalScores.at( std::min(gameScore[1], maxPossibleScore) ) + advantageScore2;

	score =  score1 + "-" + score2;

	return score;
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

bool TennisGameScoringSystem::isEnded() const
{
	int maxScore = std::max(gameScore[0], gameScore[1]);

	return (maxScore >= 4 && std::abs(gameScore[0] - gameScore[1]) >= 2);
}
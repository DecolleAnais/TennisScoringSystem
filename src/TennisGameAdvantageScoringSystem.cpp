#include "TennisGameAdvantageScoringSystem.h"

TennisGameAdvantageScoringSystem::TennisGameAdvantageScoringSystem()
{
	maxPossibleScore = (--mapOfPlainNumericalScores.end())->first;

	minPointsToWin = 4;
}

std::string TennisGameAdvantageScoringSystem::plainEnglishScore() const
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

std::string TennisGameAdvantageScoringSystem::plainNumericalScore() const
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

bool TennisGameAdvantageScoringSystem::isEnded() const
{
	int maxScore = std::max(gameScore[0], gameScore[1]);

	return (maxScore >= minPointsToWin && std::abs(gameScore[0] - gameScore[1]) >= 2);
}
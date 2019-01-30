#include "TennisGameTieBreakScoringSystem.h"

TennisGameTieBreakScoringSystem::TennisGameTieBreakScoringSystem(int tieBreakValue)
{
	minPointsToWin = tieBreakValue;
}

std::string TennisGameTieBreakScoringSystem::plainEnglishScore() const
{	
	if(isEnded())
		return "Game won by Player" + std::to_string(getWinner()+1);

	// there isn't a plain english score for a tie break game
	// (too much numbers to put in map)
	return plainNumericalScore();
}

std::string TennisGameTieBreakScoringSystem::plainNumericalScore() const
{
	return std::to_string(gameScore[0]) + "-" + std::to_string(gameScore[1]);
}

bool TennisGameTieBreakScoringSystem::isEnded() const
{
	int maxScore = std::max(gameScore[0], gameScore[1]);

	return (maxScore >= minPointsToWin && std::abs(gameScore[0] - gameScore[1]) >= 2);
}


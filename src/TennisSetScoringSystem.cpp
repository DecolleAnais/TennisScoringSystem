#include "TennisSetScoringSystem.h"

TennisSetScoringSystem::TennisSetScoringSystem()
{

}

void TennisSetScoringSystem::pointWonBy(const int player)
{

}

std::string TennisSetScoringSystem::plainEnglishScore() const
{
	return "";
}

std::string TennisSetScoringSystem::plainEnglishScore(const int gameIndex) const
{
	return "";
}

std::string TennisSetScoringSystem::plainNumericalScore() const
{
	return "";
}
std::string TennisSetScoringSystem::plainNumericalScore(const int gameIndex) const
{
	return "";
}

std::string TennisSetScoringSystem::score() const
{
	return "";
}
std::string TennisSetScoringSystem::score(const int gameIndex) const
{
	return "";
}

std::vector<std::array<int,2>> TennisSetScoringSystem::getGameScores() const
{
	std::vector<std::array<int,2>> gameScores;
	gameScores.push_back(getGameScore(0));

	return gameScores;
}

std::array<int,2> TennisSetScoringSystem::getGameScore(const int gameIndex) const
{
	std::array<int, 2> gameScore {0, 0};
	return gameScore;
}

int TennisSetScoringSystem::getNbGamesWonBy(int player) const
{
	return -1;
}

bool TennisSetScoringSystem::isEnded() const
{
	return false;
}
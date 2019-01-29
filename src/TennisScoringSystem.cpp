#include "TennisScoringSystem.h"


TennisScoringSystem::TennisScoringSystem(NbSetsFormat nbSetsFormat)
{

}

void TennisScoringSystem::pointWonBy(Player player)
{
    pointCount++;
}

void TennisScoringSystem::pointsWonBy(Player player, const int nbPointsWon)
{

}

std::string TennisScoringSystem::fullEnglishScore() const
{
	return "";
}

std::string TennisScoringSystem::plainEnglishScore() const {
    return "";
}

std::string TennisScoringSystem::fullNumericalScore() const
{
	return "";
}

std::string TennisScoringSystem::plainNumericalScore() const
{
	return "";
}

std::string TennisScoringSystem::fullScore() const
{
	return "";
}

std::string TennisScoringSystem::score() const
{
	return "";
}

int TennisScoringSystem::currentPointInSet() const {
    return pointCount;
}

TennisScoringSystem::Player TennisScoringSystem::getWinner() const
{

}

bool TennisScoringSystem::isEnded() const
{
	return false;
}

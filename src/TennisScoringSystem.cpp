#include "TennisScoringSystem.h"
#include <cmath>

TennisScoringSystem::TennisScoringSystem(NbSetsFormat nbSetsFormat)
{
	sets.resize(nbSetsFormat);
}

void TennisScoringSystem::pointWonBy(Player player)
{
    sets[currentSetIndex].pointWonBy(player);
    pointCount++;

    if(sets[currentSetIndex].isEnded())
    {    	
		currentSetIndex++;
		pointCount = 0;
    }
}

void TennisScoringSystem::pointsWonBy(Player player, const int nbPointsWon)
{
	for(int i = 0;i < nbPointsWon;i++)
		pointWonBy(player);
}

std::string TennisScoringSystem::fullEnglishScore() const
{
	std::string res = "";

	for(int i = 0;i < sets.size();i++)
	{
		res += "Set " +  std::to_string(i+1) + " " + sets[i].fullEnglishScore() + "\n";
	}

	return res;
}

std::string TennisScoringSystem::plainEnglishScore(int setIndex, int gameIndex) const 
{
	if(setIndex < 0)
		setIndex = currentSetIndex;

	if(gameIndex < 0)
		gameIndex = sets[setIndex].getCurrentGameIndex();

    return sets[setIndex].plainEnglishScore(gameIndex);
}

std::string TennisScoringSystem::fullNumericalScore() const
{
	std::string res = "";

	for(int i = 0;i < sets.size();i++)
	{
		res += "Set " +  std::to_string(i+1) + " " + sets[i].fullNumericalScore() + "\n";
	}

	return res;
}

std::string TennisScoringSystem::plainNumericalScore(int setIndex, int gameIndex) const
{
	if(setIndex < 0)
		setIndex = currentSetIndex;

	if(gameIndex < 0)
		gameIndex = sets[setIndex].getCurrentGameIndex();

	return sets[setIndex].plainNumericalScore(gameIndex);
}

std::string TennisScoringSystem::fullScore() const
{
	std::string res = "";

	for(int i = 0;i < sets.size();i++)
	{
		res += "Set " + std::to_string(i+1) + " " + sets[i].fullScore() + "\n";
	}

	return res;
}

std::string TennisScoringSystem::score(int setIndex, int gameIndex) const
{
	if(setIndex < 0)
		setIndex = currentSetIndex;

	if(gameIndex < 0)
		gameIndex = sets[setIndex].getCurrentGameIndex();

	return sets[setIndex].score(gameIndex);
}

int TennisScoringSystem::currentPointInSet() const {
    return pointCount;
}

void TennisScoringSystem::setPlayerName(Player player,const char* name)
{

}

TennisScoringSystem::Player TennisScoringSystem::getWinner() const
{
	int pointsPlayer1 = 0;
	int pointsPlayer2 = 0;

	for(TennisSetScoringSystem set : sets)
	{
		pointsPlayer1 += set.getNbGamesWonBy(Player1);
		pointsPlayer2 += set.getNbGamesWonBy(Player2);
	}

	return pointsPlayer1 > pointsPlayer2 ? Player1 : Player2;
}

int TennisScoringSystem::getNbSetsWonBy(Player player) const
{
	int nbSetsWonByPlayer = 0;
	for(TennisSetScoringSystem set : sets)
	{
		if(set.isEnded() && set.getWinner() == player)
		{
			nbSetsWonByPlayer++;
		}
	}
	return nbSetsWonByPlayer;
}

bool TennisScoringSystem::isEnded() const
{
	int nbSetsWonByPlayer1 = getNbSetsWonBy(Player1);
	int nbSetsWonByPlayer2 = getNbSetsWonBy(Player2);
	
	int nbSetsToWin = std::ceil( (float)sets.size() / 2.0 );

	return nbSetsWonByPlayer1 == nbSetsToWin || nbSetsWonByPlayer2 == nbSetsToWin;
}

TennisScoringSystem::Player TennisScoringSystem::getServer() const
{
	return Player1;
}

std::string TennisScoringSystem::getServerName() const
{
	return "";
}

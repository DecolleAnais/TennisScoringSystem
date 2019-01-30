#include "TennisScoringSystem.h"
#include <cmath>

TennisScoringSystem::TennisScoringSystem(TeamsFormat teamsFormat, NbSetsFormat nbSetsFormat) : teamsFormat(teamsFormat)
{
	for(int i = 0;i < nbSetsFormat;i++)
	{
		sets.push_back(new TennisSetScoringSystem());
	}
}

TennisScoringSystem::~TennisScoringSystem()
{
	for(int i = sets.size() - 1;i >= 0;i--)
	{
		delete(sets[i]);
	}
}

void TennisScoringSystem::pointWonBy(Team team)
{
	// keep the current game index of the current set
    int gameIndexInSet = sets[currentSetIndex]->getCurrentGameIndex();

    // add a point to the team
    sets[currentSetIndex]->pointWonBy(team);
    pointCount++;

    if(sets[currentSetIndex]->isEnded())
    {   	
    	gameCount++;
		currentSetIndex++;
		pointCount = 0;
    }
    else if(sets[currentSetIndex]->isGameEnded(gameIndexInSet))
    {
    	gameCount++;
    }
}

void TennisScoringSystem::pointsWonBy(Team team, const int nbPointsWon)
{
	for(int i = 0;i < nbPointsWon;i++)
		pointWonBy(team);
}

std::string TennisScoringSystem::fullEnglishScore() const
{
	std::string res = "";

	for(int i = 0;i < sets.size();i++)
	{
		res += "Set " +  std::to_string(i+1) + " " + sets[i]->fullEnglishScore() + "\n";
	}

	return res;
}

std::string TennisScoringSystem::plainEnglishScore(int setIndex, int gameIndex) const 
{
	if(setIndex < 0)
		setIndex = currentSetIndex;

	if(gameIndex < 0)
		gameIndex = sets[setIndex]->getCurrentGameIndex();

    return sets[setIndex]->plainEnglishScore(gameIndex);
}

std::string TennisScoringSystem::fullNumericalScore() const
{
	std::string res = "";

	for(int i = 0;i < sets.size();i++)
	{
		res += "Set " +  std::to_string(i+1) + " " + sets[i]->fullNumericalScore() + "\n";
	}

	return res;
}

std::string TennisScoringSystem::plainNumericalScore(int setIndex, int gameIndex) const
{
	if(setIndex < 0)
		setIndex = currentSetIndex;

	if(gameIndex < 0)
		gameIndex = sets[setIndex]->getCurrentGameIndex();

	return sets[setIndex]->plainNumericalScore(gameIndex);
}

std::string TennisScoringSystem::fullScore() const
{
	std::string res = "";

	for(int i = 0;i < sets.size();i++)
	{
		res += "Set " + std::to_string(i+1) + " " + sets[i]->fullScore() + "\n";
	}

	return res;
}

std::string TennisScoringSystem::score(int setIndex, int gameIndex) const
{
	if(setIndex < 0)
		setIndex = currentSetIndex;

	if(gameIndex < 0)
		gameIndex = sets[setIndex]->getCurrentGameIndex();

	return sets[setIndex]->score(gameIndex);
}

std::string TennisScoringSystem::getFinalScore() const
{
	return "";
}


int TennisScoringSystem::currentPointInSet() const {
    return pointCount;
}

void TennisScoringSystem::setPlayerName(Player player,const char* name)
{
	mapOfPlayerNames.emplace(player, std::string(name));
}

TennisScoringSystem::Team TennisScoringSystem::getPlayerTeam(Player player) const
{
	return (TennisScoringSystem::Team) mapOfPlayerTeams.at(player);
}

TennisScoringSystem::Team TennisScoringSystem::getWinner() const
{
	int pointsTeam1 = 0;
	int pointsTeam2 = 0;

	for(TennisSetScoringSystem * set : sets)
	{
		pointsTeam1 += set->getNbGamesWonBy(Team1);
		pointsTeam2 += set->getNbGamesWonBy(Team2);
	}

	return pointsTeam1 > pointsTeam2 ? Team1 : Team2;
}

int TennisScoringSystem::getNbSetsWonBy(Team team) const
{
	int nbSetsWonByTeam = 0;

	for(TennisSetScoringSystem * set : sets)
	{
		if(set->isEnded() && set->getWinner() == team)
		{
			nbSetsWonByTeam++;
		}
	}
	return nbSetsWonByTeam;
}

bool TennisScoringSystem::isEnded() const
{
	int nbSetsWonByTeam1 = getNbSetsWonBy(Team1);
	int nbSetsWonByTeam2 = getNbSetsWonBy(Team2);
	
	int nbSetsToWin = std::ceil( (float)sets.size() / 2.0 );

	return nbSetsWonByTeam1 == nbSetsToWin || nbSetsWonByTeam2 == nbSetsToWin;
}

TennisScoringSystem::Player TennisScoringSystem::getServer() const
{
	int nbPlayers = (teamsFormat == TeamsFormat::Single) ? 2 : 4;

	if(sets[currentSetIndex]->isTieBreakGame())
	{
		//TennisScoringSystem::Player firstServer = (gameCount % 2 == 0) ? Player1 : Player2;
		int firstServer = gameCount % nbPlayers;

		int currentPoint = sets[currentSetIndex]->currentPointInGame();

		//int playerValue =  (int) (firstServer + std::ceil( (float)currentPoint / 2.0) ) % 2;
		int playerValue =  (int) (firstServer + std::ceil( (float)currentPoint / 2.0) ) % nbPlayers;

		return (TennisScoringSystem::Player) playerValue;
	}
	else
	{
		return (TennisScoringSystem::Player) (gameCount % nbPlayers);
	}	
}

std::string TennisScoringSystem::getServerName() const
{
	TennisScoringSystem::Player server = getServer();

	return mapOfPlayerNames.at(server);
}

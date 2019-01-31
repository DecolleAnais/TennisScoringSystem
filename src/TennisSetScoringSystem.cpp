#include "TennisSetScoringSystem.h"
#include "TennisGameAdvantageScoringSystem.h"
#include "TennisGameTieBreakScoringSystem.h"
#include <typeinfo>

TennisSetScoringSystem::TennisSetScoringSystem()
{
	for(int i = 0;i < 6;i++)
	{
		games.push_back(new TennisGameAdvantageScoringSystem());
	}
}

TennisSetScoringSystem::~TennisSetScoringSystem()
{
	for(int i = games.size() - 1;i >= 0;i--)
	{
		delete(games[i]);
	}
}

void TennisSetScoringSystem::pointWonBy(const int player)
{
	// add point
	games[currentGameIndex]->pointWonBy(player);

	// if current game is ended, increments index
	if(games[currentGameIndex]->isEnded())
	{
		currentGameIndex++;

		// if set is not ended and the games vector is full, add a new game
		if(!isEnded() && currentGameIndex == games.size())
		{
			// if equality in set score (6-6), the last game is a tie break
			if(games.size() == 12)
			{
				games.push_back(new TennisGameTieBreakScoringSystem());
			}
			else
			{
				games.push_back(new TennisGameAdvantageScoringSystem());
			}			
		}
	}

}

void TennisSetScoringSystem::pointsWonBy(const int player, const int nbPointsWon)
{
	for(int i = 0;i < nbPointsWon;i++)
	{
		pointWonBy(player);
	}
}

std::string TennisSetScoringSystem::fullEnglishScore(const bool reverseOrder) const
{
	std::string res = "";

	for(TennisGameScoringSystem *game : games)
	{
		res += "| " + game->plainEnglishScore(reverseOrder) + " |";
	}

	return res;
}

std::string TennisSetScoringSystem::plainEnglishScore(int gameIndex, const bool reverseOrder) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;

	return games[gameIndex]->plainEnglishScore(reverseOrder);
}

std::string TennisSetScoringSystem::fullNumericalScore(const bool reverseOrder) const
{
	std::string res = "";

	for(TennisGameScoringSystem *game : games)
	{
		res += "| " + game->plainNumericalScore(reverseOrder) + " |";
	}

	return res;
}

std::string TennisSetScoringSystem::plainNumericalScore(int gameIndex, const bool reverseOrder) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;

	return games[gameIndex]->plainNumericalScore(reverseOrder);
}

std::string TennisSetScoringSystem::fullScore(const bool reverseOrder) const
{
	std::string res = "";

	for(int i = 0;i  < games.size();i++)
	{
		res += "| " + score(i, reverseOrder) + " |";
	}

	return res;
}
std::string TennisSetScoringSystem::score(int gameIndex, const bool reverseOrder) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;
	
	if(reverseOrder)
		return std::to_string(games[gameIndex]->getScoreOf(1)) + "-" + std::to_string(games[gameIndex]->getScoreOf(0));
	else
		return std::to_string(games[gameIndex]->getScoreOf(0)) + "-" + std::to_string(games[gameIndex]->getScoreOf(1));
}

std::vector<std::array<int,2>> TennisSetScoringSystem::getPointScores(const bool reverseOrder) const
{
	std::vector<std::array<int,2>> pointScores;

	for(int i = 0;i < games.size();i++)
		pointScores.push_back(getPointScore(i, reverseOrder));

	return pointScores;
}

std::array<int,2> TennisSetScoringSystem::getPointScore(int gameIndex, const bool reverseOrder) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;
	
	return games[gameIndex]->getGameScore(reverseOrder);
}

std::array<int,2> TennisSetScoringSystem::getNbGamesWonByTeams() const
{
	std::array<int,2> nbGamesWonByTeams = {0};

	for(TennisGameScoringSystem *game : games)
	{
		if(game->isEnded())
		{
			nbGamesWonByTeams[game->getWinner()]++;
		}
	}
	return nbGamesWonByTeams;
}

int TennisSetScoringSystem::getNbGamesWonBy(int player) const
{
	int nbGamesWonByPlayer = 0;
	for(TennisGameScoringSystem *game : games)
	{
		if(game->isEnded() && game->getWinner() == player)
		{
			nbGamesWonByPlayer++;
		}
	}
	return nbGamesWonByPlayer;
}

int TennisSetScoringSystem::getWinner() const
{
	int nbGamesWonByPlayer1 = getNbGamesWonBy(0);
	int nbGamesWonByPlayer2 = games.size() - nbGamesWonByPlayer1;

	if(nbGamesWonByPlayer1 == nbGamesWonByPlayer2)
		return -1;

	return nbGamesWonByPlayer1 > nbGamesWonByPlayer2 ? 0 : 1;
}

bool TennisSetScoringSystem::isEnded() const
{
	int nbGamesWonByPlayer1 = getNbGamesWonBy(0);
	int nbGamesWonByPlayer2 = getNbGamesWonBy(1);

	//advantage game case
	bool endedByAdvantage = (nbGamesWonByPlayer1 == 6 || nbGamesWonByPlayer2 == 6)  && std::abs(nbGamesWonByPlayer1 - nbGamesWonByPlayer2) >= 2;

	// tie-break game case (if score for games is 6-6)
	bool endedByTieBreak = nbGamesWonByPlayer1 >= 6 && nbGamesWonByPlayer2 >= 6 && std::abs(nbGamesWonByPlayer1 - nbGamesWonByPlayer2) == 1;

	return endedByAdvantage || endedByTieBreak;
}

int TennisSetScoringSystem::getCurrentGameIndex() const
{
	return currentGameIndex;
}

bool TennisSetScoringSystem::isGameEnded(int gameIndex) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;

	return games[gameIndex]->isEnded();
}

bool TennisSetScoringSystem::isTieBreakGame(int gameIndex) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;

	return typeid(*games[gameIndex]) == typeid(TennisGameTieBreakScoringSystem); 
}

int TennisSetScoringSystem::currentPointInGame(int gameIndex) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;

	return games[gameIndex]->currentPoint();
}
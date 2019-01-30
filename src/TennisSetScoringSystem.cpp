#include "TennisSetScoringSystem.h"
#include "TennisGameAdvantageScoringSystem.h"
#include "TennisGameTieBreakScoringSystem.h"
#include <iostream>

TennisSetScoringSystem::TennisSetScoringSystem()
{
	for(int i = 0;i < 6;i++)
	{
		games.push_back(new TennisGameAdvantageScoringSystem());
	}
}

void TennisSetScoringSystem::pointWonBy(const int player)
{
	games[currentGameIndex]->pointWonBy(player);

	if(games[currentGameIndex]->isEnded())
	{
		currentGameIndex++;
		if(!isEnded() && currentGameIndex == games.size())
		{
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

std::string TennisSetScoringSystem::fullEnglishScore() const
{
	std::string res = "";

	for(TennisGameScoringSystem *game : games)
	{
		res += "| " + game->plainEnglishScore() + " |";
	}

	return res;
}

std::string TennisSetScoringSystem::plainEnglishScore(int gameIndex) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;

	return games[gameIndex]->plainEnglishScore();
}

std::string TennisSetScoringSystem::fullNumericalScore() const
{
	std::string res = "";

	for(TennisGameScoringSystem *game : games)
	{
		res += "| " + game->plainNumericalScore() + " |";
	}

	return res;
}

std::string TennisSetScoringSystem::plainNumericalScore(int gameIndex) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;

	return games[gameIndex]->plainNumericalScore();
}

std::string TennisSetScoringSystem::fullScore() const
{
	std::string res = "";

	for(int i = 0;i  < games.size();i++)
	{
		res += "| " + score(i) + " |";
	}

	return res;
}
std::string TennisSetScoringSystem::score(int gameIndex) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;
	
	return std::to_string(games[gameIndex]->getScoreOf(0)) + "-" + std::to_string(games[gameIndex]->getScoreOf(1));
}

std::vector<std::array<int,2>> TennisSetScoringSystem::getGameScores() const
{
	std::vector<std::array<int,2>> gameScores;

	for(int i = 0;i < games.size();i++)
		gameScores.push_back(getGameScore(i));

	return gameScores;
}

std::array<int,2> TennisSetScoringSystem::getGameScore(int gameIndex) const
{
	if(gameIndex < 0)
		gameIndex = currentGameIndex;
	
	return games[gameIndex]->getGameScore();
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
#include "TennisSetScoringSystem.h"

TennisSetScoringSystem::TennisSetScoringSystem()
{
	games.resize(6);
}

void TennisSetScoringSystem::pointWonBy(const int player)
{
	games[currentGameIndex].pointWonBy(player);

	if(games[currentGameIndex].isEnded())
	{
		currentGameIndex++;
		if(!isEnded() && currentGameIndex == games.size())
		{
			TennisGameScoringSystem newGame;
			games.push_back(newGame);
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

std::string TennisSetScoringSystem::plainEnglishScore() const
{
	std::string res = "";

	for(TennisGameScoringSystem game : games)
	{
		res += "| " + game.plainEnglishScore() + " |";
	}

	return res;
}

std::string TennisSetScoringSystem::plainEnglishScore(const int gameIndex) const
{
	return games[gameIndex].plainEnglishScore();
}

std::string TennisSetScoringSystem::plainNumericalScore() const
{
	std::string res = "";

	for(TennisGameScoringSystem game : games)
	{
		res += "| " + game.plainNumericalScore() + " |";
	}

	return res;
}
std::string TennisSetScoringSystem::plainNumericalScore(const int gameIndex) const
{
	return games[gameIndex].plainNumericalScore();
}

std::string TennisSetScoringSystem::score() const
{
	std::string res = "";

	for(int i = 0;i  < games.size();i++)
	{
		res += "| " + score(i) + " |";
	}

	return res;
}
std::string TennisSetScoringSystem::score(const int gameIndex) const
{
	return std::to_string(games[gameIndex].getScoreOf(0)) + "-" + std::to_string(games[gameIndex].getScoreOf(1));
}

std::vector<std::array<int,2>> TennisSetScoringSystem::getGameScores() const
{
	std::vector<std::array<int,2>> gameScores;

	for(int i = 0;i < games.size();i++)
		gameScores.push_back(getGameScore(i));

	return gameScores;
}

std::array<int,2> TennisSetScoringSystem::getGameScore(const int gameIndex) const
{
	return games[gameIndex].getGameScore();
}

int TennisSetScoringSystem::getNbGamesWonBy(int player) const
{
	int nbGamesWonByPlayer = 0;
	for(TennisGameScoringSystem game : games)
	{
		if(game.isEnded() && game.getWinner() == player)
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
	//return games[5].isEnded() && std::abs(nbGamesWonByPlayer1 - nbGamesWonByPlayer2) >= 2; 

	// tie-break game case
	return games[5].isEnded() && nbGamesWonByPlayer1 != nbGamesWonByPlayer2; 
}
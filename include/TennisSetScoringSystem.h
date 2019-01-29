#pragma once
#include <vector>
#include <array>
#include "TennisGameScoringSystem.h"

class TennisSetScoringSystem
{
private:
	std::vector<TennisGameScoringSystem> games;

	int currentGameIndex = 0;

public:
	TennisSetScoringSystem();

	void pointWonBy(const int player);
	void pointsWonBy(const int player, const int nbPointsWon);

	std::string fullEnglishScore() const;
	std::string plainEnglishScore(int gameIndex = -1) const;

	std::string fullNumericalScore() const;
	std::string plainNumericalScore(int gameIndex = -1) const;

	std::string fullScore() const;
	std::string score(int gameIndex = -1) const;

	std::vector<std::array<int,2>> getGameScores() const;
	std::array<int,2> getGameScore(int gameIndex = -1) const;

	int getNbGamesWonBy(int player) const;
	int getWinner() const;

	bool isEnded() const;

	int getCurrentGameIndex() const;
};
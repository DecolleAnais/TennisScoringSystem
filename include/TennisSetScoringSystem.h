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

	std::string plainEnglishScore() const;
	std::string plainEnglishScore(const int gameIndex) const;

	std::string plainNumericalScore() const;
	std::string plainNumericalScore(const int gameIndex) const;

	std::string score() const;
	std::string score(const int gameIndex) const;

	std::vector<std::array<int,2>> getGameScores() const;
	std::array<int,2> getGameScore(const int gameIndex) const;

	int getNbGamesWonBy(int player) const;
	int getWinner() const;

	bool isEnded() const;
};
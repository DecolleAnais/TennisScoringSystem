#pragma once
#include <vector>
#include <array>
#include "TennisGameScoringSystem.h"

class TennisSetScoringSystem
{
private:
	std::vector<TennisGameScoringSystem*> games;

	int currentGameIndex = 0;

public:
	TennisSetScoringSystem();
	~TennisSetScoringSystem();

	void pointWonBy(const int player);
	void pointsWonBy(const int player, const int nbPointsWon);

	std::string fullEnglishScore(const bool reverseOrder = false) const;
	std::string plainEnglishScore(int gameIndex = -1, const bool reverseOrder = false) const;

	std::string fullNumericalScore(const bool reverseOrder = false) const;
	std::string plainNumericalScore(int gameIndex = -1, const bool reverseOrder = false) const;

	std::string fullScore(const bool reverseOrder = false) const;
	std::string score(int gameIndex = -1, const bool reverseOrder = false) const;

	std::vector<std::array<int,2>> getPointScores(const bool reverseOrder = false) const;
	std::array<int,2> getPointScore(int gameIndex = -1, const bool reverseOrder = false) const;

	std::array<int,2> getNbGamesWonByTeams() const;
	int getNbGamesWonBy(int player) const;
	int getWinner() const;

	bool isEnded() const;

	int getCurrentGameIndex() const;

	bool isGameEnded(int gameIndex = -1) const;

	bool isTieBreakGame(int gameIndex = -1) const;

	int currentPointInGame(int gameIndex = -1) const;
};
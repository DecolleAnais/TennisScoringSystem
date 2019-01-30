#pragma once
#include <array>
#include <string>
#include <map>


class TennisGameScoringSystem
{
protected:

	std::array<int,2> gameScore = {0, 0};

	int minPointsToWin;

public:

	TennisGameScoringSystem(){};

	void pointWonBy(int player);

	void pointsWonBy(int player, const int nbPointsWon);

	virtual std::string plainEnglishScore() const = 0;

	virtual std::string plainNumericalScore() const = 0;

	std::array<int,2> getGameScore() const;

	int getScoreOf(int player) const;

	int getWinner() const;

	virtual bool isEnded() const = 0;

	int currentPoint() const;
};

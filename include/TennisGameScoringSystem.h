#pragma once
#include <array>
#include <string>
#include <map>


class TennisGameScoringSystem
{
private:

	std::array<int,2> gameScore = {0, 0};

	std::map<int, std::string> mapOfPlainEnglishScores = 
	{
		{0, "Love"},
		{1, "Fifteen"},
		{2, "Thirty"},
		{3, "Forty"}
	};

	std::map<int, std::string> mapOfPlainNumericalScores = 
	{
		{0, "0"},
		{1, "15"},
		{2, "30"},
		{3, "40"}
	};

	int maxPossibleScore;


public:

	TennisGameScoringSystem();

	void pointWonBy(int player);

	void pointsWonBy(int player, const int nbPointsWon);

	std::string plainEnglishScore() const;

	std::string plainNumericalScore() const;

	std::array<int,2> getGameScore() const;

	int getScoreOf(int player) const;

	int getWinner() const;

	bool isEnded() const;
};

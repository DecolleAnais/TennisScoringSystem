#pragma once
#include "TennisGameScoringSystem.h"

class TennisGameAdvantageScoringSystem : public TennisGameScoringSystem
{
private:

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

	TennisGameAdvantageScoringSystem();

	std::string plainEnglishScore(const bool reverseOrder = false) const;

	std::string plainNumericalScore(const bool reverseOrder = false) const;

	bool isEnded() const;
};
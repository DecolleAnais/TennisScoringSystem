#pragma once
#include "TennisGameScoringSystem.h"

class TennisGameTieBreakScoringSystem : public TennisGameScoringSystem
{
private:

public:

	TennisGameTieBreakScoringSystem(const int tieBreakValue = 7);

	std::string plainEnglishScore() const;

	std::string plainNumericalScore() const;

	bool isEnded() const;
};
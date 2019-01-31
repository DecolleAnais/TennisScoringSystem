#pragma once
#include "TennisGameScoringSystem.h"

class TennisGameTieBreakScoringSystem : public TennisGameScoringSystem
{
private:

public:

	TennisGameTieBreakScoringSystem(const int tieBreakValue = 7);

	std::string plainEnglishScore(const bool reverseOrder = false) const;

	std::string plainNumericalScore(const bool reverseOrder = false) const;

	bool isEnded() const;
};
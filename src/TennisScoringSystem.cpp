#include "TennisScoringSystem.h"

void TennisScoringSystem::pointWonBy(Player player)
{
    pointCount++;
}

std::string TennisScoringSystem::plainEnglishScore() const {
    return pointCount == 0 ? "Love-Love" : "Fifteen-Love";
}

int TennisScoringSystem::currentPointInSet() const {
    return pointCount;
}

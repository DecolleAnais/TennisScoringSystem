#pragma once
#include "TennisSetScoringSystem.h"


class TennisScoringSystem
{
private:
  int pointCount {0};

  std::vector<TennisSetScoringSystem> sets;

public:
  enum Player {
    Player1,
    Player2,
  };

  enum NbSetsFormat {
    BestOfThree = 3,
    BestOfFive = 5
  };

  TennisScoringSystem(NbSetsFormat nbSetsFormat = NbSetsFormat::BestOfThree);

  void pointWonBy(Player player);

  void pointsWonBy(Player player, const int nbPointsWon);

  std::string fullEnglishScore() const;
  std::string plainEnglishScore() const;

  std::string fullNumericalScore() const;
  std::string plainNumericalScore() const;

  std::string fullScore() const;
  std::string score() const;

  int currentSet() const { return 0; }
  
  int currentPointInSet() const;

  void setPlayerName(Player player,const char* name) {}

  Player getWinner() const;

  bool isEnded() const;
};

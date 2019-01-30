#pragma once
#include "TennisSetScoringSystem.h"

class TennisScoringSystem
{
private:
  int pointCount {0};
  int gameCount {0};

  std::vector<TennisSetScoringSystem*> sets;

  int currentSetIndex = 0;

  std::map<int, std::string> mapOfPlayerNames;

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
  ~TennisScoringSystem();

  void pointWonBy(Player player);

  void pointsWonBy(Player player, const int nbPointsWon);

  std::string fullEnglishScore() const;
  std::string plainEnglishScore(int setIndex = -1, int gameIndex = -1) const;

  std::string fullNumericalScore() const;
  std::string plainNumericalScore(int setIndex = -1, int gameIndex = -1) const;

  std::string fullScore() const;
  std::string score(int setIndex = -1, int gameIndex = -1) const;

  int currentSet() const { return currentSetIndex; }
  
  int currentPointInSet() const;

  void setPlayerName(Player player,const char* name);

  Player getWinner() const;

  int getNbSetsWonBy(Player player) const;

  bool isEnded() const;

  Player getServer() const;

  std::string getServerName() const;
};

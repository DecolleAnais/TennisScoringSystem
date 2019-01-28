#pragma once
#include <string>


class TennisScoringSystem
{
private:
  int pointCount {0};

public:
  enum Player {
    Player1,
    Player2,
  };

  void pointWonBy(Player player);

  std::string plainEnglishScore() const;

  int currentSet() const { return 0; }
  
  int currentPointInSet() const;

  void setPlayerName(Player player,const char* name) {}
};

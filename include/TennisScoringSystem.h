#pragma once
#include "TennisSetScoringSystem.h"

class TennisScoringSystem
{

public:
  enum Player {
    Player1,
    Player2,
    Player3,
    Player4
  };

  enum Team {
    Team1,
    Team2
  };

  enum NbSetsFormat {
    BestOfThree = 3,
    BestOfFive = 5
  };

  enum TeamsFormat
  {
    Single,
    Double
  };

  TennisScoringSystem(TeamsFormat teamsFormat = TeamsFormat::Single, NbSetsFormat nbSetsFormat = NbSetsFormat::BestOfThree);
  ~TennisScoringSystem();

  void pointWonBy(Team team);

  void pointsWonBy(Team team, const int nbPointsWon);

  std::string fullEnglishScore() const;
  std::string plainEnglishScore(int setIndex = -1, int gameIndex = -1) const;

  std::string fullNumericalScore() const;
  std::string plainNumericalScore(int setIndex = -1, int gameIndex = -1) const;

  std::string fullScore() const;
  std::string score(int setIndex = -1, int gameIndex = -1) const;

  std::string getFinalScore() const;

  int currentSet() const { return currentSetIndex; }
  
  int currentPointInSet() const;

  void setPlayerName(Player player,const char* name);

  Team getPlayerTeam(Player player) const;

  Team getWinner() const;

  int getNbSetsWonBy(Team team) const;

  bool isEnded() const;

  Player getServer() const;

  std::string getServerName() const;

  bool scoreDisplayShouldBeReversed() const;

private:
  int pointCount {0};
  int gameCount {0};

  std::vector<TennisSetScoringSystem*> sets;

  int currentSetIndex = 0;

  std::map<int, std::string> mapOfPlayerNames;

  std::map<int, int> mapOfPlayerTeams =
  {
    {Player1, Team1},
    {Player2, Team2},
    {Player3, Team1},
    {Player4, Team2}
  };

  TeamsFormat teamsFormat;

  std::array<int,2> finalScore = {0, 0};
};

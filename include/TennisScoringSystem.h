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

/*!
 * \brief display the full score in english
 * Example : 
 * Set 1 | Thirty-Fifteen || Love-All || Love-All || Love-All || Love-All || Love-All |
 * Set 2 | Love-All || Love-All || Love-All || Love-All || Love-All || Love-All |
 * Set 3 | Love-All || Love-All || Love-All || Love-All || Love-All || Love-All |
 */
  std::string fullEnglishScore() const;

/*!
 * \brief display the score in english
 * Example : 
 * Fifteen-Love
 */
  std::string plainEnglishScore(int setIndex = -1, int gameIndex = -1) const;

/*!
 * \brief display the full score with numerical values
 * Example : 
 * Set 1 | 15-30 || 0-0 || 0-0 || 0-0 || 0-0 || 0-0 |
 * Set 2 | 0-0 || 0-0 || 0-0 || 0-0 || 0-0 || 0-0 |
 * Set 3 | 0-0 || 0-0 || 0-0 || 0-0 || 0-0 || 0-0 |
 */
  std::string fullNumericalScore() const;

/*!
 * \brief display the score with numerical values
 * Example : 
 * 40A-40 
 * or
 * 15-30
 */
  std::string plainNumericalScore(int setIndex = -1, int gameIndex = -1) const;



/*!
 * \brief display the full score with points values
 * Example : 
 * Set 1 | 0-4 || 0-0 || 0-0 || 0-0 || 0-0 || 0-0 |
 * Set 2 | 0-0 || 0-0 || 0-0 || 0-0 || 0-0 || 0-0 |
 * Set 3 | 0-0 || 0-0 || 0-0 || 0-0 || 0-0 || 0-0 |
 */
  std::string fullScore() const;

/*!
 * \brief display the score with points values
 * Example : 
 * 0-4
 */
  std::string score(int setIndex = -1, int gameIndex = -1) const;


/*!
 * \brief display the final score (nb games won * 4)
 * Example : 
 * 39-38
 */
  std::string getFinalScore() const;

  int currentSet() const { return currentSetIndex; }
  
  int currentPointInSet() const;

  void setPlayerName(Player player,const std::string name);

  Team getPlayerTeam(Player player) const;

  int getWinner() const;

  std::string getNamesInTeam(TennisScoringSystem::Team team) const;

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

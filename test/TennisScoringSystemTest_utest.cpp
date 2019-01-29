#include "gtest/gtest.h"
#include "TennisScoringSystem.h"
#include <string>



TEST(TennisScoringSystemTest, at_start_the_plain_english_score_should_be_LoveAll)
{
    TennisScoringSystem tennisMatch;
    ASSERT_EQ(tennisMatch.plainEnglishScore(),"Love-All");
    ASSERT_EQ(0, tennisMatch.currentSet());
    ASSERT_EQ(0, tennisMatch.currentPointInSet());
    ASSERT_FALSE(tennisMatch.isEnded());
}

TEST(TennisScoringSystemTest, if_player1_wins_first_point_the_plain_english_score_should_be_FithTeenLove)
{
    // Given a Tennis match
    TennisScoringSystem tennisMatch;
    
    // When player1 wins first point
    tennisMatch.pointWonBy(TennisScoringSystem::Player1);

    // Then score should be "Fifhteen-Love" 
    ASSERT_EQ(tennisMatch.plainEnglishScore(),"Fifteen-Love");
    
    // And current set should still be 0
    ASSERT_EQ(0, tennisMatch.currentSet());

    // And current Point in Set should now be 1
    ASSERT_EQ(1, tennisMatch.currentPointInSet());

    // match should not be ended
    ASSERT_FALSE(tennisMatch.isEnded());
}

TEST(TennisScoringSystemTest, after_1_set_ended_the_plain_english_score_should_be_LoveAll)
{
    // a tennis match in 3 sets by default
    TennisScoringSystem tennisMatch;

    int nbPointsInAGame = 4;
    int nbGamesInASet = 6;

    // player1 wins 1 set
    tennisMatch.pointsWonBy(TennisScoringSystem::Player1, nbPointsInAGame * nbGamesInASet);

    // check current score
    ASSERT_EQ(tennisMatch.plainEnglishScore(),"Love-All");
    ASSERT_EQ(tennisMatch.plainNumericalScore(),"0-0");
    ASSERT_EQ(tennisMatch.score(),"0-0");

    // check full score
    std::string fullEnglishScore = "Set 1 | Game won by Player1 || Game won by Player1 || Game won by Player1 |\n"
                                   "Set 2 | Love-All || Love-All || Love-All |\n"
                                   "Set 3 | Love-All || Love-All || Love-All |\n";

    ASSERT_EQ(tennisMatch.fullEnglishScore(), fullEnglishScore.c_str());

    std::string fullNumericalScore = "Set 1 | Game won by Player1 || Game won by Player1 || Game won by Player1 |\n"
                                     "Set 2 | 0-0 || 0-0 || 0-0 |\n"
                                     "Set 3 | 0-0 || 0-0 || 0-0 |\n";

    ASSERT_EQ(tennisMatch.fullNumericalScore(), fullNumericalScore.c_str());

    std::string fullScore = "Set 1 | 4-0 || 4-0 || 4-0 |\n"
                            "Set 2 | 0-0 || 0-0 || 0-0 |\n"
                            "Set 3 | 0-0 || 0-0 || 0-0 |\n";

    ASSERT_EQ(tennisMatch.fullScore(), fullScore.c_str());

    ASSERT_EQ(1, tennisMatch.currentSet());
    ASSERT_EQ(0, tennisMatch.currentPointInSet());

    // match should not be ended
    ASSERT_FALSE(tennisMatch.isEnded());
}

TEST(TennisScoringSystemTest, after_2_sets_won_by_player1_the_match_should_be_ended)
{
    // a tennis match in 3 sets by default
    TennisScoringSystem tennisMatch;

    int nbPointsInAGame = 4;
    int nbGamesInASet = 6;
    int nbSets = 2;

    // player1 wins 2 sets
    tennisMatch.pointsWonBy(TennisScoringSystem::Player1, nbPointsInAGame * nbGamesInASet * nbSets);

    // match should be ended
    ASSERT_TRUE(tennisMatch.isEnded());
    ASSERT_EQ(tennisMatch.getWinner(), 0);
}

TEST(TennisScoringSystemTest, after_1_set_won_by_each_player_the_match_should_not_be_ended)
{
    // a tennis match in 3 sets by default
    TennisScoringSystem tennisMatch;

    int nbPointsInAGame = 4;
    int nbGamesInASet = 6;

    // player1 wins 1 set
    tennisMatch.pointsWonBy(TennisScoringSystem::Player1, nbPointsInAGame * nbGamesInASet);

    // player2 wins 1 set
    tennisMatch.pointsWonBy(TennisScoringSystem::Player2, nbPointsInAGame * nbGamesInASet);

    // match should not be ended
    ASSERT_FALSE(tennisMatch.isEnded());
}

TEST(TennisScoringSystemTest, after_1_set_won_by_player1_and_2_sets_won_by_player2_the_match_should_be_ended)
{
    // a tennis match in 3 sets by default
    TennisScoringSystem tennisMatch;

    int nbPointsInAGame = 4;
    int nbGamesInASet = 6;

    // player1 wins 1 set
    tennisMatch.pointsWonBy(TennisScoringSystem::Player1, nbPointsInAGame * nbGamesInASet);

    // player2 wins 2 sets
    tennisMatch.pointsWonBy(TennisScoringSystem::Player2, nbPointsInAGame * nbGamesInASet * 2);

    // match should be ended
    ASSERT_TRUE(tennisMatch.isEnded());
    ASSERT_EQ(tennisMatch.getWinner(), 1);
}




int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

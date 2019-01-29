#include "gtest/gtest.h"
#include "TennisScoringSystem.h"
#include "TennisGameScoringSystem.h"

// Game Tests

TEST(TennisGameScoringSystemTest, at_start_the_plain_english_score_should_be_LoveAll)
{
    TennisGameScoringSystem game;
    ASSERT_EQ(game.plainEnglishScore(),"Love-All");
    ASSERT_EQ(game.plainNumericalScore(),"0-0");
    ASSERT_FALSE(game.isEnded());
}

TEST(TennisGameScoringSystemTest, if_player1_wins_first_point_the_plain_english_score_should_be_FitTeenLove)
{
    TennisGameScoringSystem game;
    game.pointWonBy(TennisScoringSystem::Player1);
    ASSERT_EQ(game.plainEnglishScore(),"Fifteen-Love");
    ASSERT_EQ(game.plainNumericalScore(),"15-0");
    ASSERT_FALSE(game.isEnded());
}

TEST(TennisGameScoringSystemTest, if_player1_wins_first_2_points_the_plain_english_score_should_be_ThirtyLove)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player1, 2);
    ASSERT_EQ(game.plainEnglishScore(),"Thirty-Love");
    ASSERT_EQ(game.plainNumericalScore(),"30-0");
    ASSERT_FALSE(game.isEnded());
}

TEST(TennisGameScoringSystemTest, if_player1_wins_first_3_points_the_plain_english_score_should_be_FortyLove)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player1, 3);
    ASSERT_EQ(game.plainEnglishScore(),"Forty-Love");
    ASSERT_EQ(game.plainNumericalScore(),"40-0");
    ASSERT_FALSE(game.isEnded());
}

TEST(TennisGameScoringSystemTest, if_player1_wins_first_2_points_and_player2_wins_3_points_the_plain_english_score_should_be_ThirtyForty)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player1, 2);
    game.pointsWonBy(TennisScoringSystem::Player2, 3);
    ASSERT_EQ(game.plainEnglishScore(),"Thirty-Forty");
    ASSERT_EQ(game.plainNumericalScore(),"30-40");
    ASSERT_FALSE(game.isEnded());
}

TEST(TennisGameScoringSystemTest, if_equality_3_points_each_the_plain_english_score_should_be_Deuce)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player1, 3);
    game.pointsWonBy(TennisScoringSystem::Player2, 3);
    ASSERT_EQ(game.plainEnglishScore(),"Deuce");
    ASSERT_EQ(game.plainNumericalScore(),"40-40");
    ASSERT_FALSE(game.isEnded());
}

TEST(TennisGameScoringSystemTest, if_player2_wins_3_points_and_player1_wins_4_points_the_plain_english_score_should_be_Advantage_Player1)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player2, 3);
    game.pointsWonBy(TennisScoringSystem::Player1, 4);
    ASSERT_EQ(game.plainEnglishScore(),"Advantage Player1");
    ASSERT_EQ(game.plainNumericalScore(),"40A-40");
    ASSERT_FALSE(game.isEnded());
}

TEST(TennisGameScoringSystemTest, if_player2_wins_2_points_and_player1_wins_4_points_the_plain_english_score_should_be_Game_won_by_Player1)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player2, 2);
    game.pointsWonBy(TennisScoringSystem::Player1, 4);
    ASSERT_EQ(game.plainEnglishScore(),"Game won by Player1");
    ASSERT_EQ(game.plainNumericalScore(),"Game won by Player1");
    ASSERT_TRUE(game.isEnded());
    ASSERT_EQ(game.getWinner(), 0);
}

TEST(TennisGameScoringSystemTest, if_player1_wins_first_4_points_and_player2_wins_5_points_the_plain_english_score_should_be_Advantage_Player2)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player1, 4);
    game.pointsWonBy(TennisScoringSystem::Player2, 5);
    ASSERT_EQ(game.plainEnglishScore(),"Advantage Player2");
    ASSERT_EQ(game.plainNumericalScore(),"40-40A");
    ASSERT_FALSE(game.isEnded());
}
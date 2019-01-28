#include "gtest/gtest.h"
#include "TennisScoringSystem.h"
#include "TennisGameScoringSystem.h"

// Game Tests

TEST(TennisGameScoringSystem, at_start_the_plain_english_score_should_be_LoveAll)
{
    TennisGameScoringSystem game;
    ASSERT_EQ(game.plainEnglishScore(),"Love-All");
    ASSERT_EQ(game.plainNumericalScore(),"0-0");
}

TEST(TennisGameScoringSystem, if_player1_wins_first_point_the_plain_english_score_should_be_FitTeenLove)
{
    TennisGameScoringSystem game;
    game.pointWonBy(TennisScoringSystem::Player1);
    ASSERT_EQ(game.plainEnglishScore(),"Fifteen-Love");
    ASSERT_EQ(game.plainNumericalScore(),"15-0");
}

TEST(TennisGameScoringSystem, if_player1_wins_first_2_points_the_plain_english_score_should_be_ThirtyLove)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player1, 2);
    ASSERT_EQ(game.plainEnglishScore(),"Thirty-Love");
    ASSERT_EQ(game.plainNumericalScore(),"30-0");
}

TEST(TennisGameScoringSystem, if_player1_wins_first_3_points_the_plain_english_score_should_be_FortyLove)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player1, 3);
    ASSERT_EQ(game.plainEnglishScore(),"Forty-Love");
    ASSERT_EQ(game.plainNumericalScore(),"40-0");
}

TEST(TennisGameScoringSystem, if_player1_wins_first_2_points_and_player2_wins_3_points_the_plain_english_score_should_be_ThirtyForty)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player1, 2);
    game.pointsWonBy(TennisScoringSystem::Player2, 3);
    ASSERT_EQ(game.plainEnglishScore(),"Thirty-Forty");
    ASSERT_EQ(game.plainNumericalScore(),"30-40");
}

TEST(TennisGameScoringSystem, if_equality_3_points_each_the_plain_english_score_should_be_Deuce)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player1, 3);
    game.pointsWonBy(TennisScoringSystem::Player2, 3);
    ASSERT_EQ(game.plainEnglishScore(),"Deuce");
    ASSERT_EQ(game.plainNumericalScore(),"40-40");
}

TEST(TennisGameScoringSystem, if_player2_wins_3_points_and_player1_wins_4_points_the_plain_english_score_should_be_Advantage_Player1)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player2, 3);
    game.pointsWonBy(TennisScoringSystem::Player1, 4);
    ASSERT_EQ(game.plainEnglishScore(),"Advantage Player1");
    ASSERT_EQ(game.plainNumericalScore(),"40A-40");
}

TEST(TennisGameScoringSystem, if_player2_wins_2_points_and_player1_wins_4_points_the_plain_english_score_should_be_Game_won_by_Player1)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player2, 2);
    game.pointsWonBy(TennisScoringSystem::Player1, 4);
    ASSERT_EQ(game.plainEnglishScore(),"Game won by Player1");
    ASSERT_EQ(game.plainNumericalScore(),"Game won by Player1");
}

TEST(TennisGameScoringSystem, if_player1_wins_first_4_points_and_player2_wins_5_points_the_plain_english_score_should_be_Advantage_Player2)
{
    TennisGameScoringSystem game;
    game.pointsWonBy(TennisScoringSystem::Player1, 4);
    game.pointsWonBy(TennisScoringSystem::Player2, 5);
    ASSERT_EQ(game.plainEnglishScore(),"Advantage Player2");
    ASSERT_EQ(game.plainNumericalScore(),"40-40A");
}

// TEST(TennisScoringSystemTest, REPLACE_ME)
// {
//     // Failing test
//     ASSERT_TRUE(false);
// }


// TEST(TennisScoringSystemTest, REPLACE_ME2)
// {
//     ASSERT_TRUE(true);
// }

TEST(TennisScoringSystemTest, at_start_the_plain_english_score_should_be_LoveLove)
{
    TennisScoringSystem game;
    ASSERT_EQ(game.plainEnglishScore(),"Love-Love");
    ASSERT_EQ(0, game.currentSet());
    ASSERT_EQ(0, game.currentPointInSet());

}

TEST(TennisScoringSystemTest, if_player1_wins_first_point_the_plain_english_score_should_be_FithTeenLove)
{
    // Given a Tennis Gamme
    TennisScoringSystem game;
    
    // When player1 wins first point
    game.pointWonBy(TennisScoringSystem::Player1);

    // Then score should be "Fifhteen-Love" 
    ASSERT_EQ(game.plainEnglishScore(),"Fifteen-Love");
    
    // And current set should still be 0
    ASSERT_EQ(0, game.currentSet());

    // And current Point in Set should now be 1
    ASSERT_EQ(1, game.currentPointInSet());

}




int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

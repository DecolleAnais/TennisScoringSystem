#include "gtest/gtest.h"
#include "TennisScoringSystem.h"


TEST(TennisScoringSystemTest, REPLACE_ME)
{
    // Failing test
    ASSERT_TRUE(false);
}


TEST(TennisScoringSystemTest, REPLACE_ME2)
{
    ASSERT_TRUE(true);
}

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

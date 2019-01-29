#include "gtest/gtest.h"
#include "TennisScoringSystem.h"
#include "TennisSetScoringSystem.h"

// Set Tests


// TEST(TennisSetScoringSystemTest, at_start_the_plain_english_score_should_be_LoveAll)
// {
//     TennisSetScoringSystem set;
//     ASSERT_EQ(set.plainEnglishScore(),"Love-All");
//     ASSERT_EQ(set.plainNumericalScore(),"0-0");
//     ASSERT_FALSE(set.isEnded());
// }

// TEST(TennisSetScoringSystemTest, if_player2_wins_3_points_and_player1_wins_4_points_the_plain_english_score_should_be_Advantage_Player1)
// {
//     TennisSetScoringSystemTest set;
//     set.pointsWonBy(TennisScoringSystem::Player2, 3);
//     set.pointsWonBy(TennisScoringSystem::Player1, 4);
//     ASSERT_EQ(set.plainEnglishScore(),"Advantage Player1");
//     ASSERT_EQ(set.plainNumericalScore(),"40A-40");
//     ASSERT_FALSE(set.isEnded());
// }
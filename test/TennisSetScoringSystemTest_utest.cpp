#include "gtest/gtest.h"
#include "TennisScoringSystem.h"
#include "TennisSetScoringSystem.h"

// Set Tests


TEST(TennisSetScoringSystemTest, at_start_the_plain_english_score_should_be_LoveAll)
{
    TennisSetScoringSystem set;
    ASSERT_EQ(set.plainEnglishScore(),"| Love-All || Love-All || Love-All || Love-All || Love-All || Love-All |");
    ASSERT_EQ(set.plainNumericalScore(),"| 0-0 || 0-0 || 0-0 || 0-0 || 0-0 || 0-0 |");
    ASSERT_EQ(set.score(),"| 0-0 || 0-0 || 0-0 || 0-0 || 0-0 || 0-0 |");
    ASSERT_FALSE(set.isEnded());
}

TEST(TennisSetScoringSystemTest, if_player2_wins_3_points_and_player1_wins_4_points_the_plain_english_score_should_be_Advantage_Player1)
{
    TennisSetScoringSystem set;
    set.pointsWonBy(TennisScoringSystem::Player2, 3);
    set.pointsWonBy(TennisScoringSystem::Player1, 4);
    ASSERT_EQ(set.plainEnglishScore(),"| Advantage Player1 || Love-All || Love-All || Love-All || Love-All || Love-All |");
    ASSERT_EQ(set.plainNumericalScore(),"| 40A-40 || 0-0 || 0-0 || 0-0 || 0-0 || 0-0 |");
    ASSERT_EQ(set.score(),"| 4-3 || 0-0 || 0-0 || 0-0 || 0-0 || 0-0 |");
    ASSERT_FALSE(set.isEnded());
}

TEST(TennisSetScoringSystemTest, if_set1_score_0_4_set2_score_5_6_the_plain_english_score_should_be_Advantage_Player2)
{
    TennisSetScoringSystem set;
    set.pointsWonBy(TennisScoringSystem::Player2, 4);

    set.pointsWonBy(TennisScoringSystem::Player1, 3);
    set.pointsWonBy(TennisScoringSystem::Player2, 3);    
    set.pointsWonBy(TennisScoringSystem::Player1, 1);   
    set.pointsWonBy(TennisScoringSystem::Player2, 1);   
    set.pointsWonBy(TennisScoringSystem::Player1, 1);  
    set.pointsWonBy(TennisScoringSystem::Player2, 2); 
    ASSERT_EQ(set.plainEnglishScore(),"| Game won by Player2 || Advantage Player2 || Love-All || Love-All || Love-All || Love-All |");
    ASSERT_EQ(set.plainEnglishScore(0),"Game won by Player2");
    ASSERT_EQ(set.plainEnglishScore(1),"Advantage Player2");
    ASSERT_EQ(set.plainEnglishScore(2),"Love-All");
    ASSERT_EQ(set.plainNumericalScore(),"| Game won by Player2 || 40-40A || 0-0 || 0-0 || 0-0 || 0-0 |");
    ASSERT_EQ(set.plainNumericalScore(0),"Game won by Player2");
    ASSERT_EQ(set.plainNumericalScore(1),"40-40A");
    ASSERT_EQ(set.plainNumericalScore(2),"0-0");
    ASSERT_EQ(set.score(),"| 0-4 || 5-6 || 0-0 || 0-0 || 0-0 || 0-0 |");
    ASSERT_EQ(set.score(0),"0-4");
    ASSERT_EQ(set.score(1),"5-6");
    ASSERT_EQ(set.score(2),"0-0");
    ASSERT_FALSE(set.isEnded());
}

TEST(TennisSetScoringSystemTest, if_score_0_4_for_6_sets_the_plain_english_score_should_be_Game_won_by_Player2)
{
    TennisSetScoringSystem set;

    for(int i = 0;i < 6;i++)
    {
    	set.pointsWonBy(TennisScoringSystem::Player2, 4); 
    }

    ASSERT_EQ(set.plainEnglishScore(),"| Game won by Player2 || Game won by Player2 || Game won by Player2 || Game won by Player2 || Game won by Player2 || Game won by Player2 |");
    ASSERT_EQ(set.plainNumericalScore(),"| Game won by Player2 || Game won by Player2 || Game won by Player2 || Game won by Player2 || Game won by Player2 || Game won by Player2 |");
    ASSERT_EQ(set.score(),"| 0-4 || 0-4 || 0-4 || 0-4 || 0-4 || 0-4 |");
    ASSERT_TRUE(set.isEnded());
}

TEST(TennisSetScoringSystemTest, if_score_0_4_for_3_sets_and_score_4_0_for_3_sets_the_last_plain_english_score_should_be_Love_All)
{
    TennisSetScoringSystem set;

    for(int i = 0;i < 3;i++)
    	set.pointsWonBy(TennisScoringSystem::Player2, 4); 

    for(int i = 0;i < 3;i++)
    	set.pointsWonBy(TennisScoringSystem::Player1, 4); 

    ASSERT_EQ(set.plainEnglishScore(),"| Game won by Player2 || Game won by Player2 || Game won by Player2 || Game won by Player1 || Game won by Player1 || Game won by Player1 || Love-All |");
    ASSERT_EQ(set.plainNumericalScore(),"| Game won by Player2 || Game won by Player2 || Game won by Player2 || Game won by Player1 || Game won by Player1 || Game won by Player1 || 0-0 |");
    ASSERT_EQ(set.score(),"| 0-4 || 0-4 || 0-4 || 4-0 || 4-0 || 4-0 || 0-0 |");
    ASSERT_FALSE(set.isEnded());
}

TEST(TennisSetScoringSystemTest, if_player1_wins_5_games_and_player2_wins_6_games_the_set_should_not_be_ended)
{
    TennisSetScoringSystem set;

    for(int i = 0;i < 5;i++)
    	set.pointsWonBy(TennisScoringSystem::Player2, 4); 

    for(int i = 0;i < 5;i++)
    	set.pointsWonBy(TennisScoringSystem::Player1, 4); 

	set.pointsWonBy(TennisScoringSystem::Player2, 4); 

    ASSERT_EQ(set.score(),"| 0-4 || 0-4 || 0-4 || 0-4 || 0-4 || 4-0 || 4-0 || 4-0 || 4-0 || 4-0 || 0-4 || 0-0 |");
    ASSERT_FALSE(set.isEnded());
}

TEST(TennisSetScoringSystemTest, if_player1_wins_6_games_and_player2_wins_6_games_the_set_should_not_be_ended)
{
    TennisSetScoringSystem set;

    for(int i = 0;i < 5;i++)
    	set.pointsWonBy(TennisScoringSystem::Player2, 4); 

    for(int i = 0;i < 5;i++)
    	set.pointsWonBy(TennisScoringSystem::Player1, 4); 

	set.pointsWonBy(TennisScoringSystem::Player2, 4); 
	set.pointsWonBy(TennisScoringSystem::Player1, 4); 

    ASSERT_EQ(set.score(),"| 0-4 || 0-4 || 0-4 || 0-4 || 0-4 || 4-0 || 4-0 || 4-0 || 4-0 || 4-0 || 0-4 || 4-0 || 0-0 |");
    ASSERT_FALSE(set.isEnded());
}

TEST(TennisSetScoringSystemTest, if_player1_wins_7_games_and_player2_wins_6_games_the_set_should_be_ended)
{
    TennisSetScoringSystem set;

    for(int i = 0;i < 5;i++)
    	set.pointsWonBy(TennisScoringSystem::Player2, 4); 

    for(int i = 0;i < 5;i++)
    	set.pointsWonBy(TennisScoringSystem::Player1, 4); 

	set.pointsWonBy(TennisScoringSystem::Player2, 4); 
	set.pointsWonBy(TennisScoringSystem::Player1, 4); 
	set.pointsWonBy(TennisScoringSystem::Player1, 4); 

    ASSERT_EQ(set.score(),"| 0-4 || 0-4 || 0-4 || 0-4 || 0-4 || 4-0 || 4-0 || 4-0 || 4-0 || 4-0 || 0-4 || 4-0 || 4-0 |");
    ASSERT_TRUE(set.isEnded());
    ASSERT_EQ(set.getWinner(), 0);
}

TEST(TennisSetScoringSystemTest, if_player1_wins_6_games_and_player2_wins_4_games_the_set_should_be_ended)
{
    TennisSetScoringSystem set;

    for(int i = 0;i < 4;i++)
    	set.pointsWonBy(TennisScoringSystem::Player2, 4); 

    for(int i = 0;i < 6;i++)
    	set.pointsWonBy(TennisScoringSystem::Player1, 4); 

    ASSERT_EQ(set.score(),"| 0-4 || 0-4 || 0-4 || 0-4 || 4-0 || 4-0 || 4-0 || 4-0 || 4-0 || 4-0 |");
    ASSERT_TRUE(set.isEnded());
    ASSERT_EQ(set.getWinner(), 0);
}

TEST(TennisSetScoringSystemTest, if_player1_wins_5_games_and_player2_wins_4_games_the_set_should_not_be_ended)
{
    TennisSetScoringSystem set;

    for(int i = 0;i < 4;i++)
    	set.pointsWonBy(TennisScoringSystem::Player2, 4); 

    for(int i = 0;i < 5;i++)
    	set.pointsWonBy(TennisScoringSystem::Player1, 4); 

    ASSERT_EQ(set.score(),"| 0-4 || 0-4 || 0-4 || 0-4 || 4-0 || 4-0 || 4-0 || 4-0 || 4-0 || 0-0 |");
    ASSERT_FALSE(set.isEnded());
}
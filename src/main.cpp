#include "TennisScoringSystem.h"
#include <iostream>

enum ScoreDisplayMode
{
	EnglishTextScore,
	NumericalScore,
	Score
};


int main(int argc, char ** argv)
{

	int teamsFormat = -1;
	int setsFormat = -1;

	std::string inputText;

    std::cout << "Start a new Tennis Match" << std::endl;

    std::cout << "Configuration" << std::endl;

    // Tennis match configuration

	std::cout << "Sets Format | Best-Of-Three : press 3 ; Best-Of-Five : press 5" << std::endl;

	std::cout << ">>> ";
	std::cin >> setsFormat;
    while(setsFormat != 3 && setsFormat != 5)
    {    	
    	std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << ">>> ";
    	std::cin >> setsFormat;
    }
    
	std::cout << "Teams | Single Teams : press 1 ; Double Teams : press 2" << std::endl;

	std::cout << ">>> ";
	std::cin >> teamsFormat;
    while(teamsFormat != 1 && teamsFormat != 2)
    {
    	std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << ">>> ";
    	std::cin >> teamsFormat;
    }
    teamsFormat--;

    // TennisScoringSystem creation
    
    TennisScoringSystem tennis((TennisScoringSystem::TeamsFormat)teamsFormat, (TennisScoringSystem::NbSetsFormat)setsFormat);

    // Player names configuration
    
	std::cout << "Enter name of Player1 in Team1" << std::endl;
	std::cout << ">>> ";
	std::cin >> inputText;
	
	tennis.setPlayerName(TennisScoringSystem::Player1, inputText);

	std::cout << "Enter name of Player1 in Team2" << std::endl;
	std::cout << ">>> ";
	std::cin >> inputText;

	tennis.setPlayerName(TennisScoringSystem::Player2, inputText);

    if(teamsFormat == TennisScoringSystem::TeamsFormat::Double)
    {

		std::cout << "Enter name of Player2 in Team1" << std::endl;
		std::cout << ">>> ";
		std::cin >> inputText;

		tennis.setPlayerName(TennisScoringSystem::Player3, inputText);

		std::cout << "Enter name of Player2 in Team2" << std::endl;
		std::cout << ">>> ";
		std::cin >> inputText;

		tennis.setPlayerName(TennisScoringSystem::Player4, inputText);
    }
	
    // Start match

    std::cout << "The match can begin !" << std::endl;

    ScoreDisplayMode scoreDisplayMode = ScoreDisplayMode::Score;

    bool isMatchEnded = false;

    inputText = "";

    // while we don't quit and the match is not ended
	while(inputText != "q" && inputText != "Q" && !isMatchEnded)
	{
		if(inputText == "1")
		{
			// add point to Team1

			tennis.pointWonBy(TennisScoringSystem::Team1);

			isMatchEnded = tennis.isEnded();
		}
		else if(inputText == "2")
		{
			// add point to Team2

			tennis.pointWonBy(TennisScoringSystem::Team2);

			isMatchEnded = tennis.isEnded();
		}
		else if(inputText == "f" || inputText == "F")
		{
			// display full score
			switch(scoreDisplayMode)
			{
				case ScoreDisplayMode::EnglishTextScore : std::cout << tennis.fullEnglishScore() << std::endl; break;

				case ScoreDisplayMode::NumericalScore : std::cout << tennis.fullNumericalScore() << std::endl; break;

				case ScoreDisplayMode::Score : std::cout << tennis.fullScore() << std::endl; break;
			}
		}
		else if(inputText == "c" || inputText == "C")
		{
			// change score display
			scoreDisplayMode = (ScoreDisplayMode) ((scoreDisplayMode + 1) % 3);
		}
		else
		{		
			// display help	
			std::cout << "----------------------------------------------------------------" << std::endl;
		    std::cout << "press 1 or 2 to give the point to team1 or team2" << std::endl;
		    std::cout << "press f to view the whole game score" << std::endl;
		    std::cout << "press c to change score display mode (English, Numerical or Basic)" << std::endl;
		    std::cout << "press q to exit" << std::endl;
			std::cout << "----------------------------------------------------------------" << std::endl;
		}		
		
		// if the match is not ended
		if(!isMatchEnded)
		{
			// display current server and score
			std::cout << "The server is " << tennis.getServerName() << std::endl;

			std::cout << "Current score : ";

			switch(scoreDisplayMode)
			{
				case ScoreDisplayMode::EnglishTextScore : std::cout << tennis.plainEnglishScore() << std::endl; break;

				case ScoreDisplayMode::NumericalScore : std::cout << tennis.plainNumericalScore() << std::endl; break;

				case ScoreDisplayMode::Score : std::cout << tennis.score() << std::endl; break;
			}

			// wait new user entry
			std::cout << ">>> ";
			std::cin >> inputText;
		}
		
		std::cout << std::endl;
	}  	  

	// match end or quit, display winner if possible and final score
	int winnerTeam = tennis.getWinner();

	if(winnerTeam >= 0)
		std::cout << "Winner : Team" << (winnerTeam+1) << " (" << tennis.getNamesInTeam( (TennisScoringSystem::Team) winnerTeam) << ") ";

	std::cout << "Final score : " << tennis.getFinalScore() << std::endl;

    return 0;
}

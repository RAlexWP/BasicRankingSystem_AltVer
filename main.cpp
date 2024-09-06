/*
BASIC SCORE SYSTEM USING VECTORS:
-----------------------------------------------------------------------------
Testing a less tedious and faster ways to make a list of conditional statements
without manually spamming if statements.

Note:
This method is not very optimal in interms of proformance (depending on what it's
used for). But it is well structured and laysout neater than spaming if statements.

------------------------------------------------------------------------------
 Copyright (c) 2024 R. Alex. W. Phillips
*/
#include <iostream>
#include <vector>


struct GradingSys
{
	char	   grade; //data.at(0)
	int currentScore, //data.at(1)
		 lowestValue, //data.at(2)
		highestValue; //data.at(3)


	friend bool operator>(const GradingSys& current, const GradingSys& lowest)
	{ return current.currentScore > lowest.lowestValue; }

	friend bool operator<(const GradingSys& current, const GradingSys& highest)
	{ return current.currentScore < highest.highestValue; }

	friend std::ostream& operator<<(std::ostream& os, const GradingSys& Grade)
	{
		if (Grade.currentScore >= Grade.lowestValue && Grade.currentScore <= Grade.highestValue) {
			os << "grade[" << Grade.grade << "] " << " lowest[" << Grade.lowestValue << "] "
				<< " highest[" << Grade.highestValue << "] " << "current[" << Grade.currentScore << "] \n";
		}
		return os;
	}
};


void printGradeResults(std::vector<GradingSys>& data)
{
	for (int i = 0; i < data.size(); i++)
		std::cout << data.at(i);
}

void displayIfIncorrectValue(int& currentScoreRef)
{
	if (!std::cin.fail()){
		if (currentScoreRef > 0 || currentScoreRef < 100)
		{/*EXIT THE LOOP WITHOUT ENDING THE PROGRAM*/}		
	}

	else if (std::cin.fail()) {
		std::cout << "You didn't even enter a number! Because of "
			"this tomfoolery I'm turning off this program, bye bye.\n"
			" \n";

		exit(0);
	}
}

int main()
{
	int currentScore = 0;
	std::cout << "Enter a score between 0-100 " << std::endl;
	std::cin >> currentScore;

	while (currentScore < 0 || currentScore > 100)
	{
		std::cout << "You entered an incorrect number,\n"
			"Please try again and enter a number between 0 & 100 \n";
		std::cin >> currentScore;

		displayIfIncorrectValue(currentScore);
	}

	displayIfIncorrectValue(currentScore);

	/*
	You can make as much push_back calls as you want.
	as long as the values are between (0 - 100).

	the code below is the equivalent if you did something similar like 
	this 7 times:
	----------------------------------------------------------------------
	if(currentScore >= 0 && currentScore <= 15) {
	std::cout << "grade[" << F << "] " << " lowest[" << 0 << "] "
			<< " highest[" << 15 << "] " << "current[" << 10 << "] \n";
	}
	---------------------------------------------------------------------*/
	std::vector<GradingSys> grading_system;
	/*					     |Rank |CurrentScore|lower|higher| */
	grading_system.push_back({ 'F', currentScore,  0, 15 });
	grading_system.push_back({ 'E', currentScore, 15, 25 });
	grading_system.push_back({ 'D', currentScore, 25, 47 });
	grading_system.push_back({ 'C', currentScore, 47, 60 });
	grading_system.push_back({ 'B', currentScore, 60, 75 });
	grading_system.push_back({ 'A', currentScore, 75, 95 });
	grading_system.push_back({ 'S', currentScore, 95, 100 });
	printGradeResults(grading_system);
	grading_system.clear();

	return 0;
}
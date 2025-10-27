#include <iostream>
#include<cstdlib>
#include<string>


using namespace std;

enum enQestionLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };

enum enOpirationType { Add = 1, Sub = 2, Mult = 3, Divi = 4, Mixed = 5 };


struct stOpiration
{
short  int Number1;
short  int Number2;
short  int Result;
short int UserChoice;
short int WrongAnswers = 0;
short int RigthAnswers = 0;
	enQestionLevel QuestionLevel;
	enOpirationType OPtype;
	
};
struct stFinalResults
{
	short int NumberQuestions=0;
	enQestionLevel QuestionLevel;
	enOpirationType OPtype;
	short	int RigthAnswers = 0;
	short	int WrongAnswers = 0;
	string ShowQuestionLevel = "";
	string ShowOPtype = "";
	
};


int RandomNumber(short int From, short int To)
{
	return  rand() % ((To - From + 1) + From);
}

short int GetNumberOfQuestions()
{
	short int NumberOfQuestions;
	do
	{
	cout << "How many questions you want to answer ? :\n";
	cin >> NumberOfQuestions;
	} while (NumberOfQuestions<=0);

	return NumberOfQuestions;
}

enQestionLevel ReadQuestLevel()
{
		short int UserInput;
	do
	{
		cout << " Enter Question Level : [1] Easy , [2] Med , [3] Hard , [4] Mix  :" << endl;
		cin >> UserInput;
	} while (UserInput<0||UserInput>4);
	return (enQestionLevel)UserInput;
}

enQestionLevel MixQuestionLevel(stOpiration& Opiration)
{
	Opiration.QuestionLevel = (enQestionLevel)RandomNumber(1, 3);

	switch (Opiration.QuestionLevel)
	{
	case 1:
		return enQestionLevel::Easy;
	case 2:
		return enQestionLevel::Med;
	case 3:
		return enQestionLevel::Hard;
	default:1;
		break;
	}
}


enQestionLevel DetectQuestionLevel(stOpiration& Opiration)
{
	

	switch (Opiration.QuestionLevel)
	{
	case 1 : 
		return enQestionLevel::Easy;
	case 2:
		return enQestionLevel::Med;
	case 3:
		return enQestionLevel::Hard;
	case 4:
		return enQestionLevel::Mix;
	default:
		break;
	}
}
enOpirationType ReadOpirationType()
{
	int OpType;
	do
	{
		cout << " Enter Opiration Type : [1] Add , [2] Sub , [3] Multi , [4] Div , [5] Mix  :" << endl;
		cin >> OpType;
	} while (OpType < 0 || OpType>5);
	return (enOpirationType)OpType;
}	


enOpirationType MixOpirationType(stOpiration& Opiration)
{
	Opiration.OPtype = (enOpirationType)RandomNumber(1, 4);

	switch (Opiration.OPtype)
	{
	case 1:
		return enOpirationType::Add;
	case 2:
		return enOpirationType::Sub;
	case 3:
		return enOpirationType::Mult;
	case 4:
		return enOpirationType::Divi;

	}
}

enOpirationType GetOpirationType(stOpiration& Opiration)
{
	Opiration.OPtype = ReadOpirationType();

	switch (Opiration.OPtype)
	{
	case 1:
		return enOpirationType::Add;
	case 2:
		return enOpirationType::Sub;
	case 3:
		return enOpirationType::Mult;
	case 4:
		return enOpirationType::Divi;
	case 5 :
		return enOpirationType::Mixed;
	}
}

stOpiration SuggestQuestionsNumbersAccToLevel(stOpiration & Opiration)
{
	Opiration.QuestionLevel = DetectQuestionLevel(Opiration);
	
	switch (Opiration.QuestionLevel)
	{
	case Easy:
		Opiration.Number1 = RandomNumber(1, 10);
		Opiration.Number2 = RandomNumber(1, 10);
		return Opiration;

		break;
	case Med:
		Opiration.Number1 = RandomNumber(10, 20);
		Opiration.Number2 = RandomNumber(10, 20);
		return Opiration;
		
	case Hard:
		Opiration.Number1 = RandomNumber(20, 100);
		Opiration.Number2 = RandomNumber(20, 100);
		return Opiration;
		
	case Mix:
		Opiration.Number1 = RandomNumber(1, 100);
		Opiration.Number2 = RandomNumber(1, 100);
		return Opiration;
		
	default: Easy;
		break;
	}

}

int DoOpirationsAccToChoice(stOpiration& Opiration  )
{
	switch (Opiration.OPtype)
	{
	case Add:
		Opiration.Result = Opiration.Number1 + Opiration.Number2;
		return Opiration.Result;
		break;
	case Sub:
		Opiration.Result = Opiration.Number1 - Opiration.Number2;
		return Opiration.Result;
		break;
	case Mult:
		Opiration.Result = Opiration.Number1 * Opiration.Number2;
		return Opiration.Result;
		break;
	case Divi:
		Opiration.Result = Opiration.Number1 / Opiration.Number2;
		return Opiration.Result;
	case Mixed:
		
		cout << DoOpirationsAccToChoice(Opiration);
		break;
	default: Add;
		break;
	}

}

int readUserChoice(stOpiration& Opiration)
{
	
		cin >> Opiration.UserChoice;
	
	return Opiration.UserChoice;

}

bool IsUserRigth(short int& UserNum , short int& Result)
{
	
	if (Result == UserNum)
		return true;
	else
		return false;
}
void ColoringAndShowingResult(short int& UserNum, short int& Result)
{
	if (IsUserRigth(UserNum, Result) == true)
	{
		system("color 2F");
		cout << "Rigth Anwser :-)\n";
	}
	else
	{
		system("color 4F");
		cout << "Wrong Anwser >:-(\n";
		cout << "Rigth answer is : " << Result;
		cout << "\a";
	}
}
char DisplayOpirator(stOpiration& Opiration)
{
	switch (Opiration.OPtype)
	{
	case enOpirationType::Add:
		return '+';
	case enOpirationType::Sub:
		return '-';
	case enOpirationType::Mult:
		return '*';
	case enOpirationType::Divi:
		return '/';
	case enOpirationType::Mixed:
		Opiration.OPtype = MixOpirationType(Opiration);
	}

	}


void DisplayQuestion(stOpiration& Opiration)
{
	SuggestQuestionsNumbersAccToLevel(Opiration);

	cout << "\n";
	cout << Opiration.Number1<<endl;
	cout << Opiration.Number2<<"  "<< DisplayOpirator(Opiration)<<endl;
	cout << "_______________\n";
}



string PassOrFailed(short int RigthAnswers, short int WrongAnswers)
{
	if (RigthAnswers > WrongAnswers)
		return "Pass";
	else
		return "Failed";
}
void FinalReultsSign(short int RigthAnswers, short int WrongAnswers)
{
	cout << "\n---------------------------------\n";
	cout << " Final Result is  "<<PassOrFailed(RigthAnswers,WrongAnswers)<<endl;
	cout << "\n---------------------------------\n";

}

string DisplayLevel(enQestionLevel Level)
{
	string ShowLevel[4]={"Easy","Med","Hard","Mix"};
	return ShowLevel[Level - 1];
}

string DisplayOpirationType(enOpirationType OPtype)
{
	string ShowLevel[5] = { "Add","Sub","Mult","Div","Mix"};
	return ShowLevel[OPtype - 1];
}
void RefreshQuizz(char UserChoice)
{
	
	if (UserChoice == 'Y' || UserChoice == 'y')
	{
		system("color 0F");
		system("cls");
	}
}
stFinalResults FillGameResults(stOpiration Opiration, short int NumberOfQuestions)
{
	stFinalResults FinalResults;
	FinalResults.NumberQuestions = NumberOfQuestions;
	FinalResults.OPtype = Opiration.OPtype;
	FinalResults.QuestionLevel = Opiration.QuestionLevel;
	FinalResults.RigthAnswers = Opiration.RigthAnswers;
	FinalResults.WrongAnswers = Opiration.WrongAnswers;
	FinalResults.ShowOPtype = DisplayOpirationType(Opiration.OPtype);
	FinalResults.ShowQuestionLevel = DisplayLevel(Opiration.QuestionLevel);
	return FinalResults;
}
void ShowResults(stFinalResults FinalResults)
{
	cout << "Numbers of questions : " << FinalResults.NumberQuestions<<endl;
	cout << "Question Level : " << FinalResults.ShowQuestionLevel<<endl;
	cout << "OpType  : " << FinalResults.ShowOPtype<<endl;
	cout << "Number of Rigth Answers : " << FinalResults.RigthAnswers<<endl;
	cout << "Number of Wrong Answers : " << FinalResults.WrongAnswers<<endl;

}
// Play Quize its type was stFinalResult 
stFinalResults PlayQuizz(short int NumberOfQuestions)
{
	stOpiration Opiration;
	Opiration.QuestionLevel = ReadQuestLevel();
	Opiration.OPtype = ReadOpirationType();


	for (int i = 0; i <= NumberOfQuestions - 1; i++)
	{
		cout << "Question [" << i + 1 << "/" << NumberOfQuestions << "]" << endl;
		DisplayQuestion(Opiration);
		Opiration.Result = DoOpirationsAccToChoice(Opiration);
		readUserChoice(Opiration);
		IsUserRigth(Opiration.UserChoice,Opiration.Result);
		ColoringAndShowingResult(Opiration.UserChoice, Opiration.Result);
		if (IsUserRigth(Opiration.UserChoice, Opiration.Result) == true)
			Opiration.RigthAnswers++;
		else
			Opiration.WrongAnswers++;

		cout << "\n";
	}
	cout << "\n";
	FinalReultsSign(Opiration.RigthAnswers, Opiration.WrongAnswers);
	return FillGameResults(Opiration, NumberOfQuestions);

}

void StartQuizz()
{
	char Choice = 'y';
	do
	{
		stFinalResults PlayYourQuizz;
		RefreshQuizz(Choice);
		PlayYourQuizz = PlayQuizz(GetNumberOfQuestions());
		ShowResults(PlayYourQuizz);
		cout << "do you want to play again Y/N ? \n";
		cin >> Choice;
	} while (Choice == 'Y' || Choice == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartQuizz();
    return 0;
}


#include <iostream>]
#include <string>
#include <random>
#include <array>

int no_of_guesses = 10;


void CheckGuess(char& user_input, std::string& guess) {
	if (guess.find(user_input) != std::string::npos) {
		int index = guess.find(user_input);
		guess.erase(index, 1);
		std::cout << "You Got It Correct! Keep Going!" << std::endl;
		std::cout << "Remaining Words : " << guess.length() << std::endl;
		std::cout << "\n";
	}
	else {
		no_of_guesses -= 1;
		std::cout << "Wrong! Haha... It's not so easy, you dumb player ;) " << std::endl;
		std::cout << "Remaining Guesses : " << no_of_guesses << std::endl;
		std::cout << "\n";
	}
}

int main() {
	while (true) {
		std::cout << "---------------------WELCOME TO CLASSIC HANGMAN!--------------------------" << "\n";
		std::cout << "I've thought a word..... Can you guess it? Let's see ;)" << std::endl;
		std::cout << "You've got 5 tries to guess..........." << std::endl;

		char user_input;
		std::string s_cont;
		std::array<std::string, 10> words = {
		"coffee", "keys", "phone", "wallet", "glasses",
		"book", "shoes", "umbrella", "watch", "notebook"
		};

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, words.size() - 1);

		std::string guess = words[dis(gen)];
		bool won = false;

		while (no_of_guesses > 0 && won == false)
		{
			std::cout << "Enter your letter : " << std::endl;
			std::cin >> user_input;
			CheckGuess(user_input, guess);

			if (guess.length() == 0)
			{
				won = true;
			}

		}

		if (won) {
			std::cout << "\n";
			std::cout << "CONGRATS YOU WON!!!!!!!!!" << std::endl;
		}
		else {
			std::cout << "GAME OVER! BETTER LUCK NEXT TIME!";
		}

		std::cout << "Wanna Play Again? Enter Y : " << std::endl;
		won = false;
		no_of_guesses = 10;
		std::cin >> s_cont;
		if (s_cont[0] != 'Y' && s_cont[0] != 'y')
		{
			break;
		}
	}
}

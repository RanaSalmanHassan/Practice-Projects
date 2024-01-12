#include <iostream>
#include <fstream>
#include <string>


std::string encryptCeaser(std::string& plaintext, int shift) {
	std::string encrypted_text = ""; // Initializing Encrypted Text

	for (char ch : plaintext) // Looping through plain text just like in python : for x in text.......
	{
		if (isalpha(ch)) // Checking if character is an alphabet
		{
			char base = isupper(ch) ? 'A' : 'a'; // Checking if character is uppercase,if so base = 65 (ASCII OF A) //  and if not base = 97 (ASCII OF a)
			encrypted_text += (ch - base + shift) % 26 + base; // Encryption 
		}
		else
		{
			encrypted_text += ch;
		}
	}

	return encrypted_text;
}

std::string decryptCaesar(const std::string& ciphertext, int shift) {
	std::string decrypted_text = "";

	for (char ch:ciphertext)
	{
		if (isalpha(ch))
		{
			char base = isupper(ch) ? 'A' : 'a';
			decrypted_text += (ch - base - shift + 26) % 26 + base;
		}
		else
		{
			decrypted_text += ch;
		}
	}

	return decrypted_text;
}


int main() {
	std::cout << "--------------------------WELCOME THE ENRYPTION/DECRYPTION SAFETY TOOL!---------------------------------" << std::endl;
	std::cout << "Encrypt and Decrypt using Keys and be the safest data person!" << std::endl;

	std::cout << "\n";

	std::string file_name,user_choice;
	std::cout << "Do you wanna encrypt or decrypt? Enter e for encrypt and d for decrypt!" << std::endl;
	std::cin >> user_choice;

	std::cout << "Enter File Name : " << std::endl;
	std::cin >> file_name;

	std::ifstream InputFile(file_name);
	if (InputFile.is_open())
	{
		std::string line,ed_line;
		std::string encrypted_content = "";

		while (std::getline(InputFile,line))
		{
			if (user_choice[0] == 'e')
			{
				ed_line = encryptCeaser(line, 3);
				encrypted_content += ed_line + "\n";
			}
			if (user_choice[0] == 'd')
			{
				ed_line = decryptCaesar(line, 3);
				encrypted_content += ed_line + "\n";
			}
		}

		InputFile.close();

		if (user_choice[0] == 'e')
		{
			std::ofstream EncryptedFile("encrypt.txt");
			if (EncryptedFile.is_open()) {
				EncryptedFile << encrypted_content;
				EncryptedFile.close();
				std::cout << "File Encrypted!" << std::endl;
			}
			else {
				std::cout << "Unable to open the file for writing!" << std::endl;
			}
		}
		if (user_choice[0] == 'd')
		{
			std::ofstream DecryptedFile("decrypt.txt");
			if (DecryptedFile.is_open()) {
				DecryptedFile << encrypted_content;
				DecryptedFile.close();
				std::cout << "File Decrypted!" << std::endl;
			}
			else {
				std::cout << "Unable to open the file for writing!" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Unable to open the file!" << std::endl;
	}

}
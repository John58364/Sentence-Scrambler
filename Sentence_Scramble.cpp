
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// Create the random shuffler
	random_device rnd;
	const auto seed = rnd.entropy() ? rnd() : time(0);
	mt19937_64 engine(static_cast<mt19937_64::result_type>(seed));

	// Prompt user for a phrase or word to be scrambled
	cout << "Enter a word or phrase to be scrambled:" << endl << endl;
	string phrase = "";
	getline(cin, phrase);

	// Create a vector to store each word
	vector<string> words;
	string word = "";

	// Split the phrase into words
	for(int i = 0; i < phrase.length(); i++)
	{
		if(phrase[i] == ' ')
		{
			words.push_back(word);
			word = "";
		}
		else
		{
			word += phrase[i];
		}
	}
	// Adds the last word to the vector
	words.push_back(word);

	// Use enhanced for loop to go through vector
	for(int i = 0; i <= words.size(); i++)
	{
		// Shuffle the phrase or word and output
		shuffle(words[i].begin(), words[i].end(), engine);
		cout << words[i] << " ";
	}
}

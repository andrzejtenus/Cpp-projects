
#include <iostream>
#include<vector>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

//struktura żeby przetrzymac razem litere i jej wartość
struct Leter
{
	int value;
	char leter;
	Leter(int value_, char leter_):value(value_),leter(leter_)
	{}
	Leter() :value(0), leter(' ') {}
};
//wyświetla ekran gry
void view(Leter table[15][15])
{
	char a = (char)65;
	cout << " " << "\t";
	for (int i = 1; i < 16; i++) {
		cout << i << "\t";
	}	
	cout << endl;
	cout << endl;
	for (int i = 0; i < 15; i++)
	{
		cout <<  (char)(a + i)<< "\t";
		for (int j = 0; j < 15; j++)
		{
			cout << table[i][j].leter<<"\t";
		}
		cout << endl;
		cout << endl;
	}
}
//otwiera plik i zczytuje dane ze słownika (duży jest temu długo sie odpala)
void init_dictionary(vector<string> &dictionary)
{
	ifstream file;
	file.open("DICTIONARY.txt");
	string word;
	while (file >> word)
	{
		dictionary.push_back(word);
	}
	file.close();
}
//inicjalizuje torbe z literami
void init_bag(vector<Leter> &bag)
{
	ifstream file;
	file.open("LETERS.txt");
	char leter;
	int value;
	int number;
	while (file >> leter, file >> value, file >> number)
	{

		for (int i = 0; i < number; i++)
		{
			bag.push_back(Leter(value, leter));
		}
	}
	file.close();
}
//daje graczowi losową litere i zabiera z torby
void get_letter(vector<Leter> &bag, vector<Leter> &user_leters)
{
	srand(time(NULL));
	int random = rand() % bag.size();

	user_leters.push_back(bag[random]);
	bag.erase(bag.begin()+random); 
}
//uzupełnia litery do 7 jak w poleceniu 
void compleate_user_leters(vector<Leter> &bag, vector<Leter> &user_leters)
{
	while (user_leters.size()<7)
	{
		get_letter(bag, user_leters);
	}
}
//widok menu
void print_menu(vector<Leter> user_leters)
{
	cout << endl;
	cout << "Posiadane litery: " << endl;
	for (int i = 0; i < user_leters.size(); i++)
	{
		cout << user_leters[i].leter << "(" << user_leters[i].value << ")\t";
	}
	cout << endl;
	if (user_leters.size() < 14)
		cout << "Aby dobrac litere wcisnij 1" << endl;
	cout << "Aby dodac slowo wcisnij 2" << endl;
	cout << "Aby zakonczyc gre wcisnij 3" << endl;
}
//sprawdza czy można dodać w tym miejscu wyraz (każde słowo musi się łączyć z innym na oczatku z *)
bool check_pleace(vector<Leter> word)
{
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i].leter != ' ')
		{
			return true;
		}
	}
	return false;
}
//sprawdza czy słowo jest w słowniku
bool check_word(string word, vector<string> dictionary)
{
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (word == dictionary[i])
		{
			return true;
		}
	}
	return false;
}
//dodaje litere z puli użytkownika do słowa
bool add_Leter_to_word(vector<Leter> &word, vector<Leter> &user_bag, char leter)
{
	for (int i = 0; i < user_bag.size(); i++)
	{
		if (leter == user_bag[i].leter)
		{
			word.push_back(user_bag[i]);
			user_bag.erase(user_bag.begin() + i);
			return true;
		}
	}
	return false;
}
int main()
{
	int points = 0;				//lb punktów
	vector<string> dictionary;	//słownik
	Leter table[15][15];		//tablicza do gry
	table[7][7].leter = '*';	
	vector<Leter> bag;			//tobra z literami
	vector<Leter> user_leters;	//litery użytkownika
	init_dictionary(dictionary);
	init_bag(bag);

	int flag = 0;
	while (true)				//pentla gry
	{
		compleate_user_leters(bag, user_leters);
		view(table);
		cout << "Masz " << points << "punktow. Pozostalo " << bag.size() << " liter w worku";
		print_menu(user_leters);
		cin >> flag;
		if (flag == 3) {
			break;
		}
		else if (flag == 2) 
		{
			string co_ordinates;		//współrzędne
			vector<Leter> tmp_word;
			int x, y;
			string word = "";
			cout << "Podaj slowo: ";
			cin >> word;
			if (word.size() > 2 & check_word(word, dictionary))
			{
				cout << "Podaj wspolrzedne: ";
				cin >> co_ordinates;

				//w poziomie
				if (co_ordinates[0] > 64)
				{
					//dekodowanie współrzędnych
					y = co_ordinates[0] - 64 - 1;
					co_ordinates.erase(co_ordinates.begin());
					x = stoi(co_ordinates) - 1;
					//sprawdzamy czy słowo mieści sie w tablicy
					if (y < 15 & (x + word.size() - 1) < 15 & x >= 0 & y >= 0)
					{
						//przekopiowanie słowa z tablicy do TMP
						for (int i = x; i < x + word.size(); i++)
						{
							tmp_word.push_back(table[y][i]);
						}
						if (check_pleace(tmp_word))
						{
							bool is_ok = true;
							vector<Leter> tmp_leters;
							for (int i = 0; i < word.size(); i++)
							{
								//sprawdzamy czy litera jet taka sama w słowie i w tablicy(tablica jest w tmp)
								if (word[i] != tmp_word[i].leter)
								{
									//Jeżeli nie są takie samy to musimy sprawdzić czy nie próbujemy czegoś nadpisać 
									if (tmp_word[i].leter == ' ' || tmp_word[i].leter == '*')
									{
										//sprawdzamy czy użytkownik ma wymagana brakujące litery
										if (add_Leter_to_word(tmp_leters,user_leters,word[i]))
										{
											tmp_word[i] = tmp_leters.back();
										}
										else
										{
											is_ok = false;
											break;
										}
									}
									else 
									{
										is_ok = false;
										break;
									}
								}
							}
							if (is_ok)
							{
								for (int i = x; i < x + word.size(); i++)
								{
									table[y][i] = tmp_word[i-x];
									points += tmp_word[i - x].value;
								}
								tmp_word.clear();
								tmp_leters.clear();
							}
							//jak coś poszło nie tak to oddajemy litery
							else
							{
								for (int i = 0; i < tmp_leters.size(); i++)
								{
									user_leters.push_back(tmp_leters[i]);
								}
								tmp_leters.clear();
							}
						}
					}
				}
				//w pionie
				else
				{
					y = co_ordinates[co_ordinates.size() - 1] - 64 - 1;
					co_ordinates.erase(co_ordinates.begin() + co_ordinates.size() - 1);
					x = stoi(co_ordinates) - 1;

					if (x < 15 & (y + word.size() - 1) < 15 & x >= 0 & y >= 0)
					{
						for (int i = y; i < y + word.size(); i++)
						{
							tmp_word.push_back(table[i][x]);
						}
						if (check_pleace(tmp_word))
						{
							bool is_ok = true;
							vector<Leter> tmp_leters;
							for (int i = 0; i < word.size(); i++)
							{
								if (word[i] != tmp_word[i].leter)
								{
									if (tmp_word[i].leter == ' ' || tmp_word[i].leter == '*')
									{
										if (add_Leter_to_word(tmp_leters, user_leters, word[i]))
										{
											tmp_word[i] = tmp_leters.back();
										}
										else
										{
											
											is_ok = false;
											break;
										}
									}
									else
									{
										is_ok = false;
										break;
									}
								}
							}
							if (is_ok)
							{
								for (int i = y; i < y + word.size(); i++)
								{
									table[i][x] = tmp_word[i - y];
									points += tmp_word[i - y].value;
								}
								tmp_word.clear();
							}
							else
							{
								for (int i = 0; i < tmp_leters.size(); i++)
								{
									user_leters.push_back(tmp_leters[i]);
								}
								tmp_leters.clear();
							}
						}
					}

				}
			}
		}
		else if (flag == 1)
		{
			if (user_leters.size() < 14)
				get_letter(bag, user_leters);
		}
		system("cls");
	}
	cout << "Zakonczyles gre z wynikiem: " << points<<" punktow";

	return 0;
}
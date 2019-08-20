// Игра Word Jumble, она же игра 'Словомеска'
// Игра - головоломка, в которой необходимо отгодать слово с перемешанными словами. 
// -------------------------------------------------------------------------------------
// Словомеска v1.1.
// - Изменен баг с вылетом из игры во время победы.
// -------------------------------------------------------------------------------------
//                                 !!!!!ОШИБКИ!!!!!
// -------------------------------------------------------------------------------------
// Закоментить код.
// -------------------------------------------------------------------------------------
//                                 !!!!!ЗАДАЧИ!!!!!
// -------------------------------------------------------------------------------------
// Оптимизировать код под алгоритмы ¯\_(ツ)_/¯
// Придумать корректную систему подсчета очков.


#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//Предустановки. 

	enum fields { word, hint, num_field };
	const int num_words = 10;
	const string words[num_words][num_field] =
	{
		{"comedy", "Жанр театрального искусства"},
		{"car", "Средство передвижения"},
		{"farsh", "Пища"},
		{"resistor", "радиокомпонент"},
		{"star", "Космический объект"},
		{"computer", "То, на чем вы сейчас играете"},
		{"lamp", "Это может помочь в темных местах"},
		{"compas", "Укажет путь в нужный момент"},
		{"clock", "Помогут не опоздать"},
		{"water", "Синоним слова влага"},
	};

	srand(static_cast<unsigned int>(time(0)));
	string guess;

	//Блок ознакомления.

	cout << "\t\t\t Добро пожаловать в игру 'Словомеска'!\n\n";
	cout << "\t\t\t Правила игры!\n";
	cout << "Разгадайте зашифрованное слово. \n";
	cout << "У вас будет 3 попытки, чтобы разгадать. \n";
	cout << "Учтите, что подсказки будут доступны после первой неудачной попытки! \n";
	cout << "Введите 'hint' для подсказки. \n";
	cout << "Введите 'quit' для выхода из игры. \n\n";
	cout << "\t\t Введите 'start' для начала игры. \n\n";
	cout << "Ваш ввод: ";
	cin >> guess;
	// Логика игры.

	while (guess != "quit")
	{
		//Перемешивание слов.
		int choice = (rand() % num_words);
		string theWord = words[choice][word]; // слово, которое надо угадать
		string theHint = words[choice][hint]; // подсказка для этого слова
		string jumble = theWord; // перемешанный вариант слова
		
		
		/*std::random_device rd;
		std::mt19937 g(rd());

		string jumble = shuffle(theWord.begin, theWord.end, g);*/

		int length = jumble.size();

		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		cout << "Зашифрованное слово: " << jumble;

		cout << "\n\nВаша попытка: ";
		cin >> guess;

		//Блок игрового процесса.

		while ((guess != theWord) && (guess != "quit")) 
		{
			/*if (guess == "hint")
			{
				cout << theHint;
			}*/

			// Тут теряется первая попытка угадать слово.


			cout << "Извините, это не то слово :(\n";
			cout << "Может подсказку?\n";
			cout << "\nВаша попытка: ";
			cin >> guess;
			
			if (guess == "quit")
				break;

			if (guess == "hint")
			{
				cout << theHint << endl;
				cout << "\nВаша попытка: ";
				cin >> guess;
				if (guess == "quit")
					break;
				if (guess == theWord)
					cout << "Ура! Вы угадали слово!\n\n";
				else 
				{
					cout << "Извините, это не то слово :(\n";
					cout << "ПОдумайте хорошенько. У вас осталось не так уж много шансов угадать :(\n";
					cout << "\nВаша попытка: ";
					cin >> guess;
					if (guess == "quit")
						break;
					if (guess == theWord)
						cout << "Ура! Вы угадали слово!\n\n";
					else
					{
						cout << "Извините, это не то слово :(\n";
						cout << "ПОдумайте хорошенько. У вас осталось не так уж много шансов угадать :(\n";
						cout << "\nВаша попытка: ";
						cin >> guess;
						if (guess == "quit")
							break;
						if (guess == theWord)
							cout << "Ура! Вы угадали слово!\n\n";
						else
						{
							cout << "";
							guess = "quit";
						}
						
					}
				}
			}
			else
			{
				/*if (guess == theWord)
					cout << "Ура! Вы угадали слово!\n\n";*/
				if (guess == "quit")
					break;
				if (guess != theWord) // В случае отказа от подсказки теряется вторая попытка.
				{
					cout << "Извините, это не то слово :(\n";
					cout << "Уверены, что не хотите взять подсказку?\n";
					cout << "\nВаша попытка: ";
					// Последняя попытка угадать 
					cin >> guess;
					if (guess == "quit")
						break;
					if (guess == "hint")
					{
						cout << theHint << endl;
						cin >> guess;
						if (guess == "quit")
							break;

						/*if (guess == theWord)
							cout << "Ура! Вы угадали слово!\n\n";*/
						else
						{
							cout << "Извините, это не то слово :(\n";
							guess = "quit";
						}
					} 
					else
					{
						if (guess == "quit")
							break;
						if (guess == theWord)
							cout << "Ура! Вы угадали слово!\n\n";
						else
						{
							cout << "Извините, это не то слово :(\n";
							guess = "quit";
						}
					}
				}
			}

		}
		//if (guess == theWord)
		cout << "Ура! Вы угадали слово!\n\n";
	}




	//Блок прощания.

	cout << "\nСпасибо за игру!\n ";
}
			
			
			
			
			
			
			/*if (guess == "hint")
				cout << theHint;
			if ()
				
			cout << "\n\nВаша попытка: ";
			cin >> guess;

			
			cout << "Новое слово! " << jumble;
			cout << "\n\nВаша попытка: ";
			cin >> guess;
			*/
	
	
	
	
	

//  Предыдущая версия игровой логики.

/*	string jumble = theWord; // перемешанный вариант слова
	int length = jumble.size();

	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "Извините, это не то слово :(";
		}
		cout << "\n\nВаша попытка: ";
		cin >> guess;
	}*/

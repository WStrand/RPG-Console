
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <cctype>
#include <vector>
#include <ctime>
#include <random>
int Balance = 100;
int Rank = 1;
float Health_Player = 100;
int Health_Monster = 50;
int Health_Monster2 = 200;
int Health_Guard = 100;
int Total_Damage = 100;
int Inventory_HPotion = 1;

//A struct for the attacks so we can list them in a vector
struct Attack
{
	Attack(std::string name, int damage)
	{
		Name = name;
		Damage = damage;

	}
	std::string Name;
	int Damage;

};
//A struct for the shop si we can list the ites in a vector
struct Shop
{
	Shop(std::string name, int price, int stock)
	{
		Name = name;
		Price = price;
		Stock = stock;

	}
	std::string Name;
	int Price;
	int Stock;
};

//A more advanced random number generator, I am going to be honest, I dont't understand this one but it works and I grabbed it from the internet
int GenerateRandomNumber(int min, int max)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> dist(min, max);
	return dist(mt);
}





//I don't need to use I or length since I will only write strings with this function
void write(std::string Text)
{
	for (char c : Text)
	{
		std::cout << c;
		Sleep(50);
	}
	std::cout << std::endl;
	Sleep(100);
}

void quest(int money, int rank)
{
	std::string My_input;
	write("Rewards: Rank " + std::to_string(rank) + " and " + std::to_string(money) + " Gold pieces");
	write("Accept or Decline?");

};
//This the shop function
void shop()
{
	std::string My_input;
	std::vector<Shop> items;
	//here the vector with all the items in the shop is created
	items.push_back(Shop("Health Potion", 5, 15));
	items.push_back(Shop("Book of the adventurer", 200, 1));

	write("Welcome to my shop!");
	write("What would you like to buy?");
	//this for loop is created to cycle through all the items an to write them in the console
	for (int i = 0; i < items.size(); i++)
	{
		write(std::to_string(i + 1) + ". " + items[i].Name);
	}
	std::cin >> My_input;
	int Choice = std::stoi(My_input);

	write("Great! How many do you want?");
	std::cin >> My_input;
	int amount = std::stoi(My_input);
	

	//instead of using a switch here I use an if statement to pick the item. Since the items have a number as an name I can call on them by typing the number and -1

	if (Choice <= items[Choice - 1].Stock)
	{
		//An int to remember what the player paid for the items
		int price = items[Choice - 1].Price * amount;

		//Made the in to a string so I can write it with the write function.
		write("That will cost you " + std::to_string(price) + " gold pieces");

		items[Choice - 1].Stock -= amount;
		Balance -= price;
		
		std::cout << Balance << std::endl;	

		if (Choice == 1 )
		{
			Inventory_HPotion += amount;

		}
	}
	else
	{
		write("We don't have that many sorry");
	}
	
}


int main()
{
	//You write this to be able to write an input if you have a "if" function or something
	//string is used to save an array of characters

	std::string My_input;





	std::vector<Attack> attacks;

	attacks.push_back(Attack("Slash", 15));
	attacks.push_back(Attack("Thrust", 30));







	std::string Startup_sequence = "You're shaking in your boots, this is it. You're going to register yourself as an adventurer in the local guild!";

	write(Startup_sequence);

	write("You walk up to the big fella at the register.");

	write("Hello boy! I am Big Fella Steve. Are you ready to take on the life as an adventurer?");
	std::cin >> My_input;

	//This transform is so you can write letters with uppercase and it will still understand that you mean yes. I understand it's function I just don't understand the code, I have not written this one myself
	std::transform(My_input.begin(), My_input.end(), My_input.begin(),
		[](unsigned char c) { return std::tolower(c); });
	if (My_input == "yes" || My_input == "hell yeah!")
	{
		write("Good choice! You will need to fill out this form and pay the entering fee of 50 gold pieces! You will be able to earn moeney by doing simple tasks, by doing those you can move up in rank and unlock even harder tasks!");
	}
	else
	{
		write("Game over!");
		return 0;
	}
	system("cls");
	write("The form was a just a regular form");

	std::string Name;

	//While loop is used here to repeat the sequence till the player is satisfied with his or hers name.
	while (true)
	{
		write("Name:");
		std::cin >> My_input;
		Name = My_input;
		write(My_input + " was your name right?");
		std::cin >> My_input;

		std::transform(My_input.begin(), My_input.end(), My_input.begin(),
			[](unsigned char c) { return std::tolower(c); });
		//Here I use an if function to get the right input.
		if (My_input == "yes")
		{
			write("Good luck " + Name + "!");
			
			break;
		}


	}
	system("cls");

	write("The form is finished so " + Name + " heads back to Big Fella Steve");
	write("Thank you! Now I will need 50 gold pieces from you.");
	write("You give Big Fella Steve 50 gold pieces! Your balance is now updated :)");
	Balance = Balance - 50;


	//This is where the starting sequence ends
	system("cls");

	while (true)
	{

		//Endless loop where you can select what to do
		write("What would you like to do now?");
		write("1. Balance and rank");
		write("2. Check what tasks are available");
		write("3. Visit the shop");


		std::cin >> My_input;
		std::transform(My_input.begin(), My_input.end(), My_input.begin(),
			[](unsigned char c) { return std::tolower(c); });
		if (My_input == "3" || My_input == "3.")
		{
			system("cls");
			shop();
			Sleep(2000);
			system("cls");
		}

		//Balance
		if (My_input == "1" || My_input == "1.")
		{
			system("cls");
			std::cout << Balance << " gold pieces" << std::endl;
			std::cout << "You're rank " << Rank << std::endl;
			Sleep(2000);//2000
			system("cls");
			continue;

		}
		//Taskboard
		if (My_input == "2" || My_input == "2.")
		{
			system("cls");
			if (Rank == 3)
			{
				write("No more tasks available at this time");
				continue;
			}
			//If you've completed the first quest then the other quest will be available, hence the if rank 2
			if (Rank == 2)
			{
				while (true)
				{

					//This is the start of the second quest
					write("You walk up to the board once again and there seems to be only 1 available task");
					write("1. Loot the chest in the ruins");
					Sleep(2000);
					std::cin >> My_input;
					if (My_input == "1" || My_input == "1.")
					{
						write("Loot thest in the ruins to the west");
						quest(1000, 3);
						std::cin >> My_input;
						std::transform(My_input.begin(), My_input.end(), My_input.begin(),
							[](unsigned char c) { return std::tolower(c); });
						if (My_input == "accept")
						{

							write("Quest accepted");
							write("Are you doing that quest young man?");
							std::cin >> My_input;
							std::transform(My_input.begin(), My_input.end(), My_input.begin(),
								[](unsigned char c) { return std::tolower(c); });
							if (My_input == "yes" || My_input == "I am")
							{
								write("Then go ahead and report it to the register");
								Sleep(2000);
								system("cls");
							}
							else
							{
								continue;
							}
						}
						else
						{
							continue;
						}

					}

					write("Oh, your doing this one next. You're supposed to head to the west. Follow the trail to the old king's castle. which is in ruins now. Get the stuff from the chest.");
					write("You will be rewarded 500 gold pieces and rank 3. Good luck!");
					system("cls");
					write(Name + " heads out to the west.");
					write(Name + " sees the ruins and runs toward it.");
					write("When " + Name + " arrives at the chest they see that a bigger monster is protecting the chest!");
					write("The monster comes running at you but it appears to be very slow");

					//This is the third and last battle of the game
					bool turn = true;

					while (true)
					{

						write("What attack do you want to use?");



						for (int i = 0; i < attacks.size(); i++)
						{

							write(std::to_string(i + 1) + ". " + attacks[i].Name);

						}
						std::cin >> My_input;

						int Choice = std::stoi(My_input);

						if (turn == true)
						{



							if (Choice == 1)
							{

								//My turn and I have a choice to use attack 1 or attack 2. Attack 2 has a bigger chance miss then attack 1.
								int Random_Number = GenerateRandomNumber(1, 100);
								if (Random_Number <= 95)
								{

									std::cout << attacks[0].Name << " used" << std::endl;
									Health_Monster2 -= attacks[0].Damage;
									std::cout << "The monsters health is now " << Health_Monster2 << std::endl;
									turn = false;

								}
								else
								{
									write("You missed");
									turn = false;
								}
							}


							if (Choice == 2)
							{
								int Random_Number = GenerateRandomNumber(1, 100);
								if (Random_Number <= 80)
								{

									std::cout << attacks[1].Name << " used" << std::endl;
									Health_Monster2 -= attacks[1].Damage;
									std::cout << "The mosters health is now " << Health_Monster2 << std::endl;
									turn = false;
								}
								else
								{
									write("You missed");
									turn = false;
								}
							}


							if (Health_Monster2 <= 0)
							{
								write("You won the battle!");
								Health_Monster2 = 100;
								break;
							}
							if (Health_Player <= 0)
							{
								write("Game over");
								return 0;
							}
						}
						if (turn == false)
						{
							//Monsters turn and the monster has a big chance to miss but he hits hard.
							int Random_Number = GenerateRandomNumber(1, 100);
							if (Random_Number >= 30)
							{
								float Damage_Multiplier = GenerateRandomNumber(100, 125);


								std::cout << "The monster used " << attacks[0].Name << " and it hit for " << Damage_Multiplier / 100.0 * attacks[0].Damage << std::endl;
								Total_Damage = Damage_Multiplier / 100.0 * attacks[0].Damage;
								Health_Player -= Total_Damage;
								std::cout << Name << " health is now " << Health_Player << std::endl;
								turn = true;



							}
							else

							{
								write("The monster missed");
								turn = true;
							}
							if (Health_Player <= 0)
							{
								write("Game Over");
								return 0;
							}
							if (Health_Monster2 <= 0)
							{
								write("You won the battle!");
								Health_Monster2 = 200;
								break;
							}
						}
					}
					Sleep(2000);
					system("cls");
					write("That sure was a though fight");
					if (Inventory_HPotion >= 1)
					{
						//The game asks if you want to use a health potion or not
						write("Do you want to use a health potion?");
						std::cin >> My_input;
							std::transform(My_input.begin(), My_input.end(), My_input.begin(),
								[](unsigned char c) { return std::tolower(c); });
							if (My_input == "yes")
							{
								write(Name + " drank a health potion and is now at full hp");
								Inventory_HPotion = 0;
							}
							else
							{
								write("You did not drink a potion");
							}
					}
				
					
					
					//The game prints out that you looted the chest
					write("You loot the chest and found a book");
					write("The book was big and dusty, looked like it hadn't been used in ages");
					system("cls");
					write(Name + " walked back to town with the book");
					write(Name + " got rewarded with 1000 gold pieces and rank 3!");
					Rank = 3;
					Balance += 1000;
					break;
				}
			}
			//This is actually where the gamebe
			else
			{
				write("You walk to the board with all the task posters on.");

				system("cls");
				write("There seems to be only 1 available task.");

				system("cls");
				while (true)
				{


					write("1. Deliever the scroll to the guards outside of the castle!");

					std::cin >> My_input;
					if (My_input == "1" || My_input == "1.")
					{
						write("You pick up the parchment and it says you are to head to the south and deliever the scroll to the guards at the gates of the castle.");
						quest(500, 2);

						std::cin >> My_input;

						std::transform(My_input.begin(), My_input.end(), My_input.begin(),
							[](unsigned char c) { return std::tolower(c); });

						if (My_input == "accept")
						{

							write("Quest Accepted");
							write("Are you doing that quest young man?");
							std::cin >> My_input;
							std::transform(My_input.begin(), My_input.end(), My_input.begin(),
								[](unsigned char c) { return std::tolower(c); });
							if (My_input == "yes" || My_input == "I am")
							{
								write("Then go ahead and report it to the register");
								break;
							}
							else
							{
								continue;
							}

						}
						else
						{
							continue;
						}


					}

				}
				Sleep(2000);
				system("cls");
				write(Name + " heads to the register");
				write("Big Fella Steve is still there and he welcomes you back");
				write("So you want to do this one?");
				write("Exit this town through the south gate and from there follow the trail. When you reach Outfall Town you are at the place. I'm sure you can figure it out from there");

				system("cls");
				Sleep(2000);

				write(Name + " goes to the south gate and heads out of town");
				write("A tiny blonde goblin appears right in front of you and tries to attack you with a spear, it only scrapes ur right arm abit.");
				write("The goblin dealt 5 DMG to you");

				Health_Player -= 5;

				std::cout << Health_Player << " is " << Name << "'s current health" << std::endl;


				bool turn = true;

				//Battle sequence with turn based combat
				while (true)
				{

					write("What attack do you want to use?");



					for (int i = 0; i < attacks.size(); i++)
					{

						write(std::to_string(i + 1) + ". " + attacks[i].Name);

					}
					std::cin >> My_input;

					int Choice = std::stoi(My_input);

					if (turn == true)
					{



						if (Choice == 1)
						{


							int Random_Number = GenerateRandomNumber(1, 100);
							if (Random_Number <= 95)
							{

								std::cout << attacks[0].Name << " used" << std::endl;
								Health_Monster -= attacks[0].Damage;
								std::cout << "The goblins health is now " << Health_Monster << std::endl;
								turn = false;

							}
							else
							{
								write("You missed");
								turn = false;
							}
						}


						if (Choice == 2)
						{
							int Random_Number = GenerateRandomNumber(1, 100);
							if (Random_Number <= 80)
							{

								std::cout << attacks[1].Name << " used" << std::endl;
								Health_Monster -= attacks[1].Damage;
								std::cout << "The goblins health is now " << Health_Monster << std::endl;
								turn = false;
							}
							else
							{
								write("You missed");
								turn = false;
							}
						}


						if (Health_Monster <= 0)
						{
							write("You won the battle!");
							Health_Monster = 100;
							break;
						}
						if (Health_Player <= 0)
						{
							write("Game over");
							return 0;
						}
					}
					if (turn == false)
					{
						int Random_Number = GenerateRandomNumber(1, 100);
						if (Random_Number >= 20)
						{
							std::cout << "The goblin used " << attacks[0].Name << std::endl;
							Health_Player -= attacks[0].Damage;
							std::cout << Name << "'s health is now " << Health_Player << std::endl;
							turn = true;
						}
						else
						{
							std::cout << "The goblin used " << attacks[1].Name << std::endl;
							Health_Player -= attacks[1].Damage;
							std::cout << Name << "'s health is now " << Health_Player << std::endl;
							turn = true;
						}


						if (Health_Monster <= 0)
						{
							write("You won the battle!");
							Health_Monster = 100;
							break;
						}
						if (Health_Player <= 0)
						{
							write("Game over");
							return 0;
						}


					}
				};
				if (Inventory_HPotion >= 1)
				{
					write("This fight left you in quite the bad shape, Do you want to heal?");
					std::cin >> My_input;

					std::transform(My_input.begin(), My_input.end(), My_input.begin(),
						[](unsigned char c) { return std::tolower(c); });

					if (My_input == "yes")
					{
						Health_Player = 100;
						write(Name + " used an health potion, " + Name + " is now at full hp");
					}
				}
			
				else
				{
					continue;
				}

				Sleep(2000);
				system("cls");
				write("You continue down the path to Outfall town");
				write("I took 2 full days to get to Outfall town");
				write("When you got there you delivered the scroll to the guards they thanked you and you started to head back");
				Sleep(2000);
				system("cls");
				write("When you walked back to the gate a guard started following you");
				write("He had followed you in the shadows for about an hour now");
				write("You started to get used to it and let down your guard");
				write("Anoter hour passes and the guard starts running at you");


				turn = true;

				//Battle sequence with turn based combat
				while (true)
				{

					write("What attack do you want to use?");



					for (int i = 0; i < attacks.size(); i++)
					{

						write(std::to_string(i + 1) + ". " + attacks[i].Name);

					}
					std::cin >> My_input;

					int Choice = std::stoi(My_input);

					if (turn == true)
					{

						int Random_Number = GenerateRandomNumber(1, 100);



						if (Choice == 1)
						{
							if (Random_Number <= 95)
							{
								std::cout << attacks[0].Name << " used" << std::endl;
								Health_Guard -= attacks[0].Damage;
								std::cout << "The guards health is now " << Health_Guard << std::endl;
								turn = false;
							}
							else
							{
								write("You missed");
								turn = false;
							}
						}

						if (Choice == 2)
						{
							if (Random_Number <= 80)
							{
								std::cout << attacks[1].Name << " used" << std::endl;
								Health_Guard -= attacks[1].Damage;
								std::cout << "The guards health is now " << Health_Guard << std::endl;
								turn = false;
							}
							else
							{
								write("You missed");
								turn = false;
							}
						}





						if (Health_Guard <= 0)
						{
							write("You won the battle!");
							Health_Guard = 100;
							break;
						}
						if (Health_Player <= 0)
						{
							write("Game over");
							return 0;
						}
					}
					if (turn == false)
					{
						int Random_Number = GenerateRandomNumber(1, 100);
						if (Random_Number >= 20)
						{
							std::cout << "The guard used " << attacks[0].Name << std::endl;
							Health_Player -= attacks[0].Damage;
							std::cout << Name << "'s health is now " << Health_Player << std::endl;
							turn = true;
						}
						else
						{
							std::cout << "The guard used " << attacks[1].Name << std::endl;
							Health_Player -= attacks[1].Damage;
							std::cout << Name << "'s health is now " << Health_Player << std::endl;
							turn = true;
						}


						if (Health_Guard <= 0)
						{
							write("You won the battle!");
							Health_Guard = 100;
							break;
						}
						if (Health_Player <= 0)
						{
							write("Game over");
							return 0;
						}


					}
				};

				Sleep(2000);
				system("cls");
				write("Quite an unexpected battle but it turned out okay");
				write("You ran out of healing potions during your last fight");
				Sleep(2000);
				write("You got back to town, when you were traveling you healed back up to full hp");
				Health_Player = 100;
				system("cls");
				write("You got back to the guild and they rewarded you with 500 gold pieces and you ranked up to rank 2!");
				system("cls");
				Balance += 500;
				Rank = 2;
















			}
		}


	}
}
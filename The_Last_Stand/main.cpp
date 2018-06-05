
#include <iostream>
#include <fstream>
#include <string>
#include "cell.h"
#include "character.h"
#include "playable_character.h"
#include "grid.h"
#include "gameView.h"
#include "enemy.h"
#include "Buff.h"
#include "Spells.h"
#include <SFML/Graphics.hpp>
#include <math.h>
/*SOUND*/
#include <SFML/Audio.hpp>

using namespace std;

const int nbCharactersMax = SIZE * SIZE;
int nbCharacters = 5;
int nbPlayable = 3;
const int TILE_SIZE = 60;
int counter = 0;
int counter2 = 0;

bool isMove = false;
float dx = 0, dy = 0;
sf::Vector2f oldPos, newPos;
sf::Vector2f myPos, enPos;
//std::string str;
int n = 0;
int k = 0;
int k1 = 0;
int kMe = 0;
int kEn = 0;

sf::Sprite mapSprite[SIZE*SIZE];
sf::Sprite characterSprite[nbCharactersMax];
vector<sf::Sprite> vecCarP;
vector<sf::Sprite> vecCarE;

sf::Texture mapTexture;
sf::Texture characterTexture;


/*
int mapSFML[SIZE][SIZE] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
*/


bool isEnemy(game &g, int px, int py) {
	if (enemy *b = dynamic_cast<enemy*>(&g.getMap().getCell(px, py).getChara()))
	{
		return true;
	}
	return false;
}

bool isRange(character * actualChar, sf::Vector2f oldPos, sf::Vector2f newPos) {
	int a = newPos.y / TILE_SIZE - oldPos.y / TILE_SIZE;
	int b = newPos.x / TILE_SIZE - oldPos.x / TILE_SIZE;
	a = abs(a);
	b = abs(b);
	cout << "MY****************XXXXXXXXXX" << oldPos.y / TILE_SIZE << endl;
	cout << "MY****************YYYYYYYYY" << oldPos.x / TILE_SIZE << endl;
	cout << "EN****************XXXXXXXXXX" << newPos.y / TILE_SIZE << endl;
	cout << "EN****************YYYYYYYYY" << newPos.x / TILE_SIZE << endl;
	if (a + b <= actualChar->getMovement()) {
		return true;
	}
	else {
		return false;
	}
}



void loadMap(game& g) {
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					mapSprite[k].setTextureRect(sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
				}
				else
					mapSprite[k].setTextureRect(sf::IntRect(0, 60, TILE_SIZE, TILE_SIZE));
			}
			else
			{
				if (j % 2 == 0)
				{
					mapSprite[k].setTextureRect(sf::IntRect(0, 60, TILE_SIZE, TILE_SIZE));
				}
				else
					mapSprite[k].setTextureRect(sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
			}
			mapSprite[k].setPosition(TILE_SIZE*j, TILE_SIZE*i);
			if (&g.getMap().getCell(i, j).getChara() != nullptr)
			{
				if (isEnemy(g, i, j))
				{
					cout << "YY" << endl;
					cout << "KK" << k1 << endl;
					//characterSprite[k1].setTextureRect(sf::IntRect(0, 180, TILE_SIZE, TILE_SIZE));
					//characterSprite[k1].setPosition(TILE_SIZE*j, TILE_SIZE*i);

					vecCarP[k1].setTextureRect(sf::IntRect(0, 180, TILE_SIZE, TILE_SIZE));
					vecCarP[k1].setPosition(TILE_SIZE*j, TILE_SIZE*i);

					cout << "POSITION XXX" << j << endl;
					cout << "POSITION YYY" << i << endl;
					k1++;
				}
				else
				{
					cout << "XX" << endl;
					//characterSprite[k1].setTextureRect(sf::IntRect(0, counter, TILE_SIZE, TILE_SIZE));
					//characterSprite[k1].setPosition(TILE_SIZE*j, TILE_SIZE*i);
					counter = g.getIndex(g.getMap().getCell(i, j).getChara()) * 60;
					vecCarP[k1].setTextureRect(sf::IntRect(0, counter, TILE_SIZE, TILE_SIZE));
					vecCarP[k1].setPosition(TILE_SIZE*j, TILE_SIZE*i);
					//counter += TILE_SIZE;
					k1++;
				}
			}
			k++;
		}
	}
}

void setSpritePosition(game& g) {
	k1 = 0;
	counter = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (&g.getMap().getCell(i, j).getChara() != nullptr)
			{
				if (k1 > nbCharacters) {
					vecCarP.push_back(characterSprite[k1]);
					nbCharacters++;
				}
				if (isEnemy(g, i, j))
				{
					cout << "YY" << endl;
					cout << "KK" << k1 << endl;
					//characterSprite[k1].setTextureRect(sf::IntRect(0, 180, TILE_SIZE, TILE_SIZE));
					//characterSprite[k1].setPosition(TILE_SIZE*j, TILE_SIZE*i);

					vecCarP[k1].setTextureRect(sf::IntRect(0, 180, TILE_SIZE, TILE_SIZE));
					vecCarP[k1].setPosition(TILE_SIZE*j, TILE_SIZE*i);

					cout << "POSITION XXX" << j << endl;
					cout << "POSITION YYY" << i << endl;
					k1++;
				}
				else
				{
					cout << "XX" << endl;
					//characterSprite[k1].setTextureRect(sf::IntRect(0, counter, TILE_SIZE, TILE_SIZE));
					//characterSprite[k1].setPosition(TILE_SIZE*j, TILE_SIZE*i);
					counter = g.getIndex(g.getMap().getCell(i, j).getChara()) * 60;
					std::cout << "counter = " << counter << std::endl;
					vecCarP[k1].setTextureRect(sf::IntRect(0, counter, TILE_SIZE, TILE_SIZE));
					vecCarP[k1].setPosition(TILE_SIZE*j, TILE_SIZE*i);
					//counter += TILE_SIZE;
					k1++;
				}
			}
		}
	}
	for (int i = k1; i < nbCharacters; ++i) {
		vecCarP.erase(vecCarP.begin() + i);
		nbCharacters--;
	}
}



int isTaken(sf::Vector2f v, game& g) {
	for (int i = 0; i < nbCharacters; i++)
	{
		//if ((characterSprite[i].getPosition().x == v.x) && (characterSprite[i].getPosition().y == v.y)) {
		if ((vecCarP[i].getPosition().x == v.x) && (vecCarP[i].getPosition().y == v.y)) {
			if (isEnemy(g, v.y / TILE_SIZE, v.x / TILE_SIZE))
			{
				return 1;
			}
			return 2;
		}
		if (v.x < -1 || v.x > 540 || v.y < -1 || v.y > 540)
		{
			return 2;
		}
	}
	return 0;
}

/*
std::string toChessNote(sf::Vector2f p)
{
	std::string s = "";
	s += char(p.x / TILE_SIZE + 97);
	s += char(7 - p.y / TILE_SIZE + 49);
	return s;
}
*/

int main() {
	/****************/
	sf::Vector2f screenDimensions(600, 600);
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Tile Maps Demo");
	
	/*AUDIO*/
	sf::Music musicBegin;
	if (!musicBegin.openFromFile("sounds/begin.ogg")) {
		std::cout << "Error! sound didn't load" << std::endl;
	}
	musicBegin.play();
	sf::Music musicEnd;
	if (!musicEnd.openFromFile("sounds/end.ogg")) {
		std::cout << "Error! sound didn't load" << std::endl;
	}

	sf::Music musicPunch;
	if (!musicPunch.openFromFile("sounds/punch.ogg")) {
		std::cout << "Error! sound didn't load" << std::endl;
	}

	sf::Music musicTeleport;
	if (!musicTeleport.openFromFile("sounds/teleport.ogg")) {
		std::cout << "Error! sound didn't load" << std::endl;
	}
	


	if (!mapTexture.loadFromFile("images/grid.jpg"))
		std::cout << "Error! image didn't load" << std::endl;

	if (!characterTexture.loadFromFile("images/caracters.png"))
		std::cout << "Error! image didn't load" << std::endl;


	for (int i = 0; i < SIZE*SIZE; i++)
	{
		mapSprite[i].setTexture(mapTexture);
	}

	for (int i = 0; i < nbCharacters; i++)
	{
		characterSprite[i].setTexture(characterTexture);
		vecCarP.push_back(characterSprite[i]);
	}
	for (int i = 3; i < nbCharacters; ++i)
	{
		characterSprite[i].setTexture(characterTexture);
		vecCarE.push_back(characterSprite[i]);
	}


	/****************/
	game g;
	gameView game;

	Buff Force10("Muscle", "Strength", 10);
	Buff Increvable("Increvable", "HP", 30);
	Spells s("TimeControl", 6);
	playable_character c("Goku", Berserk, 5);
	c.setSkill(&Force10);
	c.setSkill(&s);
	playable_character f("Vegeta", 4);
	//enemy f("Fenix");
	f.setSkill(&Increvable);
	playable_character m("Gohan", 3);
	c.setMovement(2);
	f.setMovement(2);
	m.setMovement(2);
	//enemy m("Zergling");
	enemy e1("Peon1");
	enemy e2("Péon2");
	g.addPlayable(c);
	g.addPlayable(f);
	g.addPlayable(m);
	g.addEnemy(e1);
	g.addEnemy(e2);
	character * actualChar = nullptr;
	actualChar = g.getplayable()[0];
	cout << "Welcome to our game :" << endl;
	cout << "This is our first character: " << endl;
	cout << c << endl;
	g.addChara(0, 0, c);
	g.addChara(0, 1, f);
	g.addChara(0, 5, m);
	g.addChara(9, 9, e1);
	g.addChara(9, 0, e2);
	cout << "This is the grid: " << endl;
	game.printGame(g);

	bool exit = false;
	int choice = 0;

	loadMap(g);
	while (!exit && !g.gameOver() && Window.isOpen()) { //c.getHP() > 0
		/*
		cout << "Choose a direction: 0 = TOP, 1 = RIGHT, 2 = BOT, 3 = LEFT, 4 = QUIT, 5 = FIRST CHAR, 6 = SECOND CHAR,7 = THIRD CHAR" << endl;
		cin >> choice;
		if (choice == 4) {
			exit = true;
		}
		else if (choice == 5) {
			actualChar = g.getplayable()[0];
		}
		else if (choice == 6) {
			actualChar = g.getplayable()[1];
		}
		else if (choice == 7) {
			actualChar = g.getplayable()[2];
		}

		else {
			g.movingCharacter(*actualChar, choice);
			//g.movingEnemy(f);
			//g.movingEnemy(m);
			//g.movingEnemy(e2);
			//game.printGrid(g);
			g.enemyPhase();
			g.spawning();
			game.printGame(g);
			cout << c << endl;

			if (g.getplayable()[1]->getHP() > 0)
				cout << f << endl;
			if (g.getplayable()[2]->getHP() > 0)
				cout << m << endl;
			cout << "tour : " << g.getTurn()<<endl;
			g.incTurn();

		}
		//g.movingEnemy(e1);

		/*******************/

		sf::Vector2i pos = sf::Mouse::getPosition(Window);
		sf::Event event;
		while (Window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;

			case sf::Event::MouseButtonPressed:
				/*SOUND*/
				musicPunch.stop();
				musicTeleport.stop();
				cout << "PRESSED" << endl;
				if (event.key.code == sf::Mouse::Left)
					for (int i = 0; i < nbCharacters; i++)
					{
						//if (characterSprite[i].getGlobalBounds().contains(pos.x, pos.y))
						if (vecCarP[i].getGlobalBounds().contains(pos.x, pos.y))
						{
							//cout << "SELECT XXXX" << characterSprite[i].getPosition().x / TILE_SIZE << endl;
							//cout << "SELECT YYYY" << characterSprite[i].getPosition().y / TILE_SIZE << endl;
							//if (isEnemy(g, characterSprite[i].getPosition().y / TILE_SIZE, characterSprite[i].getPosition().x / TILE_SIZE))
							if (isEnemy(g, vecCarP[i].getPosition().y / TILE_SIZE, vecCarP[i].getPosition().x / TILE_SIZE))

							{
								cout << "ENNEMI" << endl;
								isMove = false;
								break;
							}
							isMove = true;
							n = i;
							//dx = pos.x - characterSprite[i].getPosition().x;
							//dy = pos.y - characterSprite[i].getPosition().y;

							dx = pos.x - vecCarP[i].getPosition().x;
							dy = pos.y - vecCarP[i].getPosition().y;

							//oldPos = characterSprite[i].getPosition();
							oldPos = vecCarP[i].getPosition();
							
							actualChar = nullptr;
							//if (&g.getMap().getCell(characterSprite[i].getPosition().y / TILE_SIZE, characterSprite[i].getPosition().x / TILE_SIZE).getChara() != nullptr) {
								//actualChar = &g.getMap().getCell(characterSprite[i].getPosition().y / TILE_SIZE, characterSprite[i].getPosition().x / TILE_SIZE).getChara();
							//}
							if (&g.getMap().getCell(vecCarP[i].getPosition().y / TILE_SIZE, vecCarP[i].getPosition().x / TILE_SIZE).getChara() != nullptr) {
								actualChar = &g.getMap().getCell(vecCarP[i].getPosition().y / TILE_SIZE, vecCarP[i].getPosition().x / TILE_SIZE).getChara();
							}
							cout << "bla" << actualChar->getName();
						}
					}
				break;

			case sf::Event::MouseButtonReleased:
				cout << "RELEASED" << endl;
				if (isMove == true)
				{
					if (event.key.code == sf::Mouse::Left)
					{
						//sf::Vector2f p = characterSprite[n].getPosition() + sf::Vector2f(TILE_SIZE / 2, TILE_SIZE / 2); //specific box
						sf::Vector2f p = vecCarP[n].getPosition() + sf::Vector2f(TILE_SIZE / 2, TILE_SIZE / 2); //specific box

						sf::Vector2f newPos = sf::Vector2f(TILE_SIZE*int(p.x / TILE_SIZE), TILE_SIZE*int(p.y / TILE_SIZE));
						if (isTaken(newPos, g) == 2)
						{
							std::cout << "************" << newPos.x << std::endl;
							//std::cout << str << std::endl;
							isMove = false;
							//characterSprite[n].setPosition(oldPos);
							vecCarP[n].setPosition(oldPos);
							break;
						}
						if (isTaken(newPos, g) == 1)
						{
							if (isRange(actualChar, oldPos, newPos))
							{
								actualChar->attacking(g.getMap().getCell(newPos.y / TILE_SIZE, newPos.x / TILE_SIZE).getChara());
								if (g.getMap().getCell(newPos.y / TILE_SIZE, newPos.x / TILE_SIZE).getChara().getHP()>0) {
									g.getMap().getCell(newPos.y / TILE_SIZE, newPos.x / TILE_SIZE).getChara().attacking(*actualChar);
								}
								cout << "HP !!!!! " << g.getMap().getCell(newPos.y / TILE_SIZE, newPos.x / TILE_SIZE).getChara().getHP() << endl;
							}
							//characterSprite[n].setPosition(oldPos);
							vecCarP[n].setPosition(oldPos);
							/*SOUND*/
							musicPunch.play();
						}
						else
						{
							//if (newPos.y / TILE_SIZE <= oldPos.y / TILE_SIZE + actualChar->getMovement() && newPos.x / TILE_SIZE <= oldPos.x / TILE_SIZE + actualChar->getMovement() && newPos.y / TILE_SIZE >= oldPos.y / TILE_SIZE - actualChar->getMovement() && newPos.x / TILE_SIZE >= oldPos.x / TILE_SIZE - actualChar->getMovement()) {
							if (isRange(actualChar, oldPos, newPos)) {
								/*SOUND*/
								musicTeleport.play();
								vecCarP[n].setPosition(newPos);
								g.getMap().getCell(oldPos.y / TILE_SIZE, oldPos.x / TILE_SIZE).resetChara();
								g.addChara(newPos.y / TILE_SIZE, newPos.x / TILE_SIZE, *actualChar);
							}
							else {
								vecCarP[n].setPosition(oldPos);
							}
							//str = toChessNote(oldPos) + toChessNote(newPos);
							//std::cout << str << std::endl;
						}
						isMove = false;
					}
				}

				g.enemyPhase();
				setSpritePosition(g);

				for (int i = 0; i < nbCharacters; i++)
				{
					if (!isEnemy(g, vecCarP[i].getPosition().y / TILE_SIZE, vecCarP[i].getPosition().x / TILE_SIZE))
					{
						myPos.x = vecCarP[i].getPosition().x;
						myPos.y = vecCarP[i].getPosition().y;
						for (int j = 0; j < nbCharacters; j++)
						{
							if (isEnemy(g, vecCarP[j].getPosition().y / TILE_SIZE, vecCarP[j].getPosition().x / TILE_SIZE))
							{
								enPos.x = vecCarP[j].getPosition().x;
								enPos.y = vecCarP[j].getPosition().y;

								if (&g.getMap().getCell(myPos.y / TILE_SIZE, myPos.x / TILE_SIZE).getChara()!=nullptr&&isRange(&g.getMap().getCell(myPos.y / TILE_SIZE, myPos.x / TILE_SIZE).getChara(), myPos, enPos))
								{
									counter2 = g.getIndex(g.getMap().getCell(myPos.y / TILE_SIZE, myPos.x / TILE_SIZE).getChara()) * 60;
									vecCarP[j].setTextureRect(sf::IntRect(TILE_SIZE, 180, TILE_SIZE, TILE_SIZE));
									vecCarP[i].setTextureRect(sf::IntRect(TILE_SIZE, counter2, TILE_SIZE, TILE_SIZE));
									break;
								}
								else
								{
									counter2 = g.getIndex(g.getMap().getCell(myPos.y / TILE_SIZE, myPos.x / TILE_SIZE).getChara()) * 60;
									vecCarP[i].setTextureRect(sf::IntRect(0, counter2, TILE_SIZE, TILE_SIZE));
								}
							}
						}
						counter2 += TILE_SIZE;
					}
					else
					{
						enPos.x = vecCarP[i].getPosition().x;
						enPos.y = vecCarP[i].getPosition().y;

						for (int j = 0; j < nbCharacters; j++)
						{
							if (!isEnemy(g, vecCarP[j].getPosition().y / TILE_SIZE, vecCarP[j].getPosition().x / TILE_SIZE))
							{
								myPos.x = vecCarP[j].getPosition().x;
								myPos.y = vecCarP[j].getPosition().y;
								if (enPos.x/TILE_SIZE==9&& enPos.y / TILE_SIZE == 9)
								{
									cout << "YO" << endl;
								}
								if (isRange(&g.getMap().getCell(enPos.y / TILE_SIZE, enPos.x / TILE_SIZE).getChara(), myPos, enPos))
								{
									vecCarP[i].setTextureRect(sf::IntRect(TILE_SIZE, 180, TILE_SIZE, TILE_SIZE));
									break;
								}
								else
								{
									vecCarP[i].setTextureRect(sf::IntRect(0, 180, TILE_SIZE, TILE_SIZE));
								}
							}
						}
						if (g.getMap().getCell(enPos.y / TILE_SIZE, enPos.x / TILE_SIZE).getChara().getHP() < 0) {
							vecCarP.erase(vecCarP.begin() + i);
							nbCharacters--;
						}
					}
					
				}
				counter2 = 0;
				//g.enemyPhase();
				//setSpritePosition(g);
			}
		}
		if (isMove)
		{
			vecCarP[n].setPosition(pos.x - dx, pos.y - dy);
		}

		Window.clear();
		for (int i = 0; i < SIZE*SIZE; i++) {
			Window.draw(mapSprite[i]);
		}

		for (int i = 0; i < nbCharacters; i++) {
			//Window.draw(characterSprite[i]);
			Window.draw(vecCarP[i]);
		}
		Window.display();

		/******************/
	}
	//A faire : Perdre quand les 3 persos n'ont plus de vie
	/*if (&actualChar.getHP() == 0) {
		cout << "You lose" << endl;
	}*/
	/*SOUND*/
	musicEnd.play();
	cout << "lose in " << g.getTurn();
	std::system("pause");
	return 0;
}
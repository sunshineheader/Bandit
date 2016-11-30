#ifndef __GAME__DATA__H__H__
#define __GAME__DATA__H__H__
#include "cocos2d.h"

class GameData {
public:
	GameData();
	static GameData* getInstance();
	static void destoryInstance();
public:
	void setCoin(int coin);
	int  getCoin();

private:
	void flush();

private:
	~GameData();
private:
	int _coins;
private: //  pointer
	static GameData* _insatnce;

};
#endif







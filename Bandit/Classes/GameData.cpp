#include "GameData.h"
GameData* GameData::_insatnce = nullptr;

GameData::GameData()
	:_coins(200)
{}

GameData::~GameData()
{}

GameData* GameData::getInstance()
{
	if (!_insatnce)
	{
		_insatnce = new GameData();
	}
	return _insatnce;
}

void GameData::destoryInstance()
{
	delete _insatnce;
	_insatnce = nullptr;
}

void GameData::setCoin(int coin)
{
	_coins = coin;
	cocos2d::UserDefault::getInstance()->setIntegerForKey("PlayerCoin", _coins);
	flush();
}

int  GameData::getCoin()
{
	return 	cocos2d::UserDefault::getInstance()->getIntegerForKey("PlayerCoin", _coins);
}
void GameData::flush()
{
	cocos2d::UserDefault::getInstance()->flush();
}
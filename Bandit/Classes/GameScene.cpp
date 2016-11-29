#include "GameLayer.h"
#include "GameScene.h"

bool GameScene::init()
{
	if (!cocos2d::Scene::init()) {
		return false;
	}
	_gameLayer = GameLayer::create(this);
	addChild(_gameLayer);
	scheduleUpdate();
	return true;
}

void GameScene::update(float delta)
{
	// to do list 
}

#include "GameScene.h"
#include "BaseLayer.h"
BaseLayer::BaseLayer()
	: _doEvent(nullptr)
	, _doUI(nullptr)
	, _removeEvent(nullptr)
	, _gameScene(nullptr)
	, RESOURCE_NAME("")
{}

BaseLayer::~BaseLayer()
{}

bool BaseLayer::init()
{
	if (!cocos2d::Layer::init()){
		return false;
	}
	return true;
}

void BaseLayer::initWithGameScene(GameScene* scene)
{
	if (!this->init())
		return;

	_gameScene = scene;
}


void BaseLayer::onEnter()
{
	cocos2d::Layer::onEnter();
	if (_doEvent) _doEvent();
	if (_doUI)	  _doUI();
}

void BaseLayer::onExit()
{
	cocos2d::Layer::onExit();
	if (_removeEvent)	  _removeEvent();
}
#include "BaseObject.h"
BaseObject::BaseObject()
	: _initObject(nullptr)
	, _destoryObject(nullptr)
	,RESOURCE_NAME("")
{}

BaseObject::~BaseObject()
{}

bool BaseObject::init()
{
	if (!cocos2d::Node::init())
	{
		return false;
	}

	return true;
}

void BaseObject::onEnter()
{
	Node::onEnter();
	if (_initObject) _initObject();
}
void BaseObject::onExit()
{
	Node::onExit();
	if (_destoryObject) _destoryObject();
}
#ifndef __GAME__HELPER__H__H__
#define __GAME__HELPER__H__H__
#include "cocos2d.h"
using namespace cocos2d;

class GameHelper 
{
public:
	GameHelper();
	~GameHelper();
	static cocos2d::Node* seekNodeByName(cocos2d::Node* root, const std::string& name);
private:

};

#endif



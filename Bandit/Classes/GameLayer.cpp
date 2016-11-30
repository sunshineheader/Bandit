#include "AudioHelper.h"
#include "GameData.h"
#include "ElementItem.h"
#include "ButtonItem.h"
#include "GameLayer.h"

static ButtonItemData  buttonItemData[8] = 
{
	{ 0, 5 } , { 1, 10 }, { 2, 10 }, { 3, 15 },
	{ 4, 20 }, { 5, 30 }, { 6, 40 }, { 7, 120 }
};

static ElementItemData elementItemData[24] = 
{
	 // left
	{  0,  2, 15, 33,   1 },
	{  1,  5, 10, 20,   1 },
	{  2,  5, 10, 80,   3 },
	{  3, -1,  5,  0,   0 },
	{  4,  0, 20, 25,   1 },
	{  5,  3, 15, 67,   3 },
	// top			   
	{  6,  1, 20, 33,   1 },
	{  7,  3, 15, 33,   1 },
	{  8,  7,  5, 50,  50 },
	{  9,  7,  5, 50, 120 },
	{ 10,  0, 20, 25,   1 },
	{ 11,  0, 20, 75,   3 },
	// right
	{ 12,  2, 15, 67,   1 },
	{ 13,  4, 15, 33,   1 },
	{ 14,  4, 15, 67,   3 },
	{ 15, -1,  5,  0,   0 },
	{ 16,  0, 20, 25,   1 },
	{ 17,  1, 20, 67,   3 },
	// botton
	{ 18,  1, 20, 33,   1 },
	{ 19,  3, 15, 33,   1 },
	{ 20,  6,  5, 50,   3 },
	{ 21,  6,  5, 50,   1 },
	{ 22,  0, 20, 25,   1 },
	{ 23,  2, 15, 33,   3 },
};


GameLayer* GameLayer::create(GameScene* scene)
{
	GameLayer* layer = new GameLayer();
	if (layer && layer->init(scene)) 
	{
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return nullptr;
}

bool GameLayer::init(GameScene* scene)
{
	BaseLayer::initWithGameScene(scene);
	this->reset();
	this->_doEvent = std::bind(&GameLayer::doEvent, this);
	this->_doUI = std::bind(&GameLayer::doUI, this);
	this->_removeEvent = std::bind(&GameLayer::removeEvent, this);
	return true;
}
void GameLayer::doEvent()
{}

void GameLayer::doUI()
{
	RESOURCE_NAME = "Game/GameLayer.csb";
	auto rootNode = CSLoader::createNode(RESOURCE_NAME);
	addChild(rootNode);
	this->doTopsLayout(rootNode);
	this->doItemLayout(rootNode);
	this->doMiddleBtns(rootNode);
	this->doButtomBtns(rootNode);
}

void GameLayer::reset()
{
	repeatCount = 0;
	currIndex = 0;
	elementHitPool.reserve(4);
}


void GameLayer::removeEvent()
{}

void GameLayer::doTopsLayout(Node* rootNode)
{
	winText = static_cast<Text*> (GameHelper::seekNodeByName(rootNode, "win_txt"));
	creditText = static_cast<Text*> (GameHelper::seekNodeByName(rootNode, "credit_txt"));
	this->refreshUI();
}

void GameLayer::doItemLayout(Node* rootNode)
{
	Layout* elementPanel = static_cast<Layout*> (GameHelper::seekNodeByName(rootNode, "element_panel"));
	for (int index = 0; index < 24; index++) 
	{
		ElementItem* element = ElementItem::createItem(index, elementItemData[index]);
		elementPanel->addChild(element);
		elements[index] = element;
		element->changeElementSeclted(false);
	}
}

void GameLayer::doMiddleBtns(Node* rootNode)
{
	//// 中间部分的Go
	Button* goBtn = static_cast<Button*> (GameHelper::seekNodeByName(rootNode, "goBtn"));
	goBtn->addClickEventListener(CC_CALLBACK_1(GameLayer::goBtnCallBack, this));

	Button* bigBtn = static_cast<Button*> (GameHelper::seekNodeByName(rootNode, "bigBtn"));
	bigBtn->addClickEventListener(CC_CALLBACK_1(GameLayer::bigBtnCallBack, this));

	Button* smallBtn = static_cast<Button*> (GameHelper::seekNodeByName(rootNode, "smallBtn"));
	smallBtn->addClickEventListener(CC_CALLBACK_1(GameLayer::smallBtnCallBack, this));

	Button* rightBtn = static_cast<Button*> (GameHelper::seekNodeByName(rootNode, "rightBtn"));
	rightBtn->addClickEventListener(CC_CALLBACK_1(GameLayer::rightBtnCallBack, this));

	Button* leftBtn = static_cast<Button*> (GameHelper::seekNodeByName(rootNode, "leftBtn"));
	leftBtn->addClickEventListener(CC_CALLBACK_1(GameLayer::leftBtnCallBack, this));

	Button* allBtn = static_cast<Button*> (GameHelper::seekNodeByName(rootNode, "allBtn"));
	allBtn->addClickEventListener(CC_CALLBACK_1(GameLayer::allBtnCallBack, this));
}

void GameLayer::doButtomBtns(Node* rootNode)
{
	Layout* buttomPanel = static_cast<Layout*> (GameHelper::seekNodeByName(rootNode, "buttom_panel"));
	for (int index = 0; index < 8; index++)  
	{
		ButtonItem* itemBtn = ButtonItem::createItem(this,index,buttonItemData[index]);
		buttomPanel->addChild(itemBtn);
		buttons[index] = itemBtn;
	}
}

int GameLayer::checkIndex(int index) {
	int cur_index = index;
	if (cur_index < 0) {
		cur_index += 24;
	}	
	return (cur_index % 24);
}

void GameLayer::checkStepByStep()
{
	// check 大盘
	int currcertGrailElement = this->checkGrailElementStep();
	this->checkElementStep(currcertGrailElement);
}

int GameLayer::checkGrailElementStep()
{
	int currcertGrailElement = 0;
	int randomType = cocos2d::random() % 100 + 1;
	if (randomType <= GrailElement0) {
		currcertGrailElement = 0;

	}
	else if (randomType <= GrailElement1) {
		currcertGrailElement = 1;

	}
	else if (randomType <= GrailElement2) {
		currcertGrailElement = 2;

	}
	else if (randomType <= GrailElement3) {
		currcertGrailElement = 3;

	}
	else if (randomType <= GrailElement4) {
		currcertGrailElement = 4;

	}
	else if (randomType <= GrailElement5) {
		currcertGrailElement = 5;

	}
	else if (randomType <= GrailElement6) {
		currcertGrailElement = 6;

	}
	else if (randomType <= GrailElement7) {
		currcertGrailElement = 7;

	}
	else if (randomType <= GrailElement8) {
		currcertGrailElement = -1;
	}

	return currcertGrailElement;
}

void GameLayer::checkElementStep(int grailelement)
{
	int currcertGrailElement = grailelement;
	// find all data about element
	for (int index = 0; index < 24; index++) {
		int elementIndex = elements[index]->getElementItemData().basic_button_index;
		if (currcertGrailElement == elementIndex) {
			elementHitPool.pushBack(elements[index]);
		}
	}
}

int GameLayer::checkEndedElementIndex()
{
	int randomType = cocos2d::random() % 100 + 1;
	int minRate = 25;
	if (randomType <= minRate) {
	
	}
	else {

	}
	return 0;
}

bool GameLayer::checkButtonItemClick()
{
	for (int index = 0; index < 8; index++) 
	{
		if (buttons[index]->getItemNum()!= 0)
		{
			return true;
		}
	}
	return false;
}

void GameLayer::goBtnCallBack(Ref* psender)
{
	if (this->checkButtonItemClick()) {
		this->checkStepByStep();
	}
	// this->schedule(schedule_selector(GameLayer::startRun), 0.333, 2, 0.5);
}

void GameLayer::startRun(float delta) 
{
	currIndex = this->checkIndex(currIndex);
	elements[currIndex]->changeElementSeclted(true);
	currIndex++;
	repeatCount++;
	if (repeatCount == 3) {
		repeatCount = 0;
		this->unschedule(schedule_selector(GameLayer::startRun));
		this->schedule(schedule_selector(GameLayer::startAddSpeed), 0.1, 100, 0);
	}
}

void GameLayer::startAddSpeed(float delta)
{
	currIndex = this->checkIndex(currIndex);
	elements[currIndex]->changeElementSeclted(true);

	int nextIndex = currIndex = this->checkIndex(currIndex + 1);
	elements[nextIndex]->changeElementSeclted(true);
}


void GameLayer::bigBtnCallBack(Ref* psender)
{}
void GameLayer::smallBtnCallBack(Ref* psender)
{}
void GameLayer::rightBtnCallBack(Ref* psender)
{}
void GameLayer::leftBtnCallBack(Ref* psender)
{}

void GameLayer::allBtnCallBack(Ref* psender) 
{
	for (int index = 0; index < 8; index++) 
	{
		buttons[index]->itemBtnCallBack(psender);
	}
}

void GameLayer::refreshUI()
{
	// TOOD
	int coin = GameData::getInstance()->getCoin();
	creditText->setString(String::createWithFormat("%d", coin)->_string);
	int currCoin = 0;
	winText->setString(String::createWithFormat("%d", currCoin)->_string);
}
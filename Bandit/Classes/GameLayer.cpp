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
	if (layer && layer->init(scene)) {
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return nullptr;
}

bool GameLayer::init(GameScene* scene)
{
	BaseLayer::initWithGameScene(scene);
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
void GameLayer::removeEvent()
{}

void GameLayer::doTopsLayout(Node* rootNode)
{
	winText = static_cast<Text*> (GameHelper::seekNodeByName(rootNode, "win_txt"));
	winText->setString("default");
	creditText = static_cast<Text*> (GameHelper::seekNodeByName(rootNode, "credit_txt"));
	creditText->setString("default");
}

void GameLayer::doItemLayout(Node* rootNode)
{
	Layout* elementPanel = static_cast<Layout*> (GameHelper::seekNodeByName(rootNode, "element_panel"));
	for (int index = 0; index < 24; index++) {
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
	for (int index = 0; index < 8; index++) {
		ButtonItem* itemBtn = ButtonItem::createItem(this,index,buttonItemData[index]);
		buttonItemPool.pushBack(itemBtn);
		buttomPanel->addChild(itemBtn);
	}
}

void GameLayer::goBtnCallBack(Ref* psender)
{}
void GameLayer::bigBtnCallBack(Ref* psender)
{}
void GameLayer::smallBtnCallBack(Ref* psender)
{}
void GameLayer::rightBtnCallBack(Ref* psender)
{}
void GameLayer::leftBtnCallBack(Ref* psender)
{}
void GameLayer::allBtnCallBack(Ref* psender) 
{}
void GameLayer::refreshUI()
{}
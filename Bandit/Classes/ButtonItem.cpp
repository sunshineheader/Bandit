#include "GameLayer.h"
#include "ButtonItem.h"

ButtonItem*ButtonItem::createItem(GameLayer* layer, int index, const ButtonItemData& data)
{
	ButtonItem* item = new ButtonItem();
	if (item && item->initItem(layer, index, data)) {
		item->autorelease();
		return item;
	}
	CC_SAFE_DELETE(item);
	return nullptr;
}

bool ButtonItem::initItem(GameLayer* layer, int index, const ButtonItemData& data)
{
	if (!BaseObject::init()) {
		return false;
	}
	gameLayer = layer;
	m_index = index;
	m_button_data = data;
	m_num = 0;
	this->_initObject = std::bind(&ButtonItem::initObject, this);
	this->_destoryObject = std::bind(&ButtonItem::destoryObject, this);
	return true;
}


void ButtonItem::initObject()
{
	RESOURCE_NAME = "Game/ButtonItem.csb";
	auto rootNode = CSLoader::createNode(RESOURCE_NAME);
	addChild(rootNode);

	Layout* panel = static_cast<Layout*> (GameHelper::seekNodeByName(rootNode, "panel"));
	setContentSize(panel->getContentSize());
	itemText = static_cast<Text*> (GameHelper::seekNodeByName(rootNode, "element_txt"));
	itemSourceText = static_cast<Text*> (GameHelper::seekNodeByName(rootNode, "element_sorce_txt"));
	itemSourceText->setString(String::createWithFormat("%d", m_button_data.basic_grade)->_string);

	Button* itemBtn = static_cast<Button*> (GameHelper::seekNodeByName(rootNode, "element_btn"));
	itemBtn->addClickEventListener(CC_CALLBACK_1(ButtonItem::itemBtnCallBack, this));
	this->setPositionByIndex(m_index);
}

void ButtonItem::destoryObject()
{}

void ButtonItem::setPositionByIndex(int index)
{
	// ´ÓÓÒ±ßÏò×ó±ßÒÀ´ÎµÝ¼õ
	int curIndex = index;
	this->setPosition(Vec2(450 - 60 * curIndex , 65));
}


void ButtonItem::itemBtnCallBack(Ref* psender)
{
	m_num++;
	if (m_num >= MAX_NUM) {
		m_num = 99;
	}
	itemText->setString(String::createWithFormat("%02d", m_num)->_string);
}


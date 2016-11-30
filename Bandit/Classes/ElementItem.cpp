#include "ElementItem.h"

ElementItem*ElementItem::createItem(int index,const ElementItemData& data)
{
	ElementItem* item = new ElementItem();
	if (item && item->initItem(index, data)) {
		item->autorelease();
		return item;
	}
	CC_SAFE_DELETE(item);
	return nullptr;
}

bool ElementItem::initItem(int index, const ElementItemData& data)
{
	if (!BaseObject::init()) {
		return false;
	}
	m_index = index;
	m_element_data = data;
	this->_initObject = std::bind(&ElementItem::initObject, this);
	this->_destoryObject = std::bind(&ElementItem::destoryObject, this);
	return true;
}


void ElementItem::initObject()
{
	RESOURCE_NAME = "Game/ElementItem.csb";
	auto rootNode = CSLoader::createNode(RESOURCE_NAME);
	addChild(rootNode);
	Layout* element = static_cast<Layout*> (GameHelper::seekNodeByName(rootNode, "element"));
	setContentSize(element->getContentSize());

	fruitImage = static_cast<ImageView*> (GameHelper::seekNodeByName(rootNode, "fruit_image"));
	blinkImage = static_cast<ImageView*> (GameHelper::seekNodeByName(rootNode, "blink_image"));
	this->setPositionByIndex(m_index);
}

void ElementItem::destoryObject()
{}

void ElementItem::changeElementSeclted(bool seclted)
{
	blinkImage->setVisible(seclted);
}
void ElementItem::run(std::function<void()> func)
{
	blinkImage->setVisible(true);
}

void ElementItem::setPositionByIndex(int index)
{
	int tempIndex = 0;
	int curIndex = index;
	Vec2 elementPos = Vec2::ZERO;
	if (curIndex < 6){
		tempIndex = curIndex % 6;
		elementPos.x = ELEMENT_WIDTH / 2;
		elementPos.y = ELEMENT_WIDTH / 2 + tempIndex * ELEMENT_WIDTH;
	}
	else if (curIndex < 12){
		tempIndex = curIndex % 6;
		elementPos.x = ELEMENT_WIDTH / 2 + tempIndex * ELEMENT_WIDTH;
		elementPos.y = 390;
	}
	else if (curIndex < 18){
		tempIndex = curIndex % 6;
		elementPos.x = 390;
		elementPos.y = 390 - tempIndex * ELEMENT_WIDTH;
	}
	else if (curIndex < 24){
		tempIndex = curIndex % 6;
		elementPos.x = 390 - tempIndex * ELEMENT_WIDTH;
		elementPos.y = ELEMENT_WIDTH / 2;
	}
	this->setPosition(elementPos);
}




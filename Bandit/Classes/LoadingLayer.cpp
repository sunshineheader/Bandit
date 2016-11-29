#include "LoadingLayer.h"
LoadingLayer* LoadingLayer::create()
{
	LoadingLayer* layer = new LoadingLayer();
	if (layer && layer->init()) {
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return nullptr;
}

bool LoadingLayer::init()
{
	if (!BaseLayer::init()) {
		return false;
	}
	return true;
}

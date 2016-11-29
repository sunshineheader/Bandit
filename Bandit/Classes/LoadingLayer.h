#ifndef __GAME__LOADING__LAYER__
#define __GAME__LOADING__LAYER__

#include "BaseLayer.h"

class LoadingLayer :public BaseLayer {

public:
	static LoadingLayer* create();
private:
	bool init();

};

#endif








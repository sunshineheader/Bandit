#include "GameHelper.h"

GameHelper::GameHelper()
{}

GameHelper::~GameHelper()
{}

Node* GameHelper::seekNodeByName(Node* root, const std::string& name) {
	if (!root) {
		return nullptr;
	}
	if (root->getName() == name) {
		return root;
	}
	const auto& arrayRootChildren = root->getChildren();
	for (auto& subWidget : arrayRootChildren) {
		Node* child = dynamic_cast<Node*>(subWidget);
		if (child) {
			Node* res = seekNodeByName(child, name);
			if (res != nullptr) {
				return res;
			}
		}
	}
	return nullptr;
}
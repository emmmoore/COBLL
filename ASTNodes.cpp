///*
// * Nodes.cpp
// *
// *  Created on: Apr 22, 2022
// *      Author: elanor
// */
#include <string>
#include "Driver.h"

class ASTNode {
public:
	virtual ~ASTNode() {}
};

class DisplayNode : public ASTNode {
};

class StringLitNode : public ASTNode {
	std::string value;

	StringLitNode(std::string value): value(value) {}
};

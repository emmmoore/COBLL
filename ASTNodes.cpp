///*
// * Nodes.cpp
// *
// *  Created on: Apr 22, 2022
// *      Author: elanor
// *  Based heavily on LLVM's "My First Language Frontend" Tutorial Ch. 2
// */
#include <string>
#include "Driver.h"

/**
 * Used to store information on the type of data stored in a node
 */
enum DataType {
	String,
	Number
};


/**
 * Parent Node Class
 */
class ASTNode {
	DataType type;

public:
	virtual ~ASTNode() {}
};

/**
 * Node for String literals
 */
class StringLitNode : public ASTNode {
	std::string value;

public:
	StringLitNode(std::string value): value(value), type(String) {}
};

/**
 * Node for numbers
 */
class NumberNode : public ASTNode {
	double value;

public:
	NumberNode(double value): value(value), type(Number) {}
};

/**
 *Node for variables
 */
class VariableNode : public ASTNode {
	std::string name;

public:
	VariableNode(const std::string &name): name(name) {}
};

/**
 * Node for calls to functions
 */
class FnCallNode : public ASTNode {
	std::string calling;
	std::vector<std::unique_ptr<ASTNode>> args;

public:
	FnCallNode(const std::string &calling, std::vector<std::unique_ptr<ASTNode>> args)
	: calling(calling), args(std::move(args)) {}
};

/**
 * Node for information regarding a function (its "header")
 */
class FnHeaderNode : ASTNode {
	std::string name;
	std::vector<std::string> args;

public:
	FnHeaderNode(const std::string &name, std::vector<std::string> args)
	: name(name), args(std::move(args)) {}

	const std::string &getName() const {
		return name;
	}
};

/**
 * Node for function declaration
 */
class FnNode : ASTNode {
	std::unique_ptr<FnHeaderNode> header;
	std::unique_ptr<ASTNode> body;

public:
	FnNode(std::unique_ptr<FnHeaderNode> header, std::unique_ptr<ASTNode> body)
	: header(std::move(header)), body(std::move(body)) {}
};

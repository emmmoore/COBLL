///
/// \file
/// This file contains declarations for the ASTNode class and all child classes of ASTNode.
/// @author Elanor Moore
///
///

#include <string>
#include "Driver.h"

///
/// Specifies data types a node can represent.
///
enum DataType {
	String,
	Number
};


///
/// A generic node for the Abstract Syntax Tree.
///
/// All other Abstract Syntax Tree node classes inherit from ASTNode.
///
class ASTNode {
	///
	/// Stores the data type of this node, if any.
	///
	DataType type;

public:
	virtual ~ASTNode() {}
};

///
/// An Abstract Syntax Tree node representing a String literal.
///
class StringLitNode : public ASTNode {
	std::string value;

public:
	///
	/// Creates a StringLitNode with a specified String value.
	/// @param value The String value of the node.
	///
	StringLitNode(std::string value): value(value), type(String) {}
};

///
/// An Abstract Syntax Tree node representing a numerical literal.
///
class NumberNode : public ASTNode {
	double value;

public:
	///
	/// Creates a NumberNode with a specified numerical value.
	/// @param value The numerical value of the node.
	///
	NumberNode(double value): value(value), type(Number) {}
};

///
/// An Abstract Syntax Tree node representing a variable.
///
class VariableNode : public ASTNode {
	std::string name;

public:
	///
	/// Creates a VariableNode with a specified name.
	/// @param name The name of the node.
	///
	VariableNode(const std::string &name): name(name) {}
};

///
/// An Abstract Syntax Tree node representing a call to a function.
///
class FnCallNode : public ASTNode {
	std::string calling;
	std::vector<std::unique_ptr<ASTNode>> args;

public:
	///
	/// Creates a FnCallNode with a specified callee and arguments.
	/// @param &calling The name of the callee.
	/// @param args A vector containing the arguments passed to the function.
	///
	FnCallNode(const std::string &calling, std::vector<std::unique_ptr<ASTNode>> args)
	: calling(calling), args(std::move(args)) {}
};

///
/// An Abstract Syntax Tree node representing the header of a function.
///
/// Contains information about the name and arguments of the function, not its functionality.
///
class FnHeaderNode : ASTNode {
	std::string name;
	std::vector<std::string> args;

public:
	///
	/// Creates a FnHeaderNode with a specified name and arguments.
	/// @param &name The name of the function.
	/// @param args The names of function arguments.
	///
	FnHeaderNode(const std::string &name, std::vector<std::string> args)
	: name(name), args(std::move(args)) {}

	///
	/// Returns the name of the function.
	const std::string &getName() const {
		return name;
	}
};

///
/// An Abstract Syntax Tree node representing a function.
///
/// Contains information about what the function does (its body), as well as its name and arguments (its header).
///
class FnNode : ASTNode {
	std::unique_ptr<FnHeaderNode> header;
	std::unique_ptr<ASTNode> body;

public:
	///
	/// Creates a FnNode with a specified header and body.
	/// @param header The FnHeaderNode representing the name and arguments of the function.
	/// @param body A portion of an Abstract Syntax Tree representing the functionality of the function.
	///
	FnNode(std::unique_ptr<FnHeaderNode> header, std::unique_ptr<ASTNode> body)
	: header(std::move(header)), body(std::move(body)) {}
};

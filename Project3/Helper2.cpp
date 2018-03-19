#include "Helper2.h"
#include "node.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstddef>

using namespace std;

void List(node *n) {
	if (n != NULL) {
		n->list = true;	
	
		if (n->left != NULL) {
			List(n->left);
		}
		while (n->right != NULL) {
			n = n->right;
			if (n->left != NULL) {
				List(n->left);
			}
		}
	} else {
		n->list = false;
	}
	return;
}


int nodeLength(node *n) {
	int length = 0;
	//while (n != NULL) {
	while(n->value != "NIL") {
		if (n->left != NULL) {
			length++;
		}
		n = n->right;
	}
	return length;
}

bool Atom(node *n) {	
	if (n->type == "Atom" && n != NULL) {
		return true;
	} 
	return false;	
}

bool isNull(node *n) {
	if (Atom(n) && n->value == "NIL") {
		return true;
	} 
	return false;
}

bool isInteger(node *n) {
	int value(0);
	stringstream ss;
	try {
		if(n->type == "Atom" && n->value != "NIL" && n->value != "T") {
			if (((n->value[0] >= '0') && (n->value[0] <= '9')) || n->value[0] == '-') {
				ss << n->value;
				ss >> value;
				return true;
			} else {
				return false;
			}
		}
	} catch (exception& e) {
 		return false;
	}
	return false;
}

node *car(node *n) {
	node *root = n;
	if (n != NULL) {
		if (n->type == "Atom") {
			cout << "ERROR: CAR function cannot be performed on atom" << endl;
			exit(10);
		} else {
			if (n->left != NULL) {
				root = n->left;
			} else {
				cout << "ERROR: unexpected error in CAR function" << endl;
				exit(10);
			}
		}
	} else {
		cout << "ERROR: undefined arguments in CAR function" << endl;
		exit(10);
	}
	return root;
}

node *cdr(node *n) {
	node *root = n;
	if (!isNull(n)) {
		if (n->type == "Atom") {
			cout << "ERROR: CDR function cannot be performed on atom" << endl;
			exit(10);
		} else {
			if (n->right != NULL) {
				root = n->right;
			} else {
				cout << "ERROR: unexpected error in CDR function" << endl;
				exit(10);
			}
		}
	} 
	return root;
}

node *cons(node *left, node *right) {
	node *root = new node;
	if (left == NULL && right == NULL) {
		cout << "ERROR: undefined arguments for CONS function" << endl;
		exit(10);
	} else if (left == NULL) {
		root = right;
	} else if (right == NULL) {
		root = left;
	} else {
		root->left = left;
		root->right = right;
	}
	return root;
}

node *PLUS(node *left, node *right) {
	node *root = new node;
	if(Atom(left) && Atom(right)) {
		if (isInteger(left) && isInteger(right)) {
			stringstream ss, sss;
			ss << left->value << ' ' << right->value;
			int lInt, rInt;
			ss >> lInt >> rInt;
			int result = lInt + rInt;
			root->type = "Atom";
			sss << result;
			root->value = sss.str();
		} else {
			cout << "ERROR: unexpected literal for PLUS function" << endl;
			exit(10);
		}
	} else {
		cout << "ERROR: undefined argument(s) for PLUS function" << endl;
		exit(10);
	}
	return root;
}

node *MINUS(node *left, node *right) {
	node *root = new node;
	if(Atom(left) && Atom(right)) {
		if (isInteger(left) && isInteger(right)) {
			stringstream ss, sss;
			ss << left->value << ' ' << right->value;
			int lInt, rInt;
			ss >> lInt >> rInt;
			int result = lInt - rInt;
			root->type = "Atom";
			sss << result;
			root->value = sss.str();
		} else {
			cout << "ERROR: unexpected literal for MINUS function" << endl;
			exit(10);
		}
	} else {
		cout << "ERROR: undefined argument(s) for MINUS function" << endl;
		exit(10);
	}
	return root;
}

node *TIMES(node *left, node *right) {
	node *root = new node;
	if(Atom(left) && Atom(right)) {
		if (isInteger(left) && isInteger(right)) {
			stringstream ss, sss;
			ss << left->value << ' ' << right->value;
			int lInt, rInt;
			ss >> lInt >> rInt;
			int result = lInt * rInt;
			root->type = "Atom";
			sss << result;
			root->value = sss.str();
		} else {
			cout << "ERROR: unexpected literal for TIMES function" << endl;
			exit(10);
		}
	} else {
		cout << "ERROR: undefined argument(s) for TIMES function" << endl;
		exit(10);
	}
	return root;
}

bool eq(node *left, node *right) {
	if(Atom(left) && Atom(right)) {
		if(isInteger(left) && isInteger(right)) {
			int lInt, rInt;
			stringstream ss;
			ss << left->value << ' ' << right->value;
			ss >> lInt >> rInt;
			if (lInt == rInt) {
				return true;
			} 
		} else if(left->value == right->value) {
			return true;
		}
	} else {
		cout << "ERROR: unexpected argument(s) in EQ function" << endl;
		exit(10);
	}
	return false;
}

bool LESS(node *left, node *right) {
	if(Atom(left) && Atom(right)) {
		if(isInteger(left) && isInteger(right)) {
			int lInt, rInt;
			stringstream ss;
			ss << left->value << ' ' << right->value;
			ss >> lInt >> rInt;
			if (lInt < rInt) {
				return true;
			} 
		} else  {
			cout << "ERROR: unexpected literal for LESS function" << endl;
			exit(10);
		}
	} else {
		cout << "ERROR: unexpected argument(s) in LESS function" << endl;
		exit(10);
	}

	return false;
}

bool GREATER(node *left, node *right) {
	if(Atom(left) && Atom(right)) {
		if(isInteger(left) && isInteger(right)) {
			int lInt, rInt;
			stringstream ss;
			ss << left->value << ' ' << right->value;
			ss >> lInt >> rInt;
			if (lInt > rInt) {
				return true;
			} 
		} else  {
			cout << "ERROR: unexpected literal for GREATER function" << endl;
			exit(10);
		}
	} else {
		cout << "ERROR: unexpected argument(s) in GREATER function" << endl;
		exit(10);
	}

	return false;
}

node *eval(node *root) {
	node *temp = NULL;
	if(Atom(root)) {
		if (root->value != "T" && !isNull(root) && !isInteger(root)) {
			cout << "ERROR: Undefined Atom found: " + root->value + ". T, NIL, or Numeric Atom Expected" << endl;
			exit(10);
		} else if(root->value == "T" || isNull(root) || isInteger(root)) {
			if(isNull(root)) {
				root->type = "Atom";
				root->value = "NIL";
			}
			temp = root;
		}
	} else {
		int length = nodeLength(cdr(root));
		if(car(root)->value == "") {
			cout << "ERROR: NULL value returned" << endl;
			exit(10);
		}
		if(car(root)->value == "QUOTE") {
			if(length != 1) {
				cout << "ERROR: more than 1 parameter found; only parameter expected for QUOTE" << endl;
				exit(10);
			}
			temp = car(cdr(root));
		} else if (car(root)->value == "COND") {
			try {
				temp = cond(cdr(root));
			} catch(exception& e) {
				cout << "ERROR: unkown error in COND function" << endl;
				exit(10);
			}
		} else {
			temp = apply(car(root), evalList(cdr(root)));
		}
	}
	return temp;
}

node *cond(node *root) {
	if(isNull(root)) {
		cout << "ERROR: NULL found in COND function" << endl;
		exit(10);
	} else if(eval(car(car(root)))->value != "NIL") {
		return eval(car(cdr(car(root))));
	} else {
		return cond(cdr(root));
	}
}

node *evalList(node *root) {
	if(isNull(root)) {
		node *temp = new node;
		temp->type = "Atom";
		temp->value = "NIL";
		return temp;
	} else {
		return cons(eval(car(root)), evalList(cdr(root)));
	}
}

bool command(node *root) {
	string functions[14] = {"ATOM", "INT", "NULL", "CAR", "CDR", "CONS", "PLUS", "MINUS", "TIMES", "LESS", "GREATER", "EQ", "QUOTE", "COND"};
	int i;
	for(i = 0; i < 14; i++) {
		if (functions[i] == root->value) {
			return true;
		} 
	}
	return false;
}

node *apply(node *function, node *parameters) {
	int length;
	length = nodeLength(parameters);
	node *temp = new node;
	if (command(function) == false) {
		cout << "ERROR: function undefined" << endl;
		exit(10);
	}
	if (function->value == "ATOM") {
		if (length != 1) {
			cout << "ERROR: more than 1 parameter found for ATOM function; Only 1 parameter expected" << endl;
			exit(10);
		}
		if (Atom(car(parameters))) {
			temp->type = "Atom";
			temp->value = "T";
		} else { 
			temp->type = "Atom";
			temp->value = "NIL";
		}
		return temp;
	} else if(function->value == "NULL") {
		if (length != 1) {
			cout << "ERROR: more than 1 parameter found for NULL function; Only 1 parameter expected" << endl;
			exit(10);
		}
		if (isNull(car(parameters))) {
			temp->type = "Atom";
			temp->value = "T";
		} else { 
			temp->type = "Atom";
			temp->value = "NIL";
		}
		return temp;
	} else if(function->value == "INT") {
		if (length != 1) {
			cout << "ERROR: more than 1 parameter found for INT function; Only 1 parameter expected" << endl;
			exit(10);
		}
		if (isInteger(car(parameters))) {
			temp->type = "Atom";
			temp->value = "T";
		} else { 
			temp->type = "Atom";
			temp->value = "NIL";
		}
		return temp;
	} else if(function->value == "PLUS") {
		if (length != 2) {
			cout << "ERROR: Only 2 parameters expected for PLUS function" << endl;
			exit(10);
		}
		return PLUS(car(parameters), car(cdr(parameters)));
	} else if(function->value == "MINUS") {
		if (length != 2) {
			cout << "ERROR: Only 2 parameters expected for MINUS function" << endl;
			exit(10);
		}
		return MINUS(car(parameters), car(cdr(parameters)));
	} else if(function->value == "TIMES") {
		if (length != 2) {
			cout << "ERROR: Only 2 parameters expected for TIMES function" << endl;
			exit(10);
		}
		return TIMES(car(parameters), car(cdr(parameters)));
	} else if(function->value == "EQ") {
		if (length != 2) {
			cout << "ERROR: Only 2 parameters expected for EQ function" << endl;
			exit(10);
		}
		if (eq(car(parameters), car(cdr(parameters)))) {
			temp->type = "Atom";
			temp->value = "T";
		} else { 
			temp->type = "Atom";
			temp->value = "NIL";
		}
		return temp;
	} else if(function->value == "LESS") {
		if (length != 2) {
			cout << "ERROR: Only 2 parameters expected for LESS function" << endl;
			exit(10);
		}
		if (LESS(car(parameters), car(cdr(parameters)))) {
			temp->type = "Atom";
			temp->value = "T";
		} else { 
			temp->type = "Atom";
			temp->value = "NIL";
		}
		return temp;
	} else if(function->value == "GREATER") {
		if (length != 2) {
			cout << "ERROR: Only 2 parameters expected for GREATER function" << endl;
			exit(10);
		}
		if (GREATER(car(parameters), car(cdr(parameters)))) {
			temp->type = "Atom";
			temp->value = "T";
		} else { 
			temp->type = "Atom";
			temp->value = "NIL";
		}
		return temp;
	} else if(function->value == "CAR") {
		if (length != 1) {
			cout << "ERROR: Only 1 parameter expected for CAR function" << endl;
			exit(10);
		}
		temp = car(car(parameters));
		temp->list = true;
		return temp;
	} else if (function->value == "CDR") {
		if (length != 1) {
			cout << "ERROR: Only 1 parameter expected for CDR function" << endl;
			exit(10);
		}
		temp = cdr(car(parameters));
		temp->list = true;
		return temp;
	} else if(function->value == "CONS") {
		if (length != 2) {
			cout << "ERROR: Only 2 parameters expected for CONS function" << endl;
			exit(10);
		}
		temp = cons(car(parameters), car(cdr(parameters)));
		temp->list = true;
		return temp;
	} else {
		return function;
	}
}

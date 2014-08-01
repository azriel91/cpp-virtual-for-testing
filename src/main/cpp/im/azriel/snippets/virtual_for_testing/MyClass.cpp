/*
 * MyClass.cpp
 *
 *  Created on: 31/07/2014
 *      Author: azriel
 */

#include "im/azriel/snippets/virtual_for_testing/MyClass.h"

namespace im {
namespace azriel {
namespace snippets {
namespace virtual_for_testing {

MyClass::MyClass(const Collaborator* const collaborator) : collaborator(collaborator) {
}

MyClass::~MyClass() {
}

const int MyClass::call() const {
	return this->collaborator->call();
}

} /* namespace virtual_for_testing */
} /* namespace snippets */
} /* namespace azriel */
} /* namespace im */

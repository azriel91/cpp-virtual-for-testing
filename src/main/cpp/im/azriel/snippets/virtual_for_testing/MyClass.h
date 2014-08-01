/*
 * MyClass.h
 *
 *  Created on: 31/07/2014
 *      Author: azriel
 */

#ifndef __IM_AZRIEL_SNIPPETS_VIRTUAL_FOR_TESTING__MYCLASS_H_
#define __IM_AZRIEL_SNIPPETS_VIRTUAL_FOR_TESTING__MYCLASS_H_

#include "im/azriel/snippets/virtual_for_testing/Collaborator.h"

namespace im {
namespace azriel {
namespace snippets {
namespace virtual_for_testing {

class MyClass {
private:
	const Collaborator* const collaborator;
public:
	MyClass(const Collaborator* const collaborator);
	virtual ~MyClass();

	/**
	 * Returns a number determined by the collaborator.
	 *
	 * @returns the number retrieved from the collaborator
	 */
	const int call() const;
};

} /* namespace virtual_for_testing */
} /* namespace snippets */
} /* namespace azriel */
} /* namespace im */

#endif /* __IM_AZRIEL_SNIPPETS_VIRTUAL_FOR_TESTING__MYCLASS_H_ */

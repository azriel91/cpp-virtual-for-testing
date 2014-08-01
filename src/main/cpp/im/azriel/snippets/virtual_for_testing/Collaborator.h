/*
 * Collaborator.h
 *
 *  Created on: 31/07/2014
 *      Author: azriel
 */

#ifndef __IM_AZRIEL_SNIPPETS_VIRTUAL_FOR_TESTING__COLLABORATOR_H_
#define __IM_AZRIEL_SNIPPETS_VIRTUAL_FOR_TESTING__COLLABORATOR_H_

namespace im {
namespace azriel {
namespace snippets {
namespace virtual_for_testing {

class Collaborator {
public:
	Collaborator();
	virtual ~Collaborator();

	/**
	 * Returns 1.
	 *
	 * @returns 1
	 */
	VIRTUAL_FOR_TESTING const int call() const;
};

} /* namespace virtual_for_testing */
} /* namespace snippets */
} /* namespace azriel */
} /* namespace im */

#endif /* __IM_AZRIEL_SNIPPETS_VIRTUAL_FOR_TESTING__COLLABORATOR_H_ */

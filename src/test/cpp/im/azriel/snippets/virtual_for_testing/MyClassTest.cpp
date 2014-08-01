#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "im/azriel/snippets/virtual_for_testing/Collaborator.h"
#include "im/azriel/snippets/virtual_for_testing/MyClass.h"

using namespace im::azriel::snippets::virtual_for_testing;

using testing::Return;

class MockCollaborator : public Collaborator {
public:
	MockCollaborator() {}
	virtual ~MockCollaborator() {}

	// VIRTUAL_FOR_TESTING is used, so this should result in a compilation error if it doesn't work
	MOCK_CONST_METHOD0(call, const int());
};

class MyClassTest : public testing::Test {
protected:
	MockCollaborator* collaborator;
	MyClass* myClass;

	virtual void SetUp() {
		this->collaborator = new MockCollaborator();
		this->myClass = new MyClass(collaborator);
	}

	virtual void TearDown() {
		delete this->myClass;
		delete this->collaborator;
	}
};

TEST_F(MyClassTest, callsCollaborator) {
	// the default implementation returns 1
	EXPECT_CALL(*this->collaborator, call()).Times(1).WillOnce(Return(1337));

	EXPECT_EQ(1337, this->myClass->call());
}

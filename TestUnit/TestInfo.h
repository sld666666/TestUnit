#pragma  once
#include <string>
#include "ITest.h"

class TestInfo
{
public:
	TestInfo(ITest* test, const std::wstring& infoName)
		: test_(test)
		, infoName_(infoName)
	{
	}

	TestInfo(){}
	~TestInfo(){}

	virtual void run() { 
		if (test_){
			test_->testBody();
		}
	}

private:
	std::wstring infoName_;
	ITest*		test_;
};


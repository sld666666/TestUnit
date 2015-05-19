#pragma  once
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "TestInfo.h"

typedef std::vector<TestInfo*>	TestInfos;

class TestCase
{
public:
	TestCase(){}
	~TestCase(){}

	void doRegister(TestInfo* testInfo)
	{
		testInfos_.push_back(testInfo);
	}

	void run()
	{
		std::for_each(testInfos_.begin(), testInfos_.end()
			, [](TestInfo* testInfo){
			testInfo->run();
		});
	}
private:
	TestInfos	testInfos_;
};

#pragma  once 
#include "TestCase.h"
#include "ITest.h"
#include <iostream>

class UnitTest
{
public:
	typedef std::unordered_map<std::wstring, TestCase*> TestCases;

	static UnitTest* getInstance(){
		static UnitTest instance;
		return &instance;
	}
	~UnitTest(){}

	void run()
	{
		std::for_each(testCases_.begin(), testCases_.end()
			, [](std::pair<std::wstring, TestCase*> iter){iter.second->run(); });
	}

	void doRegister(const std::wstring& testCaseName, TestInfo* testInfo)
	{
		auto found = std::find_if(testCases_.begin()
			, testCases_.end()
			, [testCaseName](std::pair<std::wstring, TestCase*> iter)->bool{
			return (testCaseName == iter.first);
		});

		if (found == testCases_.end())
		{
			TestCase* testCase = new TestCase();
			testCase->doRegister(testInfo);
			testCases_.insert(std::make_pair(testCaseName, testCase));
		}
		else
		{
			found->second->doRegister(testInfo);
		}
	}
private:
	UnitTest(){}
	TestCases	testCases_;

};

static TestInfo* makeAndRegisterTestInfo(const std::wstring& testCaseName
	                                  , const std::wstring& testInfoName
	                                 , ITest* test)
{
	TestInfo* testInfo = new TestInfo(test, testInfoName);
	UnitTest::getInstance()->doRegister(testCaseName, testInfo);
	return testInfo;
}

#define EXPECT_EQ(m, n) \
if (m != n) \
{ \
	std::cout  << "Failed" << std::endl; \
	std::cout  << "Expect:" << m << std::endl; \
	std::cout  << "Actual:" << n << std::endl; \
}


// TestUnit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "UnitTest.h"
#include "TestInfo.h"
#include "TestCase.h"
#include "ITest.h"


class ToTestor{
public:
	int add(int a, int b){
		return a + b;
	}
};

class Testor : public ITest{
public:
	virtual void testBody()
	{
		ToTestor testor;
		EXPECT_EQ(4, testor.add(1, 2));

	}
private:
	static TestInfo* testInfo_;
};
TestInfo* Testor::testInfo_ = makeAndRegisterTestInfo(L"Testor", L"add", new Testor());;

int _tmain(int argc, _TCHAR* argv[])
{
	
	UnitTest::getInstance()->run();

	return 0;
}


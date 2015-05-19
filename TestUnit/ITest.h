#pragma once

class ITest
{
public:
	ITest(){}
	virtual ~ITest(){};
public:
	virtual void testBody() = 0;
private:


};
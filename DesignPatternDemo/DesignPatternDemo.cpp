// DesignPatternDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "MyGameLogicExample.h"


//test
#include "MyDisplayExample.h"

int main()
{
	//std::shared_ptr<MyDisplayExample> display = std::shared_ptr<MyDisplayExample>(new MyDisplayExample());
	MyGameLogicExample l;
	l.run();

    return 0;
}


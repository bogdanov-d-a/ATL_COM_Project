// ATL_COM_Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../ATL_COM_Project/ATLCOMProject_i.h"

BOOST_AUTO_TEST_CASE(ExampleTest)
{
	BOOST_CHECK(2 + 2 == 4);
}

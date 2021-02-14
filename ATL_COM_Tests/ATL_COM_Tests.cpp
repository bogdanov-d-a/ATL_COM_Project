// ATL_COM_Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ComInitializer.h"
#include "CoCreateInstanceHelper.h"
#include "../ATL_COM_Project/ATLCOMProject_i.h"

namespace
{

auto CreateATLSimpleObject()
{
	return CoCreateInstanceHelper<IATLSimpleObject>(__uuidof(ATLSimpleObject));
}

}

BOOST_FIXTURE_TEST_SUITE(Com, CComInitializer)

BOOST_AUTO_TEST_CASE(TestSuccess)
{
	auto pComObject = CreateATLSimpleObject();

	{
		// Check positive argument
		DOUBLE result = 0.0;
		BOOST_CHECK(SUCCEEDED(pComObject->CalcSqrt(100.0, &result)));
		BOOST_CHECK_CLOSE(result, sqrt(100.0), 1e-10);
	}

	{
		// Check zero argument
		DOUBLE result = -1.0;
		BOOST_CHECK(SUCCEEDED(pComObject->CalcSqrt(0.0, &result)));
		BOOST_CHECK_EQUAL(result, 0.0);
	}
}

BOOST_AUTO_TEST_CASE(TestNegative)
{
	auto pComObject = CreateATLSimpleObject();

	DOUBLE result = -42.0;
	BOOST_CHECK(pComObject->CalcSqrt(-1.0, &result) == E_INVALIDARG);
	BOOST_CHECK_EQUAL(result, -42.0);
}

BOOST_AUTO_TEST_CASE(TestNullptr)
{
	auto pComObject = CreateATLSimpleObject();

	BOOST_CHECK(pComObject->CalcSqrt(42.0, nullptr) == E_POINTER);
}

BOOST_AUTO_TEST_SUITE_END()

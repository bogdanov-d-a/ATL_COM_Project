// ATL_COM_Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ComInitializer.h"
#include "../ATL_COM_Project/ATLCOMProject_i.h"

BOOST_FIXTURE_TEST_SUITE(Com, CComInitializer)

BOOST_AUTO_TEST_CASE(TestSuccess)
{
	CComPtr<IATLSimpleObject> pComObject;
	if (FAILED(pComObject.CoCreateInstance(__uuidof(ATLSimpleObject))))
	{
		throw std::runtime_error("Com Object creation failed");
	}

	// Check positive argument
	DOUBLE result;
	BOOST_CHECK(SUCCEEDED(pComObject->CalcSqrt(100.0, &result)));
	BOOST_CHECK_CLOSE(result, sqrt(100.0), 1e-10);

	// Check zero argument
	BOOST_CHECK(SUCCEEDED(pComObject->CalcSqrt(0.0, &result)));
	BOOST_CHECK_EQUAL(result, 0.0);
}

BOOST_AUTO_TEST_SUITE_END()

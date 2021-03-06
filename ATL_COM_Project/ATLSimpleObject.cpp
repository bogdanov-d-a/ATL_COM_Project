// ATLSimpleObject.cpp : Implementation of CATLSimpleObject

#include "pch.h"
#include "ATLSimpleObject.h"


// CATLSimpleObject



STDMETHODIMP CATLSimpleObject::CalcSqrt(DOUBLE arg, DOUBLE* pResult)
{
	if (!pResult)
	{
		return E_POINTER;
	}

	if (arg < 0)
	{
		return E_INVALIDARG;
	}

	*pResult = sqrt(arg);
	return S_OK;
}

// ATLSimpleObject.cpp : Implementation of CATLSimpleObject

#include "pch.h"
#include "ATLSimpleObject.h"


// CATLSimpleObject



STDMETHODIMP CATLSimpleObject::CalcSqrt(DOUBLE arg, DOUBLE* pResult)
{
	*pResult = sqrt(arg);
	return S_OK;
}

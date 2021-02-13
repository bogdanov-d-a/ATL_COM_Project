#pragma once

class CCoCreateInstanceError : public std::runtime_error
{
public:
	CCoCreateInstanceError()
		: runtime_error("Com Object creation failed")
	{
	}
};

template<typename T>
CComPtr<T> CoCreateInstanceHelper(REFCLSID rclsid)
{
	CComPtr<T> pComObject;
	if (FAILED(pComObject.CoCreateInstance(rclsid)))
	{
		throw CCoCreateInstanceError();
	}
	return pComObject;
}

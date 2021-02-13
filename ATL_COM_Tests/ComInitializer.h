#pragma once

class CComInitializationError : public std::runtime_error
{
public:
	CComInitializationError()
		: runtime_error("COM initialization failed")
	{
	}
};

class CComInitializer
{
	CComInitializer(CComInitializer const&);
	CComInitializer& operator=(CComInitializer const&);

public:
	explicit CComInitializer(DWORD dwCoInit = COINIT_APARTMENTTHREADED)
	{
		if (FAILED(::CoInitializeEx(NULL, dwCoInit)))
		{
			throw CComInitializationError();
		}
	}

	~CComInitializer()
	{
		::CoUninitialize();
	}
};

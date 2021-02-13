// dllmain.h : Declaration of module class.

class CATLCOMProjectModule : public ATL::CAtlDllModuleT< CATLCOMProjectModule >
{
public :
	DECLARE_LIBID(LIBID_ATLCOMProjectLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLCOMPROJECT, "{d989bf29-b6fb-4352-b84c-a41f23a0f1b9}")
};

extern class CATLCOMProjectModule _AtlModule;

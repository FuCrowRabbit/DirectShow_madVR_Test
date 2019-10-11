#include "stdafx.h"
#include "ChimeraException.h"

ChimeraException::ChimeraException(const HRESULT& hresult) : hresult_{ hresult }
{
}

char const* ChimeraException::what() const
{
   LPWSTR string = nullptr;
   FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
      FORMAT_MESSAGE_FROM_SYSTEM,
      nullptr,
      hresult_,
      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
      string,
      0,
      nullptr);
   if (string != nullptr)
   {
      USES_CONVERSION;
      return T2A(string);
   }
   return "";
}

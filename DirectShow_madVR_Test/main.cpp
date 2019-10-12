#include "stdafx.h"
#include "ChimeraVideoWindow.h"

CAppModule _Module;  // CComModule‚©‚çCAppModule‚É’u‚«Š·‚¦‚é
const wchar_t* g_video_path = L"D:\\sample.mp4";
const CLSID CLSID_madVR = { 0xe1a8b82a, 0x32ce, 0x4b0d, {0xbe, 0x0d, 0xaa, 0x68, 0xc7, 0x72, 0xe4, 0x23} };

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
   // WTL
   _Module.Init(nullptr, hInstance);

   CMessageLoop theLoop;
   _Module.AddMessageLoop(&theLoop);

   auto player = std::make_unique<ChimeraVideoWindow>();

   try
   {
      player->ready(g_video_path);

      player->Create(nullptr, CWindow::rcDefault, L"", WS_OVERLAPPEDWINDOW | WS_VISIBLE);

      player->ShowWindow(nCmdShow);

      player->play();
   }
   catch (std::exception& ex)
   {
      _RPTFN(_CRT_WARN, "deleting %Xh\n", ex.what());

      player->DestroyWindow();

      _Module.RemoveMessageLoop();

      _Module.Term();

      return -1;
   }

   const auto nRet = theLoop.Run();

   _Module.RemoveMessageLoop();

   _Module.Term();

   return nRet;
}

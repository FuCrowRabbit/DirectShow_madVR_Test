#include "stdafx.h"
#include "VideoWindow.h"

CAppModule _Module;  // CComModuleからCAppModuleに置き換える

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
   // WTL
   _Module.Init(nullptr, hInstance);

   CMessageLoop theLoop;
   _Module.AddMessageLoop(&theLoop);

   auto player = std::make_unique<VideoWindow>();

   player->Create(nullptr, CWindow::rcDefault, L"", WS_OVERLAPPEDWINDOW | WS_VISIBLE);

   ShowWindow(player->m_hWnd, nCmdShow);

   const auto nRet = theLoop.Run();

   _Module.RemoveMessageLoop();

   _Module.Term();

   return nRet;
}

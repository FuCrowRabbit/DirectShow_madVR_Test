#include "stdafx.h"
#include "VideoWindow.h"

VideoWindow::VideoWindow() : hwnd_(nullptr), hinstance_(GetModuleHandle(nullptr))
{
   CoInitialize(nullptr);
}

VideoWindow::~VideoWindow()
{
   CoUninitialize();
}

BOOL VideoWindow::PreTranslateMessage(MSG* pMsg)
{
   return FALSE;
}

BOOL VideoWindow::OnIdle()
{
   return FALSE;
}

void VideoWindow::OnFinalMessage(HWND)
{
}

void VideoWindow::onChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
}

void VideoWindow::onPaint(CDCHandle dc)
{
}

void VideoWindow::onSize(UINT nType, CSize size)
{
}

void VideoWindow::onLButtonDown(UINT nFlags, CPoint point)
{
}

void VideoWindow::onLButtonDblClk(UINT nFlags, CPoint point)
{
}

void VideoWindow::onDestroy()
{
}

int VideoWindow::onCreate(LPCREATESTRUCT lpCreateStruct)
{
   auto pLoop = _Module.GetMessageLoop();
   pLoop->AddMessageFilter(this);
   pLoop->AddIdleHandler(this);
   return 0;
}

void VideoWindow::onMouseMove(UINT nFlags, CPoint point)
{
}

void VideoWindow::fullScreen()
{
   // ウィンドウスタイル変更(メニューバーなし、最前面)
   SetWindowLongPtr(GWL_STYLE, WS_POPUP);
   SetWindowLongPtr(GWL_EXSTYLE, WS_EX_TOPMOST);
   // 最大化する
   ShowWindow(SW_MAXIMIZE);
}

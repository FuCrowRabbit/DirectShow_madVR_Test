#pragma once
#include "ChimeraPlayer.h"
#include <boost/core/noncopyable.hpp>

class ChimeraVideoWindow : public CWindowImpl<ChimeraVideoWindow>, public CMessageFilter, public CIdleHandler, public boost::noncopyable, public ChimeraPlayer
{
protected:
   auto setVideoWindow() const noexcept(false) -> void;

public:
   ChimeraVideoWindow();
   virtual ~ChimeraVideoWindow();
   ChimeraVideoWindow(const ChimeraVideoWindow&&) = delete;
   ChimeraVideoWindow& operator=(const ChimeraVideoWindow&&) = delete;

   BOOL PreTranslateMessage(MSG* pMsg) override;
   BOOL OnIdle() override;
   void OnFinalMessage(HWND) override;

   virtual void onChar(UINT nChar, UINT nRepCnt, UINT nFlags);
   virtual void onPaint(CDCHandle dc);
   virtual void onSize(UINT nType, CSize size);
   virtual void onLButtonDown(UINT nFlags, CPoint point);
   virtual void onLButtonDblClk(UINT nFlags, CPoint point);
   virtual void onDestroy();
   virtual int onCreate(LPCREATESTRUCT lpCreateStruct);
   virtual void onMouseMove(UINT nFlags, CPoint point);

   // メッセージマップ
   BEGIN_MSG_MAP_EX(ChimeraVideoWindow)
      MSG_WM_CHAR(onChar)
      MSG_WM_PAINT(onPaint)
      MSG_WM_SIZE(onSize)
      MSG_WM_LBUTTONDOWN(onLButtonDown)
      MSG_WM_LBUTTONDBLCLK(onLButtonDblClk)
      MSG_WM_DESTROY(onDestroy)
      MSG_WM_CREATE(onCreate)
      MSG_WM_MOUSEMOVE(onMouseMove)
      END_MSG_MAP()

   virtual void fullScreen();
};

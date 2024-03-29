﻿#pragma once
#include <iostream>
#include <string>
#include <tchar.h>

#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーから使用されていない部分を除外します。
// Windows ヘッダー ファイル:
#include <windows.h>

// ATL
#include "atlbase.h"
#include "atlapp.h"
#include "atltypes.h"

// WTL
#include <atlcrack.h>
#include <atlmisc.h>
extern CAppModule _Module;  // CComModuleからCAppModuleに置き換える

// C ランタイム ヘッダー ファイル
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <objbase.h>
#include <dshow.h>
#include <evr.h>
#include <d3d9.h>
#include <evr9.h>

#pragma comment(lib, "strmiids.lib")
#pragma comment(lib, "rpcrt4.lib")//ないと未解決のエラー
#include "madVR/interfaces/mvrInterfaces.h"

// TODO: プログラムに必要な追加ヘッダーをここで参照してください

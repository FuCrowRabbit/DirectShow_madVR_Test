#include "stdafx.h"
#include "ChimeraPlayer.h"
#include "ChimeraException.h"

ChimeraPlayer::ChimeraPlayer(): now_playing_path_{nullptr}
{
}

void ChimeraPlayer::check(const HRESULT hr) noexcept(false)
{
   if (SUCCEEDED(hr)) throw ChimeraException(hr);
}

void ChimeraPlayer::play() noexcept(false)
{
   // フィルタグラフの作成
   check(CoCreateInstance(CLSID_FilterGraph, nullptr, CLSCTX_INPROC_SERVER,IID_PPV_ARGS(&this->graph_builder_)));
   check(this->graph_builder_->QueryInterface(IID_PPV_ARGS(&this->media_control_)));
   check(this->graph_builder_->QueryInterface(IID_IBasicVideo2, reinterpret_cast<void**>(&this->base_filter_)));
   check(this->graph_builder_->QueryInterface(IID_IBasicVideo2, reinterpret_cast<void**>(&this->video_window_)));
   check(CoCreateInstance(CLSID_CaptureGraphBuilder2, nullptr, CLSCTX_INPROC_SERVER, IID_ICaptureGraphBuilder2, reinterpret_cast<void**>(&this->capture_graph_builder2_)));
   check(this->capture_graph_builder2_->SetFiltergraph(this->graph_builder_));
   check(CoCreateInstance(CLSID_madVR, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&this->base_filter_)));
   check(this->graph_builder_->AddFilter(this->base_filter_, L"madVR"));
   check(this->base_filter_->QueryInterface(IID_PPV_ARGS(&this->mad_vr_subclass_replacement_)));
   CComQIPtr<IMFGetService> service = nullptr;
   check(this->base_filter_->QueryInterface(IID_PPV_ARGS(&service)));
   CComQIPtr<IDirect3DDeviceManager9> manager = nullptr;
   check(service->GetService(MR_VIDEO_ACCELERATION_SERVICE, IID_PPV_ARGS(&manager)));
   CComQIPtr<IDirectXVideoMemoryConfiguration> memory = nullptr;
   check(service->GetService(MR_VIDEO_ACCELERATION_SERVICE, IID_PPV_ARGS(&memory)));
   auto handle = INVALID_HANDLE_VALUE;
   check(manager->OpenDeviceHandle(&handle));

   CComQIPtr<IBaseFilter> source;
   this->graph_builder_->AddSourceFilter(this->now_playing_path_, this->now_playing_path_, &source);
   this->capture_graph_builder2_->RenderStream(nullptr, nullptr, source, nullptr, nullptr);
}

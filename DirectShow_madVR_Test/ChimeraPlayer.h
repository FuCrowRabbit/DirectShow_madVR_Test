#pragma once
#include "stdafx.h"

class ChimeraPlayer
{
public:
   ChimeraPlayer();
   virtual ~ChimeraPlayer() = default;
   static void check(HRESULT hr) noexcept(false);
   ChimeraPlayer(const ChimeraPlayer&) = delete;
   ChimeraPlayer(const ChimeraPlayer&&) = delete;
   ChimeraPlayer& operator=(const ChimeraPlayer&) = delete;
   ChimeraPlayer& operator=(const ChimeraPlayer&&) = delete;
   auto play() noexcept(false) -> void;
   auto play(const wchar_t* path) -> void;
   auto setVideoPath(const wchar_t*) noexcept -> void;

protected:
   const wchar_t* now_playing_path_;
   CComQIPtr<IVideoWindow> video_window_;
   CComQIPtr<IBaseFilter> base_filter_;
   CComQIPtr<IBasicVideo2> basic_video2_;
   CComQIPtr<IGraphBuilder> graph_builder_;
   CComQIPtr<IMediaControl> media_control_;
   CComQIPtr<ICaptureGraphBuilder2> capture_graph_builder2_;
   CComQIPtr<IMFVideoMixerBitmap> mf_imf_video_mixer_bitmap_;
   CComQIPtr<IMFVideoProcessor> mfv_imf_video_processor_;
   CComQIPtr<IMadVRSubclassReplacement> mad_vr_subclass_replacement_;

   virtual void setVideoWindow(HWND& hwnd) const noexcept(false);

private:
   auto readyVideo() noexcept(false) -> void;
};

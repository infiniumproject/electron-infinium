/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "extensions/webrtc/event_wrapper.h"

#if defined(_WIN32)
#include <windows.h>
#include "extensions/webrtc/event_win.h"
#elif defined(WEBRTC_MAC) && !defined(WEBRTC_IOS)
#include <ApplicationServices/ApplicationServices.h>
#include <pthread.h>
#include "extensions/webrtc/event_posix.h"
#else
#include <pthread.h>
#include "extensions/webrtc/event_posix.h"
#endif

namespace webrtcports {
EventWrapper* EventWrapper::Create() {
#if defined(_WIN32)
  return new EventWindows();
#else
  return EventPosix::Create();
#endif
}
}  // namespace webrtc

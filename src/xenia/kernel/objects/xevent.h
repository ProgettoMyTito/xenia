/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_KERNEL_XBOXKRNL_XEVENT_H_
#define XENIA_KERNEL_XBOXKRNL_XEVENT_H_

#include "xenia/kernel/xobject.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {

class XEvent : public XObject {
 public:
  XEvent(KernelState* kernel_state);
  virtual ~XEvent();

  void Initialize(bool manual_reset, bool initial_state);
  void InitializeNative(void* native_ptr, DISPATCH_HEADER& header);

  int32_t Set(uint32_t priority_increment, bool wait);
  int32_t Pulse(uint32_t priority_increment, bool wait);
  int32_t Reset();
  void Clear();

  virtual void* GetWaitHandle() { return native_handle_; }

 private:
  HANDLE native_handle_;
};

}  // namespace kernel
}  // namespace xe

#endif  // XENIA_KERNEL_XBOXKRNL_XEVENT_H_

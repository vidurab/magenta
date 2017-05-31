// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <ddk/binding.h>

mx_status_t read_driver_info(int fd, void *cookie,
                             void (*func)(magenta_note_driver_t* note,
                                          mx_bind_inst_t* binding,
                                          void *cookie));

// Lookup the human readable name of a bind program parameter, or return NULL if
// the name is not known.  Used by debug code to do things like dump the
// published parameters of a device, or dump the bind program of a driver.
const char* lookup_bind_param_name(uint32_t param_num);

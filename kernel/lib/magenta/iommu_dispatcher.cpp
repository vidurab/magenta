// Copyright 2017 The Fuchsia Authors
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#include <magenta/iommu_dispatcher.h>

#include <dev/iommu.h>
#include <magenta/rights.h>
#include <mxalloc/new.h>

#include <assert.h>
#include <err.h>
#include <inttypes.h>
#include <trace.h>

#define LOCAL_TRACE 0

mx_status_t IommuDispatcher::Create(uint32_t type, const void* desc, uint32_t desc_len,
                                    mxtl::RefPtr<Dispatcher>* dispatcher, mx_rights_t* rights) {

    mxtl::RefPtr<Iommu> iommu;
    switch (type) {
        default:
            return ERR_NOT_SUPPORTED;
    }

    AllocChecker ac;
    auto disp = new (&ac) IommuDispatcher(mxtl::move(iommu));
    if (!ac.check())
        return MX_ERR_NO_MEMORY;

    *rights = MX_DEFAULT_IOMMU_RIGHTS;
    *dispatcher = mxtl::AdoptRef<Dispatcher>(disp);
    return MX_OK;
}

IommuDispatcher::IommuDispatcher(mxtl::RefPtr<Iommu> iommu)
    : iommu_(iommu) {}

IommuDispatcher::~IommuDispatcher() {
}

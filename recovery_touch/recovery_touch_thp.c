/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * The NT36532 is a host-processed touch IC: the driver only streams raw
 * frames and Xiaomi's THP daemon turns them into input events. Outside of
 * touchfeature-service, which recovery doesn't have, nothing runs it, so
 * run it here.
 */

#include <android/log.h>
#include <dlfcn.h>

#define LOG_TAG "recovery_touch_thp"
#define LOG(prio, ...) __android_log_print(ANDROID_LOG_##prio, LOG_TAG, __VA_ARGS__)

int main(void) {
    void* handle = dlopen("libtouchreport.so", RTLD_NOW);
    if (!handle) {
        LOG(ERROR, "dlopen failed: %s", dlerror());
        return 1;
    }

    int (*thp_daemon_main)(void) = (int (*)(void))dlsym(handle, "thp_daemon_main");
    if (!thp_daemon_main) {
        LOG(ERROR, "thp_daemon_main not found: %s", dlerror());
        return 1;
    }

    int ret = thp_daemon_main();
    LOG(ERROR, "thp_daemon_main returned %d", ret);
    return ret ? ret : 1;
}

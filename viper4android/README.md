# ViPER4Android FX

Prebuilt ViPER4Android FX Redesign 8.0 and `libv4a_re` 0.6.3 from
[Evolution-X-Devices/packages_apps_ViPER4AndroidFX](https://github.com/Evolution-X-Devices/packages_apps_ViPER4AndroidFX)
(branch `bka`, commit `ba9b1b0`), built by WSTxda
([ViPERFX_RE](https://github.com/WSTxda/ViPERFX_RE)).

The Evo-X package depends on `libviperaidl` for the AIDL effects HAL. This
device uses the HIDL effects HAL, so the library is registered through
`configs/audio/audio_effects.xml` instead and the dependency is dropped.

To update, copy `system/app/ViPER4AndroidFX/ViPER4AndroidFX.apk` and
`vendor/lib{,64}/soundfx/libv4a_re.so` from the upstream repository.

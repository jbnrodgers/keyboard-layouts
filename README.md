# keyboard-layouts

## Description
Custom keyboard layouts. Each build may require unique firmware packages, such as QMK or ZMK. See references.

## Layouts

### Helix
* Built with an Atmega32u4 Micro Pro.
* Requires QMK for firmware flashing.
1. Copy the helix folder along with its contents to the appropriate qmk_firmware directory.
    ```bash
    cp -r ./helix ~/Repos/qmk_firmware/keyboards/helix/rev3_5rows/keymaps/
    ```
2. Run the following command to flash the layout.
    ```bash
    qmk flash -bl avrdude -kb helix/rev3_5rows -km helix
    ```

## References
* [GitHub: MakotoKurauchi/helix](https://github.com/MakotoKurauchi/helix)
* [GitHub: qmk/qmk_firmware](https://github.com/qmk/qmk_firmware/)
* [QMK Configurator](https://config.qmk.fm/)
* [QMK Docs](https://docs.qmk.fm/#/newbs_getting_started)

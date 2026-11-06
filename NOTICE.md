# Credits and component licensing

Port and presentation: **Youss Riaal**.

Forgotten Warrior is the original game. The supplied J2ME edition identifies wait4u and Amusingware. Original game artwork, maps, audio and game logic, including the converted `src/game.hpp`, retain their original ownership. This project does not claim ownership of that content or grant a new license for it.

From version 1.2.0, neither this repository nor its release archives contain the original game's artwork, maps or audio. Users load them from their own copy of the original game.

Original PS5 port contributions are licensed under GPL-3.0-only, within the scope defined in [COPYRIGHT.md](COPYRIGHT.md). This grant does not relicense the original game or third-party components. Preserve their respective licenses and notices.

- Native application tooling and clean-room companion runtime: BlackBearReloaded native-app boilerplate tooling vendored from [darkxex/ProsperoStore](https://github.com/darkxex/ProsperoStore/tree/22d5a44a053b4dad4f3a5867fe39d262a80a1b8c/tooling), GPL-3.0. Source, runtime manifests and license are under `vendor/ps5-native-tool`. The bundled `runtime/libc.prx` is the generated clean-room companion runtime.
- PS5 compatibility layer: [kvaps/syobon-action-ps5](https://github.com/kvaps/syobon-action-ps5), GPL-3.0; see `vendor/ps5_compat.cpp` and the GPL text in `vendor/ps5-native-tool/LICENSE`.
- SDL2: zlib license, `vendor/SDL2-LICENSE.txt`. PS5 backend: [ps5-payload-dev/SDL](https://github.com/ps5-payload-dev/SDL). `vendor/sdl-ps5video/SDL_ps5video.c` is a modified copy of its PS5 video driver (commit 160954c), changed for 4K output and a smaller double buffer; it is marked as modified in the file.
- stb headers: license text at the end of each included header.
- TinySoundFont / TinyMidiLoader: MIT license, `src/TinySoundFont-LICENSE` and header notices. Soundfont data (`assets/soundfont.sf2`) is `florestan-subset.sf2` from the TinySoundFont examples, a subset of Nando Florestan's public-domain soundfonts; no separate ownership is claimed.
- Cinzel font: SIL Open Font License, `vendor/cinzel/OFL.txt`.
- Build dependencies include the [PS5 Payload SDK](https://github.com/ps5-payload-dev/sdk), pacbrew libraries, LLVM/MinGW and zlib; their respective licenses apply.

The remaster credit identifies the port and presentation work. It does not imply an official release or endorsement by the original developers or Sony.

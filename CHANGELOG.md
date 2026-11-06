# Version 1.3.0

- 4K (3840 × 2160) output through a modified SDL PS5 video driver.
- Optional ambient side panels from the scenery, with blur and brightness settings; the central gameplay pixels are unchanged.
- Options menu: sound, vibration, game speed, side panels, blur and brightness.
- Jumping: short landing glide in the jump direction and a 120 ms jump buffer.
- Vibration feedback on hits and damage, with lighter rumble.
- New cover icon.
- Still ships no original game files; the game reads them from the user's own copy.
- `build-title.py` also runs on Linux and builds the modified SDL video driver.

# Version 1.2.0

- The release no longer contains any original game files (artwork, maps, audio).
- On first launch the game extracts the files it needs from the user's own `.jar` placed in `/data/ForgottenWarrior/`, or reads them from `/data/ForgottenWarrior/data/`.
- A setup screen explains what to add when files are missing; press Cross to check again.
- The bundled soundfont (TinySoundFont example, not game content) stays in the app folder.

# Version 1.1.2

- Packaging update for the ProsperoStore catalog; the game executable and assets are unchanged from 1.1.
- The release ZIP now contains only the `FWRG00001` folder; LICENSE, COPYRIGHT.md, NOTICE.md and README.txt are inside it.
- `contentVersion` raised to 01.001.002 so consoles detect the update.
- `sce_sys/param.json` is now kept in the repository and read by `build-title.py`.
- One installable file per release; the source is available from GitHub's automatic source archives.

# Version 1.1.1

- Packaging and documentation update; the game executable and assets are unchanged from 1.1.
- Release archives now include LICENSE (GPL-3.0), COPYRIGHT.md and NOTICE.md.
- Fixed broken characters in the README.

# Version 1.1

- PS5 native game-folder release.
- Circle uses an HP potion in gameplay and returns in menus; R2 is unassigned.
- Square attacks, Cross jumps, Options opens options, and Touchpad pauses.
- Corrected movement during jumping and restored the approved game timing.
- 1080p output with original aspect ratio and enhanced pixel scaling.
- Compact Youss Riaal credit avoids overlapping menu buttons.
- Clean Quit and relaunch; original sound effects without added looping music.


# Copyright and license scope

PS5 port modifications and presentation: **Youss Riaal**, 2026.

The original contributions to this PS5 port are offered under the GNU General Public License, version 3 only (`GPL-3.0-only`), to the extent the contributor holds the relevant rights. The complete license text is in [LICENSE](LICENSE).

## Covered port code

This grant covers the original PS5 integration and enhancements in:

- `src/main.cpp`: application integration, controls, timing and held movement.
- `src/platform.hpp`: platform adaptation and rendering support.
- `src/controller_help.hpp`: controller glyphs and help presentation.
- `src/pixel_scaler.hpp`: pixel scaling implementation.
- `src/credit_design.hpp`: credit presentation code.
- `native_shims.cpp` and `build-title.py`: original integration and build contributions.

The grant applies to original contributions in these files, not any pre-existing material incorporated into them. Existing copyright notices and applicable upstream license terms remain in force.

## Attribution and redistribution

Keep existing copyright, attribution and license notices when redistributing covered code. Mark modified versions with prominent notices describing that they were changed and the relevant date. When distributing a covered executable, comply with GPLv3's corresponding-source requirements. Recipients retain the rights GPLv3 grants, including modification, redistribution and commercial use. The license does not require forks to keep the same project name or branding.

Suggested attribution: **PS5 port and enhancements by Youss Riaal.** Credit the original game developers and upstream component authors as described in [NOTICE.md](NOTICE.md). This suggested wording is not an additional license restriction.

## Material outside this grant

- The original Forgotten Warrior game, its artwork, maps, audio and game logic, including the converted `src/game.hpp`, are not relicensed by this notice. No permission over those original materials is granted here.
- `vendor/`, third-party headers, font data (including `src/credit_font.hpp`), and other upstream material remain under their own licenses. See [NOTICE.md](NOTICE.md).
- Generated cover art and other non-code artwork are not licensed by this code grant.

The presence of a GPL license at the repository root does not mean every file or the complete bundled game is available under GPL. The source code headers and this scope document identify the grant. For legal details, the license text governs the material to which it applies.

This notice was added after the v1.1 release. The v1.1 release archives and tag have not been rewritten; release v1.1.1 and later include this notice and the LICENSE file.

CHANGELOG.md

# Changelog

All notable changes to this project are documented in this file.

This project is currently in early development for the 42 Berlin Rank 1
`push_swap` project.

---

## [2026-06-05]

LEXXY:

### Added
- `merge_sort` for `--complex`
  - providing the two files `sort_complex.c` and `sort_complex_base.c`
- normietted `sort_complex.c` and `sort_complex_base.c`
- `t_stack_track` in `stack_track.h` for `--complex`
- `sort_complex_base.c` contains now:
  - void `sort_pairs()`
  - void `split_stack()`
  - `t_stack_track` `*init_stack_track()`
- `sort_complex.c` contains now:
  - void `merge_sort()`
  - void `merge_level()`
  - void `merge()`
  - void `merge_to_a()`
  - void `merge_to_b()`

### Changed
- prototype `func0()` in `sort_medium.c` --> `sort_medium()`
- adapted to your changes in `sort_simple_0.c`
- general adaptions in `sort_complex*.c` to your changes 

RAVEN:

### Added
- `sort_bucket` for `--medium`
- Cleanup functions for the interface and stacks

### Changed
- `op_tracker` is now a part of `interface`
- merged `interface.a` and `interface.b` into an array `interface.stacks[2]`
- Changed the corresponding interface functions and exec
- exec calls `ft_putendl` instead of `ft_printf` to print to `STDOUT`
- Removed redundancies
- Added `interface.funcs` initialization to `init`
- `interface.stats` (i.e. `op_tracker`) is initialized to `NULL` and may be changed when `--bench` is raised
- `array_handling.c` has been renamed to `cleanup.c`, the string array cleanup was removed, interface and stacks cleanup functions added.
- `t_op_tracker` has been renamed to `t_stats`
- exec now counts `total_ops` as well and only changes stats if they aren't `NULL`
- Added comments
- Deleted `get_max` since it's unused
### Notes
Some changes I made the last few days before are not tracked in here, sry >.<

## [2026-06-??]

### Added
- CLI flag handling via `ui_cli.c` / `ui_cli.h`.
- Validation for command-line flags.
- Array handling utilities for freeing arrays and setting pointers to `NULL`.
- Basic stack scanning functions.
- Disorder metric for estimating stack order.
- Operation tracker structure and related output utilities.
- Execution wrappers for stack operations.
- Simple sorting algorithm prototype.
- Output files for benchmark-related output.

### Changed
- Moved validation logic into `validation.c`.
- Split output-related headers:
  - `op_tracker.h`
  - `output.h`
- Updated `exec_*` functions to print executed operations to `STDOUT`.
- Updated simple sort behavior to sort in ascending order.
- Improved interface initialization and malloc protection.

### Notes
- Current sorting logic is intentionally simple and mainly serves as a
  functional prototype.
- Benchmark/output behavior is being prepared for later comparison and
  optimization.

---

## [2026-05-29]

### Added
- Implemented array handling for freeing arrays and setting pointers to `NULL`.
- Added `ui_cli.*` to read and process CLI flags.
- Added flag validation.

### Changed
- Moved validation function into `validation.c`.

Relevant commits:
- `36813ac` - implemented array handling free and NULL, used in ui\_cli; implemented ui\_cli.* to read flags
- `e6f7f22` - moved validation function to validation.c, added flag validation

---

## [2026-05-28]

### Added
- Implemented output files needed for benchmark output.
- Implemented `exec_*_n` functions to call an interface operation `n` times.
- Added operation tracker updates for repeated executions.
- Implemented a first simple sorting algorithm.
- Added `lxy_putzu_fd` utility for printing `size_t`.

### Changed
- Updated `exec_*` functions to print execution to `STDOUT`.
- Changed simple sort behavior to sort in ascending order.
- Split `op_tracker.h` into:
  - `op_tracker.h`
  - `output.h`

Relevant commits:
- `8d7ea62` - updated exec output, simple sort ascending, split headers, added lxy_putzu_fd
- `bbf3505` - implemented simple sorting algorithm
- `f18a9ed` - implemented exec_*_n functions
- `9079284` - implemented output files needed for benchmark output

---

## [2026-05-27]

### Added
- Implemented stack operations for the interface.
- Added additional stack scanning functions.
- Implemented disorder metric.
- Added `op_tracker.h`.

### Changed
- Rewrote disorder metric.
- Improved malloc protections.
- Finished initial interface initialization.

Relevant commits:
- `c3b592d` - stack operations for interface
- `405816a` - malloc protections, rewrote disorder metric, finished interface init
- `677e941` - implemented scan functions, disorder metric, op tracker
- `ce7fb90` - implemented stack scanning functions

---

## [2026-05-26]

### Added
- Added basic stack functions.
- Started interface initialization.
- Created initial skeleton for a frame datatype.
- Started writing initialization logic.

### Changed
- Solved part of the initial TODOs in `interface.c`.

Relevant commits:
- `cadacc4` - solved TODO in interface.c
- `2809ac2` - added stack functions, started interface init
- `81a9912` - created skeleton for frame datatype and started init

---

## Current File Overview

### Core / Interface
- `interface.c`
- `interface_flags.c`
- `interface_push.c`
- `interface_rotate.c`
- `interface_rrotate.c`
- `interface_swap.c`

### Stack Operations
- `stack.c`
- `stack.h`
- `exec_push.c`
- `exec_rotate.c`
- `exec_rrotate.c`
- `exec_swap.c`

### Scanning / Metrics
- `scan_stack_0.c`
- `scan_stack_1.c`
- `disorder_metric.c`

### Sorting
- `sort_simple_0.c`

### CLI / Validation
- `ui_cli.c`
- `ui_cli.h`
- `validation.c`

### Output / Tracking
- `output.h`
- `op_tracker.h`
- `output_layer_0.c`
- `output_layer_1.c`
- `utility_output.c`

### General
- `push_swap.h`
- `array_handling.c`
- `skeleton_def.c`

---

## Development Notes

### Current Focus
- Build a stable internal stack interface.
- Track and print operations correctly.
- Validate input and optional flags safely.
- Create simple sorting prototypes before optimizing.

### Next Steps
- Improve input parsing for actual `push_swap` arguments.
- Add duplicate detection.
- Add integer range validation.
- Add sorted-state detection.
- Build specialized sorting for small stack sizes:
  - 2 numbers
  - 3 numbers
  - 4–5 numbers
- Start designing a real cost-based sorting strategy.
- Add test cases and benchmark cases.


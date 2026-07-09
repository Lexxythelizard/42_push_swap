# Development Notes

## Current focus

- Build stable input validation.
- Finish CLI flag handling.
- Separate sorting strategies cleanly.
- Keep stack primitives independent from sorting logic.

---

## Status and questions

### DOCUMENTATION

- CHANGELOG.md and ARCHITACTURE.md have been added
- reason: since You have been sick for the last two days and I will be short on time on Mon & Tue I decided to document my work :)

### Error handling

- Should `raise_x_error()` only print `Error\n`, or handle specific debug output in bench mode?

### Flags

- Should flags be allowed before and after numbers?
- Should flags overwrite each other, or should it raise an error?
- Should flags be stripped before parsing the integer list?
- Should the order of flags and numbers be restricted or arbitary?
- Should a flag interuped the parsed numbers or raise an error?

*I thought of an arbitary oder of argumnents: last parsed flag overwrites the others 
but I'm maybe wrong in my assumption*

### Sorting

- `sort_simple()`
  - runs with O($n^2$)
  - just uses ra, rra, pa, pb
  - got inspired by selection/insertion sort
  - in worst case 2750 operations (100 elements) see comments in files *simple_0.c*
- `sort_medium()`
  - considered two use a binary radix sort
  - just uses ra, rra, pa, pb
  - haven't scetched it yet, need to think it through
  - estimating worst case 1664 operations (100 elements)
  - maybe even consider merge sort...
- `sort_complex()`
  - not a clue yet ...

---

## NEXT

- Add test files for every layer.
- sorry didn't make it the last days...

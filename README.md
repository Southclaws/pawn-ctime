# pawn-ctime

[![sampctl](https://shields.southcla.ws/badge/sampctl-pawn--ctime-2f2f2f.svg?style=for-the-badge)](https://github.com/Southclaws/pawn-ctime)

The original CTime plugin by RyDeR`, with some major stability and quality
improvements.

> This plugin allows you to use the functions of the C++ library called "ctime"
> (time.h) in Pawn. All functions, macros and "structures" are included and are
> as easy as to use. See more information and examples below.

-_RyDeR`_

The old version had quite a few bad practices, memory leaks and just general not
very nice code. This updated version is fully unit tested, cross-platform
development ready with CMake and Docker, packaged as a Pawn Package and
documented.

Also the questionably confusing `tm<var>` macro is gone, just allocate the
standard Pawn way: `new var[e_tm];`

The badly named `time()` function is gone, you can now name local variables
`time` without errors. Just use the standard `gettime()` function.

## Installation

Simply install to your project:

```bash
sampctl package install Southclaws/pawn-ctime
```

Include in your code and begin using the library:

```pawn
#include <ctime>
```

## Usage

### `tm` Struct

```pawn
enum e_tm {
    tm_sec,
    tm_min,
    tm_hour,
    tm_mday,
    tm_mon,
    tm_year,
    tm_wday,
    tm_yday,
    tm_isdst
};
```

This mirrors the ctime `tm` struct in Pawn land. Simply allocate an array with
this enumerator as the indices:

```pawn
new time[e_tm];
```

### Timestamps

Get a current timestamp with the Pawn standard library function `gettime()`:

```pawn
new Time:timestamp = Time:gettime();
```

(notice the tag `Time:` is used to preseve compatibility with the old version,
this will likely be removed in future.)

### Timestamp to `tm` struct

Then pass that `timestamp` to `localtime` to extract values into a `e_tm`:

```pawn
new time[e_tm];
localtime(timestamp, time);
```

You can now access granular attributes such as seconds, days, months, etc:

```pawn
printf("second: %d", time[tm_sec]);
printf("day:    %d", time[tm_mday]);
printf("month:  %d", time[tm_mon]);
```

### Formatting Strings With `strftime`

You can then pass a `tm` struct to `strftime` to create custom strings:

```pawn
new buf[128];
strftime(buf, sizeof(buf), "%a", tm); // buf: Mon
strftime(buf, sizeof(buf), "%A", tm); // buf: Monday
strftime(buf, sizeof(buf), "%b", tm); // buf: Apr
strftime(buf, sizeof(buf), "%B", tm); // buf: April
```

As you can see, `%a`, `%A`, etc are special specifiers for outputting
datetime-specific strings. See a full list in the
[documentation](http://en.cppreference.com/w/cpp/chrono/c/strftime).

## Testing

Run unit tests with:

### Windows

```powershell
make test-windows
```

### Linux

```bash
make test-linux
```

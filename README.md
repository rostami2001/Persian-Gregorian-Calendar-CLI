# Persian-Gregorian-Calendar-CLI

A simple command-line calendar application with Persian (Solar Hijri) and Gregorian calendar support, developed as a university project in January 2022.

## Features

- **Dual Calendar Support**:
  - Persian (Jalali/Shamsi) calendar
  - Gregorian calendar
- **Date Navigation**:
  - Next day (`n` key)
  - Previous day (`p` key)
- **Note System**:
  - Add/edit daily notes (`s` key)
  - Notes persist in `note.txt`
- **System Integration**:
  - Auto-detects current system date
  - Proper month/year transitions
- **Terminal UI**:
  - Clean console display
  - Position-based rendering

## Technical Details

- **Object-Oriented Design**:
  - Separate classes for each calendar type
  - Encapsulated date logic
- **Date Conversion**:
  - Built-in Gregorian-to-Persian conversion
  - Handles leap years
- **Platform-Specific**:
  - Windows console functions (`gotoxy()`)
  - Keyboard input handling

## Limitations (Student Project Context)

⚠️ **Note**: This was one of my early university projects (Jan 2022). Code reflects beginner-level C++ skills.

- Basic terminal interface (no colors/advanced UI)
- Minimal error handling
- No GUI version (pure console)
- Persian month names use shorthand abbreviations

## How to Compile/Run

1. Compile with any C++11+ compatible compiler:
   ```bash
   g++ main.cpp Calendarp.cpp Calendar.cpp Datep.cpp Date.cpp -o calendar
   ```
2. Run executable:
   ```bash
   ./calendar
   ```

## Controls

| Key | Action |
|-----|--------|
| `1` | Switch to Gregorian calendar |
| `2` | Switch to Persian calendar |
| `n` | Next day |
| `p` | Previous day |
| `s` | Add/edit note |
| `b` | Back to calendar selection |
| `q` | Quit |

---

### Why This Matters
This project represents my first hands-on experience with:
- Object-oriented design patterns
- Date/time algorithms
- Console manipulation
- File I/O operations

While the implementation isn't production-grade, it served as a foundational step in my programming journey.

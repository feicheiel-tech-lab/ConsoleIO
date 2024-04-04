/*
## Screen Modes

### Set Mode
| ESC Code Sequence | Description                                                                                                                                                           |
| :---------------- | :--------------------------------------------------------------------------------------- |
| `ESC[={value}h`   | Changes the screen width or type to the mode specified by value.                                                                                                      |
| `ESC[=0h`         | 40 x 25 monochrome (text)                                                                                                                                             |
| `ESC[=1h`         | 40 x 25 color (text)                                                                                                                                                  |
| `ESC[=2h`         | 80 x 25 monochrome (text)                                                                                                                                             |
| `ESC[=3h`         | 80 x 25 color (text)                                                                                                                                                  |
| `ESC[=4h`         | 320 x 200 4-color (graphics)                                                                                                                                          |
| `ESC[=5h`         | 320 x 200 monochrome (graphics)                                                                                                                                       |
| `ESC[=6h`         | 640 x 200 monochrome (graphics)                                                                                                                                       |
| `ESC[=7h`         | Enables line wrapping                                                                                                                                                 |
| `ESC[=13h`        | 320 x 200 color (graphics)                                                                                                                                            |
| `ESC[=14h`        | 640 x 200 color (16-color graphics)                                                                                                                                   |
| `ESC[=15h`        | 640 x 350 monochrome (2-color graphics)                                                                                                                               |
| `ESC[=16h`        | 640 x 350 color (16-color graphics)                                                                                                                                   |
| `ESC[=17h`        | 640 x 480 monochrome (2-color graphics)                                                                                                                               |
| `ESC[=18h`        | 640 x 480 color (16-color graphics)                                                                                                                                   |
| `ESC[=19h`        | 320 x 200 color (256-color graphics)                                                                                                                                  |
| `ESC[={value}l`   | Resets the mode by using the same values that Set Mode uses, except for 7,
which disables line wrapping. The last character in this escape sequence is a lowercase L.

## Resources
- [Wikipedia: ANSI escape code](https://en.wikipedia.org/wiki/ANSI_escape_code)
- [Build your own Command Line with ANSI escape codes](http://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html)
- [ascii-table: ANSI Escape sequences](http://ascii-table.com/ansi-escape-sequences.php)
- [bluesock: ansi codes](https://bluesock.org/~willkg/dev/ansi.html)
- [bash-hackers: Terminal Codes (ANSI/VT100) introduction](http://wiki.bash-hackers.org/scripting/terminalcodes)
- [XTerm Control Sequences](https://invisible-island.net/xterm/ctlseqs/ctlseqs.html)
- [VT100 � Various terminal manuals](https://vt100.net/)
- [xterm.js � Supported Terminal Sequences](https://xtermjs.org/docs/api/vtfeatures/)

*/

#if defined(__linux__) || defined(__APPLE__)
    #ifndef FMT_HEADER_ONLY
    #define FMT_HEADER_ONLY
    #endif
    #include "fmt/format.h"
    using namespace fmt;

#elif defined(_WIN32)
    #include <format>
    
#endif

#ifndef ConsoleIO_H
#define ConsoleIO_H

#include <cstdint>
#include <string>

using namespace std;

class ConsoleColor
{
private:
    ConsoleColor();
    ConsoleColor(ConsoleColor&);

    // Reset
public:
    static const char* const RESET; // = "\033[0m";  // Text Reset

    // Regular Colors
    static const char* const REGULAR_BLACK; // = "\033[0;30m";   // BLACK
    static const char* const REGULAR_RED; // = "\033[0;31m";     // RED
    static const char* const REGULAR_GREEN; // = "\033[0;32m";   // GREEN
    static const char* const REGULAR_YELLOW; // = "\033[0;33m";  // YELLOW
    static const char* const REGULAR_BLUE; // = "\033[0;34m";    // BLUE
    static const char* const REGULAR_PURPLE; // = "\033[0;35m";  // PURPLE
    static const char* const REGULAR_CYAN; // = "\033[0;36m";    // CYAN
    static const char* const REGULAR_WHITE; // = "\033[0;37m";   // WHITE

    // Bold
    static const char* const BOLD_BLACK; // = "\033[1;30m";  // BLACK
    static const char* const BOLD_RED; // = "\033[1;31m";    // RED
    static const char* const BOLD_GREEN; // = "\033[1;32m";  // GREEN
    static const char* const BOLD_YELLOW; // = "\033[1;33m"; // YELLOW
    static const char* const BOLD_BLUE; // = "\033[1;34m";   // BLUE
    static const char* const BOLD_PURPLE; // = "\033[1;35m"; // PURPLE
    static const char* const BOLD_CYAN; // = "\033[1;36m";   // CYAN
    static const char* const BOLD_WHITE; // = "\033[1;37m";  // WHITE

    // Underline
    static const char* const UNDERLINED_BLACK; // = "\033[4;30m";  // BLACK
    static const char* const UNDERLINED_RED; // = "\033[4;31m";    // RED
    static const char* const UNDERLINED_GREEN; // = "\033[4;32m";  // GREEN
    static const char* const UNDERLINED_YELLOW; // = "\033[4;33m"; // YELLOW
    static const char* const UNDERLINED_BLUE; // = "\033[4;34m";   // BLUE
    static const char* const UNDERLINED_PURPLE; // = "\033[4;35m"; // PURPLE
    static const char* const UNDERLINED_CYAN; // = "\033[4;36m";   // CYAN
    static const char* const UNDERLINED_WHITE; // = "\033[4;37m";  // WHITE

    // Background
    static const char* const BACKGROUND_BLACK; // = "\033[40m";  // BLACK
    static const char* const BACKGROUND_RED; // = "\033[41m";    // RED
    static const char* const BACKGROUND_GREEN; // = "\033[42m";  // GREEN
    static const char* const BACKGROUND_YELLOW; // = "\033[43m"; // YELLOW
    static const char* const BACKGROUND_BLUE; // = "\033[44m";   // BLUE
    static const char* const BACKGROUND_PURPLE; // = "\033[45m"; // PURPLE
    static const char* const BACKGROUND_CYAN; // = "\033[46m";   // CYAN
    static const char* const BACKGROUND_WHITE; // = "\033[47m";  // WHITE

    // High Intensity
    static const char* const BRIGHT_BLACK; // = "\033[0;90m";  // BLACK
    static const char* const BRIGHT_RED; // = "\033[0;91m";    // RED
    static const char* const BRIGHT_GREEN; // = "\033[0;92m";  // GREEN
    static const char* const BRIGHT_YELLOW; // = "\033[0;93m"; // YELLOW
    static const char* const BRIGHT_BLUE; // = "\033[0;94m";   // BLUE
    static const char* const BRIGHT_PURPLE; // = "\033[0;95m"; // PURPLE
    static const char* const BRIGHT_CYAN; // = "\033[0;96m";   // CYAN
    static const char* const BRIGHT_WHITE; // = "\033[0;97m";  // WHITE

    // Bold High Intensity
    static const char* const BRIGHT_BOLD_BLACK; // = "\033[1;90m"; // BLACK
    static const char* const BRIGHT_BOLD_RED; // = "\033[1;91m";   // RED
    static const char* const BRIGHT_BOLD_GREEN; // = "\033[1;92m"; // GREEN
    static const char* const BRIGHT_BOLD_YELLOW; // = "\033[1;93m";// YELLOW
    static const char* const BRIGHT_BOLD_BLUE; // = "\033[1;94m";  // BLUE
    static const char* const BRIGHT_BOLD_PURPLE; // = "\033[1;95m";// PURPLE
    static const char* const BRIGHT_BOLD_CYAN; // = "\033[1;96m";  // CYAN
    static const char* const BRIGHT_BOLD_WHITE; // = "\033[1;97m"; // WHITE

    // High Intensity backgrounds
    static const char* const BRIGHT_BACKGROUND_BLACK; // = "\033[0;100m";// BLACK
    static const char* const BRIGHT_BACKGROUND_RED; // = "\033[0;101m";// RED
    static const char* const BRIGHT_BACKGROUND_GREEN; // = "\033[0;102m";// GREEN
    static const char* const BRIGHT_BACKGROUND_YELLOW; // = "\033[0;103m";// YELLOW
    static const char* const BRIGHT_BACKGROUND_BLUE; // = "\033[0;104m";// BLUE
    static const char* const BRIGHT_BACKGROUND_PURPLE; // = "\033[0;105m"; // PURPLE
    static const char* const BRIGHT_BACKGROUND_CYAN; // = "\033[0;106m";  // CYAN
    static const char* const BRIGHT_BACKGROUND_WHITE; // = "\033[0;107m";   // WHITE

    // Set RGB foreground and background
    static const string setForeGround(const uint8_t& r, const uint8_t& g, const uint8_t& b);
    static const string setBackGround(const uint8_t& r, const uint8_t& g, const uint8_t& b);

};


class ConsoleCommands {


private:
    ConsoleCommands();
    ConsoleCommands(ConsoleCommands&);

public:
    static const string moveCursorToLineNColM(const uint8_t& n, const uint8_t& m);
    static const string moveCursorToBegninningOfNextNLinesDown(const uint8_t& n);
    static const string moveCursorToBeginningOfPreviousNLinesUp(const uint8_t& n);
    static const string moveCursorToColumn(const uint8_t& n);
    static const string moveCursorUpOneLine();
    static const string saveCurrentCursorPosition();
    static const string restoreCursorToLastSavedPosition();
    static const string moveCursorUp(const uint8_t& n);
    static const string moveCursorDown(const uint8_t& n);
    static const string moveCursorRight(const uint8_t& n);
    static const string moveCursorLeft(const uint8_t& n);
    static const string moveCursorHome(void);
    static const string cls();
    static const string eraseFromCursorToEndOfLine(void);
    static const string eraseFromStartOfLineToCursor(void);
    static const string eraseEntireLine(void);
    static const string eraseFromCursorToBeginningOfScreen(void);
    static const string eraseFromCursorTillEndOfScreen(void);
    static const string makeCursorInvisible();
    static const string makeCursorVisible();
    static const string reset();
    static const string bold();
    static const string unbold();
    static const string light();
    static const string unlight();
    static const string italic();
    static const string unitalic();
    static const string underline();
    static const string ununderline();
    static const string strikethrough();
    static const string unstrikethrough();
    static const string cursorBlinkOn(void);
    static const string cursorBlinkOff(void);
    static const string makeTextInvisible();
    static const string makeTextVisible();
    static const string password(void);
};
#endif // !ConsoleIO_H
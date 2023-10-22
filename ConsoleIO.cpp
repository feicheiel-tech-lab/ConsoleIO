#include "ConsoleIO.h"


//static const char*
const char* const ConsoleColor::RESET = "\033[0m";  // Text Reset

// Regular Colors
const char* const ConsoleColor::REGULAR_BLACK = "\033[0;30m";   // BLACK
const char* const ConsoleColor::REGULAR_RED = "\033[0;31m";     // RED
const char* const ConsoleColor::REGULAR_GREEN = "\033[0;32m";   // GREEN
const char* const ConsoleColor::REGULAR_YELLOW = "\033[0;33m";  // YELLOW
const char* const ConsoleColor::REGULAR_BLUE = "\033[0;34m";    // BLUE
const char* const ConsoleColor::REGULAR_PURPLE = "\033[0;35m";  // PURPLE
const char* const ConsoleColor::REGULAR_CYAN = "\033[0;36m";    // CYAN
const char* const ConsoleColor::REGULAR_WHITE = "\033[0;37m";   // WHITE

// Bold
const char* const ConsoleColor::BOLD_BLACK = "\033[1;30m";  // BLACK
const char* const ConsoleColor::BOLD_RED = "\033[1;31m";    // RED
const char* const ConsoleColor::BOLD_GREEN = "\033[1;32m";  // GREEN
const char* const ConsoleColor::BOLD_YELLOW = "\033[1;33m"; // YELLOW
const char* const ConsoleColor::BOLD_BLUE = "\033[1;34m";   // BLUE
const char* const ConsoleColor::BOLD_PURPLE = "\033[1;35m"; // PURPLE
const char* const ConsoleColor::BOLD_CYAN = "\033[1;36m";   // CYAN
const char* const ConsoleColor::BOLD_WHITE = "\033[1;37m";  // WHITE

// Underline
const char* const ConsoleColor::UNDERLINED_BLACK = "\033[4;30m";  // BLACK
const char* const ConsoleColor::UNDERLINED_RED = "\033[4;31m";    // RED
const char* const ConsoleColor::UNDERLINED_GREEN = "\033[4;32m";  // GREEN
const char* const ConsoleColor::UNDERLINED_YELLOW = "\033[4;33m"; // YELLOW
const char* const ConsoleColor::UNDERLINED_BLUE = "\033[4;34m";   // BLUE
const char* const ConsoleColor::UNDERLINED_PURPLE = "\033[4;35m"; // PURPLE
const char* const ConsoleColor::UNDERLINED_CYAN = "\033[4;36m";   // CYAN
const char* const ConsoleColor::UNDERLINED_WHITE = "\033[4;37m";  // WHITE

// Background
const char* const ConsoleColor::BACKGROUND_BLACK = "\033[40m";  // BLACK
const char* const ConsoleColor::BACKGROUND_RED = "\033[41m";    // RED
const char* const ConsoleColor::BACKGROUND_GREEN = "\033[42m";  // GREEN
const char* const ConsoleColor::BACKGROUND_YELLOW = "\033[43m"; // YELLOW
const char* const ConsoleColor::BACKGROUND_BLUE = "\033[44m";   // BLUE
const char* const ConsoleColor::BACKGROUND_PURPLE = "\033[45m"; // PURPLE
const char* const ConsoleColor::BACKGROUND_CYAN = "\033[46m";   // CYAN
const char* const ConsoleColor::BACKGROUND_WHITE = "\033[47m";  // WHITE

// High Intensity
const char* const ConsoleColor::BRIGHT_BLACK = "\033[0;90m";  // BLACK
const char* const ConsoleColor::BRIGHT_RED = "\033[0;91m";    // RED
const char* const ConsoleColor::BRIGHT_GREEN = "\033[0;92m";  // GREEN
const char* const ConsoleColor::BRIGHT_YELLOW = "\033[0;93m"; // YELLOW
const char* const ConsoleColor::BRIGHT_BLUE = "\033[0;94m";   // BLUE
const char* const ConsoleColor::BRIGHT_PURPLE = "\033[0;95m"; // PURPLE
const char* const ConsoleColor::BRIGHT_CYAN = "\033[0;96m";   // CYAN
const char* const ConsoleColor::BRIGHT_WHITE = "\033[0;97m";  // WHITE

// Bold High Intensity
const char* const ConsoleColor::BRIGHT_BOLD_BLACK = "\033[1;90m"; // BLACK
const char* const ConsoleColor::BRIGHT_BOLD_RED = "\033[1;91m";   // RED
const char* const ConsoleColor::BRIGHT_BOLD_GREEN = "\033[1;92m"; // GREEN
const char* const ConsoleColor::BRIGHT_BOLD_YELLOW = "\033[1;93m";// YELLOW
const char* const ConsoleColor::BRIGHT_BOLD_BLUE = "\033[1;94m";  // BLUE
const char* const ConsoleColor::BRIGHT_BOLD_PURPLE = "\033[1;95m";// PURPLE
const char* const ConsoleColor::BRIGHT_BOLD_CYAN = "\033[1;96m";  // CYAN
const char* const ConsoleColor::BRIGHT_BOLD_WHITE = "\033[1;97m"; // WHITE

// High Intensity backgrounds
const char* const ConsoleColor::BRIGHT_BACKGROUND_BLACK = "\033[0;100m";// BLACK
const char* const ConsoleColor::BRIGHT_BACKGROUND_RED = "\033[0;101m";// RED
const char* const ConsoleColor::BRIGHT_BACKGROUND_GREEN = "\033[0;102m";// GREEN
const char* const ConsoleColor::BRIGHT_BACKGROUND_YELLOW = "\033[0;103m";// YELLOW
const char* const ConsoleColor::BRIGHT_BACKGROUND_BLUE = "\033[0;104m";// BLUE
const char* const ConsoleColor::BRIGHT_BACKGROUND_PURPLE = "\033[0;105m"; // PURPLE
const char* const ConsoleColor::BRIGHT_BACKGROUND_CYAN = "\033[0;106m";  // CYAN
const char* const ConsoleColor::BRIGHT_BACKGROUND_WHITE = "\033[0;107m";   // WHITE

// RGB
// ****************************//
// Set RGB Foreground Color.
// `ESC[38;2; {r}; {g}; {b}m` ---> Set foreground color as RGB.
const string ConsoleColor::setForeGround(const uint8_t& r, const uint8_t& g, const uint8_t& b)
{
	return format("\033[38;2;{};{};{}m", r, g, b);
}

// Set RGB Background color.
// `ESC[48;2; {r}; {g}; {b}m` ---> Set background color as RGB.
const string ConsoleColor::setBackGround(const uint8_t& r, const uint8_t& g, const uint8_t& b)
{
	return format("\033[48;2;{};{};{}m", r, g, b);
}



/*
*
* ConsoleCommands.
* ~~~~~~~~~~~~~~~~~~~~~~~~
*
*/
// Moves cursor to line n col m.
// `ESC[{line};{column}H`  ---> moves cursor to moves cursor to line #, column #
// or `ESC[{line};{column}f`
const string ConsoleCommands::moveCursorToLineNColM(const uint8_t& n, const uint8_t& m) {
	return format("\033[{};{}H", n, m);
}


// Moves the cursor to the beginning of next n lines down.
// `ESC[#E`  ---> moves cursor to the beginning of # lines down.
const string ConsoleCommands::moveCursorToBegninningOfNextNLinesDown(const uint8_t& n) {
	return format("\033[{}E", n);
}

// Moves the cursor to the beginning of previous n lines up.
// `ESC[#F`  ---> moves cursor to the beginning of # lines up.
const string ConsoleCommands::moveCursorToBeginningOfPreviousNLinesUp(const uint8_t& n) {
	return string("\033[") + to_string(n) + "F";
}

// Moves the cursor to column #
// `ESC[#G`  ---> moves cursor to column #
const string ConsoleCommands::moveCursorToColumn(const uint8_t& n) {
	return string("\033[") + to_string(n) + "G";
}

// Moves the cursor up one line scrolling if needed.
// `ESC M`   ---> moves cursor one line up, scrolling if needed 
const string ConsoleCommands::moveCursorUpOneLine() {
	return string("\033 M");
}

// Save the current cursor position
// `ESC 7`   ---> save cursor position (DEC)
const string ConsoleCommands::saveCurrentCursorPosition() {
	return string("\033 7");
}

// Restore the cursor to the last saved position.
// `ESC 8`   ---> restores the cursor to the last saved position (DEC)
const string ConsoleCommands::restoreCursorToLastSavedPosition() {
	return string("\033 8");
}

// Moves the cursor n lines up.
// `ESC[#A`  ---> moves cursor up # lines.
const string ConsoleCommands::moveCursorUp(const uint8_t& n)
{
	return "\033[" + to_string(n) + "A";
}

// Moves the cursor n lines down.
// `ESC[#B`  ---> moves cursor down # lines.
const string ConsoleCommands::moveCursorDown(const uint8_t& n)
{
	return "\033[" + to_string(n) + "B";
}


// Moves the cursor n columns right.
// `ESC[#C`  ---> moves cursor right # columns.
const string ConsoleCommands::moveCursorRight(const uint8_t& n)
{

	return string("\033[") + to_string(n) + "C";
}

// Moves the cursor n columns left.
// `ESC[#D`  ---> moves cursor left # columns.
const string ConsoleCommands::moveCursorLeft(const uint8_t& n)
{
	return string("\033[") + to_string(n) + "D";
}

// Moves the cursor home (0,0).
// `ESC[H`  ---> moves cursor home (0,0).
const string ConsoleCommands::moveCursorHome(void)
{
	return string("\033[H");
}

// Clears the screen entirely.
const string ConsoleCommands::cls()
{
	return string("\033[2J");
}

// Erase from cursor to end of line
// `ESC[0K`  ---> erase from cursor to end of line
const string ConsoleCommands::eraseFromCursorToEndOfLine(void) {
	return string("\033[0K\r");
}

// Erase from start of line to the cursor
// `ESC[1K` ---> erase start of line to the cursor
const string ConsoleCommands::eraseFromStartOfLineToCursor(void) {
	return string("\033[1K\r");
}

// Erase entireline
// `ESC[2K` ---> erase the entire line
const string ConsoleCommands::eraseEntireLine(void) {
	return string("\033[2K\r");
}

// Erase from cursor to the beginning of screen.
// `ESC[1J` ---> erase from cursor to beginning of screen
const string ConsoleCommands::eraseFromCursorToBeginningOfScreen(void) {
	return string("\033[1J\r");
}

// Erase from cursor until end of screen.
// `ESC[0J` ---> erase from cursor until end of screen 
const string ConsoleCommands::eraseFromCursorTillEndOfScreen(void) {
	return string("\033[0J\r");
}

// Make the cursor invisible
// `ESC[?25l`  ---> make cursor invisible
const string ConsoleCommands::makeCursorInvisible() {
	return string("\033[?25l");
}

// Make cursor visible.
// `ESC[?25h`  ---> make cursor visible
const string ConsoleCommands::makeCursorVisible() {
	return string("\033[?25h");
}


// `ESC[0m` |           | reset all modes(styles and colors)
const string ConsoleCommands::reset() {
	return string("\033[0m");
}

// `ESC[1m` | `ESC[22m` | set bold mode. 
const string ConsoleCommands::bold() {
	return string("\033[1m");
}
const string ConsoleCommands::unbold() {
	return string("\033[22m");
}

// `ESC[2m` | `ESC[22m` | set dim / faint mode.
const string ConsoleCommands::light() {
	return string("\033[2m");
}
const string ConsoleCommands::unlight() {
	return string("\033[22m");
}

// `ESC[3m` | `ESC[23m` | set italic mode. 
const string ConsoleCommands::italic() {
	return string("\033[3m");
}
const string ConsoleCommands::unitalic() {
	return string("\033[23m");
}

// `ESC[4m` | `ESC[24m` | set underline mode.
const string ConsoleCommands::underline() {
	return string("\033[4m");
}
const string ConsoleCommands::ununderline() {
	return string("\033[24m");
}

// `ESC[9m` | `ESC[29m` | set strikethrough mode.
const string ConsoleCommands::strikethrough() {
	return string("\033[9m");
}
const string ConsoleCommands::unstrikethrough() {
	return string("\033[29m");
}

// `ESC[5m` | `ESC[25m` | set blinking mode.
const string ConsoleCommands::cursorBlinkOn(void) {
	return string("\033[5m");
}
const string ConsoleCommands::cursorBlinkOff(void) {
	return string("\033[25m");
}

// `ESC[7m` | `ESC[27m` | set inverse / reverse mode.
// `ESC[8m` | `ESC[28m` | set hidden / invisible mode.
const string ConsoleCommands::makeTextInvisible() {
	return string("\033[8m");
}
const string ConsoleCommands::makeTextVisible() {
	return string("\033[28m");
}


/*
* ### Keyboard Strings

`ESC[{code};{string};{...}p`

Redefines a keyboard key to a specified string.

The parameters for this escape sequence are defined as follows:

- `code` is one or more of the values listed in the following table. These values represent keyboard keys and key combinations.
When using these values in a command, you must type the semicolons shown in this table in addition to the semicolons required
by the escape sequence. The codes in parentheses are not available on some keyboards.
`ANSI.SYS` will not interpret the codes in parentheses for those keyboards unless you specify the `/X` switch in the `DEVICE`
command for `ANSI.SYS`.

- `string` is either the ASCII code for a single character or a string contained in quotation marks. For example, both 65
and "A" can be used to represent an uppercase A.

> **IMPORTANT:** Some of the values in the following table are not valid for all computers.
Check your computer's documentation for values that are different.

#### List of keyboard strings

| Key                      | Code     | SHIFT+code | CTRL+code | ALT+code  |
| ------------------------ | -------- | ---------- | --------- | --------- |
| F1                       | 0;59     | 0;84       | 0;94      | 0;104     |
| F2                       | 0;60     | 0;85       | 0;95      | 0;105     |
| F3                       | 0;61     | 0;86       | 0;96      | 0;106     |
| F4                       | 0;62     | 0;87       | 0;97      | 0;107     |
| F5                       | 0;63     | 0;88       | 0;98      | 0;108     |
| F6                       | 0;64     | 0;89       | 0;99      | 0;109     |
| F7                       | 0;65     | 0;90       | 0;100     | 0;110     |
| F8                       | 0;66     | 0;91       | 0;101     | 0;111     |
| F9                       | 0;67     | 0;92       | 0;102     | 0;112     |
| F10                      | 0;68     | 0;93       | 0;103     | 0;113     |
| F11                      | 0;133    | 0;135      | 0;137     | 0;139     |
| F12                      | 0;134    | 0;136      | 0;138     | 0;140     |
| HOME (num keypad)        | 0;71     | 55         | 0;119     | \--       |
| UP ARROW (num keypad)    | 0;72     | 56         | (0;141)   | \--       |
| PAGE UP (num keypad)     | 0;73     | 57         | 0;132     | \--       |
| LEFT ARROW (num keypad)  | 0;75     | 52         | 0;115     | \--       |
| RIGHT ARROW (num keypad) | 0;77     | 54         | 0;116     | \--       |
| END (num keypad)         | 0;79     | 49         | 0;117     | \--       |
| DOWN ARROW (num keypad)  | 0;80     | 50         | (0;145)   | \--       |
| PAGE DOWN (num keypad)   | 0;81     | 51         | 0;118     | \--       |
| INSERT (num keypad)      | 0;82     | 48         | (0;146)   | \--       |
| DELETE (num keypad)      | 0;83     | 46         | (0;147)   | \--       |
| HOME                     | (224;71) | (224;71)   | (224;119) | (224;151) |
| UP ARROW                 | (224;72) | (224;72)   | (224;141) | (224;152) |
| PAGE UP                  | (224;73) | (224;73)   | (224;132) | (224;153) |
| LEFT ARROW               | (224;75) | (224;75)   | (224;115) | (224;155) |
| RIGHT ARROW              | (224;77) | (224;77)   | (224;116) | (224;157) |
| END                      | (224;79) | (224;79)   | (224;117) | (224;159) |
| DOWN ARROW               | (224;80) | (224;80)   | (224;145) | (224;154) |
| PAGE DOWN                | (224;81) | (224;81)   | (224;118) | (224;161) |
| INSERT                   | (224;82) | (224;82)   | (224;146) | (224;162) |
| DELETE                   | (224;83) | (224;83)   | (224;147) | (224;163) |
| PRINT SCREEN             | \--      | \--        | 0;114     | \--       |
| PAUSE/BREAK              | \--      | \--        | 0;0       | \--       |
| BACKSPACE                | 8        | 8          | 127       | (0)       |
| ENTER                    | 13       | \--        | 10        | (0        |
| TAB                      | 9        | 0;15       | (0;148)   | (0;165)   |
| NULL                     | 0;3      | \--        | \--       | \--       |
| A                        | 97       | 65         | 1         | 0;30      |
| B                        | 98       | 66         | 2         | 0;48      |
| C                        | 99       | 66         | 3         | 0;46      |
| D                        | 100      | 68         | 4         | 0;32      |
| E                        | 101      | 69         | 5         | 0;18      |
| F                        | 102      | 70         | 6         | 0;33      |
| G                        | 103      | 71         | 7         | 0;34      |
| H                        | 104      | 72         | 8         | 0;35      |
| I                        | 105      | 73         | 9         | 0;23      |
| J                        | 106      | 74         | 10        | 0;36      |
| K                        | 107      | 75         | 11        | 0;37      |
| L                        | 108      | 76         | 12        | 0;38      |
| M                        | 109      | 77         | 13        | 0;50      |
| N                        | 110      | 78         | 14        | 0;49      |
| O                        | 111      | 79         | 15        | 0;24      |
| P                        | 112      | 80         | 16        | 0;25      |
| Q                        | 113      | 81         | 17        | 0;16      |
| R                        | 114      | 82         | 18        | 0;19      |
| S                        | 115      | 83         | 19        | 0;31      |
| T                        | 116      | 84         | 20        | 0;20      |
| U                        | 117      | 85         | 21        | 0;22      |
| V                        | 118      | 86         | 22        | 0;47      |
| W                        | 119      | 87         | 23        | 0;17      |
| X                        | 120      | 88         | 24        | 0;45      |
| Y                        | 121      | 89         | 25        | 0;21      |
| Z                        | 122      | 90         | 26        | 0;44      |
| 1                        | 49       | 33         | \--       | 0;120     |
| 2                        | 50       | 64         | 0         | 0;121     |
| 3                        | 51       | 35         | \--       | 0;122     |
| 4                        | 52       | 36         | \--       | 0;123     |
| 5                        | 53       | 37         | \--       | 0;124     |
| 6                        | 54       | 94         | 30        | 0;125     |
| 7                        | 55       | 38         | \--       | 0;126     |
| 8                        | 56       | 42         | \--       | 0;126     |
| 9                        | 57       | 40         | \--       | 0;127     |
| 0                        | 48       | 41         | \--       | 0;129     |
| \-                       | 45       | 95         | 31        | 0;130     |
| \=                       | 61       | 43         | \---      | 0;131     |
| \[                       | 91       | 123        | 27        | 0;26      |
| \]                       | 93       | 125        | 29        | 0;27      |
|                          | 92       | 124        | 28        | 0;43      |
| ;                        | 59       | 58         | \--       | 0;39      |
| '                        | 39       | 34         | \--       | 0;40      |
| ,                        | 44       | 60         | \--       | 0;51      |
| .                        | 46       | 62         | \--       | 0;52      |
| /                        | 47       | 63         | \--       | 0;53      |
| \`                       | 96       | 126        | \--       | (0;41)    |
| ENTER (keypad)           | 13       | \--        | 10        | (0;166)   |
| / (keypad)               | 47       | 47         | (0;142)   | (0;74)    |
| \* (keypad)              | 42       | (0;144)    | (0;78)    | \--       |
| \- (keypad)              | 45       | 45         | (0;149)   | (0;164)   |
| \+ (keypad)              | 43       | 43         | (0;150)   | (0;55)    |
| 5 (keypad)               | (0;76)   | 53         | (0;143)   | \--       |

`ESC[{code};{string};{...}p`
*/
const string ConsoleCommands::password(void)
{
	return string("\033[65;66;...p");
}



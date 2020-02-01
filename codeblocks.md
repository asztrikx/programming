# Download
codeblocks-17.12mingw-setup.exe
# Settings
- Compiler
	- Selected compiler: `GNU GCC Compiler`
	- Compiler settings > Compiler flags
		- General
			- %C++11%: `true`
		- Warnings
			- %-Wall%: `true`
			- %-Weffc++%: `true`
			- %-Wextra: `true`
	- Other compiler options
		- `-fsanitize=undefined`
		- `-fsanitize-undefined-trap-on-error`
- Debugger > GDB/CDB debugger > Default
	- Executable path: `Find`
	- Disable startup scripts (-nx) (GDB only): `false`
	- Evaluate expression under cursor: `true`
- Editor
	- General settings > Editor settings > TAB options
		- Use TAB character: `true`
	- Code completion //Ha nem megy az autocomplete
		- Disable SmartSense: `true`
# .h és .cpp hozzáadása
Project > Add files... > Select > Ok
# Debug
- Debugging windows
	- Watches: `true`
	- Call stack: `true`
# Shortcuts
http://wiki.codeblocks.org/index.php?title=Keyboard_Shortcuts

| Action        | Key           |
|---------------|---------------|
| Build         | Ctrl+F9       |
| Compile       | Ctrl+Shift+F9 |
| Run           | F9            |
| Debug         | F8            |
| Step over     | F7            |
| Step into     | Shift+F7      |
| Step out      | Ctrl+Shift+F7 |
| Run to cursor | F4            |
# No UTF-8
# Uninstall
- Windows  
	- `uninstaller`  
	- `%appdata%`

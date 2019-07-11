# Codeblocks
## Download
codeblocks-17.12mingw-setup.exe
## Settings
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
# Debug
- Debugging windows > Watches
## No UTF-8
## Uninstall
- Windows  
	- `uninstaller`  
	- `%appdata%`
# Tester
## Windows
```bat
@echo off
if not exist test ( mkdir test )
for /L %%i in (1,1,99) do (
	if exist be%%i.txt (
		program.ext < be%%i.txt > test/ki%%i.txt
		fc ki%%i.txt test/ki%%i.txt
	)
)
pause
```
## Linux
[R]TODO

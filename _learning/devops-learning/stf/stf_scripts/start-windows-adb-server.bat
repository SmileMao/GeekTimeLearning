@echo off


REM 更改当前目录为批处理本身的目录
cd /d %~dp0

REM adb version > 1.0.32   otherwise use adb -a -P 5037 fork-server server

for /F "tokens=5 delims= " %%a in ('netstat -aon ^| findstr 5037 ^| findstr LISTENING') do ( 
	echo port occupied : %%a
	taskkill /pid %%a /f /t
)
adb devices
adb kill-server
adb nodaemon server -a -P 5037

pause
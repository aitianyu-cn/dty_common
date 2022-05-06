@echo off

chcp 65001

@echo ##################################################################################
@echo #
@echo # 天宇开发者库(Tianyu Developing Library)
@echo # 项目(Project): Tianyu Development library
@echo # 
@echo # 本程序用于初始化 天宇开发者库 以配置部分依赖
@echo # Tianyu Developing Library init runner to configure some necessary dependency
@echo # 
@echo ##################################################################################

set language="zh_CN"

set par1=%1

if "%par1%" == "help" (
    goto help_part
) else (
    set pre=%par1:~0,3%
    if "%pre%" == "-l:" (call :set_language)
)

: 国际化文件初始化模块
@echo.
@echo 当前设置语言为(Currently Setting Language is): %language:~1,-1%
@echo 创建多语言依赖(Create Multi-Language Dependency)
cd .\native\res\creater
call dotnet Creater.dll -l %language:~1,-1%
cd ..\..\..\
@echo 创建完成(Done...)
@echo.
: 国际化文件初始化模块

goto finish

:help_part
    @echo -- 初始化程序帮助
    @echo -- Init Runner Helper
    @echo.
    @echo -- init.bat [option][params]
    @echo.
    @echo -- - option
    @echo -- -         help: 打开帮助菜单
    @echo -- -               Open Init Runner Helper List
    @echo -- - 
    @echo -- - params
    @echo -- -         -l:language_type: 设置需要初始化的语言(大小写不敏感)
    @echo -- -                           set the init language what is need(no matter the case)
    @echo -- -                           zh[_ch] - 中文/Chinese
    @echo -- -                           en[_us] - 英文/English
    @echo -- - 

    goto :eof

:set_language
    set lang=%par1:~3%
    if /i "%lang%"=="zh_CN" (
        set language="zh_CN"
    ) else if /i "%lang%"=="zh" (
        set language="zh_CN"
    ) else if /i "%lang%"=="en_us" (
        set language="en_US"
    ) else if /i "%lang%"=="en" (
        set language="en_US"
    )

    goto :eof

:finish
    @echo.
    @echo 初始化完成(Initial Done...)
    goto :eof
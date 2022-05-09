#!/bin/bash
# Tianyu Native Init Runner

# set variables
language="zh_CN"
par1=$1

function print()
{
    echo "$1"
    return
}

function printHelp()
{
    print "-- 初始化程序帮助"
    print "-- Init Runner Helper"
    print ""
    print "-- init.bat [option][params]"
    print ""
    print "-- - option"
    print "-- -         help: 打开帮助菜单"
    print "-- -               Open Init Runner Helper List"
    print "-- - "
    print "-- - params"
    print "-- -         -l:language_type: 设置需要初始化的语言(大小写不敏感)"
    print "-- -                           set the init language what is need(no matter the case)"
    print "-- -                           zh[_ch] - 中文/Chinese"
    print "-- -                           en[_us] - 英文/English"
    print "-- - "
}

function process_language()
{
    lang=$(echo $1 | tr 'A-Z' 'a-z')
    case $lang in
        "zh")
        language="zh_CN"
        ;;
        "cn")
        language="zh_CN"
        ;;
        "zh_cn")
        language="zh_CN"
        ;;
        "en")
        language="en_US"
        ;;
        "en_us")
        language="en_US"
        ;;
        *)
        ;;
    esac

    print "Setting Language - Current language is "${language}
}

function processParams()
{
    array=${par1//\:/ }
    index=0
    value=0
    key=0
    for var in ${array[*]}
        do
            if [ $index -eq 0 ]; then
                key=$var
            fi
            if [ $index -eq 1 ]; then
                value=$var
            fi
            index=`expr $index + 1`
        done

    if [ $index -gt 1 ]; then
        if [[ $key=="-l" ]]; then
            process_language $value
        fi
    fi

    print ""
}

function runI18NInit()
{
    print ""
    print "    + Create Multi-Language Dependency"

    cd ./native/res/creater
    command $(dotnet Creater.dll -l $language)
    cd ../../../

    print "    - Create Done..."
}
function runFlow()
{
    print "----------------------------------------------------------------------------------"
    print ""
    print "Start Initialize"

    runI18NInit

    print ""
    print "Initialize Finish..."
    print ""
}

print "##################################################################################"
print "#"
print "# 天宇开发者库(Tianyu Developing Library)"
print "# 项目(Project): Tianyu Development library"
print "# "
print "# 本程序用于初始化 天宇开发者库 以配置部分依赖"
print "# Tianyu Developing Library init runner to configure some necessary dependency"
print "# "
print "##################################################################################"

if [ [$par1] == "[help]" ]; 
    then
        printHelp
    else
        processParams
        runFlow
fi
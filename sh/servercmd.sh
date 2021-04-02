#!/bin/bash
#参数1： 命令
# start[默认] 启动
# stop 停止
CMD=$1
#参数2：服务名称
NAME=$2
#参数3： 类型
# release[默认] 后台启动
# debug 前台启动
MODE=$3

#参数4:启动配置文件

TMP=$PATH
# . /etc/init.d/functions #添加 开机启动中
# ./lib/lsb/init-functions

PATH=$TMP
CUR_PATH=$(dirname $(readlink -f $0))
WORK_PATH=$(dirname $CUR_PATH)
# echo "当前目录"$CUR_PATH
# echo "工作目录"$WORK_PATH
PID_DIR="/var/run/skynet"
PID_FILE=$PID_DIR"/"$NAME".pid"

# echo $PID_FILE
if [ -z "$4" ]; then
  CONFIG=$CUR_PATH"/config."$NAME
else
  CONFIG=$CUR_PATH"/"$4
fi

#后台启动
function back
{
  echo -n $"Starting "$NAME": "
  $WORK_PATH/common/skynet/skynet $CONFIG
  if [ $? -eq 0 ]; then
    success && echo
  else
    failure && echo
  fi
}

#前台启动
function view
{
  debug_cfg=$CUR_PATH"/debug."$NAME

  # sed -e 's/^logger/--logger/' -e 's/daemon/--daemon/' $CONFIG > $debug_cfg
  $WORK_PATH/common/skynet/skynet $debug_cfg
}

function start
{
  case "$MODE" in
    release)
    #sh sh/log_name.sh login
      back
      ;;
    debug)
      view
      ;;
    *)
      echo "mode[$MODE] invalid param, please sure [release|debug]"
      exit 2
  esac
}

function stop
{
  if [ ! -f $PID_FILE ] ;then
    echo "not found pid file have no myservice"
    exit 0
  fi

  pid=`cat $PID_FILE`
  exist_pid=`pgrep skynet | grep $pid`
  if [ -z "$exist_pid" ] ;then
    echo "have no myservice"
    exit 0
  else
    echo -n $"$pid myservice will killed"
    kill -s QUIT $pid 
    echo
  fi
}


case "$CMD" in
  start)
    start
    ;;
  stop)
    stop
    ;;
  *)
    echo "$0 start [release|debug config] | $0 stop"
    exit 2
esac


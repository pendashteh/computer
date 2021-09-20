#!/usr/bin/env bash

POTATO_DEFAULT_TASK="help"
POTATO_TASK_PATH_PATTERN="tasks/__TASK__"
POTATO_INCLUDES=( 'inc' )

[ ! -f "$POTATO_CORE" ] && echo "Please get potato first..." && exit || . $POTATO_CORE

#!/usr/bin/env bash

function app_computer_name {
  local computer_id=${1:-$(potato_get_id)}
  echo ${computer_id##@}
}

function app_exec {
  local interactive=
  if [ "$1" = '-i' ]; then
    interactive=1
    shift
  fi
  echo '> '$@
  if test ! -z "$interactive"; then
    read -p 'Are you sure? [Y/n]' answer && [ "$answer" = 'n' ] && return
  fi
  $@
}

function app_validate_computer_exists {
  local computer_name=$1
  [ ! -z "$(lxc ls --format csv | cut -d',' -f1 | grep $computer_name)" ]
}

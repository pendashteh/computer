#!/usr/bin/env bash

function app_computer_name {
  local computer_id=${1:-$POTATO_THIS_ID}
  [ ! "$computer_id" = "$POTATO_DEFAULT_ID" ] && echo ${computer_id##@}
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
  [ ! -z "$computer_name" ] && [ ! -z "$(lxc ls --format csv | cut -d',' -f1 | grep $computer_name)" ]
}

function app_require_computer_name {
  local computer_name=$(app_computer_name)
  [ -z "$computer_name" ] && echo "Please provide the computer_name" && return 1
  return 0
}

function app_computer_should_exist {
  local computer_name=$(app_computer_name)
  ! app_validate_computer_exists $computer_name && echo 'Computer '$computer_name' does not exist.' && return 1
  return 0
}

function app_computer_should_not_exist {
  local computer_name=$(app_computer_name)
  app_validate_computer_exists $computer_name && echo 'Computer '$computer_name' already exists.' && return 1
  return 0
}

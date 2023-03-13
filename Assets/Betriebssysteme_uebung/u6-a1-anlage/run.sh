#!/bin/sh
make --silent ; ./syscall ; echo "[returned $?]"

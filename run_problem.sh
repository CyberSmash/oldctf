#!/bin/sh
socat TCP4-LISTEN:5555,fork,tcpwrap=script EXEC:./password2.2

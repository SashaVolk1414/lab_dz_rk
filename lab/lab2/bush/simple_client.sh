#!/bin/bash
echo "$1" | nc localhost 12345
echo "Сообщение отправлено: $1"

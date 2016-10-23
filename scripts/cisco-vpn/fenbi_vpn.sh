#!/bin/bash

if [ $# -eq 1 ]
then
    command=$1
else
    command='connect'
fi

if [ $command == 'stop' ]
then
    echo 'stop vpn'
    /opt/cisco/anyconnect/bin/vpn disconnect
    exit
fi

echo 'start vpn'
username='[your ldap username]'
passwd='[your ldap password]'`sh ./fenbi_oath.sh [profile_name]`

/opt/cisco/anyconnect/bin/vpn -s << EOF
connect [vpn address]
$username
$passwd
EOF

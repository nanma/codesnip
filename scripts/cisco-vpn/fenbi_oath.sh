#!/bin/bash
#fork from http://superuser.com/questions/462478/is-there-a-google-authenticator-desktop-client , by Peter Beckman

scriptname=`basename $0`
if [ -z $1 ]
then
echo "$scriptname: Service Name Req'd"
echo ""
echo "Usage:"
echo "   otp google"
echo ""
echo "Configuration: $HOME/.otpkeys"
echo "Format: name=key"
exit
fi
otpkey=` grep ^$1 $HOME/.otpkeys | cut -d"=" -f 2 | sed "s/ //g" `
if [ -z $otpkey ]
then
echo "$scriptname: Bad Service Name"
exit
fi
token=`/usr/local/bin/oathtool --totp -b $otpkey`
echo $token
echo $token | /usr/bin/pbcopy #自动拷贝至剪贴板

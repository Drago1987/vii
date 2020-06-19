#!/bin/sh
tmp=$( pwd )
echo $tmp
url_playlist=$( find . -name url_playlist.txt )
cat_url=$( cat $url_playlist )
youtube-dl -i  $cat_url

import os
import re
import youtube_dl

url_file=""
root_file=""
for root, dirs, files in os.walk("."):
    for filename in files:
        found=re.search('.txt',filename)
        if found == None:
            pass
        else:
            root_file=root
            url_file=filename

my_file_handle=open(root_file + '/' + url_file)
url_=my_file_handle.read()


ydl = youtube_dl.YoutubeDL({'outtmpl': '%(id)s%(ext)s'})
try:
    with ydl:
        result = ydl.extract_info(
            url_,
            download=True
            )
except IOError:
    print("File missing, please add in current directory.")



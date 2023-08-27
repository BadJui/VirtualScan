# VirtualScan
一个Web路径扫描器，支持HTTP/HTTPS协议，慢速扫描等功能
<br/>
具体使用方法：

__     ___      _               _   ____
\ \   / (_)_ __| |_ _   _  __ _| | / ___|  ___ __ _ _ __
 \ \ / /| | '__| __| | | |/ _` | | \___ \ / __/ _` | '_ \
  \ V / | | |  | |_| |_| | (_| | |  ___) | (_| (_| | | | |
   \_/  |_|_|   \__|\__,_|\__,_|_| |____/ \___\__,_|_| |_|


[VirtualScan v1.0.0]
[Copyright (c) 2023 BadJui, Virtual (D@1) ]

<Usage>: VirtualScan [options]


          -url <http/https url>
          -m thread      : set max thread
          -t timeout     : tcp timeout in seconds
          -r rootpath    : set root path to scan
          -o           : set log output path
          -shutdown           : set auto shutdown
          -d           : set dictionary path
          -w           : wait for a minute
<Example>:
          VirtualScan www.target.com:8080 -m 10 -t 16 -d D:\dictionary\dictionary.txt
          VirtualScan www.target.com:80 -r "/test/" -d C:\Windows\dictionary.txt -w 50
          VirtualScan www.tartget.com -o C:\VirtualLog\Log.txt -shutdown true -w 20 -d G:\test\dictionary.txt

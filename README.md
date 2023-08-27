# VirtualScan
一个Web路径扫描器，支持HTTP/HTTPS协议，慢速扫描等功能
<br/>
具体使用方法：



          -url <http/https url>
          -m thread      : set max thread
          -t timeout     : tcp timeout in seconds
          -r rootpath    : set root path to scan
          -o           : set log output path
          -shutdown           : set auto shutdown
          -d           : set dictionary path
          -w           : wait for a minute

          VirtualScan www.target.com:8080 -m 10 -t 16 -d D:\dictionary\dictionary.txt
          VirtualScan www.target.com:80 -r "/test/" -d C:\Windows\dictionary.txt -w 50
          VirtualScan www.tartget.com -o C:\VirtualLog\Log.txt -shutdown true -w 20 -d G:\test\dictionary.txt

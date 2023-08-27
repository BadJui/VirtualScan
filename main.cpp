#include <bits/stdc++.h>
#include <windows.h>
#include <curl/curl.h>

using namespace std;

long port,thread_,timeout,url_count,wait;
string url,output_path,rootpath,dpath;
bool auto_shutdown;


size_t curlCallback(void* contents,size_t size,size_t nmemb,string* response) {
	size_t totalSize=size*nmemb;
	response->append((char*)contents,totalSize);
	return totalSize;
}
string getHttpResponseHeader(const string& url) {
	string header;
	CURL* curl=curl_easy_init();
	if(curl){
		if(!timeout)curl_easy_setopt(curl,CURLOPT_TIMEOUT,timeout);
		curl_easy_setopt(curl,CURLOPT_SSL_VERIFYPEER,0L);
		curl_easy_setopt(curl,CURLOPT_SSL_VERIFYHOST,0L);
		curl_easy_setopt(curl,CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl,CURLOPT_HEADER, 1L);
		curl_easy_setopt(curl,CURLOPT_NOBODY, 1L);
		curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION, curlCallback);
		curl_easy_setopt(curl,CURLOPT_WRITEDATA, &header);
		CURLcode res=curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return header;
}

void log_(string str_log){
	ofstream ofile(output_path,ios::app);
	ofile<<str_log;
	ofile.close();
	cout<<str_log;
}
const string introduction="\x5f\x5f\x20\x20\x20\x20\x20\x5f\x5f\x5f\x20\x20\x20\x20\x20\x20\x5f\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x5f\x20\x20\x20\x5f\x5f\x5f\x5f\x0a\x5c\x20\x5c\x20\x20\x20\x2f\x20\x28\x5f\x29\x5f\x20\x5f\x5f\x7c\x20\x7c\x5f\x20\x5f\x20\x20\x20\x5f\x20\x20\x5f\x5f\x20\x5f\x7c\x20\x7c\x20\x2f\x20\x5f\x5f\x5f\x7c\x20\x20\x5f\x5f\x5f\x20\x5f\x5f\x20\x5f\x20\x5f\x20\x5f\x5f\x0a\x20\x5c\x20\x5c\x20\x2f\x20\x2f\x7c\x20\x7c\x20\x27\x5f\x5f\x7c\x20\x5f\x5f\x7c\x20\x7c\x20\x7c\x20\x7c\x2f\x20\x5f\x60\x20\x7c\x20\x7c\x20\x5c\x5f\x5f\x5f\x20\x5c\x20\x2f\x20\x5f\x5f\x2f\x20\x5f\x60\x20\x7c\x20\x27\x5f\x20\x5c\x0a\x20\x20\x5c\x20\x56\x20\x2f\x20\x7c\x20\x7c\x20\x7c\x20\x20\x7c\x20\x7c\x5f\x7c\x20\x7c\x5f\x7c\x20\x7c\x20\x28\x5f\x7c\x20\x7c\x20\x7c\x20\x20\x5f\x5f\x5f\x29\x20\x7c\x20\x28\x5f\x7c\x20\x28\x5f\x7c\x20\x7c\x20\x7c\x20\x7c\x20\x7c\x0a\x20\x20\x20\x5c\x5f\x2f\x20\x20\x7c\x5f\x7c\x5f\x7c\x20\x20\x20\x5c\x5f\x5f\x7c\x5c\x5f\x5f\x2c\x5f\x7c\x5c\x5f\x5f\x2c\x5f\x7c\x5f\x7c\x20\x7c\x5f\x5f\x5f\x5f\x2f\x20\x5c\x5f\x5f\x5f\x5c\x5f\x5f\x2c\x5f\x7c\x5f\x7c\x20\x7c\x5f\x7c\x0a";
int main(int argc,char* argv[]){
	cout<<introduction<<endl<<endl;
	if(argc==1){WelCome:
		cout<<"[VirtualScan v1.0.0]\n[Copyright (c) 2023 BadJui, Virtual (D@1) ]\n\n";
		cout<<"<Usage>: VirtualScan [options]\n\n";
		cout<<"\n          -url <http/https url>\n          -m thread      : set max thread\n          -t timeout     : tcp timeout in seconds\n          -r rootpath    : set root path to scan\n          -o           : set log output path\n          -shutdown           : set auto shutdown\n          -d           : set dictionary path\n          -w           : wait for a minute\n<Example>:\n          VirtualScan www.target.com:8080 -m 10 -t 16 -d D:\\dictionary\\dictionary.txt\n          VirtualScan www.target.com:80 -r \"/test/\" -d C:\\Windows\\dictionary.txt -w 50\n          VirtualScan www.tartget.com -o C:\\VirtualLog\\Log.txt -shutdown true -w 20 -d G:\\test\\dictionary.txt\n\n";
		return 0;
	}else{
		int thread_num=1;  // 默认线程数为1
		for(int i=1;i<argc;i++){
			string temp=argv[i];
			if(temp=="-url")url=argv[i+1];
			else if(temp=="-p")port=atoi(argv[i+1]);
			else if(temp=="-m")thread_=atoi(argv[i+1]);
			else if(temp=="-t")timeout=atoi(argv[i+1]);
			else if(temp=="-r")rootpath=argv[i+1];
			else if(temp=="-o")output_path=argv[i+1];
			else if(temp=="-shutdown"){
				if(string(argv[i+1])=="true")auto_shutdown=true;
				else auto_shutdown=false;
			}
			else if(temp=="-d")dpath=argv[i+1];
			else if(temp=="-m")thread_num=atoi(argv[i+1]);
			else if(temp=="-w")wait=atoi(argv[i+1]);
			
			
			else if(temp=="-h")goto WelCome;
			
			else if(temp=="-test"){
				cout<<url<<endl<<port<<endl<<thread_<<endl<<timeout<<endl<<rootpath<<endl<<output_path<<endl;
				if(auto_shutdown==true)cout<<"true\n";
				else cout<<"false\n";
			}
			
			
			else continue;
		}
	}
	
	if(!url.empty()&&!dpath.empty()){
		url+=rootpath;
		if(!getHttpResponseHeader(url).empty())log_("[+] URL verification completed.\n");
		else{
			log_("[-] URL verification failed.\n");
			return 0;
		}
		ifstream load_dpath(dpath);
		if(load_dpath.good())log_("[+] Dictionary loading completed.\n");
		else{
			log_("[-] Dictionary loading failed.\n");
			load_dpath.close();
			return 0;
		}
//		vector<thread> threads;
		
		string line;
		while(getline(load_dpath,line)){
//			if(url[url.size()-1]!='/')url+='/';
			string header=getHttpResponseHeader(url+line);
//			if(header[header.find("HTTP/1.1 200 OK")+16]=='\r'||header[header.find("HTTP/1.1 200 OK")+16]=='\n')log_(url+line+'\n');
            if (!line.empty()){
            	Sleep(wait);
//                threads.emplace_back([&url,&line](){
                    string header=getHttpResponseHeader(url+line);
//                    cout<<header<<endl<<endl;
                    if(header.find("HTTP/")!=string::npos&&header.find(" 200")!=string::npos&&header.find(" OK")!=string::npos&&(header.find("404 File not found")==string::npos||header.find("404 Not Found")==string::npos))log_(url + line + '\n'),url_count++;
//                });
            }
        }
//        for(auto& t:threads)t.join();
        log_("\n[+] VirtualScan scanned a total of "+to_string(url_count)+" paths.\n");
		if(auto_shutdown)system("shutdown /s /t 0");
	}
	else log_("[-] Scan failed! Parameter error!\n");
	return 0;
}
